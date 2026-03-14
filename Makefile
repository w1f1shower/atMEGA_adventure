CC = avr-gcc
MCU = atmega328p
F_CPU = 16000000UL
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall -ffreestanding # -nostdlib (do not do this (until u will want to implement some crazy stuff))

TARGET = game

LIBDIR = lib
#LIBDIR_DRIVERS = $(LIBDIR)/drivers
INCDIR = include

SOURCES = $(wildcard *.c) $(wildcard $(LIBDIR)/*.c) #$(wildcard $(LIBDIR_DRIVERS)/*.c)
OBJECTS = $(SOURCES:.c=.o)


all: clean $(TARGET).hex

#$(OBJECTS): # $(SOURCES)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET).elf: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(TARGET).hex: $(TARGET).elf
	avr-objcopy -O ihex -R .eeprom $< $@


clean:
	rm -f $(OBJECTS) $(TARGET).elf $(TARGET).hex 


flash: $(TARGET).hex
	sudo avrdude -p $(MCU) -P usb -c usbasp -U flash:w:$<

flash_init:
	avrdude -p $(MCU) -c usbasp -n


dump:
	avr-objdump -S $(TARGET).elf | less

analyze:
	avr-size -A --mcu=$(MCU) $(TARGET).elf
	avr-size -A --mcu=$(MCU) $(TARGET).hex


.PHONY: all clean flash flash_init analyze
