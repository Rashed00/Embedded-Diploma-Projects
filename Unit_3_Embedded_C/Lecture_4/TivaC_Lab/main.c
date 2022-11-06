#include <stdint.h>

typedef volatile unsigned int vuint32_t;
typedef volatile unsigned char vuint8_t;

#define SYSCTL_BASE 0x400FE000
#define GPIO_BASE 0x40025000

#define SYSCTL_RCGC2_R 	*((vuint32_t*)(SYSCTL_BASE + 0x108))
#define GPIO_PORTF_DIR_R *((vuint32_t*)(GPIO_BASE + 0x400))
#define GPIO_PORTF_DEN_R *((vuint32_t*)(GPIO_BASE + 0x51C))
#define GPIO_PORTF_DATA_R *((vuint32_t*)(GPIO_BASE + 0x3FC))

typedef union
{	
	vuint8_t all_fields;
	struct 
	{
		vuint8_t reserved:3;
		vuint8_t Bit_3:1;
	}Bit;
		
}Register;

volatile Register* PF3 = (volatile Register*)(GPIO_BASE + 0x400);
volatile Register* ENABLE = (volatile Register*)(GPIO_BASE + 0x51C);
volatile Register* DATA = (volatile Register*)(GPIO_BASE + 0x3FC);

int main(void)
{
	volatile unsigned int delay_count;

	SYSCTL_RCGC2_R = 0x20;
	//delay to make sure GPIO wake and running 
	for(delay_count=0; delay_count<500; delay_count++);

	PF3->Bit.Bit_3 = 1;
	ENABLE->Bit.Bit_3 = 1;
	

	while(1){
		DATA->Bit.Bit_3 = 1;
		for(delay_count=0; delay_count<10000; delay_count++);
		DATA->Bit.Bit_3 = 0;
		for(delay_count=0; delay_count<10000; delay_count++);
	}

	return 0;
}

