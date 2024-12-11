#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_NeoPixel.h>


//DISPLAY THINGS
#define OLED_RESET    4     // Reset pin # (or -1 if sharing Arduino reset pin)
#define OLED_ADDRESS  0x3C  // I2C address of the display.
#define SCREEN_WIDTH  128   // OLED display width, in pixels
#define SCREEN_HEIGHT 64    // OLED display height, in pixels

#define BEEP 2

//BUTTON THINGS
#define LEFT_B_IN     A0       
#define RIGHT_B_IN    A1       

//GAME OPTIONS

#define WIN_POINTS 20
#define CYCLE_INTERVAL 500
#define BUTTON_INTERVAL 100

unsigned long previousTime = 0;

//---------DISPLAY STUFF---------

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


#define PIN 13 // led dat pin
#define DIOD_NO 1 // number of used RGB diodes
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(DIOD_NO, PIN, NEO_GRB + NEO_KHZ800);


//Draws a square on the 21x10 board
//(A 128x64 board reduced to 126x60, each element is 6x6)
//x is between 0 and 20 inclusive
//y is between 0 and 9 inclusive
//thing: 0 = erase, 1 = snake, 2 = food 
//Could've used a switch statement here...
void drawSquare(byte x, byte y, byte thing)
{
  if (thing == 1){
      display.fillRect(6*x+2,6*y+3,4,4,WHITE);  
      return;
  }
  if (thing == 2){
      display.drawRoundRect(6*x+2,6*y+3,4,4,1,WHITE);
      return;
  }
  display.fillRect(6*x+2,6*y+3,4,4,BLACK);
}

//---------SNAKE STUFF---------

//Coordinate struct
//With the size of the game board (21x10), you could technically shrink it to
//1 byte, but I don't quite know how to do that yet.
typedef struct
{
  byte x;
  byte y;
} coord;

//THE SNAKE
//#Apparently snake[] took up so much space that it interfered with the OLED
//#Keep it a reasonable size.
coord snake[100];
byte snakeLength = 2;
short directions[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
short dirIndex = 0;

coord foodCoord;

#define C_BLACK 0
#define C_RED 1
#define C_ORANGE 2
#define C_YELLOW 3
#define C_GREEN 4
#define C_CYAN 5
#define C_BLUE 6
#define C_PURPLE 7
#define C_WHITE 8

byte Colors[9][3]={
  {0,0,0},      //BLACK
  {255,0,0},    //RED
  {255,165,0},  //ORANGE
  {255,255,0},  //YELLOW
  {0,255,0},    //GREEN
  {0,127,255},  //CYAN
  {0,0,255},    //BLUE
  {139,0,255},  //PURPLE
  {255,255,255} //WHITE
};

//Initializes the snake with an initial length of 2
//and initial direction right.
void makeSnake()
{
  snakeLength = 2;
  snake[0] = {1, (byte) random(0,10)};
  snake[1] = {0, snake[0].y};
  drawSquare(snake[0].x,snake[0].y,1);
  drawSquare(snake[1].x,snake[1].y,1);
  dirIndex = 0;
  
}

//Modify direction according to button press
unsigned long tempTime = millis();
bool R = true;
bool L = true;
int Step=0;
void redirect()
{  
  switch(Step)
  {
    case 0:
    {
      if (millis()-tempTime > BUTTON_INTERVAL) Step=1;
    }break;
    case 1:
    {
      //Listen for button presses
      L=!digitalRead(LEFT_B_IN);
      R=!digitalRead(RIGHT_B_IN);
      if(R==L)
      {
        Step=2;
      }
    }break;
    case 2:
    {
      L=!digitalRead(LEFT_B_IN);
      R=!digitalRead(RIGHT_B_IN);
      //Ignore double presses and non presses
      if (R != L)
      {
        delay(20);
        L=!digitalRead(LEFT_B_IN);
        R=!digitalRead(RIGHT_B_IN);
        if (R != L)
        {
          //If right, increment direction index
          if (R){
            dirIndex++;
            if (dirIndex > 3){dirIndex = 0;}
            //return;
          }
          //If left, decrement direction index
          if(L)
          {
          dirIndex--;
          if (dirIndex < 0){dirIndex = 3;}
          }
          tempTime = millis();
          Step=0;
        }
      }
    }break;
    default:break;  
  }
}

//Moves the snake
bool moveSnake()
{
  //Calculate the new coordinates
  int x = snake[0].x+directions[dirIndex][0];
  int y = snake[0].y+directions[dirIndex][1];

  //If out of bounds, exit and lose.
  if (x > 20 || x < 0 || y > 9 || y < 0)
  {
    return 1;
  }

  coord newHead = {byte(x),byte(y)};
  //Draw the new head
  drawSquare(newHead.x,newHead.y,1);
  
  //Did we land on food? / Does the new head line up with the food location?
  bool onFood = (newHead.x == foodCoord.x && newHead.y == foodCoord.y);
  
  //Shift all the snake coords back to make space for the head
  for (int i = snakeLength; i != 0; --i)
  {
    //If the new head contacts any snake coord, exit and lose
    if (!onFood && newHead.x == snake[i].x && newHead.y == snake[i].y)
    {
      return 1;
    }
    snake[i] = snake[i-1];
  }

  //If nothing wrong, set the new head of the snake.
  snake[0] = newHead;

  //If no food, erase tail
  if (!onFood)
  {
    drawSquare(snake[snakeLength].x,snake[snakeLength].y,0);
    
  }
  //Else dont erase tail, increment length of snake,
  //and put a new food    
  else
  {
    tone(BEEP,1000);//147
    delay(100);
    noTone(BEEP);
    snakeLength++;
    putFood();
  }
  return 0;
}

//Puts a new piece of food on the game board.
void putFood()
{
  bool foodOkay = false;
  //Make sure the food doesnt fall on top of the snake
  while (!foodOkay)
  {
    foodCoord = {byte(random(0,21)),byte(random(0,10))};
    foodOkay = true;
    for (byte i = 0; i < snakeLength; ++i)
    {
      if (foodCoord.y == snake[i].y && foodCoord.x == snake[i].x)
      {
        foodOkay = false;
        break;
      }
    }
  }
  drawSquare(foodCoord.x,foodCoord.y,2);
}

void Turn_on()
{
    tone(BEEP,2093);
    RGB_LED(C_CYAN);
    delay(100);
    noTone(BEEP);
    delay(80);
    tone(BEEP,2960);
    RGB_LED(C_YELLOW);
    delay(100);
    noTone(BEEP);
    delay(80);
    tone(BEEP,2093);
    RGB_LED(C_RED);
    delay(100);
    noTone(BEEP);
    delay(80);
    tone(BEEP,2960);
    RGB_LED(C_BLUE);
    delay(100);
    noTone(BEEP);
    delay(80);
    tone(BEEP,3322);
    RGB_LED(C_GREEN);
    delay(500);
    noTone(BEEP);
    RGB_LED(C_BLACK);
}

void won()
{
    tone(BEEP,2093);
    RGB_LED(C_RED);
    delay(100);
    noTone(BEEP);
    delay(80);
    tone(BEEP,2093);
    RGB_LED(C_GREEN);
    delay(100);
    noTone(BEEP);
    delay(80);
    tone(BEEP,2093);
    RGB_LED(C_BLUE);
    delay(100);
    noTone(BEEP);
    delay(80);
    tone(BEEP,3322);
    RGB_LED(C_YELLOW);
    delay(500);
    noTone(BEEP);
    RGB_LED(C_BLACK);
}

void RGB_LED(int color)
{
  for(int i=0;i<DIOD_NO;i++)
  {
    pixels.setPixelColor(i, Colors[color][0], Colors[color][1], Colors[color][2]); 
    pixels.show();
  }  
}

void setup() 
{
  //Serial.begin(9600);
  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    //Serial.println(F("Oh no"));
    for(;;);
  }

  //Random numbers
  randomSeed(analogRead(7));

  //Set up the buttons
  //Left button
  pinMode(LEFT_B_IN, INPUT_PULLUP);

  //Right button
  pinMode(RIGHT_B_IN, INPUT_PULLUP);

  //Beep
  pinMode(BEEP,OUTPUT);

  pinMode(PIN,OUTPUT);
  
  //Set up the title screen
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(20,5);
  display.println(F("SNAKE"));
  display.setTextSize(1);
  display.setCursor(26,40);
  display.println(F("Hit L to play"));
  display.display();
  Turn_on();
}


