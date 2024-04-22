#include <main.hpp>
#include <stdio.h>


int main()
{
	System_F4::Init();

	NUCLEO_LED.SetUp(PIN::TYPE::OUTPUT_PushPull);

	uint32_t tick = System_F4::GetTick();
	uint32_t tick_now;
	char str[20] = {};

	for(;;)
	{

		tick_now = System_F4::GetTick();
		if((tick_now - tick) > 200)
		{
			sprintf(str, "Tick: %d\n", tick_now);
			System_F4::SWOTrace(reinterpret_cast<uint8_t*>(str), sizeof(str));
			tick = tick_now;
			NUCLEO_LED.TogglePin_BB();
		}
	}
}