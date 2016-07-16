void init() {
    unsigned char *lfb=(unsigned char*)0x18300000;
    for(int i=500;i<1000;i++)
        lfb[i]=0xFF; //Output simple message
    for(;;);
}