/* linker_script_CortexM3
Eng. Rashed
*/

MEMORY 
{
	flash(RX) : ORIGIN = 0x08000000 , LENGTH = 32K
	sram(RWX) : ORIGIN = 0x20000000 , LENGTH = 10K

}

SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text*)
		*(.rodata)
		_E_TEXT = . ;
	}> flash
	
	.data :
	{
		_S_DATA = . ;
		*(.data)
		. = ALIGN(4) ;
		_E_DATA = . ;
	}> sram AT> flash

	.bss :
	{
		_S_BSS = . ;
		*(.bss)
		_E_BSS = . ;
		. = ALIGN(4);
		. = . + 0x1000 ;
		_stack_top = . ;
	}> sram
	
}