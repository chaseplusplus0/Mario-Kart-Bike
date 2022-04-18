
int delay1(){
  int i,j;
  unsigned int count=0;
  for(i=0;i<500;i++){
    for(j=0;j<500;j++){
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
