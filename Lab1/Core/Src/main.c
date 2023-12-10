#include "main.h"
int main(void)
{
#define BIT21 0B10000000000000000000000

RCC -> AHBENR |= 1 << 21;
RCC -> AHBENR |= RCC_AHBENR_GPIOAEN;

GPIOE -> MODER |= GPIO_MODER_MODER8_0;
GPIOE -> MODER &= ~GPIO_MODER_MODER8_1;

GPIOE -> MODER &= ~GPIO_MODER_MODER0_0;
GPIOE -> MODER &= ~GPIO_MODER_MODER0_1;

while(1)
{
//read the state of the button
if(GPIOA ->IDR & GPIO_IDR_0)
{
//Button is not pressed, turn off the LED
GPIOE -> BSRR |= 1 << 8;
//Reset the bit to turn off LED
}
else
{
GPIOE -> BSRR |=1 << (8+16);// Button is pressed, t
//Set the bit to turn on LED
}
}
}
