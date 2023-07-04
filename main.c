#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include "lowpower.h"
#include "led.h"


int main(void){

  LED_Init();
  Sleep_Init();
  
  while(1){
  
    if( WDT_Get_Ticks()%5 == 0 ){
	  LED_On();
	  _delay_ms(50);
	  LED_Off();
	  Deep_Sleep();
	}else{
	  Deep_Sleep();
	}
	
  }
}