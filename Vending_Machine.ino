
class Vending_Machine
{
  
  private:

byte pin_transaction;
byte pin_cancel;
byte pin_input1; // 1 rs coin and 2 rs small coin.
byte pin_input2; // 2 rs coin.
byte pin_input3; // 5 rs coin.
byte pin_input4;// 10 rs coin.
byte pin_ir_sensor;
byte pin_electromagnet;

// Output pins :
/*byte pin_output_1_a;
byte pin_output_1_b;
byte pin_output_1_c;
byte pin_output_1_d;
byte pin_output_1_e;
byte pin_output_1_f;
byte pin_output_1_g;
byte pin_output_2_a;
byte pin_output_2_b;
byte pin_output_2_c;
byte pin_output_2_d;
byte pin_output_2_e;
byte pin_output_2_f;
byte pin_output_2_g;*/
byte pin_output1;
byte pin_output2;
byte pin_output3;
byte pin_output4;
byte pin_output5;
byte pin_output6;
byte pin_output7;
byte pin_output8;

bool output1;
bool output2;
bool output3;
bool output4;
bool output5;
bool output6;
bool output7;
bool output8;

bool transaction;
bool cancel;
bool input1;
bool input2;
bool input3;
bool input4;
byte input;
byte check;
bool ir_sensor;
bool electromagnet;
byte output;
byte output_1;
byte output_2;

// For motors

byte pin_motor_transaction;
byte pin_pwm_transaction;
byte pin_motor_dispatch;
byte pin_pwm_dispatch;
bool motor_transaction; //for direction.
byte pwm_transaction;
bool motor_dispatch; //for direction. 
byte pwm_dispatch;

byte price_product;
  
