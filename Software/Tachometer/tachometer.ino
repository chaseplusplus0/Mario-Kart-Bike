//Tachometer driver file
//Don't change baud rate of serial or it will break!!
//Delay for loop limit can be changed to speed up measurement timing

int limit = 500;

int delay1(){
  int i,j;
  unsigned int count=0;
  for(i=0;i<limit;i++){
    for(j=0;j<limit;j++){
      if(digitalRead(2) == LOW){
        count++;
        while(digitalRead(2) == LOW);
      }
    }
  }
  return count;
}

void setup(){
  Serial.begin(9600);
  pinMode(2, INPUT);
}

void loop(){
  unsigned int time=0,RPM=0;
  time=delay1();
  RPM=((time)*25)/20;
  
  Serial.print(RPM);

}
