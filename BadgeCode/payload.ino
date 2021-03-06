#include "UsbKeyboard.h"

#define BUTTON_PIN 7

// If the timer isr is corrected
// to not take so long change this to 0.
#define BYPASS_TIMER_ISR 1

void doPayload();


void setup() {
  pinMode(BUTTON_PIN, INPUT);
  digitalWrite(BUTTON_PIN, HIGH);
  
#if BYPASS_TIMER_ISR
  // disable timer 0 overflow interrupt (used for millis)
  TIMSK0&=!(1<<TOIE0); // ++
#endif

}


#if BYPASS_TIMER_ISR
void delayMs(unsigned int ms) {
   /*
  */ 
  for (int i = 0; i < ms; i++) {
    delayMicroseconds(1000);
  }
}
#endif


void sendKeys( int keys[] )
{
  int i=0;
  while(keys[i] != 0 )
  {
    UsbKeyboard.sendKeyStroke( keys[i] );
    i++;
  }
}
int skipCount=0;
void loop() {
  
  UsbKeyboard.update();

  digitalWrite(13, !digitalRead(13));

  if( skipCount > 100 ){
    doPayload();
    skipCount = 0;
  }
  skipCount++;
     
  waitSome(120);
}

void waitSome( unsigned ms ){
  #if BYPASS_TIMER_ISR  // check if timer isr fixed.
      delayMs(ms);
  #else
      delay(ms);
  #endif
}
//Example Mod Keys
//UsbKeyboard.sendKeyStroke(KEY_R,    MOD_GUI_LEFT);
//UsbKeyboard.sendKeyStroke(KEY_F3,    MOD_ALT_LEFT);
/*
MOD_CONTROL_LEFT
MOD_SHIFT_LEFT
MOD_ALT_LEFT
MOD_GUI_LEFT
MOD_CONTROL_RIGHT
MOD_SHIFT_RIGHT
MOD_ALT_RIGHT
MOD_GUI_RIGHT
*/


void onWrite(unsigned char*, unsigned char )
{

}
void doPayload(){
	UsbKeyboard.sendKeyStroke( KEY_P );
	UsbKeyboard.sendKeyStroke( KEY_L );
	UsbKeyboard.sendKeyStroke( KEY_U );
	UsbKeyboard.sendKeyStroke( KEY_M );
	UsbKeyboard.sendKeyStroke( KEY_A );
	UsbKeyboard.sendKeyStroke( KEY_ENTER );
	UsbKeyboard.sendKeyStroke( KEY_ENTER );
	UsbKeyboard.sendKeyStroke( KEY_ENTER );
	UsbKeyboard.sendKeyStroke( KEY_E );
	UsbKeyboard.sendKeyStroke( KEY_S );
	UsbKeyboard.sendKeyStroke( KEY_T );
	UsbKeyboard.sendKeyStroke( KEY_E );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_F );
	UsbKeyboard.sendKeyStroke( KEY_U );
	UsbKeyboard.sendKeyStroke( KEY_E );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_M );
	UsbKeyboard.sendKeyStroke( KEY_I );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_P );
	UsbKeyboard.sendKeyStroke( KEY_A );
	UsbKeyboard.sendKeyStroke( KEY_Y );
	UsbKeyboard.sendKeyStroke( KEY_L );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_A );
	UsbKeyboard.sendKeyStroke( KEY_D );
	UsbKeyboard.sendKeyStroke( KEY_ENTER );
	UsbKeyboard.sendKeyStroke( KEY_ENTER );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_TILDE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_ENTER );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_ENTER );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_ENTER );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_ENTER );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_ENTER );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_ENTER );
	UsbKeyboard.sendKeyStroke( KEY_TILDE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_QUOTE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_TILDE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_QUOTE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_TILDE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_QUOTE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_TILDE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_TILDE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_ENTER );
	UsbKeyboard.sendKeyStroke( KEY_TILDE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_QUOTE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_TILDE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_QUOTE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_TILDE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_QUOTE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_TILDE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_TILDE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_QUOTE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_QUOTE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_PERIOD );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_TILDE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_QUOTE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_SPACE );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_O );
	UsbKeyboard.sendKeyStroke( KEY_ENTER );
	UsbKeyboard.sendKeyStroke( KEY_ENTER );
	UsbKeyboard.sendKeyStroke( KEY_ENTER );
}
