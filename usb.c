

#include <avr/io.h>
#include <util/delay.h>
#include "usb.h"


#define  USB_DP_DDR  DDRD 
#define  USB_DP_PORT PORTD 
#define  USB_DP_bp   2

#define  USB_DM_DDR  DDRD 
#define  USB_DM_PORT PORTD 
#define  USB_DM_bp   3

void USB_Init(void){
  USB_DP_DDR  &=~(1<<USB_DP_bp);
  USB_DM_DDR  &=~(1<<USB_DM_bp);
  USB_DP_PORT |= (1<<USB_DP_bp);
  USB_DM_PORT |= (1<<USB_DM_bp);
}