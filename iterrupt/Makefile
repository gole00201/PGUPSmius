BUILD 	 = ./build
TARGET 	 = $(BUILD)/main.hex
OBJ		 = $(BUILD)/main.o
ELF 	 = $(BUILD)/main.elf
SRC  	 = main.c
DEVICE	 = atmega8535
CLK 	 = 16000000
CC		 = avr-gcc
CC_FLAGS = -Wall -Os -DF_CPU=$(CLK) -mmcu=$(DEVICE) -Wl,-M -Wl,--gc-section>> $(BUILD)/memmap

all: $(TARGET)

$(TARGET): $(ELF)
	rm -f $(TARGET)
	avr-objcopy -j .text -j .data -O ihex $(ELF) $(TARGET)
	avr-objdump -D $(ELF) >> $(BUILD)/asmdump
	avr-size --format=avr --mcu=$(DEVICE) $(ELF)

$(ELF): $(OBJ)
	$(CC) $(CC_FLAGS) -o $(ELF) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CC_FLAGS) -c $< -o $@

flash:
	avrdude -c arduino -p $(DEVICE) -P /dev/ttyACM0 -U flash:w:$(TARGET)

clean:
	rm -f $(TARGET) $(ELF) $(OBJ) $(BUILD)/memmap $(BUILD)/asmdump
