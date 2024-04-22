#include <main.hpp>

int main()
{
	System_F4::Init();

	NUCLEO_LED.SetUp(PIN::TYPE::OUTPUT_PushPull);

	uint32_t tick = System_F4::GetTick();
	uint32_t tick_now;
	for(;;)
	{

		tick_now = System_F4::GetTick();
		if((tick_now - tick) > 200)
		{
			tick = tick_now;
			NUCLEO_LED.TogglePin_BB();
		}
	}
}