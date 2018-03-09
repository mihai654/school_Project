void Error_Handling(char Err_Comm, char Err_source)
{
  int i=0;
   do
   {
       
       if(Errors_array[Err_source][i]==0) 
       {
           Errors_array[Err_source][i]==Err_Comm;
       }
       else if(i==4)
       {
           Errors_array[Err_source][i]==Err_Comm;
       }
       else
       {
            i++;
       }
   } while((Errors_array[Err_source][i]!=0)||(i < 4));
    
}
void Print_Errors()
{
    for(int i=0; i<10; i++)
       {
           if(Errors_array[i][0] != 0)
           {
                Serial.write("\n Errors for ");
                Serial.write(i);
                Serial.write(" are ");
                Serial.write(Errors_array[i][0]);
                Serial.write(Errors_array[i][1]);
                Serial.write(Errors_array[i][2]);
                Serial.write(Errors_array[i][3]);
           }
       }  
}
