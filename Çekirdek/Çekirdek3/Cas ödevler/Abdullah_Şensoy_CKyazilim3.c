#include <stdio.h>

int main() {
    unsigned short girilendeger = 0xABCD; // Örnek bir deger girdim

   
    unsigned short sesduzeyi = girilendeger >> 12;
    printf("Anlik ses duzeyi: %u%%\n", sesduzeyi);

    
    unsigned short sarkisayisi = (girilendeger >> 8) & 0xF;
    printf("Hafizadaki sarki sayisi: %u\n", sarkisayisi);

   
    unsigned short sarkiyuzdesi = (girilendeger >> 4) & 0xF;
    printf("Sarki suresi yuzdesi: %u%%\n", sarkiyuzdesi);

   
    unsigned short pilyuzdesi = girilendeger & 0xF;
    printf("Pil yuzdesi: %u%%\n", pilyuzdesi);

    return 0;
}
