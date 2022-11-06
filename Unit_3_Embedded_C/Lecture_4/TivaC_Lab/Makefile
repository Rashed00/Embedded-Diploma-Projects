#@copyright: Rashed is raging embedded systems

CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -mthumb -gdwarf-2 -g
INCS= -I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_name = Unit3_lab4_CortexM4

all: $(Project_name).bin
	@echo "=======Build is done======="



%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS)  $< -o $@


$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(AsOBJ) $(OBJ) -o $@ -Map=Map_file.map
	cp $(Project_name).elf $(Project_name).axf
	
$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all: 
	rm *.o *.elf *.bin 

clean: 
	rm *.elf *.bin 
