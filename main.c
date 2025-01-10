#include <stdint.h> 
#include "PLL.h" 
#include "tm4c123gh6pm.h" 
#include "DAC.h" 
#include "Piano.h" 
#include "Sound.h" 

#define C   4778 // 523.3 Hz 
#define A   5682 // 440 Hz 
#define E   7576 // 330 Hz 
#define C_A 2595 // 963.3 Hz frequency of the chord formed by notes C and A 
#define C_E 2930 // 853.3 Hz frequency of the chord formed by notes C and E 
#define A_E 3247 // 770 Hz frequency of the chord formed by notes A and E 
#define Off 0 // 

const unsigned long FREQ_SYSTICK_TO_WAVE[8] = {Off, 
C, A, C_A, E, C_E, A_E, Off }; //array for the buttons 

int main(void) { 
  PLL_Init(Bus80MHz); 
  Piano_Init(); 
  Sound_Init(); 

  while(1) { 
    Sound_Play(FREQ_SYSTICK_TO_WAVE[Piano_In()]); 
  } 
} 