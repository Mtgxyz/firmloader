#include "common.h"
#include "sdmmc.h"
struct FIRM_sect {
    u32 offset;
    u32 physical;
    u32 size;
    u32 arm11;
    u8 SHA256[0x20]; //Implement later.
}__attribute__((packed));
struct FIRM_header {
    char magic[4];
    int reserved1;
    u32 arm11Entry;
    u32 arm9Entry;
    u8 reserved2[0x30];
    struct FIRM_sect sections[4];
    u8 RSA2048[0x100]; //I'd need to find out big N's private key to do that!
}__attribute__((packed));
struct chs {
    u8 head;
    u8 sector;
    u8 cylinder;
}__attribute__((packed));
struct partition {
    u8 status;
    struct chs start_chs;
    u8 parttype;
    struct chs end_chs;
    u32 start;
    u32 length;
}__attribute__((packed));
struct MBR {
    u8 bootstrap[0x1BE];
    struct partition partition[4];
    u16 signature;
}__attribute__((packed));
void main() {
    // start up SD-Card controller
    sdmmc_sdcard_init();
    
    struct MBR drive;
    sdmmc_sdcard_readsectors(0,1, (u8*)&drive);
    if(drive.partition[3].status==0) {
        //Found the partition
        struct FIRM_header firm;
        sdmmc_sdcard_readsectors(drive.partition[3].start,1, (u8*)&firm);
        char* magic="FIRM";
        for(int i=0;i<4;i++)
            if(magic[i]!=firm.magic[i])
        return; //Check magic
        for(;;); //Deadlock if checksum's right. for debugging
    }
}
void init() {
    main();
    u8 *lfb=(u8*)0x18300000;
    for(int i=0;i<500;i++)
        lfb[i]=0xFF; //Output simple error
    for(;;);
}