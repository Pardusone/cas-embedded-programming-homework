#include <stdio.h>
#include <stdlib.h>

enum Kartlar { 
   AnaKart = 15,
   BMS = 10,
   AkilliGucModulu = 7,
   KontrolIstasyonuKarti = 13,
   HidrafonKarti = 8,
   KontrolKolu = 9
};

struct Person { 
   struct Person* sonraki;
   int hours;
};

int main() {
   struct Person* Yasin = malloc(sizeof(struct Person)); 
   struct Person* Alper = malloc(sizeof(struct Person)); 
   struct Person* Eren = malloc(sizeof(struct Person)); 
   struct Person* Guler = malloc(sizeof(struct Person)); 
   
   Yasin->sonraki = Alper; 
   Alper->sonraki = Eren; 
   Eren->sonraki = Guler; 
   Guler->sonraki = Yasin; 
   
   Yasin->hours = 0;
   Alper->hours = AnaKart;
   Eren->hours = AnaKart + BMS;
   Guler->hours = AnaKart + BMS + AkilliGucModulu;
   
   struct Person* current = Yasin; 
   
   enum Kartlar current_kart = AnaKart; 
   
   int i;
   for (i = 0; i < 5; i++) { 
      printf("Hangi kart lehimlenecek? (0-AnaKart, 1-BMS, 2-AkilliGucModulu, 3-KontrolIstasyonuKarti, 4-HidrafonKarti, 5-KontrolKolu)\n");
      int kart;
      scanf("%d", &kart);
      
      current_kart = (enum Kartlar) kart; 
      
      current->hours += current_kart; 
      
      current = current->sonraki; 
      
      printf("Yasin: %d saat\n", Yasin->hours);
      printf("Alper: %d saat\n", Alper->hours);
      printf("Eren: %d saat\n", Eren->hours);
      printf("Guler: %d saat\n", Guler->hours);
   }
   
   free(Yasin); 
   free(Alper);
   free(Eren);
   free(Guler);
   
   return 0;
}
