# firmloader
3DS bootloader for custom FIRM binaries

# Setup
You require MTGos's cross compiler suite (or at least an arm-none-eabi compiler in path.
run `make` and copy arm9loaderhax.bin on the top of SD card.
You need a 4th partition on the SD card. Write the FIRM binary raw on the partition (i.e. `dd if=firm.bin of=/dev/da0s4 bs=1M`)
