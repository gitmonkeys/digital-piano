#include "Piano.h" 
#include "tm4c123gh6pm.h" 
#include <stdint.h> 
//#include "DAC.h" 
 
// Port E bits 2-0 have 3 piano keys 
 
void Piano_Init(void){ 
 
 
    //Port F 
            SYSCTL_RCGCGPIO_R |= 0x20;  // Enable Port F clock 
            while(SYSCTL_RCGCGPIO_R !=0x20){};// ready? 
            GPIO_PORTF_LOCK_R = 0x4C4F434B;  // Unlock Port F 
            GPIO_PORTF_CR_R = 0x1F;  // Allow changes to all of Port F 
            GPIO_PORTF_PUR_R |= 0x11;  // Enable pull-up resistors for SW1 and SW2 
            GPIO_PORTF_DIR_R |= 0x0A;  // Set Port F1 and Port F3 as output 
            GPIO_PORTF_AFSEL_R &= ~0x0A; 
            GPIO_PORTF_DIR_R &= ~0x11;  // Set Port F4 and Port F0 as input 
            GPIO_PORTF_DEN_R |= 0x1F;  // Enable digital I/O on Port F 
            GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&0xFFFFF0FF)+0x00000000; 
            GPIO_PORTF_AMSEL_R = 0;     // disable analog functionality on PF 
 
     // Enable Port  E clock 
            SYSCTL_RCGCGPIO_R |= 0x10; 
             while((SYSCTL_PRGPIO_R&0x10)!= 0x10){};// ready? 
                  // 2) no need to unlock 
                  // 3) disable analog function on PE2-0 
             GPIO_PORTE_AMSEL_R &= ~0x07; 
                  // 4) enable regular GPIO 
             GPIO_PORTE_PCTL_R &= ~0x000000FF; 
                  // 5) inputs on PE1-0 
             GPIO_PORTE_DIR_R &= ~0x07; 
                  // 6) regular function on PE2-0 
             GPIO_PORTE_AFSEL_R &= ~0x07; 
                  // 7) enable digital on PE2-0 
              GPIO_PORTE_DEN_R |= 0x07; 
 
 
} 
 
uint8_t Piano_In(void){ 
    return GPIO_PORTE_DATA_R; 
 
} 