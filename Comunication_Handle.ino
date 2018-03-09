
/*===============================Compute the Check sum================================*/
bool computeCS(char *Msg)   /* source 1=serial0; 2=serial1(Bluetooth)  */
{ 
 bool MessageOk=0;
 int CheckSum = 0;
 /*--todo make the checksum as: 2*number of odd numbers + 4*number of even numbers  --*/
  unsigned short int i=0;
  for( i=0; i<4; i++)
     {
        CheckSum += Msg[i]-48;
     }   
  
 /*------part used only for debug   DELETE after -------*/ 
  Serial.write("\n Checksum:");
  Serial.println(CheckSum);
  /*------------------end DELETE part-------------------*/
  
  
  if(CheckSum == Msg[4])
     {
     MessageOk = 1;
     }
   return MessageOk;
}
/*===============================read serial message RX0 TX0===============================*/
bool read_Message()
{
  unsigned short int i=0;
  bool readOk = 0;
  char Read_Byte;

  Read_Byte = Serial.read();
  if(Read_Byte=='@')
    {
      for(i=0; i<6; i++)
      {
        while(Serial.available()==0);//wait until the serial becomes available
        rec_Arr[i] = Serial.read();
        
      }
      if(rec_Arr[5] == '#')
      {
          readOk = 1;
      }
  return readOk;
}
}
/*===============================Read bluetooth serial message RX1 TX1========================*/
bool read_Bluetooth_Message()
{
  unsigned short int i=0;
  bool readOk = 1;
  char Read_Byte;
  
  
  Read_Byte = Serial1.read();
  if(Read_Byte=='@')
    {
      for(i=0; i<6; i++)
      {
        while(Serial1.available()==0);//wait until the serial becomes available
        rec_Blu_Arr[i] = Serial1.read();    
      }
      if(rec_Blu_Arr[5] != '#')
      {
          readOk = 0;
      }
      if(computeCS(rec_Blu_Arr) == 0)
      {
          readOk = 0;  
      }   /* to do find a checksum easy to compute*/
  return readOk;
}
}

/*===============================Check the id of the of the message=========================*/
void Msg_handle(char *Msg_to_handle)
{
   switch(Msg_to_handle[0]){
         case '1': 
         {
               Motor_Steer(Msg_to_handle[1]);
               Serial.write("\n index is :");
               Serial.write(rec_Blu_Arr[0]);
         }
         break;
         case '2':
               {
               Motor_Move(Msg_to_handle[1], MakeValueFormChar(Msg_to_handle[2], Msg_to_handle[3]));
               Serial.write("\n index is :");
               Serial.write(rec_Blu_Arr[0]);
               }
         break;
         case '3': 
         {
               Control_Lights(Msg_to_handle[1]);
               Serial.write("\n index is :");
               Serial.write(rec_Blu_Arr[0]);
         }
         break;
         case '4':
         {      
               Control_Signal_Light(Msg_to_handle[1]);
               Serial.write("\n index is :");
               Serial.write(rec_Blu_Arr[0]);
         }   
         break;
         case '7': 
         {
               Print_Errors();
         }      
         break;
         case '8': 
         {
               // TO DO: add a file for autodriving
         }      
         break;
         default: Error_Handling(ErrorCOM_ID_Blu_message, ErrorSRC_Blu_message);  /*error handle */
   }
}
/*===============================end of message reading================================*/
int MakeValueFormChar(char Value10, char Value1 )
{
    int resultNumber=0;
    resultNumber = (int)(Value10 - 48);    
    resultNumber = resultNumber * 10;
    resultNumber += (int)(Value1 - 48);
    return resultNumber;
}
