#include "DAC.h" 
#include "tm4c123gh6pm.h" 
#include <stdint.h> 

void DAC_Init(void){ 
    SYSCTL_RCGCGPIO_R |= 0x02;// activate port B 
    while((SYSCTL_PRGPIO_R&0x02)!= 0x02){};// ready? 
        // 3) disable analog function on PB3-0 
        GPIO_PORTB_AMSEL_R &= ~0x0F; 
        // 4) enable regular GPIO 
        GPIO_PORTB_PCTL_R &=~0x00FFFFFF; 
        // 5) outputs on PB3-0 
        GPIO_PORTB_DIR_R |= 0x0F; 
        // 6) regular function on PB3-0 
        GPIO_PORTB_AFSEL_R &= ~0x0F; 
        // 7) enable digital on PB3-0 
        GPIO_PORTB_DEN_R |= 0x0F; 
    } 
    
void DAC_Out(unsigned long data){ 
    GPIO_PORTB_DATA_R = data; 
}