CC = avr-gcc
MCU = atmega328p
F_CPU = 16000000UL
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall -ffreestanding -I$(INCDIR)

TARGET = game
BUILD_DIR = build

LIBDIR = lib
INCDIR = include

SOURCES = $(wildcard *.c) $(wildcard $(LIBDIR)/*.c)

OBJECTS = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SOURCES))
ELF = $(BUILD_DIR)/$(TARGET).elf
HEX = $(BUILD_DIR)/$(TARGET).hex

all: $(HEX)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(ELF): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(HEX): $(ELF)
	avr-objcopy -O ihex -R .eeprom $< $@

clean:
	rm -rf $(BUILD_DIR)

flash: $(HEX)
	sudo avrdude -p $(MCU) -P usb -c usbasp -U flash:w:$<

flash_init:
	avrdude -p $(MCU) -c usbasp -n

dump: $(ELF)
	avr-objdump -S $(ELF) | less

r2: $(ELF)
	r2 -AAA $(ELF)

analyze: $(ELF) $(HEX)
	avr-size -A --mcu=$(MCU) $(ELF)
	avr-size -A --mcu=$(MCU) $(HEX)

.PHONY: all clean flash flash_init dump r2 analyze
