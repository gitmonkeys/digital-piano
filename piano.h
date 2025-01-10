#include <stdint.h> 
#ifndef __piano_H__ 
#define __piano_H__ 
 
// **************Piano_Init********************* 
// Initialize piano key inputs 
// Input: none 
// Output: none 
void Piano_Init(void); 
 
// **************Piano_In********************* 
// Input from piano key inputs 
// Input: none 
// Output: 0 to 15 depending on keys 
// 0x01 is key 0 pressed, 0x02 is key 1 pressed, 
// 0x04 is key 2 pressed. 
//Switches connected to PE0-2 are used as keys 
uint8_t Piano_In(void); 
#endif 