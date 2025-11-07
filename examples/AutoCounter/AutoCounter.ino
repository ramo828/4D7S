#include "4D7S.h"

// Seqment pinləri (a, b, c, d, e, f, g)
#define A 4   // a seqmenti
#define B 5   // b seqmenti
#define C 6   // c seqmenti
#define D 7   // d seqmenti
#define E 15  // e seqmenti
#define F 16  // f seqmenti
#define G 17  // g seqmenti

// Rəqəm (digit) pinləri
#define DIGIT1 18  // Birinci rəqəm (soldan)
#define DIGIT2 8   // İkinci rəqəm
#define DIGIT3 3   // Üçüncü rəqəm
#define DIGIT4 46  // Dördüncü rəqəm

// Seqment və rəqəm pinlərini massivdə topla
int segments[] = { A, B, C, D, E, F, G };           // 7 seqmentin pinləri
int digits[] = { DIGIT1, DIGIT2, DIGIT3, DIGIT4 };  // 4 rəqəmin pinləri

// Displey obyekti: NEGATIVE (ortaq anod) tipində
FourDSevenS disp = FourDSevenS(segments, digits, FourDSevenS::NEGATIVE);

void setup() {
  Serial.begin(115200);    // Serial monitoru başlat (115200 baud)
  disp.refresh(1);         // Hər rəqəm arası keçid 1ms olsun (çox sürətli yeniləmə)
  disp.set_interval(100);  // Hər 100ms-də bir nömrə dəyişsin (avtomatik oynatma)

  disp.clear_box();  // Əvvəlki nömrələri sil (təmiz başla)

  // 0000 - 9999 arası bütün 4 rəqəmli nömrələri qutuya əlavə et
  for (int i = 0; i <= 9999; i++) {
    char num[5];                   // 4 rəqəm + null sonu üçün buffer
    sprintf(num, "%04d", i);       // i-ni 4 rəqəmli formata çevir (məsələn: 0001)
    disp.add_number(String(num));  // String-ə çevirib qutuya əlavə et
  }
}

void loop() {
  disp.play();  // Avtomatik oynatma: hər 100ms-də nömrəni dəyiş və göstər
}
