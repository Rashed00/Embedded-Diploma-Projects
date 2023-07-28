// Startup.c
// Eng.Rashed



#include <stdint.h>

void Reset_Handler(void);
extern int main(void);

void Default_Handler(void)
{
	Reset_Handler();
}
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));;
void Hard_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));;
void MM_Fault(void) __attribute__((weak, alias("Default_Handler")));;
void Bus_Fault(void) __attribute__((weak, alias("Default_Handler")));;
void Usage_Fault(void) __attribute__((weak, alias("Default_Handler")));;

extern unsigned int _stack_top;
uint32_t vectors[] __attribute__((section(".vectors"))) = {
	(uint32_t)	&_stack_top,
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &Hard_Fault_Handler,
	(uint32_t)	&MM_Fault,
	(uint32_t) &Bus_Fault,
	(uint32_t) &Usage_Fault
};
extern unsigned int _E_TEXT;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_BSS;
extern unsigned int _E_BSS;

void Reset_Handler(void){// copy data section from flash to sram
	unsigned int DATA_SIZE = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;
	unsigned char* P_src = (unsigned char*)&_E_TEXT;
	unsigned char* P_dst = (unsigned char*)&_S_DATA;
	int i; 
	for(i =0; i < DATA_SIZE; i++)
	{
		*((unsigned char*)P_dst++) = *((unsigned char*)P_src++);
	}
	//Init .bss section in SRAM = 0 
	unsigned int BSS_SIZE = (unsigned char*)&_E_BSS - (unsigned char*)&_S_BSS;
	P_dst = (unsigned char*)_S_BSS;
	for(i =0; i < BSS_SIZE; i++)
	{
		*((unsigned char*)P_dst++) = (unsigned char)0 ;
	}
	//Jump to main
	main();
}

