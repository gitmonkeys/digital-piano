#include "Sound.h" 
#include "DAC.h" 
#include "tm4c123gh6pm.h" 
#include <stdint.h> 
 
unsigned char Index; 
unsigned short Sound_On_Flag; 
// 4-bit 32-element sine wave 
const uint8_t wave[32]= 
{8,9,11,12,13,14,14,15,15,15,14,14,13,12,11,9,8,7,5,4,3,2,2,1,1,1,2,2,3,4,5,7}; 
 
 
// Initialize Systick periodic interrupts 
// Also calls DAC_Init() to initialize DAC 
void Sound_Init(){ 
 
  DAC_Init();          // Port B is DAC 
 
  Index = 0; 
 
  NVIC_ST_CTRL_R = 0;         // disable SysTick during setup 
 
  NVIC_ST_CURRENT_R = 0;      // any write to current clears it 
 
  NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF)|0x20000000; // priority 1 
 
  NVIC_ST_CTRL_R = 0x0007; // enable SysTick with core clock and interrupts 
 
} 
 
void Sound_Play(unsigned long period){ 
    if(period==0)// sound_off 
    { 
        Sound_On_Flag = 0; 
        GPIO_PORTB_DATA_R = 0; 
        GPIO_PORTF_DATA_R=0x02;//Red light on that means sound-off 
    } 
    else{ 
        Sound_On_Flag = 1; 
        NVIC_ST_RELOAD_R = period-1;// reload value 
    } 
} 
 
// Interrupt service routine 
// Executed every 12.5ns*(period) 
 void SysTick_Handler(void){ 
        Index = (Index+1)&0x1F; //index increments from 0 to 31 and then starts back at 0 again 
        if(Sound_On_Flag){ 
 
           DAC_Out(wave[Index]); 
           GPIO_PORTF_DATA_R =0x08;//Green light on that means sound-on 
 
       } 
 
}