//Game loop
void loop() {

  display.display();
  //Wait for user input
  while (digitalRead(LEFT_B_IN)){}

  //GAME SETUP
  //Set up borders
  display.clearDisplay();
  display.fillRect(0,0,128,2,WHITE);
  display.fillRect(0,62,128,2,WHITE);
  display.fillRect(0,0,1,64,WHITE);
  display.fillRect(127,0,1,64,WHITE);

  //Make the snake and place the food
  makeSnake();
  putFood();
  display.display();
  bool win = false;
  delay(800);

  //Start game
  for(;;)
  {
    //Every cycle
    //Check for direction change
      redirect();
    if (millis() - previousTime > CYCLE_INTERVAL)//500
    {
      previousTime = millis();
      
      //Self contact/Out of bounds condition
      if (moveSnake())
      {
        break;
      }
      if (snakeLength == WIN_POINTS+2)
      {
        win = true;
        break;
      }
      display.display();
    }
  }

  if (win)
  {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,5);
    display.println(F("YOU WON :)"));
    won();
  }
  //Show lose screen
  else
  {
        
    //Flash the screen
    display.invertDisplay(true);tone(BEEP,200);//147
    RGB_LED(C_RED);
    delay(400);
    display.invertDisplay(false);noTone(BEEP);
    RGB_LED(C_BLACK);
    delay(400);
    display.invertDisplay(true);tone(BEEP,200);//147
    RGB_LED(C_RED);
    delay(400);
    display.invertDisplay(false);noTone(BEEP);
    RGB_LED(C_BLACK);
    delay(400);

    //Loss text
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,5);
    display.println(F("YOU LOST:("));
  }
  display.setTextSize(1);
  display.setCursor(0,30);
  display.print(F("Donuts Eaten: "));
  display.print(snakeLength-2);
  display.println();
  display.println();
  display.println(F("Hit L to play again"));
}