  public:

void Initialize(byte pin1,byte pin2,byte pin3_1,byte pin3_2,byte pin3_3,byte pin3_4,byte pin4,byte pin5)
{
   pin_transaction=pin1;
   pin_cancel=pin2;
   pin_input1=pin3_1;
   pin_input2=pin3_2;
   pin_input3=pin3_3;
   pin_input4=pin3_4;
   pin_ir_sensor=pin4;
   pin_electromagnet=pin5;
   //pin_output=pin6;
   
   pinMode(pin_transaction, INPUT); 
   pinMode(pin_cancel, INPUT); 
   pinMode(pin_input1, INPUT);
   pinMode(pin_input2, INPUT);
   pinMode(pin_input3, INPUT);
   pinMode(pin_input4, INPUT);
   pinMode(pin_ir_sensor, INPUT);
   pinMode(pin_electromagnet, OUTPUT); 
  // pinMode(pin_output, OUTPUT);
  
   transaction=0;
   cancel=0;
   input1=0;
   input2=0;
   input3=0;
   input4=0;
   ir_sensor=0;
   electromagnet=0;
   output=0;
   check=0;
}

void Initialize_motor(byte pin1,byte pin2,byte pin3,byte pin4)
{
   pin_motor_transaction=pin1;
   pin_pwm_transaction=pin2;
   pin_motor_dispatch=pin3;
   pin_pwm_dispatch=pin4;
   pinMode(pin_motor_transaction, OUTPUT); 
   pinMode(pin_pwm_transaction, OUTPUT); 
   pinMode(pin_motor_dispatch, OUTPUT); 
   pinMode(pin_pwm_dispatch, OUTPUT); 

   motor_transaction=0;
   pwm_transaction=0;
   motor_dispatch=0;  
   pwm_dispatch=0;

   digitalWrite(pin_motor_transaction, motor_transaction);
   analogWrite(pin_pwm_transaction, pwm_transaction);
   digitalWrite(pin_motor_dispatch, motor_dispatch);  
   analogWrite(pin_pwm_dispatch, pwm_dispatch);
   
}

/*void Initialize_output_1bit_pins(byte pin_1a,byte pin_1b,byte pin_1c,byte pin_1d,byte pin_1e,byte pin_1f,byte pin_1g)
{
  pin_output_1_a=pin_1a;
  pin_output_1_b=pin_1b;
  pin_output_1_c=pin_1c;
  pin_output_1_d=pin_1d;
  pin_output_1_e=pin_1e;
  pin_output_1_f=pin_1f;
  pin_output_1_g=pin_1g;

  pinMode(pin_output_1_a, OUTPUT);
  pinMode(pin_output_1_b, OUTPUT);
  pinMode(pin_output_1_c, OUTPUT);
  pinMode(pin_output_1_d, OUTPUT);
  pinMode(pin_output_1_e, OUTPUT);
  pinMode(pin_output_1_f, OUTPUT);
  pinMode(pin_output_1_g, OUTPUT);
  
}

void Initialize_output_5bit_pins(byte pin_2a,byte pin_2b,byte pin_2c,byte pin_2d,byte pin_2e,byte pin_2f,byte pin_2g)
{
  pin_output_2_a=pin_2a;
  pin_output_2_b=pin_2b;
  pin_output_2_c=pin_2c;
  pin_output_2_d=pin_2d;
  pin_output_2_e=pin_2e;
  pin_output_2_f=pin_2f;
  pin_output_2_g=pin_2g;

  pinMode(pin_output_2_a, OUTPUT);
  pinMode(pin_output_2_b, OUTPUT);
  pinMode(pin_output_2_c, OUTPUT);
  pinMode(pin_output_2_d, OUTPUT);
  pinMode(pin_output_2_e, OUTPUT);
  pinMode(pin_output_2_f, OUTPUT);
  pinMode(pin_output_2_g, OUTPUT);
  
}*/

void Initialize_output_pins(byte pin1,byte pin2,byte pin3,byte pin4,byte pin5,byte pin6,byte pin7,byte pin8)
{
   pin_output1=pin1;
   pin_output2=pin2;
   pin_output3=pin3;
   pin_output4=pin4;
   pin_output5=pin5;
   pin_output6=pin6;
   pin_output7=pin7;
   pin_output8=pin8;

   pinMode(pin_output1, OUTPUT);
   pinMode(pin_output2, OUTPUT);
   pinMode(pin_output3, OUTPUT);
   pinMode(pin_output4, OUTPUT);
   pinMode(pin_output5, OUTPUT);
   pinMode(pin_output6, OUTPUT);
   pinMode(pin_output7, OUTPUT);
   pinMode(pin_output8, OUTPUT);
}

void Initialize_price_product(byte x)
{
  price_product=x;
}

void Update()
{
   //transaction=digitalRead(pin_transaction); 
   //cancel=digitalRead(pin_cancel); 
   input1=digitalRead(pin_input1);
   input2=digitalRead(pin_input2);
   input3=digitalRead(pin_input3);
   input4=digitalRead(pin_input4);
   //ir_sensor=digitalRead(pin_ir_sensor); 
}

void Set_value()
{
   //digitalWrite(pin_electromagnet, electromagnet);
   //digitalWrite(pin_output, output);
   digitalWrite(pin_motor_transaction, motor_transaction);
   analogWrite(pin_pwm_transaction, pwm_transaction);
   digitalWrite(pin_motor_dispatch, motor_dispatch);  
   analogWrite(pin_pwm_dispatch, pwm_dispatch);
}

void Reset_value()
{
   motor_transaction=0;
   pwm_transaction=0;
   motor_dispatch=0;  
   pwm_dispatch=0;

   digitalWrite(pin_motor_transaction, motor_transaction);
   analogWrite(pin_pwm_transaction, pwm_transaction);
   digitalWrite(pin_motor_dispatch, motor_dispatch);  
   analogWrite(pin_pwm_dispatch, pwm_dispatch);
}

void Function()
{
   // functioning of ir sensor

   ir_sensor=digitalRead(pin_ir_sensor);
   if (ir_sensor)
   {
    
     delay(100); // delaying to start electromagnet.
     electromagnet=1;
     digitalWrite(pin_electromagnet, electromagnet);
     delay(100); // delay so that electromagnet can be on for 100 m.s. .
     electromagnet=0;
     digitalWrite(pin_electromagnet, electromagnet);

    while(check=0) // if coin is coming, there must be increment.
     {
       Update();
       input = input1 + 2*input2 + 5*input3 + 10*input4 ;
       output=input;
       check=input;
       //digitalWrite(pin_output, output);
     }

     if (check>0)
       check=0;
   
   }

   transaction=digitalRead(pin_transaction); 
   cancel=digitalRead(pin_cancel);
   
   if ( transaction==1 && cancel==0 )
   {
     if (output>=price_product)
     {
       motor_transaction=1;
       pwm_transaction=10; // value can be changed.
       motor_dispatch=1;
       pwm_dispatch=10; // value can be changed.
       Set_value();
       output=output-price_product;
       delay(100); // for rotation of motor.
       Reset_value();
     }
   }
   if ( cancel==1 && transaction==0 )
   {
       motor_transaction=0;
       pwm_transaction=10; // value can be changed.
       motor_dispatch=0;
       pwm_dispatch=0; // No rotation of motor.
       Set_value();
       output=0;
       delay(100); // for rotation of motor.
       Reset_value();
   }
   if ( cancel==1 && transaction==1 )
   {
       motor_transaction=0;
       pwm_transaction=10; // value can be changed.
       motor_dispatch=0;
       pwm_dispatch=0; // No rotation of motor.
       Set_value();
       output=0;
       delay(100); // for rotation of motor.
       Reset_value();
   }
   
}

void Convert(byte x,bool x1,bool x2,bool x3,bool x4)
{
  x1=x%2;
  x=x/2;
  x2=x%2;
  x=x/2;
  x3=x%2;
  x=x/2;
  x4=x%2;
}

void Show_output()
{
  output_1=output%10;
  output_2=output/10;
  Convert(output_1,output1,output2,output3,output4);
  Convert(output_2,output5,output6,output7,output8);
  
  digitalWrite(pin_output1, output1); // first bit value.
  digitalWrite(pin_output2, output2);
  digitalWrite(pin_output3, output3);
  digitalWrite(pin_output4, output4);
  digitalWrite(pin_output5, output5);
  digitalWrite(pin_output6, output6);
  digitalWrite(pin_output7, output7);
  digitalWrite(pin_output8, output8);
  
}
  
};

Vending_Machine V;

void setup()
{
  Serial.begin(9600);
  V.Initialize();
  V.Initialize_motor();
 // V.Initialize_output_1bit_pins();
 // V.Initialize_output_5bit_pins();
  V.Initialize_output_pins();
  V.Initialize_price_product(5);
}


void loop()
{
  V.Function();
  V.Show_output();
}
