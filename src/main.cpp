#include <main.hpp>
// #include "math.h"

extern "C"
{
	#include "stm32f4xx.h"
}

int main()
{
	// System::Init();
	// ClockSystem::Init_calc_pll(180000000, ClockSystem::PLL_ClockSource::HSE, 8000000);
	// System::Enable_CYCCNT();
	// NUCLEO_LED.SetUp(PIN::TYPE::OUTPUT_PushPull);

	// uint32_t tick = System::GetTick();
	// uint32_t tick_now;
	// char str[20] = {};
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	GPIOB->MODER |= 1 << 2*7;

	for(;;)
	{
		// tick_now = System::GetTick();
		// if((tick_now - tick) > 500)
		// {
			// sprintf(str, "Tick: %ld\n", tick_now);
			// System::SWOTrace(reinterpret_cast<uint8_t*>(str), sizeof(str));
			// NUCLEO_LED.TogglePin_BB();
		// }

		GPIOB->ODR ^= 1 << 7;
		for(uint32_t i = 0;i<1600000;i++){};
	}
}

extern "C" void NMI_Handler(void)
{
	while(1){};
}

extern "C" void HardFault_Handler(void)
{
	while(1){};
}

extern "C" void MemManage_Handler(void)
{
	while(1){};
}

extern "C" void BusFault_Handler(void)
{
	while(1){};
}

extern "C" void UsageFault_Handler(void)
{
	while(1){};
}