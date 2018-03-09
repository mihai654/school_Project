void LineFlw_ReadSensors()
{
   Ln_Flw_L = digitalRead(Ln_Left_Pin);
   Ln_Flw_C = digitalRead(Ln_Center_Pin);
   Ln_Flw_R = digitalRead(Ln_Right_Pin);
}

void Drive_On_line()
{
   //set the code for driving on the line  
}
