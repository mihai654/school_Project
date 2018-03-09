/*======================================defines===================================================*/
/*----------------------------------define the pin names------------------------------------------*/
/*--Line follow pins--*/
#define Ln_Left_Pin      14
#define Ln_Center_Pin    15 
#define Ln_Right_Pin     16
/*--motor driver pins--*/
#define DriverIN1        50
#define DriverIN2        51
#define DriverIN3        52
#define DriverIN4        53
#define DriverENA        7
#define DriverENB        6   /*not used if jumper is on the driver board*/

/*--ultrasonic sensors pins--*/
/*--front sensor--*/
#define Trig_Pin_1       37
#define Echo_Pin_1       36 
/*--right sensor--*/
#define Trig_Pin_2       35
#define Echo_Pin_2       34
/*--Back sensor--*/
#define Trig_Pin_3       33
#define Echo_Pin_3       32
/*--Left sensor--*/
#define Trig_Pin_4       31
#define Echo_Pin_4       30

/*--Lights heandling--*/
#define Headlights_PWM_pin     5
#define Breaklights_PWM_pin    4
#define Signal_left_pin       22
#define Signal_right_pin      23
 

/*------------------------------------used replacements-------------------------------------------*/
#define MoveForward   '1'
#define MoveBackward  '2' 
#define MoveNone      '3'
#define MoveBreak     '0'
#define Steer_L       '1'
#define Steer_R       '2'
#define Steer_None    '3'
/*--Lights heandling--*/
#define L_Beam_on     '1'
#define L_Beam_off    '2'
#define H_Beam_on     '3'
#define H_Beam_off    '4'
#define Signal_on          '1'
#define Signal_off         '2'
#define Hazard_signal_on   '5'
#define Hazard_signal_off  '6'
/*--boolean--*/
#define TRUE          1
#define FALSE         0

/*------------------------------------Errors(must not have value 0)-------------------------------*/
/*--error comm--*/
#define ErrorCOM_ID_Blu_message               1
#define ErrorCOM_Motor_Move_Blu_message       2
#define ErrorCOM_Motor_Steer_Blu_message      3

/*--error source--*/
#define ErrorSRC_Blu_message                  1


/*================================================================================================*/

/*=========================================global variables=======================================*/
char Read_Byte;
char rec_Arr[10];
char rec_Blu_Arr[12];
int Ln_Flw_L, Ln_Flw_C, Ln_Flw_R; /* line following sensors pins*/
bool Blue_Msg_Read_Lock = 0;
char Distances_around[4]; /*0=front 1=right 3=back 4=left when looking as a driver*/
bool Testing_ON = TRUE;
char Errors_array[10][4];
/*================================================================================================*/

/*=======================================function prototypes======================================*/
bool computeCS(char *Msg );  /*computing the checksum of the recieved message*/
bool read_Message(void);  /*read the message from the serial_0 comunication port*/  
bool read_Bluetooth_Message(void); /*read the message form the serial_1 comunication port(bluetooth is connected to it) */
void LineFlw_ReadSensors(void); /*read the sensors values and save it to global variables*/
void Drive_On_line(void);/* algorithm to drive(control the steering) on the line */
void Motor_Move(char Move_direction, int MoveSpeed);/*commands the motor driver to move car forward, backward, none or break*/
void Motor_Steer(char side);/* commands for motor driver for steering left, right or none*/
int USensor_measure(int TriggerPin, int EchoPin);/*Ultrasonic sensor: read the measured value from the sensor conpute and return it*/
void ReadAll_US_Sensors(); /*read all distance sensors and save the value to vector Distances_around[]*/
void Control_Lights(char Lgt_Comm);/*control the headlights and breaklights according to commands and car movements*/
void Control_Signal_Light(char Sgn_Lgt_Comm); /*control the signaling lights using the switching table for easy handle*/
void Error_Handling(char Err_Comm, char Err_source);/*save errors and return it when the apropiatte command is recieved*/
int MakeValueFormChar(char Value10, char Value1 );/*This function takes as input 2 strings and returns a 2 character number form it*/
void TestComunication(void);/*this function will call the functions wanted to be tested and print the results on serial*/
void Print_Errors(void); /*prints on serial form the error array the entries that are not 0 */
/*================================================================================================*/

/*============================================Setup ==============================================*/
void setup()                    // run once, when the sketch starts
{
    /*--init comunication--*/
  Serial.begin(9600);
  Serial1.begin(9600);            // set the baud rate to 9600, same should be of the Serial Monitor aplication
  
  /*--init line follow sensor pins--*/
  pinMode(Ln_Left_Pin, INPUT);
  pinMode(Ln_Center_Pin, INPUT);
  pinMode(Ln_Right_Pin, INPUT);
  
  /*-- init the motor driver pins--*/
  pinMode(DriverIN1, OUTPUT);
  pinMode(DriverIN2, OUTPUT);
  pinMode(DriverIN3, OUTPUT);
  pinMode(DriverIN4, OUTPUT);
  
  /*-- init the ultrasonic sensors pins--*/
  pinMode(Trig_Pin_1, OUTPUT);
  pinMode(Echo_Pin_1, INPUT);
  pinMode(Trig_Pin_2, OUTPUT);
  pinMode(Echo_Pin_2, INPUT);
  pinMode(Trig_Pin_3, OUTPUT);
  pinMode(Echo_Pin_3, INPUT);
  pinMode(Trig_Pin_4, OUTPUT);
  pinMode(Echo_Pin_4, INPUT);
  
  /*--reset  errors vector--*/
  for(int i=0; i<10; i++)
      for(int j=0; j<4; j++)
          Errors_array[i][j]=0;
}
/*================================================================================================*/

/*=======================================Main Loop================================================*/
void loop()
{
  //TestComunication();
  //test_Motor();
  if(Serial1.available()>0)
    {
      if(read_Bluetooth_Message()==1)
      {
        Msg_handle(rec_Blu_Arr);
      }
    }       
}
/*================================================================================================*/
/*======================================end of file===============================================*/
