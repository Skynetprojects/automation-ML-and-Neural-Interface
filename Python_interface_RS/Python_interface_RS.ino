//last updated 15/06/2021 by Akshay6766

int incomingByte;      // a variable to read incoming serial data into
int count = 0;
int i = 0;
 
void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  // initialize the  pin as an output:
 
  pinMode(3,  OUTPUT); //Relay 1 gray
  pinMode(4,  OUTPUT); //Relay 2 black
  pinMode(5,  OUTPUT); //Relay 3 white
  pinMode(6,  OUTPUT); //Relay 4 orange
  pinMode(7,  OUTPUT);
  pinMode(8,  OUTPUT);
  pinMode(9,  OUTPUT);
  pinMode(10, INPUT); // Setup for leads off detection LO +
  pinMode(11, INPUT); // Setup for leads off detection LO -
  pinMode(12,  OUTPUT);
  pinMode(13,  OUTPUT);

  
  

  
  digitalWrite(3,HIGH);//Relay 1 gray
  digitalWrite(4,HIGH);//Relay 2 black
  digitalWrite(5,HIGH);//Relay 3 white
  digitalWrite(6,HIGH);//Relay 4 orange
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);//status
    

  
}
 
void loop() {
  // see if there's incoming serial data:
  if (Serial.available() >= 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    
    if (incomingByte == '1') {
      //profile 1
      delay(100);
     
      digitalWrite(3,LOW);//Relay 1 gray
      digitalWrite(4,HIGH);//Relay 2 black
      digitalWrite(5,HIGH);//Relay 3 white
      digitalWrite(6,HIGH);//Relay 4 orange not using
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(13,LOW);
    } 
    if (incomingByte == '2') {
      //profile 2
      delay(100);
      digitalWrite(3,HIGH);//Relay 1 gray
      digitalWrite(4,LOW);//Relay 2 black
      digitalWrite(5,HIGH);//Relay 3 white
      digitalWrite(6,HIGH);//Relay 4 orange not using
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(13,LOW);
    }
    if (incomingByte == '3') {
      
      //profile 3
      delay(100);
      digitalWrite(3,HIGH);//Relay 1 gray
      digitalWrite(4,HIGH);//Relay 2 black
      digitalWrite(5,LOW);//Relay 3 white
      digitalWrite(6,HIGH);//Relay 4 orange not using
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(13,LOW);
    }
    if (incomingByte == '4') {
      
      //profile 4
      delay(100);
      digitalWrite(3,HIGH);//Relay 1 gray
      digitalWrite(4,HIGH);//Relay 2 black
      digitalWrite(5,HIGH);//Relay 3 white
      digitalWrite(6,LOW);//Relay 4 orange not using
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(13,LOW);
    }
    if (incomingByte == '5') {
      
      //profile 5
      delay(100);
      digitalWrite(3,HIGH);//Relay 1 gray
      digitalWrite(4,HIGH);//Relay 2 black
      digitalWrite(5,HIGH);//Relay 3 white
      digitalWrite(6,HIGH);//Relay 4 orange not using
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(13,LOW);
    }
    if (incomingByte == '6') {
            //profile 6
      delay(100);
      digitalWrite(3,HIGH);//Relay 1 gray
      digitalWrite(4,HIGH);//Relay 2 black
      digitalWrite(5,HIGH);//Relay 3 white
      digitalWrite(6,HIGH);//Relay 4 orange not using
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      digitalWrite(13,LOW);
    }
    if (incomingByte == '7') {
      //profile 7
      delay(100);
     digitalWrite(3,HIGH);//Relay 1 gray
     digitalWrite(4,HIGH);//Relay 2 black
     digitalWrite(5,HIGH);//Relay 3 white
     digitalWrite(6,HIGH);//Relay 4 orange not using
     digitalWrite(7,LOW);
     digitalWrite(8,LOW);
     digitalWrite(9,HIGH);
     digitalWrite(13,HIGH);
    }
    if (incomingByte == '8') {
      //all off
      //profile 8
      delay(100);
      digitalWrite(3, HIGH);//Relay 1 gray
      digitalWrite(4, HIGH);//Relay 2 black
      digitalWrite(5, HIGH);//Relay 3 white
      digitalWrite(6, HIGH);//Relay 4 orange not using
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(13,LOW);
    }
    if (incomingByte == '9') {
      //all on
      //Conected Appliance Self Test
      //test connected lights,massager
      //profile 9
      delay(100);
      while(i<=50)
        {
        digitalWrite(3, LOW);//Relay 1 gray
        delay(500);
        digitalWrite(3, HIGH);//Relay 1 gray
        delay(500);
        digitalWrite(4, LOW);//Relay 2 black
        delay(500);
        digitalWrite(4, HIGH);//Relay 2 black
        delay(500);
        digitalWrite(5, LOW);//Relay 3 white
        delay(500);
        digitalWrite(5, HIGH);//Relay 3 white
        delay(500);
        digitalWrite(6, LOW);
        delay(500);
        digitalWrite(6, HIGH);//Relay 4 orange not using
        delay(500);
        digitalWrite(7, HIGH);
        delay(500);
        digitalWrite(7, LOW);
        delay(500);
        digitalWrite(8, HIGH);
        delay(500);
        digitalWrite(8, LOW);
        delay(500);
        digitalWrite(9, HIGH);
        delay(500);
        digitalWrite(9, LOW);//Relay 3 white
        delay(500);
        //digitalWrite(13,HIGH);
        i++;
        
        }
    }
    if (incomingByte == '0') {
      //profile 10
      digitalWrite(12,HIGH);
      while (true)
      {
        if((digitalRead(10) == 1)||(digitalRead(11) == 1)){
        //Serial.println('!');
          }
        else{
        // send the value of analog input 0:
        Serial.println(analogRead(A0));
        delay(100);
        if (analogRead(A0) >= 450)
                
            digitalWrite(7,HIGH);
        else
            digitalWrite(7,LOW);
          
         
  
        }
        //Wait for a bit to keep serial data from saturating
        delay(1);
        
        
          
      }
       
      
    }
  }
}
