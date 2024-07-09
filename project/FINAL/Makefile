COMMON_OBJECTS 	=
CPU 		= msp430g2553
CFLAGS		= -mmcu=${CPU} -I../project/h
LDFLAGS		= -L/opt/ti/msp430_gcc/include


CC		= msp430-elf-gcc
AS		= msp430-elf-as


all:project2.elf

install:

	cd ../timerLib/ && make install

project2.elf: ${COMMON_OBJECTS} buzzer.o interrupts.o led.o switches.o mainProject2.o ../lib/libTimer.a

	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ ../lib/libTimer.a

load: project2.elf

	msp430loader.sh project2.elf

clean:

	rm -f *.o *.elf
