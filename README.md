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



# 4D7S – 4-Digit 7-Segment Display Library

---

## English

Hello!  
This library allows you to control a **4-digit 7-segment display** **directly using Arduino pins**. No extra IC (TM1637, MAX7219, etc.) is required. Just **11 pins** (7 segments + 4 digits) are enough to display numbers.

### Features
- Positive / Negative logic support  
- Smooth multiplexing  
- Serial debug output  
- Simple and clear API  

---

### Installation
1. Download the **ZIP** file → `Sketch > Include Library > Add .ZIP Library…`  
   or extract to `Documents/Arduino/libraries/`.  
2. **Restart** the Arduino IDE.  
3. Open examples via `File > Examples > 4D7S`.

---

### Wiring (Example)

#### Segment Pins
| Segment | Arduino Pin |
|---------|-------------|
| A       | 2           |
| B       | 3           |
| C       | 4           |
| D       | 5           |
| E       | 6           |
| F       | 7           |
| G       | 8           |

#### Digit Pins
| Digit  | Arduino Pin |
|--------|-------------|
| DIG1   | 9           |
| DIG2   | 10          |
| DIG3   | 11          |
| DIG4   | 12          |

> **Note:** You can change pins by editing the `segmentPins[]` and `digitPins[]` arrays.

---

### Examples

#### 1. `BasicNumbers.ino` – Full Number Display
```cpp
#include <4D7S.h>

int segmentPins[7] = {2, 3, 4, 5, 6, 7, 8};
int digitPins[4]   = {9, 10, 11, 12};
FourDSevenS display(segmentPins, digitPins, FourDSevenS::POSITIVE);

void setup() {
  Serial.begin(115200);
  display.refresh(50);   // 50 ms refresh per digit
}

void loop() {
  display.write_numbers("1234");
  delay(2000);
  display.write_numbers("5678");
  delay(2000);
}


#include <4D7S.h>

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