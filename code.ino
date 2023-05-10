#include <LiquidCrystal.h> //to include the lcd library code
LiquidCrystal lcd(2,3,4,5,6,7); //LiquidCrystal lcd(RS,EN,D4,D5,D6,D7)
int REAL_GATE= 1; // 
int MIMIC_GATE= 0; //

int AND_GATE = 13;
int OR_GATE = A0;
int NAND_GATE = A1;
int NOR_GATE = A2;
int RESET = A3;

int INPUT_SELECTOR_2 = 11;
int INPUT_SELECTOR_3 = 12;

int INPUT_A = 8;
int INPUT_B = 9;
int INPUT_C = 10;


int OUTPUT_A = A4;
int OUTPUT_B = A5;
int OUTPUT_C = A6;

int REAL_GATE_VALUE=0;
int MIMIC_GATE_VALUE=0;
int AND_GATE_VALUE=0;
int NAND_GATE_VALUE=0;
int OR_GATE_VALUE=0;
int NOR_GATE_VALUE=0;
int mimic_mode_flag=0;
int INPUT_SELECTOR_2_VALUE=0;
int INPUT_SELECTOR_3_VALUE=0;
int INPUT_A_VALUE=0;
int INPUT_B_VALUE=0;
int INPUT_C_VALUE=0;
int GATE_RESULT_FLAG=0;
int GATE_RESULT_FLAG_1=0;
int GATE_RESULT_FLAG_2=0;
int GATE_RESULT_FLAG_3=0;
bool REMAIN=0;
bool REMAIN1=0;
bool REMAIN2=0;
bool REMAIN3=0;



void setup() {
 pinMode(REAL_GATE, INPUT);// 
 pinMode(MIMIC_GATE, INPUT_PULLUP);
pinMode(AND_GATE, INPUT_PULLUP);
 pinMode(OR_GATE, INPUT_PULLUP);
 pinMode(NAND_GATE, INPUT_PULLUP);
 pinMode(NOR_GATE, INPUT_PULLUP);
 pinMode(RESET, INPUT); //
 pinMode(INPUT_SELECTOR_2, INPUT); //
   pinMode(INPUT_SELECTOR_3, INPUT); //
    pinMode(INPUT_A, INPUT); //
     pinMode(INPUT_B, INPUT); //
      pinMode(INPUT_C, INPUT); //
       pinMode(OUTPUT_A, OUTPUT); //
        pinMode(OUTPUT_B, OUTPUT); //
         pinMode(OUTPUT_C, OUTPUT); //
        
 
digitalWrite (INPUT_SELECTOR_2, HIGH);
digitalWrite (INPUT_SELECTOR_3, HIGH);
  
 digitalWrite (INPUT_A, LOW); 
 digitalWrite (INPUT_B, LOW);
 digitalWrite (INPUT_C, LOW);
 
 digitalWrite (OUTPUT_A, LOW);  
 digitalWrite (OUTPUT_B, LOW); 
 digitalWrite (OUTPUT_C, LOW); 
 
 //digitalWrite (REAL_GATE, LOW);  
 
 Serial.begin(9600); //Start a serial COMMUNICATION session 4 NORMAL SERIAL
   // WRITING INITIAL MESSAGES ON LCD
 lcd.begin(16, 2); //indicating the type of lcd in use
 lcd.print("  ARDUINO_BASED"); 
 lcd.setCursor(0,1);         //position 1, line 1
 lcd.print(" LOGIC_G_TRAINER ");
 delay (1500);

 lcd.setCursor(1,0);          //position 2,line 1
 lcd.print("SYSTEM IS READY");
 lcd.setCursor(0,1);          //position 1,line 2
 lcd.print(" FOR OPERATION....");
 delay(1000);
 
 lcd.clear();
 lcd.setCursor(1,0);          //position 3,line 1
 lcd.print("SELECT TRAINING");
 lcd.setCursor(0,1);          //position 1,line 2
 lcd.print("MODE(REAL/MIMIC)");
 
 
}

