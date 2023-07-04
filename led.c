
#include <avr/io.h>

#define  LED_DDR  DDRD 
#define  LED_PORT PORTD 
#define  LED_bp   4

void LED_Init(void){
  LED_DDR |= (1<<LED_bp);
  LED_PORT&=~(1<<LED_bp);
}

void LED_On(void){
  LED_PORT|= (1<<LED_bp);
}

void LED_Off(void){
  LED_PORT&=~(1<<LED_bp);
}

uint8_t LED_State(void){
  if(LED_PORT & (1<<LED_bp)){
    return 1;
  }else{
    return 0;
  }
}

void LED_Toggle(void){
  if(LED_State()==1){
    LED_Off();
  }else{
    LED_On();
  }
}