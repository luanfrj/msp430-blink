# Makefile

MCU = msp430g2553
INCLUDE_DIR = $$MSP_HOME/msp430-gcc/include/

IFLAGS = -I $(INCLUDE_DIR)
LFLAGS = -L $(INCLUDE_DIR)

CC = msp430-elf-gcc

CFLAGS = -Os -Wall -g -mmcu=$(MCU)

OBJS = blink.o


all: $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) -o blink.elf $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $<
 
clean:
	rm -fr blink.elf $(OBJS)
