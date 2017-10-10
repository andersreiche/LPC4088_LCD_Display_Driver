
#include "board.h"
#include "lcd.h"
#include <stdio.h>
#define TICKRATE_HZ1 (10)	/* 10 ticks per second */
char line[40];

void SysTick_Handler(void)
{
	Board_LED_Toggle(1);
}

int main(void)
{
	/* Generic Initialization */
	SystemCoreClockUpdate();
	Board_Init();

	/* Enable and setup SysTick Timer at a periodic rate */
	SysTick_Config(SystemCoreClock / TICKRATE_HZ1);
	puts("Write something to the display!");

	/* LEDs toggle in interrupt handlers */
	while (1) {
		//__WFI();
		scanf("%s", &line);
		lcd_print(line);
	}

	return 0;
}

