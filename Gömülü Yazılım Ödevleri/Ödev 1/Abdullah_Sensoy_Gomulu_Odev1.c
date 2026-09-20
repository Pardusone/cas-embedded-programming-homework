#include <Keypad.h>

const int analogPin = A0;
const int threshold = 50;
const char sifre[] = "1960";
const byte satir_sayisi = 4;
const byte sutun_sayisi = 4;

char keys[satir_sayisi][sutun_sayisi] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte pin_rows[satir_sayisi] = {9, 8, 7, 6};
byte pin_column[sutun_sayisi] = {5, 4, 3, 2};
Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, satir_sayisi, sutun_sayisi);

bool sifrekontrol = false;
bool okumakontrol = false;

void setup() {
  Serial.begin(9600);
  pinMode(analogPin, INPUT);
}

void loop() {
  char tus = keypad.getKey();
  if (tus != NO_KEY) {
    if (tus == '#') {
      if (sifrekontrol) {
        okumakontrol = !okumakontrol;
        if (okumakontrol) {
          Serial.println("Okuma basladi");
        } else {
          Serial.println("Okuma durdu");
        }
      } else {
        Serial.println("Hatali sifre tekrar deneyiniz!");
      }
    } else {
      kontrolsifre(tus);
    }
  }
  if (okumakontrol && sifrekontrol) {
    int analogValue = analogRead(analogPin);
    Serial.println(analogValue);
  }
}

void kontrolsifre(char tus) {
  static byte anlikdeger = 0;
  static char girilensifre[sizeof(sifre)];

  if (tus == sifre[anlikdeger]) {
    girilensifre[anlikdeger] = tus;
    anlikdeger++;
    if (anlikdeger == sizeof(sifre) - 1) {
      girilensifre[anlikdeger] = '\0';
      if (strcmp(girilensifre, sifre) == 0) {
        sifrekontrol = true;
        Serial.println("Dogru sifre okuma baslatildi");
      } else {
        Serial.println("Hatali sifre okuma baslatilamadi");
      }
    }
  } else {
    anlikdeger = 0;
  }
}
