void Control_Lights(char Lgt_Comm)
{
  switch(Lgt_Comm){
     case L_Beam_on: 
    {
      analogWrite(Headlights_PWM_pin, 100);
      Serial.write("\n Lights low beam on \n");
    }
    break;
    case L_Beam_off: 
    {
      analogWrite(Headlights_PWM_pin, 0);
      Serial.write("\n Lights low beam off \n");
    }
    break;
    case H_Beam_on:
    {
      analogWrite(Headlights_PWM_pin, 200);
      Serial.write("\n Lights high beam on \n");
    }
    break;
    case H_Beam_off: 
    {
      analogWrite(Headlights_PWM_pin, 0);
      Serial.write("\n Lights high beam Off \n");
    }
    break;
    default: /*error*/
    break;
  }  
}

void Control_Signal_Light(char Sgn_Lgt_Comm)
{
    switch(Sgn_Lgt_Comm){
     case Signal_on: 
    {
      digitalWrite(Signal_left_pin, HIGH);
      digitalWrite(Signal_right_pin, HIGH);
      Serial.write("\n Signal on \n");
    }
    break;
    case Signal_off: 
    {
      digitalWrite(Signal_left_pin, LOW);
      digitalWrite(Signal_right_pin, LOW);
      Serial.write("\n Signal off \n");
    }
    break;
    case Hazard_signal_on:
    {
      digitalWrite(Signal_left_pin, HIGH);
      digitalWrite(Signal_right_pin, HIGH);
      Serial.write("\n Signal hazard on \n");
    }
    break;
    case Hazard_signal_off: 
    {
      digitalWrite(Signal_left_pin, LOW);
      digitalWrite(Signal_right_pin, LOW);
      Serial.write("\n Signal hazard off \n");
    }
    break;
    default: /*error*/
    break;
  }  
}
