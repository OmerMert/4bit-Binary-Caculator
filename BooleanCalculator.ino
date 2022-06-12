int number1Pins[4] = {5, 4, 3, 2}; //4bit first number pins
int number2Pins[4] = {9, 8, 7, 6}; //4bit second number pins
int resultNumberPins[4] = {13, 12, 11, 10}; //4bit result number pins
int operatorPins[5] = {A0, A1, A2, A3, A4}; //sum, sub, mul, div, clear

uint8_t number1 = 0; //first number
uint8_t number2 = 0; //second number
uint8_t result = 0; //result number

void setup() {
  Serial.begin(9600); 
  
  for(int i = 0; i < 4; i++)
  {
    pinMode(number1Pins[i], INPUT); //first number pins set as INPUT
    pinMode(number2Pins[i], INPUT); //second number pins set as INPUT
    pinMode(resultNumberPins[i], OUTPUT); //result number pins set as OUTPUT
  }

  for(int i = 0; i < 5; i++)
    pinMode(operatorPins[i], INPUT); //operator pins set as INPUT
 
    
}

void loop() {

  for(int i = 0; i < 5; i++)
  {
    // Checking if any operator button is pressed
    if(digitalRead(operatorPins[i])){
      GetNumbers();
      switch(i)
      {
        case 0: //Clear
          result = 0;
          break;
        case 1: //Division
          result = number1 / number2;
          break;
        case 2: //Multiplication
          result = number1 * number2;
          break;
        case 3: //Subtraction
          result = number1 - number2;
          break;
        case 4: //Summation
          result = number1 + number2;
          break;
      }
      ShowOutput(result);
    }
  }
  
  delay(100);
}

void GetNumbers()
{
  for(int i = 0; i < 4; i++)
  {
    int temp = digitalRead(number1Pins[i]);
    bitWrite(number1, i, temp);
  }
  
  for(int i = 0; i < 4; i++)
  {
    int temp = digitalRead(number2Pins[i]);
    bitWrite(number2, i, temp);
  }
}

void ShowOutput(int result)
{
  for(int i = 0; i < 4; i++)
    digitalWrite(resultNumberPins[i] ,bitRead(result, i));
  
}
