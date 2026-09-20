#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    char isimler[10][10] = {"Ozgur", "Ozay", "Selen", "Begum", "Sema", "Melih", "Batuhan", "Ahmet", "Amiraslan", "Mubariz"};
    int vize1[10] = {14, 82, 22, 70, 74, 81, 25, 43, 48, 29};
    int vize2[10] = {50, 85, 72, 64, 80, 66, 34, 25, 61, 30};
    int final[10] = {43, 70, 52, 35, 45, 73, 28, 33, 82, 65};

    float hambasari[10];
    float ortalama = 0;
    float toplam = 0;
    float sapma = 5;
    
    int i;
    for(i=0; i < 10; i++){
        hambasari[i]= (vize1[i] * 0.3) + (vize2[i] * 0.3) + (final[i] * 0.4) ;
        toplam = toplam + hambasari[i];
    }
    ortalama = toplam / 10 ;
    float taban = ortalama ;

    char* harfnotu[10];
    for (i = 0; i < 10; i++) {
        if (hambasari[i] < taban - (sapma* 2))
            harfnotu[i] = "FF";
        else if (hambasari[i] < taban - sapma)
            harfnotu[i] = "FD";
        else if (hambasari[i] < taban)
            harfnotu[i] = "DD";
        else if (hambasari[i] < taban + sapma)
            harfnotu[i] = "CC";
        else if (hambasari[i] < taban + (sapma* 2))
            harfnotu[i] = "CB";
        else if (hambasari[i] < taban + (sapma* 3))
            harfnotu[i] = "BB";
        else if (hambasari[i] < taban + (sapma* 4))
            harfnotu[i] = "BA";
        else
            harfnotu[i] = "AA";
    }
    printf("Ogrenci   \tNot\tHarf_Notu\tDurum\n");
    for (i = 0; i < 10; i++) {
        if (hambasari[i] < taban)
            printf("%-10s\t%.2f\t%s\t\tKaldi\n", isimler[i],round(hambasari[i]), harfnotu[i]);
        else
            printf("%-10s\t%.2f\t%s\t\tGecti\n", isimler[i],round(hambasari[i]), harfnotu[i]);
    }

    return 0;
}