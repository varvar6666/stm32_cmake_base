#include <stdint.h>
#include "stm32f446xx.h"

int main()
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= 1 << 5*2;
	GPIOA->ODR |= 1 << 5;
	for(;;)
	{

	}
}