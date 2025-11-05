#include "4D7S.h"
#define A 4   // 11
#define B 5   // 7
#define C 6   // 4
#define D 7   // 2
#define E 15  // 1
#define F 16  // 10
#define G 17  // 5

#define DIGIT1 18  // 12
#define DIGIT2 8   // 9
#define DIGIT3 3   // 8
#define DIGIT4 46  // 6

int segments[] = { A, B, C, D, E, F, G };
int digits[] = { DIGIT1, DIGIT2, DIGIT3, DIGIT4 };
FourDSevenS disp = FourDSevenS(segments, digits);

void setup() {
  disp.refresh(5);
}

void loop() {
  disp.write_numbers("1994");
}
