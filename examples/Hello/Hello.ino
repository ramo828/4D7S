#include "4D7S.h"

// 7 seqment displeyin seqment pinləri (fiziki pin nömrələri ilə əlaqəli şərhlər)
// Hər bir #define fiziki pin nömrəsini göstərir (məsələn: A = 4 → fiziki pin 11)
#define A 4    // Fiziki pin 11 → a seqmenti
#define B 5    // Fiziki pin 7  → b seqmenti
#define C 6    // Fiziki pin 4  → c seqmenti
#define D 7    // Fiziki pin 2  → d seqmenti
#define E 15   // Fiziki pin 1  → e seqmenti
#define F 16   // Fiziki pin 10 → f seqmenti
#define G 17   // Fiziki pin 5  → g seqmenti

// Rəqəm (digit) seçim pinləri
#define DIGIT1 18  // Fiziki pin 12 → 1-ci rəqəm (soldan sağa)
#define DIGIT2 8   // Fiziki pin 9  → 2-ci rəqəm
#define DIGIT3 3   // Fiziki pin 8  → 3-cü rəqəm
#define DIGIT4 46  // Fiziki pin 6  → 4-cü rəqəm

// Seqment pinlərini massivdə topla (a, b, c, d, e, f, g)
int segments[] = { A, B, C, D, E, F, G };

// Rəqəm pinlərini massivdə topla (1, 2, 3, 4)
int digits[] = { DIGIT1, DIGIT2, DIGIT3, DIGIT4 };

// Displey obyekti: ortaqlıq anodu (NEGATIVE) olan displey üçün
FourDSevenS disp = FourDSevenS(segments, digits, FourDSevenS::NEGATIVE);

void setup() {
  // Hər rəqəm arası keçid üçün 5 millisaniyə gecikmə təyin et
  // Bu, displeyin titrəməməsi üçün kifayət qədər sürətli yenilənməni təmin edir
  disp.refresh(5);
}

void loop() {
  // Displeydə daimi olaraq "1994" nömrəsini göstər
  // Hər dəfə loop() çağırıldıqda yenidən yazılır (multiplexing ilə)
  disp.write_numbers("1994");
}
