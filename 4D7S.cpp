#include "4D7S.h"
#include <Arduino.h>

FourDSevenS ::FourDSevenS(int segments[], int digits[], int type) {
  Serial.begin(115200);
  _type = type;
  for (int digit = 0; digit < 4; digit++) {
    _digits[digit] = digits[digit];
    pinMode(digits[digit], OUTPUT);
  }
  for (int segment = 0; segment < 7; segment++) {
    _segments[segment] = segments[segment];
    pinMode(segments[segment], OUTPUT);
    digitalWrite(segments[segment], type == NEGATIVE ? HIGH : LOW);  // Acilisda ledleri sondurmek ucun
  }
}
void FourDSevenS::refresh(int time) {
  _time = time;
}
void FourDSevenS ::write_numbers(String fnum) {
  for (int numb = 0; numb < 4; numb++) {
    Serial.println(fnum[numb] - '0');
    _write_one_number(fnum[numb] - '0', numb);
    delay(_time);
  }
}
void FourDSevenS ::_write_one_number(int set_number, int digit) {
  for (int set_digit = 0; set_digit < 4; set_digit++)
    digitalWrite(_digits[set_digit], digit == set_digit ? _type == NEGATIVE ? HIGH : LOW : _type == NEGATIVE ? LOW
                                                                                                             : HIGH);
  for (int number = 0; number < 7; number++) {
    digitalWrite(_segments[number], _type == NEGATIVE ? !_numbers[set_number][number] : _numbers[set_number][number]);
  }
}