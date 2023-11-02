DEVICE	= atmega328p

CLK 	= 16000000

OBJ		= main.o

CMP		= avr-gcc -Wall -Os -DF_CPU=$(CLK) -mmcu=$(DEVICE)

all: main.hex

.c.o:
	$(CMP) -c $< -o $@

.S.o:
	$(CMP) -x assembler-with-cpp -c $< -o $@

.c.s:
	$(CMP) -S $< -o $@

flash:
	avrdude -c arduino -p $(DEVICE) -P /dev/ttyACM0 -U flash:w:main.hex

clean:
	rm -f main.hex main.elf $(OBJ)

main.elf: $(OBJ)
	$(CMP) -o main.elf $(OBJ)

main.hex: main.elf
	rm -f main.hex
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex
	avr-size --format=avr --mcu=$(DEVICE) main.elf