void loop() {
  REAL_GATE_VALUE = digitalRead(REAL_GATE);
  MIMIC_GATE_VALUE= digitalRead(MIMIC_GATE);

   if (REAL_GATE_VALUE==0 && MIMIC_GATE_VALUE ==1)//NO TRAINIG MOODE IS SELECTED OR STILL WAITING FOR MODE SELECTION  
   {
      lcd.setCursor(0,0);          //position 3,line 1
      lcd.print(".SELECT TRAINING");
      lcd.setCursor(0,1);          //position 1,line 2
      lcd.print("MODE(REAL/MIMIC)");
       } 

  else if (REAL_GATE_VALUE==1&& MIMIC_GATE_VALUE ==1)//REAL GATE TRAINIG MOODE SELECTED
    {
      lcd.setCursor(1,0);  
      lcd.print("USE BREADBOARD.. "); 
      lcd.setCursor(0,1);         //position 1, line 1
      lcd.print(" FOR EXPERIMENT ");
      }
    else if (REAL_GATE_VALUE==0&& MIMIC_GATE_VALUE ==0)//MIMIC GATE TRAINIG MOODE SELECTED
    { 
      if (mimic_mode_flag==0)
      {
      lcd.setCursor(0,0);  
      lcd.print("MIMIC MODE PICKD "); 
      lcd.setCursor(0,1);         //position 1, line 1
      lcd.print(" FOR EXPERIMENT ");
       delay (1500);
       lcd.setCursor(0,0);  
      lcd.print("SELECT THE GATE "); 
      lcd.setCursor(0,1);         //position 1, line 1
      lcd.print("FOR EXPERIMENT ");
      delay (2000);
  
      AND_GATE_VALUE = digitalRead(AND_GATE);
      NAND_GATE_VALUE = digitalRead(NAND_GATE);
      OR_GATE_VALUE = digitalRead(OR_GATE);
      NOR_GATE_VALUE = digitalRead(NOR_GATE);
      
      
      if (AND_GATE_VALUE==0&& NAND_GATE_VALUE ==1&& OR_GATE_VALUE==1&& NOR_GATE_VALUE==1)//AND GATE IS SELECTED FOR THE TRAINING
      {
      do
      {REMAIN=1;
        if (GATE_RESULT_FLAG == 0)
        {
        lcd.setCursor(0,0);  
        lcd.print("AND GATE PICKED "); 
        lcd.setCursor(0,1);         //position 1, line 1
        lcd.print("FOR EXPERIMENT...... ");
        delay (2000);
        
        lcd.setCursor(0,0);  
        lcd.print("PICK YOUR CHOICE "); 
        lcd.setCursor(0,1);         //position 1, line 1
        lcd.print("GATE INPUT TYPE ");
           delay (2000);
        
        INPUT_SELECTOR_2_VALUE= digitalRead(INPUT_SELECTOR_2);    
        INPUT_SELECTOR_3_VALUE= digitalRead(INPUT_SELECTOR_3);    
         if (INPUT_SELECTOR_2_VALUE==0 && INPUT_SELECTOR_3_VALUE==1)// 2-input gate selected
         {
          lcd.setCursor(0,0); 
          lcd.print("2-INPUT-GATE HAS "); 
          lcd.setCursor(0,1);         //position 1, line 1
          lcd.print(" BEEN SELECTED.. ");
           delay (2000);
           INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0     0  =   0 ");
             digitalWrite (OUTPUT_A, LOW);
             GATE_RESULT_FLAG=1;
            } 
            
           else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
              lcd.print(" 1     0  =   0 ");
             digitalWrite (OUTPUT_A, LOW);
              GATE_RESULT_FLAG=1;

            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
              lcd.print(" 0     1  =   0 ");
              digitalWrite (OUTPUT_A, LOW);
              GATE_RESULT_FLAG=1;

            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1     1  =   1 ");
             digitalWrite (OUTPUT_A, HIGH);
              GATE_RESULT_FLAG=1;

            } 
             else{}
            
          }
          else if (INPUT_SELECTOR_2_VALUE==1 && INPUT_SELECTOR_3_VALUE==0)// 3-INUT SELECTED
          {
           INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    0=  0 ");
            digitalWrite (OUTPUT_A, LOW);
             GATE_RESULT_FLAG=1;
            } 
            
           else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    1=  0 ");
             digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    0=  0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    1=  0 ");
            digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1    0    0=  0 ");
             digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    0    1=  0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    0=  0 ");
            digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    1=  1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            
             else{}
            }
            else{}

        GATE_RESULT_FLAG=1;
        }
         else{
        /////////
         INPUT_SELECTOR_2_VALUE= digitalRead(INPUT_SELECTOR_2);    
         INPUT_SELECTOR_3_VALUE= digitalRead(INPUT_SELECTOR_3);    
         if (INPUT_SELECTOR_2_VALUE==0 && INPUT_SELECTOR_3_VALUE==1)// 2-input gate is selected
         {
           INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0     0  =   0 ");
            digitalWrite (OUTPUT_A, LOW);
             GATE_RESULT_FLAG=1;
            } 
            
           else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1     0  =   0 ");
             digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 0     1  =   0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1     1  =   1 ");
            digitalWrite (OUTPUT_A, HIGH);
            } 
             else{}
            
          }
          else if (INPUT_SELECTOR_2_VALUE==1 && INPUT_SELECTOR_3_VALUE==0)// 3-INPUT SELECTED
          {
            INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    0 = 0 ");
            digitalWrite (OUTPUT_A, LOW);
             GATE_RESULT_FLAG=1;
            } 
            
           else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    1 = 0 ");
             digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    0 = 0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    1 = 0 ");
            digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1    0    0 = 0 ");
             digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    0    1 = 0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    0 = 0 ");
            digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    1 = 1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            
             else{}
            }
            
            else{}
        }
            AND_GATE_VALUE = digitalRead(AND_GATE);
            NAND_GATE_VALUE = digitalRead(NAND_GATE);
            OR_GATE_VALUE = digitalRead(OR_GATE);
            NOR_GATE_VALUE = digitalRead(NOR_GATE);
            
        if(AND_GATE_VALUE==0 || NAND_GATE_VALUE ==0 || OR_GATE_VALUE==0 || NOR_GATE_VALUE==0)
        {
          break;
          }
          else {}
      GATE_RESULT_FLAG=1;
      }while (REMAIN==1);
      }
    
      
      else if (AND_GATE_VALUE==1&& NAND_GATE_VALUE ==0&& OR_GATE_VALUE==1&& NOR_GATE_VALUE==1)//NAND GATE IS SELECTED FOR THE TRAINING
      {
        do
        {REMAIN1=1;
         if (GATE_RESULT_FLAG_1 == 0)
        {
        lcd.setCursor(0,0);  
        lcd.print("NAND GATE PICKED "); 
        lcd.setCursor(0,1);         //position 1, line 1
        lcd.print("FOR EXPERIMENT..... ");
        delay (2000);
        
        lcd.setCursor(0,0);  
        lcd.print("PICK YOUR CHOICE "); 
        lcd.setCursor(0,1);         //position 1, line 1
        lcd.print("GATE INPUT TYPE ");
           delay (2000);
        
        INPUT_SELECTOR_2_VALUE= digitalRead(INPUT_SELECTOR_2);    
        INPUT_SELECTOR_3_VALUE= digitalRead(INPUT_SELECTOR_3);    
         if (INPUT_SELECTOR_2_VALUE==0 && INPUT_SELECTOR_3_VALUE==1)// 2-input gate selected
         {
          lcd.setCursor(0,0); 
          lcd.print("2-INPUT-GATE HAS "); 
          lcd.setCursor(0,1);         //position 1, line 1
          lcd.print(" BEEN SELECTED.. ");
           delay (2000);
           INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0     0  =   1 ");
             digitalWrite (OUTPUT_A, HIGH);
             GATE_RESULT_FLAG_1=1;
            } 
            
           else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
              lcd.print(" 1     0  =   1 ");
             digitalWrite (OUTPUT_A, HIGH);
              GATE_RESULT_FLAG_1=1;

            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
              lcd.print(" 0     1  =   1 ");
              digitalWrite (OUTPUT_A, HIGH);
              GATE_RESULT_FLAG=1;

            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1     1  =   0 ");
             digitalWrite (OUTPUT_A, LOW);
              GATE_RESULT_FLAG_1=1;

            } 
             else{}
            
          }
          else if (INPUT_SELECTOR_2_VALUE==1 && INPUT_SELECTOR_3_VALUE==0)// 3-INUT SELECTED
          {
           INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    0=  1 ");
            digitalWrite (OUTPUT_A, HIGH);
             GATE_RESULT_FLAG_1=1;
            } 
            
           else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    1=  1 ");
             digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    0=  1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    1=  1 ");
            digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1    0    0=  1 ");
             digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    0    1=  1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    0=  1 ");
            digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    1=  0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            
             else{}
            }
            else{}

        GATE_RESULT_FLAG_1=1;
        }
         else{
        /////////
         INPUT_SELECTOR_2_VALUE= digitalRead(INPUT_SELECTOR_2);    
         INPUT_SELECTOR_3_VALUE= digitalRead(INPUT_SELECTOR_3);    
         if (INPUT_SELECTOR_2_VALUE==0 && INPUT_SELECTOR_3_VALUE==1)// 2-input gate is selected
         {
           INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0     0  =   1 ");
            digitalWrite (OUTPUT_A, HIGH);
             GATE_RESULT_FLAG_1=1;
            } 
            
           else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1     0  =   1 ");
             digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 0     1  =   1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1     1  =   0 ");
            digitalWrite (OUTPUT_A, LOW);
            } 
             else{}
            
          }
          else if (INPUT_SELECTOR_2_VALUE==1 && INPUT_SELECTOR_3_VALUE==0)// 3-INPUT SELECTED
          {
            INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    0 = 1 ");
            digitalWrite (OUTPUT_A, HIGH);
             GATE_RESULT_FLAG_1=1;
            } 
            
           else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    1 = 1 ");
             digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    0 = 1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    1 = 1 ");
            digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1    0    0 = 1 ");
             digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    0    1 = 1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    0 = 1 ");
            digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    1 = 0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            
             else{}
            }
            
            else{}
        }
            AND_GATE_VALUE = digitalRead(AND_GATE);
            NAND_GATE_VALUE = digitalRead(NAND_GATE);
            OR_GATE_VALUE = digitalRead(OR_GATE);
            NOR_GATE_VALUE = digitalRead(NOR_GATE);
            
        if(AND_GATE_VALUE==0 || NAND_GATE_VALUE ==0 || OR_GATE_VALUE==0 || NOR_GATE_VALUE==0)
        {
          break;
          }
          else {}
      GATE_RESULT_FLAG_1=1;
              } while (REMAIN1==1);
      }   
      
      ////KKKKKKKKKKKKKKKKKKKK
      
      else if (AND_GATE_VALUE==1&& NAND_GATE_VALUE ==1&& OR_GATE_VALUE==0&& NOR_GATE_VALUE==1)//OR GATE IS SELECTED FOR THE TRAINING
      {
        do
        {REMAIN2=1;
         if (GATE_RESULT_FLAG_2 == 0)
        {
        lcd.setCursor(0,0);  
        lcd.print("OR GATE PICKED "); 
        lcd.setCursor(0,1);         //position 1, line 1
        lcd.print("FOR EXPERIMENT...... ");
        delay (2000);
        
        lcd.setCursor(0,0);  
        lcd.print("PICK YOUR CHOICE "); 
        lcd.setCursor(0,1);         //position 1, line 1
        lcd.print("GATE INPUT TYPE ");
           delay (2000);
        
        INPUT_SELECTOR_2_VALUE= digitalRead(INPUT_SELECTOR_2);    
        INPUT_SELECTOR_3_VALUE= digitalRead(INPUT_SELECTOR_3);    
         if (INPUT_SELECTOR_2_VALUE==0 && INPUT_SELECTOR_3_VALUE==1)// 2-input gate selected
         {
          lcd.setCursor(0,0); 
          lcd.print("2-INPUT-GATE HAS "); 
          lcd.setCursor(0,1);         //position 1, line 1
          lcd.print(" BEEN SELECTED.. ");
           delay (2000);
           INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0     0  =   0 ");
             digitalWrite (OUTPUT_A, LOW);//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
             GATE_RESULT_FLAG_2=1;
            } 
            
           else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
              lcd.print(" 1     0  =   1 ");
             digitalWrite (OUTPUT_A, HIGH);
              GATE_RESULT_FLAG_2=1;

            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
              lcd.print(" 0     1  =   1 ");
              digitalWrite (OUTPUT_A, HIGH);
              GATE_RESULT_FLAG_2=1;

            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1     1  =   1 ");
             digitalWrite (OUTPUT_A, HIGH);
              GATE_RESULT_FLAG_2=1;

            } 
             else{}
            
          }
          else if (INPUT_SELECTOR_2_VALUE==1 && INPUT_SELECTOR_3_VALUE==0)// 3-INUT SELECTED
          {
           INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    0=  0 ");
            digitalWrite (OUTPUT_A, LOW);
             GATE_RESULT_FLAG_1=1;
            } 
            
           else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    1=  1 ");
             digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    0=  1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    1=  1 ");
            digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1    0    0=  1 ");
             digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    0    1=  1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    0=  1 ");
            digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    1=  1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            
             else{}
            }
            else{}

        GATE_RESULT_FLAG_2=1;
        }
         else{
        /////////
         INPUT_SELECTOR_2_VALUE= digitalRead(INPUT_SELECTOR_2);    
         INPUT_SELECTOR_3_VALUE= digitalRead(INPUT_SELECTOR_3);    
         if (INPUT_SELECTOR_2_VALUE==0 && INPUT_SELECTOR_3_VALUE==1)// 2-input gate is selected
         {
           INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0     0  =   0 ");
            digitalWrite (OUTPUT_A, LOW);
             GATE_RESULT_FLAG_1=1;
            } 
            
           else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1     0  =   1 ");
             digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 0     1  =   1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1     1  =   1 ");
            digitalWrite (OUTPUT_A, HIGH);
            } 
             else{}
            
          }
          else if (INPUT_SELECTOR_2_VALUE==1 && INPUT_SELECTOR_3_VALUE==0)// 3-INPUT SELECTED
          {
            INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    0 = 0 ");
            digitalWrite (OUTPUT_A, LOW);
             GATE_RESULT_FLAG_2=1;
            } 
            
           else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    1 = 1 ");
             digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    0 = 1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    1 = 1 ");
            digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1    0    0 = 1 ");
             digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    0    1 = 1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    0 = 1 ");
            digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    1 = 1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            
             else{}
            }
            
            else{}
        }
            AND_GATE_VALUE = digitalRead(AND_GATE);
            NAND_GATE_VALUE = digitalRead(NAND_GATE);
            OR_GATE_VALUE = digitalRead(OR_GATE);
            NOR_GATE_VALUE = digitalRead(NOR_GATE);
            
        if(AND_GATE_VALUE==0 || NAND_GATE_VALUE ==0 || OR_GATE_VALUE==0 || NOR_GATE_VALUE==0)
        {
          break;
          }
          else {}
      GATE_RESULT_FLAG_2=1;
               }while (REMAIN2==1);
          }
          
      else if (AND_GATE_VALUE==1&& NAND_GATE_VALUE ==1&& OR_GATE_VALUE==1&& NOR_GATE_VALUE==0)//NOR GATE IS SELECTED FOR THE TRAINING
      {
        do
        {REMAIN3=1;
        if (GATE_RESULT_FLAG_3 == 0)
        {
        lcd.setCursor(0,0);  
        lcd.print("NOR GATE PICKED "); 
        lcd.setCursor(0,1);         //position 1, line 1
        lcd.print("FOR EXPERIMENT.... ");
        delay (2000);
        
        lcd.setCursor(0,0);  
        lcd.print("PICK YOUR CHOICE "); 
        lcd.setCursor(0,1);         //position 1, line 1
        lcd.print("GATE INPUT TYPE ");
           delay (2000);
        
        INPUT_SELECTOR_2_VALUE= digitalRead(INPUT_SELECTOR_2);    
        INPUT_SELECTOR_3_VALUE= digitalRead(INPUT_SELECTOR_3);    
         if (INPUT_SELECTOR_2_VALUE==0 && INPUT_SELECTOR_3_VALUE==1)// 2-input gate selected
         {
          lcd.setCursor(0,0); 
          lcd.print("2-INPUT-GATE HAS "); 
          lcd.setCursor(0,1);         //position 1, line 1
          lcd.print(" BEEN SELECTED.. ");
           delay (2000);
           INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0     0  =   1 ");
             digitalWrite (OUTPUT_A, HIGH);//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
             GATE_RESULT_FLAG_3=1;
            } 
            
           else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
              lcd.print(" 1     0  =   0 ");
             digitalWrite (OUTPUT_A, LOW);
              GATE_RESULT_FLAG_2=1;

            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
              lcd.print(" 0     1  =   0 ");
              digitalWrite (OUTPUT_A, LOW);
              GATE_RESULT_FLAG_3=1;

            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1     1  =   0 ");
             digitalWrite (OUTPUT_A, LOW);
              GATE_RESULT_FLAG_3=1;

            } 
             else{}
            
          }
          else if (INPUT_SELECTOR_2_VALUE==1 && INPUT_SELECTOR_3_VALUE==0)// 3-INUT SELECTED
          {
           INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    0=  1 ");
            digitalWrite (OUTPUT_A, HIGH);
             GATE_RESULT_FLAG_3=1;
            } 
            
           else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    1=  0 ");
             digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    0=  0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    1=  0 ");
            digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1    0    0=  0 ");
             digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    0    1=  0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    0=  0 ");
            digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    1=  0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            
             else{}
            }
            else{}

        GATE_RESULT_FLAG_3=1;
        }
         else{
        /////////
         INPUT_SELECTOR_2_VALUE= digitalRead(INPUT_SELECTOR_2);    
         INPUT_SELECTOR_3_VALUE= digitalRead(INPUT_SELECTOR_3);    
         if (INPUT_SELECTOR_2_VALUE==0 && INPUT_SELECTOR_3_VALUE==1)// 2-input gate is selected
         {
           INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0     0  =   1 ");
            digitalWrite (OUTPUT_A, HIGH);
             GATE_RESULT_FLAG_3=1;
            } 
            
           else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1     0  =   0 ");
             digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 0     1  =   0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1     1  =   0 ");
            digitalWrite (OUTPUT_A, LOW);
            } 
             else{}
            
          }
          else if (INPUT_SELECTOR_2_VALUE==1 && INPUT_SELECTOR_3_VALUE==0)// 3-INPUT SELECTED
          {
            INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    0 = 1 ");
            digitalWrite (OUTPUT_A, HIGH);
             GATE_RESULT_FLAG_3=1;
            } 
            
           else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    1 = 0 ");
             digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    0 = 0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    1 = 0 ");
            digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1    0    0 = 0 ");
             digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    0    1 = 0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    0 = 0 ");
            digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    1 = 0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            
             else{}
            }
            
            else{}
        }
            AND_GATE_VALUE = digitalRead(AND_GATE);
            NAND_GATE_VALUE = digitalRead(NAND_GATE);
            OR_GATE_VALUE = digitalRead(OR_GATE);
            NOR_GATE_VALUE = digitalRead(NOR_GATE);
            
        if(AND_GATE_VALUE==0 || NAND_GATE_VALUE ==0 || OR_GATE_VALUE==0 || NOR_GATE_VALUE==0)
        {
          break;
          }
          else {}
      GATE_RESULT_FLAG_3=1;
               }while (REMAIN3==1);
              }
      else{}
      
      mimic_mode_flag=1; // SET FLAG 
      }
      
     
      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     else
     {  
      AND_GATE_VALUE = digitalRead(AND_GATE);
      NAND_GATE_VALUE = digitalRead(NAND_GATE);
      OR_GATE_VALUE = digitalRead(OR_GATE);
      NOR_GATE_VALUE = digitalRead(NOR_GATE);
      
    if (AND_GATE_VALUE==0&& NAND_GATE_VALUE ==1&& OR_GATE_VALUE==1&& NOR_GATE_VALUE==1)//AND GATE IS SELECTED FOR THE TRAINING
    {
       do
      {
        REMAIN=1;
        if (GATE_RESULT_FLAG == 0)
        {
        lcd.setCursor(0,0);  
        lcd.print("AND GATE PICKED "); 
        lcd.setCursor(0,1);         //position 1, line 1
        lcd.print("FOR EXPERIMENT...... ");
        delay (2000);
        
        lcd.setCursor(0,0);  
        lcd.print("PICK YOUR CHOICE "); 
        lcd.setCursor(0,1);         //position 1, line 1
        lcd.print("GATE INPUT TYPE ");
           delay (2000);
        
        INPUT_SELECTOR_2_VALUE= digitalRead(INPUT_SELECTOR_2);    
        INPUT_SELECTOR_3_VALUE= digitalRead(INPUT_SELECTOR_3);    
         if (INPUT_SELECTOR_2_VALUE==0 && INPUT_SELECTOR_3_VALUE==1)// 2-input gate selected
         {
          lcd.setCursor(0,0); 
          lcd.print("2-INPUT-GATE HAS "); 
          lcd.setCursor(0,1);         //position 1, line 1
          lcd.print(" BEEN SELECTED.. ");
           delay (2000);
           INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0     0  =   0 ");
             digitalWrite (OUTPUT_A, LOW);
             GATE_RESULT_FLAG=1;
            } 
            
           else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
              lcd.print(" 1     0  =   0 ");
             digitalWrite (OUTPUT_A, LOW);
              GATE_RESULT_FLAG=1;

            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
              lcd.print(" 0     1  =   0 ");
              digitalWrite (OUTPUT_A, LOW);
              GATE_RESULT_FLAG=1;

            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1     1  =   1 ");
             digitalWrite (OUTPUT_A, HIGH);
              GATE_RESULT_FLAG=1;

            } 
             else{}
            
          }
          else if (INPUT_SELECTOR_2_VALUE==1 && INPUT_SELECTOR_3_VALUE==0)// 3-INUT SELECTED
          {
           INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    0=  0 ");
            digitalWrite (OUTPUT_A, LOW);
             GATE_RESULT_FLAG=1;
            } 
            
           else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    1=  0 ");
             digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    0=  0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    1=  0 ");
            digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1    0    0=  0 ");
             digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    0    1=  0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    0=  0 ");
            digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    1=  1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            
             else{}
            }
            else{}

        GATE_RESULT_FLAG=1;
        }
         else{
        /////////
         INPUT_SELECTOR_2_VALUE= digitalRead(INPUT_SELECTOR_2);    
         INPUT_SELECTOR_3_VALUE= digitalRead(INPUT_SELECTOR_3);    
         if (INPUT_SELECTOR_2_VALUE==0 && INPUT_SELECTOR_3_VALUE==1)// 2-input gate is selected
         {
           INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0     0  =   0 ");
            digitalWrite (OUTPUT_A, LOW);
             GATE_RESULT_FLAG=1;
            } 
            
           else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1     0  =   0 ");
             digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 0     1  =   0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1     1  =   1 ");
            digitalWrite (OUTPUT_A, HIGH);
            } 
             else{}
            
          }
          else if (INPUT_SELECTOR_2_VALUE==1 && INPUT_SELECTOR_3_VALUE==0)// 3-INPUT SELECTED
          {
            INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    0 = 0 ");
            digitalWrite (OUTPUT_A, LOW);
             GATE_RESULT_FLAG=1;
            } 
            
           else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    1 = 0 ");
             digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    0 = 0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    1 = 0 ");
            digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1    0    0 = 0 ");
             digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    0    1 = 0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    0 = 0 ");
            digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    1 = 1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            
             else{}
            }
            
            else{}
        }
          AND_GATE_VALUE = digitalRead(AND_GATE);
          NAND_GATE_VALUE = digitalRead(NAND_GATE);
          OR_GATE_VALUE = digitalRead(OR_GATE);
          NOR_GATE_VALUE = digitalRead(NOR_GATE);
          
        if(AND_GATE_VALUE==0 || NAND_GATE_VALUE ==0 || OR_GATE_VALUE==0 || NOR_GATE_VALUE==0)
        {
         break;
          }
          else {}
      GATE_RESULT_FLAG=1;
      }while (REMAIN==1);
     }
   
      else if (AND_GATE_VALUE==1&& NAND_GATE_VALUE ==0&& OR_GATE_VALUE==1&& NOR_GATE_VALUE==1)//NAND GATE IS SELECTED FOR THE TRAINING
      {
        do
        {REMAIN1=1;
         if (GATE_RESULT_FLAG_1 == 0)
        {
        lcd.setCursor(0,0);  
        lcd.print("NAND GATE PICKED "); 
        lcd.setCursor(0,1);         //position 1, line 1
        lcd.print("FOR EXPERIMENT..... ");
        delay (2000);
        
        lcd.setCursor(0,0);  
        lcd.print("PICK YOUR CHOICE "); 
        lcd.setCursor(0,1);         //position 1, line 1
        lcd.print("GATE INPUT TYPE ");
           delay (2000);
        
        INPUT_SELECTOR_2_VALUE= digitalRead(INPUT_SELECTOR_2);    
        INPUT_SELECTOR_3_VALUE= digitalRead(INPUT_SELECTOR_3);    
         if (INPUT_SELECTOR_2_VALUE==0 && INPUT_SELECTOR_3_VALUE==1)// 2-input gate selected
         {
          lcd.setCursor(0,0); 
          lcd.print("2-INPUT-GATE HAS "); 
          lcd.setCursor(0,1);         //position 1, line 1
          lcd.print(" BEEN SELECTED.. ");
           delay (2000);
           INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0     0  =   1 ");
             digitalWrite (OUTPUT_A, HIGH);
             GATE_RESULT_FLAG_1=1;
            } 
            
           else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
              lcd.print(" 1     0  =   1 ");
             digitalWrite (OUTPUT_A, HIGH);
              GATE_RESULT_FLAG_1=1;

            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
              lcd.print(" 0     1  =   1 ");
              digitalWrite (OUTPUT_A, HIGH);
              GATE_RESULT_FLAG=1;

            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".AND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1     1  =   0 ");
             digitalWrite (OUTPUT_A, LOW);
              GATE_RESULT_FLAG_1=1;

            } 
             else{}
            
          }
          else if (INPUT_SELECTOR_2_VALUE==1 && INPUT_SELECTOR_3_VALUE==0)// 3-INUT SELECTED
          {
           INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    0=  1 ");
            digitalWrite (OUTPUT_A, HIGH);
             GATE_RESULT_FLAG_1=1;
            } 
            
           else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    1=  1 ");
             digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    0=  1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    1=  1 ");
            digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1    0    0=  1 ");
             digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    0    1=  1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    0=  1 ");
            digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    1=  0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            
             else{}
            }
            else{}

        GATE_RESULT_FLAG_1=1;
        }
         else{
        /////////
         INPUT_SELECTOR_2_VALUE= digitalRead(INPUT_SELECTOR_2);    
         INPUT_SELECTOR_3_VALUE= digitalRead(INPUT_SELECTOR_3);    
         if (INPUT_SELECTOR_2_VALUE==0 && INPUT_SELECTOR_3_VALUE==1)// 2-input gate is selected
         {
           INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0     0  =   1 ");
            digitalWrite (OUTPUT_A, HIGH);
             GATE_RESULT_FLAG_1=1;
            } 
            
           else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1     0  =   1 ");
             digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 0     1  =   1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1     1  =   0 ");
            digitalWrite (OUTPUT_A, LOW);
            } 
             else{}
            
          }
          else if (INPUT_SELECTOR_2_VALUE==1 && INPUT_SELECTOR_3_VALUE==0)// 3-INPUT SELECTED
          {
            INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    0=  1 ");
            digitalWrite (OUTPUT_A, HIGH);
             GATE_RESULT_FLAG_1=1;
            } 
            
           else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    1=  1 ");
             digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    0=  1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    1=  1 ");
            digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1    0    0=  1 ");
             digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    0    1=  1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    0=  1 ");
            digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    1=  0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            
             else{}
            }
            
            else{}
        }
      AND_GATE_VALUE = digitalRead(AND_GATE);
            NAND_GATE_VALUE = digitalRead(NAND_GATE);
            OR_GATE_VALUE = digitalRead(OR_GATE);
            NOR_GATE_VALUE = digitalRead(NOR_GATE);
            
        if(AND_GATE_VALUE==0 || NAND_GATE_VALUE ==0 || OR_GATE_VALUE==0 || NOR_GATE_VALUE==0)
        {
          break;
          }
          else {}
      GATE_RESULT_FLAG_1=1;
              } while (REMAIN1==1);
              }

  
      else if (AND_GATE_VALUE==1&& NAND_GATE_VALUE ==1&& OR_GATE_VALUE==0&& NOR_GATE_VALUE==1)//OR GATE IS SELECTED FOR THE TRAINING
      {  
        do
        {REMAIN2=1;
        if (GATE_RESULT_FLAG_2 == 0)
        {
        lcd.setCursor(0,0);  
        lcd.print("OR GATE PICKED "); 
        lcd.setCursor(0,1);         //position 1, line 1
        lcd.print("FOR EXPERIMENT.... ");
        delay (2000);
        
        lcd.setCursor(0,0);  
        lcd.print("PICK YOUR CHOICE "); 
        lcd.setCursor(0,1);         //position 1, line 1
        lcd.print("GATE INPUT TYPE ");
           delay (2000);
        
        INPUT_SELECTOR_2_VALUE= digitalRead(INPUT_SELECTOR_2);    
        INPUT_SELECTOR_3_VALUE= digitalRead(INPUT_SELECTOR_3);    
         if (INPUT_SELECTOR_2_VALUE==0 && INPUT_SELECTOR_3_VALUE==1)// 2-input gate selected
         {
          lcd.setCursor(0,0); 
          lcd.print("2-INPUT-GATE HAS "); 
          lcd.setCursor(0,1);         //position 1, line 1
          lcd.print(" BEEN SELECTED.. ");
           delay (2000);
           INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0     0  =   0 ");
             digitalWrite (OUTPUT_A, LOW);//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
             GATE_RESULT_FLAG_2=1;
            } 
            
           else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
              lcd.print(" 1     0  =   1 ");
             digitalWrite (OUTPUT_A, HIGH);
              GATE_RESULT_FLAG_2=1;

            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
              lcd.print(" 0     1  =   1 ");
              digitalWrite (OUTPUT_A, HIGH);
              GATE_RESULT_FLAG_2=1;

            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1     1  =   1 ");
             digitalWrite (OUTPUT_A, HIGH);
              GATE_RESULT_FLAG_2=1;

            } 
             else{}
            
          }
          else if (INPUT_SELECTOR_2_VALUE==1 && INPUT_SELECTOR_3_VALUE==0)// 3-INUT SELECTED
          {
           INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    0=  0 ");
            digitalWrite (OUTPUT_A, LOW);
             GATE_RESULT_FLAG_1=1;
            } 
            
           else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    1=  1 ");
             digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    0=  1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    1=  1 ");
            digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1    0    0=  1 ");
             digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    0    1=  1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    0=  1 ");
            digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NAND GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    1=  1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            
             else{}
            }
            else{}

        GATE_RESULT_FLAG_2=1;
        }
         else{
        /////////
         INPUT_SELECTOR_2_VALUE= digitalRead(INPUT_SELECTOR_2);    
         INPUT_SELECTOR_3_VALUE= digitalRead(INPUT_SELECTOR_3);    
         if (INPUT_SELECTOR_2_VALUE==0 && INPUT_SELECTOR_3_VALUE==1)// 2-input gate is selected
         {
           INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0     0  =   0 ");
            digitalWrite (OUTPUT_A, LOW);
             GATE_RESULT_FLAG_1=1;
            } 
            
           else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1     0  =   1 ");
             digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 0     1  =   1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1     1  =   1 ");
            digitalWrite (OUTPUT_A, HIGH);
            } 
             else{}
            
          }
          else if (INPUT_SELECTOR_2_VALUE==1 && INPUT_SELECTOR_3_VALUE==0)// 3-INPUT SELECTED
          {
            INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    0 = 0 ");
            digitalWrite (OUTPUT_A, LOW);
             GATE_RESULT_FLAG_2=1;
            } 
            
           else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    1 = 1 ");
             digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    0 = 1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    1 = 1 ");
            digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1    0    0 = 1 ");
             digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    0    1 = 1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    0 = 1 ");
            digitalWrite (OUTPUT_A, HIGH);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".OR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    1 = 1 ");
              digitalWrite (OUTPUT_A, HIGH);
            } 
            
             else{}
            }
            
            else{}
        }
      AND_GATE_VALUE = digitalRead(AND_GATE);
            NAND_GATE_VALUE = digitalRead(NAND_GATE);
            OR_GATE_VALUE = digitalRead(OR_GATE);
            NOR_GATE_VALUE = digitalRead(NOR_GATE);
            
        if(AND_GATE_VALUE==0 || NAND_GATE_VALUE ==0 || OR_GATE_VALUE==0 || NOR_GATE_VALUE==0)
        {
          break;
          }
          else {}
      GATE_RESULT_FLAG_2=1;
               }while (REMAIN2==1);
              }
              
      else if (AND_GATE_VALUE==1&& NAND_GATE_VALUE ==1&& OR_GATE_VALUE==1&& NOR_GATE_VALUE==0)//NOR GATE IS SELECTED FOR THE TRAINING
      {
        do
        {REMAIN3=1;
         if (GATE_RESULT_FLAG_3 == 0)
        {
        lcd.setCursor(0,0);  
        lcd.print("NOR GATE PICKED "); 
        lcd.setCursor(0,1);         //position 1, line 1
        lcd.print("FOR EXPERIMENT.... ");
        delay (2000);
        
        lcd.setCursor(0,0);  
        lcd.print("PICK YOUR CHOICE "); 
        lcd.setCursor(0,1);         //position 1, line 1
        lcd.print("GATE INPUT TYPE ");
           delay (2000);
        
        INPUT_SELECTOR_2_VALUE= digitalRead(INPUT_SELECTOR_2);    
        INPUT_SELECTOR_3_VALUE= digitalRead(INPUT_SELECTOR_3);    
         if (INPUT_SELECTOR_2_VALUE==0 && INPUT_SELECTOR_3_VALUE==1)// 2-input gate selected
         {
          lcd.setCursor(0,0); 
          lcd.print("2-INPUT-GATE HAS "); 
          lcd.setCursor(0,1);         //position 1, line 1
          lcd.print(" BEEN SELECTED.. ");
           delay (2000);
           INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0     0  =   1 ");
             digitalWrite (OUTPUT_A, HIGH);//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
             GATE_RESULT_FLAG_3=1;
            } 
            
           else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
              lcd.print(" 1     0  =   0 ");
             digitalWrite (OUTPUT_A, LOW);
              GATE_RESULT_FLAG_2=1;

            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
              lcd.print(" 0     1  =   0 ");
              digitalWrite (OUTPUT_A, LOW);
              GATE_RESULT_FLAG_3=1;

            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1     1  =   0 ");
             digitalWrite (OUTPUT_A, LOW);
              GATE_RESULT_FLAG_3=1;

            } 
             else{}
            
          }
          else if (INPUT_SELECTOR_2_VALUE==1 && INPUT_SELECTOR_3_VALUE==0)// 3-INUT SELECTED
          {
           INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    0=  1 ");
            digitalWrite (OUTPUT_A, HIGH);
             GATE_RESULT_FLAG_3=1;
            } 
            
           else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    1=  0 ");
             digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    0=  0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    1=  0 ");
            digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1    0    0=  0 ");
             digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    0    1=  0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    0=  0 ");
            digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    1=  0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            
             else{}
            }
            else{}

        GATE_RESULT_FLAG_3=1;
        }
         else{
        /////////
         INPUT_SELECTOR_2_VALUE= digitalRead(INPUT_SELECTOR_2);    
         INPUT_SELECTOR_3_VALUE= digitalRead(INPUT_SELECTOR_3);    
         if (INPUT_SELECTOR_2_VALUE==0 && INPUT_SELECTOR_3_VALUE==1)// 2-input gate is selected
         {
           INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0     0  =   1 ");
            digitalWrite (OUTPUT_A, HIGH);
             GATE_RESULT_FLAG_3=1;
            } 
            
           else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1     0  =   0 ");
             digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 0     1  =   0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1     1  =   0 ");
            digitalWrite (OUTPUT_A, LOW);
            } 
             else{}
            
          }
          else if (INPUT_SELECTOR_2_VALUE==1 && INPUT_SELECTOR_3_VALUE==0)// 3-INPUT SELECTED
          {
            INPUT_A_VALUE=digitalRead(INPUT_A);   
           INPUT_B_VALUE=digitalRead(INPUT_B);
           INPUT_C_VALUE=digitalRead(INPUT_C);
           
           if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    0 = 1 ");
            digitalWrite (OUTPUT_A, HIGH);
             GATE_RESULT_FLAG_3=1;
            } 
            
           else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    0    1 = 0 ");
             digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    0 = 0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==0 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 0    1    1 = 0 ");
            digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==0)
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
             lcd.print(" 1    0    0 = 0 ");
             digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==0 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    0    1 = 0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==0 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    0 = 0 ");
            digitalWrite (OUTPUT_A, LOW);
            } 
            else if ( INPUT_A_VALUE==1 &&  INPUT_B_VALUE==1 && INPUT_C_VALUE==1 )
           { 
             lcd.setCursor(0,0); 
             lcd.print(".NOR GATE LOGIC. "); 
             lcd.setCursor(0,1);         //position 1, line 1
            lcd.print(" 1    1    1 = 0 ");
              digitalWrite (OUTPUT_A, LOW);
            } 
            
             else{}
            }
            
            else{}
        }
       AND_GATE_VALUE = digitalRead(AND_GATE);
            NAND_GATE_VALUE = digitalRead(NAND_GATE);
            OR_GATE_VALUE = digitalRead(OR_GATE);
            NOR_GATE_VALUE = digitalRead(NOR_GATE);
            
        if(AND_GATE_VALUE==0 || NAND_GATE_VALUE ==0 || OR_GATE_VALUE==0 || NOR_GATE_VALUE==0)
        {
          break;
          }
          else {}
      GATE_RESULT_FLAG_3=1;
               }while (REMAIN3==1);
              }
      else{}
    }
    }
    else{}
}
    
