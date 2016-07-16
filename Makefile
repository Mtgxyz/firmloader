CC=~/opt/bin/arm-none-eabi-gcc
LD=~/opt/bin/arm-none-eabi-ld
all: arm9loaderhax.bin
arm9loaderhax.bin: arm9loaderhax.elf
	objcopy -O binary $^ $@
arm9loaderhax.elf: sdmmc.o loader.o delay.o
	$(LD) -T loader.ld -o $@ $^
%.o: %.c
	$(CC) -c $^ -mcpu=arm946e-s -march=armv5te -mlittle-endian
%.o: %.s
	$(CC) -c $^ -mcpu=arm946e-s -march=armv5te -mlittle-endian