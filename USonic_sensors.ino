void ReadAll_US_Sensors()
{
      for(int i=0; i<4; i++)
  {
      switch(i){
        case 0:
        {
            Distances_around[i] = USensor_measure(Trig_Pin_1, Echo_Pin_1);    
        }
        case 1:
        {
            Distances_around[i] = USensor_measure(Trig_Pin_2, Echo_Pin_2);    
        }
        case 2:
        {
            Distances_around[i] = USensor_measure(Trig_Pin_3, Echo_Pin_3);    
        }
        case 3:
        {
            Distances_around[i] = USensor_measure(Trig_Pin_4, Echo_Pin_4);    
        }
      }
      
  }
    
}

int USensor_measure(int TriggerPin, int EchoPin)
 {
  int duration, distance;
  digitalWrite(TriggerPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(TriggerPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(TriggerPin, LOW);
  
  /*pulseln() returns the length of the pulse (in microseconds) or
  0 if no trigger pulse is found until timeout: */
  
  duration = pulseIn(EchoPin, HIGH, 500);
  if(duration != 0)
  {
      distance = (duration) / 58;
        //Serial.print(distance);
       // Serial.println(" cm");
      //delay(500);
  }
  else 
  { 
    /*error*/
  }
 return distance;
 }
