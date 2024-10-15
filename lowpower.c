

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include "lowpower.h"

volatile uint32_t WDT_Ticks=0;

void Deep_Sleep(void){
  sleep_enable();
  sleep_bod_disable();
  sei();
  sleep_cpu();
  sleep_disable();
}

void ADC_Disable(void){
  ADCSRA &=~ (1<<ADEN);
}

void Analog_Comparator_Disable(void){
  ACSR   &=~ (1<<ACIE) ;
  ACSR   |=  (1<<ACD) ;
}

uint32_t WDT_Get_Ticks(void){
  return WDT_Ticks;
}

void Sleep_Init(void){
  cli();
  WDTCSR=(1<<WDCE)|(1<<WDE);
  WDTCSR=(1<<WDP0)|(1<<WDP2)|(1<<WDIE);
  
  ADC_Disable();
  Analog_Comparator_Disable();
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  
  sei();
}

ISR(WDT_vect){
  WDTCSR|=(1<<WDIE);
  WDT_Ticks++;
}

