// Header file for the 4-bit digital to analog converter 
#ifndef __DAC_H__ 
#define __DAC_H__ 
// **************DAC_Init********************* 
// Initialize 4-bit DAC 
// Input: none 
// Output: none 
void DAC_Init(void); 
// **************DAC_Out********************* 
// output to DAC 
// Input: 4-bit data, 0 to 15 
// Output: none 
void DAC_Out(unsigned long data); 
#endif