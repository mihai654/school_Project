
void Motor_Move(char Move_direction, int MoveSpeed)
{
  switch(Move_direction){
     case MoveBreak: 
    {
      digitalWrite(DriverIN1, HIGH);
      digitalWrite(DriverIN2, HIGH);
      Serial.write(" Move break \n ");
    }
    break;
    case MoveForward: 
    {
      digitalWrite(DriverIN1, HIGH);
      digitalWrite(DriverIN2, LOW);
      analogWrite(DriverENA, MoveSpeed);
      Serial.write(" Move forward \n ");
    }
    break;
    case MoveBackward:
    {
      digitalWrite(DriverIN1, LOW);
      digitalWrite(DriverIN2, HIGH);
      analogWrite(DriverENA, MoveSpeed);
      Serial.write(" Move backward \n ");
    }
    break;
    case MoveNone: 
    {
      digitalWrite(DriverIN1, LOW);
      digitalWrite(DriverIN2, LOW);
      Serial.write(" Move none \n ");
    }
    break;
    default: Error_Handling(ErrorCOM_Motor_Move_Blu_message, ErrorSRC_Blu_message);/*error*/
  }
 
}

void Motor_Steer(char SteerSide)
{
   switch(SteerSide){
    case Steer_None: 
    {
      digitalWrite(DriverIN3, LOW);
      digitalWrite(DriverIN4, LOW);
      Serial.write(" Steer none \n ");
    }
    break;
    case Steer_L:
    {
      digitalWrite(DriverIN3, LOW);
      digitalWrite(DriverIN4, HIGH);
      Serial.write(" Steer left \n ");
    }
    break;
    case Steer_R: 
    {
      digitalWrite(DriverIN3, LOW);
      digitalWrite(DriverIN4, LOW);
      Serial.write(" Steer right \n ");
    }
    break;
    default: Error_Handling(ErrorCOM_Motor_Steer_Blu_message, ErrorSRC_Blu_message);/*error*/
  }
}

