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

//booking 1024 Bytes located by .bss thruogh an unintialized array of int 256 elements (4*256=1024)
static unsigned long Stack_Top[256];


void (* g_p_fun_vectors[])()__attribute__((section(".vectors"))) =
{
	(void (*)()) ((unsigned long)Stack_Top + sizeof(Stack_Top)),
	&Reset_Handler,
	&NMI_Handler,
	&Hard_Fault_Handler,
	&MM_Fault,
	&Bus_Fault,
	&Usage_Fault
};

extern unsigned int _E_TEXT;
extern unsigned _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_BSS;
extern unsigned int _E_BSS;

void Reset_Handler(void){

	// copy data section from flash to sram
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

