#include <main.hpp>

int main()
{
	System::Init();

	NUCLEO_LED.SetUp(PIN::TYPE::OUTPUT_PushPull);

	uint32_t tick = System::GetTick();
	uint32_t tick_now;
	char str[20] = {};

	for(;;)
	{

		tick_now = System::GetTick();
		if((tick_now - tick) > 200)
		{
			sprintf(str, "Tick: %ld\n", tick_now);
			System::SWOTrace(reinterpret_cast<uint8_t*>(str), sizeof(str));
			tick = tick_now;
			NUCLEO_LED.TogglePin_BB();
		}
	}
}