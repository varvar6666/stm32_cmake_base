#include <main.hpp>
#include "math.h"

USART usart2(USART2, 115200, PIN(GPIOA,2), PIN(GPIOA,3));

Interface_USART PC_USART(&usart2, DMA1_Stream6, DMA1_Stream5, 0 ,0);

TIM PC_TIM(TIM14);

struct tx_b_s
{
	uint16_t header;
	int16_t data[5];
	uint16_t terminator;
}tx_data = {	.header = 0x6565,
				.data = {0,1,2,3,4},
				.terminator = 0x6666};


int main()
{
	System::Init();
	ClockSystem::Init_calc_pll(180000000, ClockSystem::PLL_ClockSource::HSE, 8000000);
	System::Enable_CYCCNT();

	NUCLEO_LED.SetUp(PIN::TYPE::OUTPUT_PushPull);

	PC_USART.Init();

	PC_TIM.SetHard();
	PC_TIM.SetFreq(10);
	PC_TIM.Enable_IRQ(TIM::IRQ::UE);
	PC_TIM.Start();

	uint32_t tick = System::GetTick();
	uint32_t tick_now;
	// char str[20] = {};

	for(;;)
	{

		tick_now = System::GetTick();
		if((tick_now - tick) > 500)
		{
			// sprintf(str, "Tick: %ld\n", tick_now);
			// System::SWOTrace(reinterpret_cast<uint8_t*>(str), sizeof(str));
			tick = tick_now;
			NUCLEO_LED.TogglePin_BB();
		}
	}
}

extern "C" void USART2_IRQHandler(void)
{
	PC_USART.IRQHandler();
}

extern "C" void TIM8_TRG_COM_TIM14_IRQHandler(void)
{
	PC_TIM.ClearFlags();
	static float i = 0;

	i += 0.01;

	if(i >= 2*3.14) i = 0;

	tx_data.data[0]++;
	tx_data.data[1] = sinf(10*i)*1000;

	PC_USART.Send((uint8_t*)&tx_data, sizeof(tx_data));


}