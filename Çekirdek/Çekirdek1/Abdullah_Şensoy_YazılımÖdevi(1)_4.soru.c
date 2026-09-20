#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){

float dip,boy,zayif,normal,fazla;
printf("lutfen boyunuzu metre cinsinden girin:\n");
scanf("%f",&boy);
dip=boy*0;
zayif=18.4*pow(boy,2);
normal=24.9*pow(boy,2);
fazla=29.9*pow(boy,2);
printf("Vucut kitle indeksine gore kilo kategorileri aralıkları:\nZayif kilo araligi: %.1f-%.3f\nNormal kilo araligi: %.3f-%.3f\nFazla kilo araligi: %.3f-%.3f\nObez kilo araligi: %.3f- ve ustu",dip,zayif,zayif,normal,normal,fazla,fazla);
}