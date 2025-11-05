# 4D7S – 4 Rəqəmli 7 Seqment Ekran Kitabxanası / 4‑Digit 7‑Segment Display Library  

---

## Azərbaycan dili

Salam!  
Bu kitabxana **4 rəqəmli 7 seqment ekranı** **doğrudan Arduino pinləri ilə** idarə etmək üçün yaradılıb. Heç bir əlavə çip (TM1637, MAX7219 və s.) lazım deyil. Sadəcə **11 pin** (7 seqment + 4 digit) istifadə edərək rəqəmləri göstərə bilərsən.

### Xüsusiyyətlər
- Pozitiv / Negativ logic dəstəyi  
- Multiplexing ilə hamar göstərmə  
- Serial debug çıxışı  
- Sadə və başa düşülən API  

---

### Quraşdırma
1. **ZIP** faylı endir → `Sketch > Include Library > Add .ZIP Library…`  
   və ya `Documents/Arduino/libraries/` qovluğuna çıxar.  
2. Arduino IDE‑ni **yenidən başlat**.  
3. `Fayl > Misallar > 4D7S` menyusundan misalları aç.

---

### Pin Birleşməsi (Nümunə)

| Seqment | Arduino Pin |
|--------|-------------|
| A      | 2           |
| B      | 3           |
| C      | 4           |
| D      | 5           |
| E      | 6           |
| F      | 7           |
| G      | 8           |

| Digit  | Arduino Pin |
|--------|-------------|
| DIG1   | 9           |
| DIG2   | 10          |
| DIG3   | 11          |
| DIG4   | 12          |

> **Qeyd:** Pinləri `segmentPins[]` və `digitPins[]` massivlərində dəyişə bilərsən.

---

### Misallar

#### 1. `BasicNumbers.ino` – Tam Rəqəm Sırası
```cpp
#include <4D7S.h>

int segmentPins[7] = {2, 3, 4, 5, 6, 7, 8};
int digitPins[4]   = {9, 10, 11, 12};
FourDSevenS ekran(segmentPins, digitPins, FourDSevenS::POSITIVE);

void setup() {
  Serial.begin(115200);
  ekran.refresh(50);   // 50 ms yeniləmə
}

void loop() {
  ekran.write_numbers("1234");
  delay(2000);
  ekran.write_numbers("5678");
  delay(2000);
}

#include <4D7S.h>

int segmentPins[7] = {2, 3, 4, 5, 6, 7, 8};
int digitPins[4]   = {9, 10, 11, 12};
FourDSevenS ekran(segmentPins, digitPins, FourDSevenS::NEGATIVE);

void setup() {
  Serial.begin(115200);
  ekran.refresh(100);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    ekran.write_number(i, FourDSevenS::DIGIT_1);
    delay(500);
  }
}


FunksiyaİzahatFourDSevenS(segment[], digit[], type)Obyekt yaradır. type → POSITIVE və ya NEGATIVErefresh(ms)Hər digitin göstərmə vaxtını təyin edirwrite_numbers("1234")4 rəqəmi ard‑arda göstərirwrite_number(rəqəm, digit)Tək rəqəmi müəyyən digiti göstərir

Məsləhətlər

Serial Monitor (115200 baud) aç → debug görəcəksən.
Negativ logic üçün LED‑lər GND‑ə bağlı olmalıdır.



English
Hello!
This library lets you control a 4‑digit 7‑segment display directly with Arduino pins. No extra IC (TM1637, MAX7219, etc.) is required. Just 11 pins (7 segments + 4 digits) are enough to show numbers.
Features

Positive / Negative logic support
Smooth multiplexing
Serial debug output
Simple and clear API


Installation

Download ZIP → Sketch > Include Library > Add .ZIP Library…
or extract to Documents/Arduino/libraries/.
Restart Arduino IDE.
Open File > Examples > 4D7S.


Wiring (example)





































SegmentArduino PinA2B3C4D5E6F7G8

























DigitArduino PinDIG19DIG210DIG311DIG412

Change pins by editing segmentPins[] and digitPins[].


Examples
1. BasicNumbers.ino – Full Number Display
cpp#include <4D7S.h>

int segmentPins[7] = {2, 3, 4, 5, 6, 7, 8};
int digitPins[4]   = {9, 10, 11, 12};
FourDSevenS display(segmentPins, digitPins, FourDSevenS::POSITIVE);

void setup() {
  Serial.begin(115200);
  display.refresh(50);
}

void loop() {
  display.write_numbers("1234");
  delay(2000);
  display.write_numbers("5678");
  delay(2000);
}
2. SingleDigit.ino – Single Digit Test
cpp#include <4D7S.h>

int segmentPins[7] = {2, 3, 4, 5, 6, 7, 8};
int digitPins[4]   = {9, 10, 11, 12};
FourDSevenS display(segmentPins, digitPins, FourDSevenS::NEGATIVE);

void setup() {
  Serial.begin(115200);
  display.refresh(100);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    display.write_number(i, FourDSevenS::DIGIT_1);
    delay(500);
  }
}

Functions

























FunctionDescriptionFourDSevenS(segment[], digit[], type)Creates object. type → POSITIVE or NEGATIVErefresh(ms)Sets refresh time per digitwrite_numbers("1234")Shows 4 digits in sequencewrite_number(num, digit)Shows one number on a specific digit

Tips

Open Serial Monitor (115200 baud) to see debug.
For negative logic, connect LEDs to GND.
