#ifndef __4D7S__
#define __4D7S__
#include <Arduino.h>
class FourDSevenS {
public:
  FourDSevenS(int segments[], int digits[], int type = 0);
  void write_numbers(String fnum);
  void refresh(int time);
private:
  int _numbers[10][7] = {
    { 1, 1, 1, 1, 1, 1, 0 },  // 0
    { 0, 1, 1, 0, 0, 0, 0 },  // 1
    { 1, 1, 0, 1, 1, 0, 1 },  // 2
    { 1, 1, 1, 1, 0, 0, 1 },  // 3
    { 0, 1, 1, 0, 0, 1, 1 },  // 4
    { 1, 0, 1, 1, 0, 1, 1 },  // 5
    { 1, 0, 1, 1, 1, 1, 1 },  // 6
    { 1, 1, 1, 0, 0, 0, 0 },  // 7
    { 1, 1, 1, 1, 1, 1, 1 },  // 8
    { 1, 1, 1, 1, 0, 1, 1 },  // 9
  };

  enum {
    DIGIT_1,
    DIGIT_2,
    DIGIT_3,
    DIGIT_4,
  };
  enum {
    NEGATIVE,
    POSITIVE
  };

  void _write_one_number(int set_number, int digit);
  int _digits[4] = {};
  int _segments[7] = {};
  int _type = 0;
  int _time = 0;
};
#endif