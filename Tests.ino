/*-----Call the functions and print the values on serial---- */

char test_message[6] = {0};
void TestComunication()
{
    if(Serial1.available()>0)
    {
      if(read_Bluetooth_Message()==1)
      {
          Serial.write("The message is correct: ");
          for (int j=0; j<5; j++)
          {
             Serial.write(rec_Blu_Arr[j]); 
          }
          computeCS(rec_Blu_Arr);//will print the checksum
          Serial.write("Sent value is: ");
          Serial.write(MakeValueFormChar(rec_Blu_Arr[2], rec_Blu_Arr[3]));
          
          Msg_handle(rec_Blu_Arr);
          Serial.write("\n");
      }
      else 
      {
          Serial.write("Message error: ");
          for (int j=0; j<5; j++)
          {
             Serial.write(rec_Blu_Arr[j]); 
          }
          Serial.write("\n");   
          computeCS(rec_Blu_Arr);
          Serial.write("\n");
      }
       
    }
    delay(100);
}

void test_Motor()
{
 
    Serial.write("Testing the motor move ");
    Motor_Move(MoveBreak, 50);
    delay(1000);
    Motor_Move(MoveForward, 50);
    delay(1000);  
    Motor_Move(MoveBackward, 50);
    delay(1000);  
    Motor_Move(MoveNone, 50);
    delay(1000);

    Serial.write("Testing the motor steer ");
    Motor_Steer(Steer_None);
    delay(1000);  
    Motor_Steer(Steer_L);
    delay(1000);
    Motor_Steer(Steer_R);
    delay(1000);
    
}
