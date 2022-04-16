int vibrationRead = 1;

int val = 0;
int val2 = 0;
int test = 0;

void setup() {
  // put your setup code here, to run once:
   TCCR2B = TCCR2B & B11111000 | B00000110; // Freq 61.04 Hz
   pinMode(6, OUTPUT); // (Use D6 for voltage output)
   pinMode(A0, INPUT);
   pinMode(A1, INPUT);


   Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*val = analogRead(A0); //Read pin A0 voltage (Use for voltage input)
  Serial.println(val); //Check serial monitor for value and voltage
  Serial.print("Voltage: ");
  Serial.println(((float(val)*5)/1024));

  val2 = analogRead(A1); //Read pin A0 voltage (Use for voltage input)
  Serial.println(val2); //Check serial monitor for value and voltage
  Serial.print("Amps: ");
  Serial.println(((float(val)*1.75)/1024));*/

  // All of these change if you change the frequency, which shouldn't help anything

  //digitalWrite(6, HIGH);
  
 while(1){
    if(Serial.available() > 0){
      String data = Serial.readStringUntil('\n');
    }
    if(vibrationRead == 1){
      digitalWrite(6, HIGH); //VRMS = 1.5 V
      delay(10);
      digitalWrite(6, LOW);
      delay(10);
      delay(random(10000, 45000));
    }
   }
  //}
  
  //analogWrite(3, 123); //VRMS = 2 V

  //analogWrite(6, 75); //VRMS = 2.5 V
  
  //analogWrite(6, 104); //VRMS = 3 V

  //analogWrite(6, 138); //VRMS = 3.5 V

  //analogWrite(6, 177); //VRMS = 4 V

  //analogWrite(6, 224); //VRMS = 4.5 V

  //analogWrite(6, 254); //VRMS = 4.74 V
}
