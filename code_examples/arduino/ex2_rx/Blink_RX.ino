/*
  VNG IoT Lab - 2017

  Website: 
    + http://iotviet.com.vn
    + https://www.facebook.com/bleviet

  Examples for VBLUno v2 board

  Arduino_Ex2: Receive UART and transmit response over UART

*/

char val=0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Init");
}

// the loop function runs over and over again forever
void loop() {
  if(Serial.available()){
    val = Serial.read();
    Serial.print("\r\nResponse: ");
    Serial.println(char(val+1));
  }
}
