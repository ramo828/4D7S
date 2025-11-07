#include "4D7S.h"
#include <Arduino.h>

// Konstruktor: 7 seqmentli displeyin pinlərini təyin edir
FourDSevenS ::FourDSevenS(int segments[], int digits[], int type) {
  _type = type;                              // Displey tipi: NEGATIVE (ortaq anod) və ya POZITIVE (ortaq katod)
  for (int digit = 0; digit < 4; digit++) {  // Hər rəqəm (digit) üçün
    _digits[digit] = digits[digit];          // Rəqəm pinlərini saxla
    pinMode(digits[digit], OUTPUT);          // Pinləri çıxış olaraq təyin et
  }
  for (int segment = 0; segment < 7; segment++) {                    // Hər seqment üçün
    _segments[segment] = segments[segment];                          // Seqment pinlərini saxla
    pinMode(segments[segment], OUTPUT);                              // Pinləri çıxış olaraq təyin et
    digitalWrite(segments[segment], type == NEGATIVE ? HIGH : LOW);  // Başlanğıcda LED-ləri söndür (tipə görə)
  }
}

// Yeniləmə vaxtını təyin edir (rəqəmlər arası keçid gecikməsi)
void FourDSevenS::refresh(int time) {
  _time = time;  // Gecikmə müddətini saxla
}

// Verilən 4 rəqəmli string-i displeydə göstərir
void FourDSevenS ::write_numbers(String fnum) {
  for (int numb = 0; numb < 4; numb++) {        // Hər rəqəm üçün
    _write_one_number(fnum[numb] - '0', numb);  // Rəqəmi ASCII-dən ədədə çevirib göstər
    delay(_time);                               // Rəqəmlər arası keçid üçün gözlə
  }
}

// Tək bir rəqəmi müəyyən digitdə göstərir
void FourDSevenS ::_write_one_number(int set_number, int digit) {
  for (int set_digit = 0; set_digit < 4; set_digit++)  // Bütün digitləri idarə et
    digitalWrite(_digits[set_digit], digit == set_digit ? (_type == NEGATIVE ? HIGH : LOW) : (_type == NEGATIVE ? LOW : HIGH));
  // Cari digiti aktivləşdir, qalanlarını deaktiv et (tipə görə)
  for (int number = 0; number < 7; number++) {  // 7 seqment üçün
    digitalWrite(_segments[number], _type == NEGATIVE ? !_numbers[set_number][number] : _numbers[set_number][number]);
    // Rəqəmə uyğun seqmentləri yandır/söndür (məntiq tipə görə tərsinə çevrilir)
  }
}

// Qutudakı nömrələrin sayını qaytarır
int FourDSevenS::readBoxIndex() {
  return _box_index;  // Hazırda saxlanılan nömrələrin sayını qaytar
}

// Yeni nömrəni qutuya əlavə edir
void FourDSevenS::add_number(String number) {
  _number_box[_box_index] = number;  // Nömrəni massivə əlavə et
  _box_index++;                      // İndeksi artır
}

// Avtomatik rejimdə nömrələri dəyişərək göstərir
void FourDSevenS::play() {
  unsigned long nowTime = millis();                        // Cari vaxtı al
  if (nowTime - _last_time >= _interval) {                 // Müəyyən interval keçibsə
    _last_time = nowTime;                                  // Son vaxtı yenilə
    _current_number = (_current_number + 1) % _box_index;  // Növbəti nömrəyə keç (dövrəvi)
  }
  write_numbers(_number_box[_current_number]);  // Cari nömrəni göstər
}

// Qutunu təmizləyir (bütün nömrələri silir)
void FourDSevenS::clear_box() {
  _box_index = 0;  // İndeksi sıfırla
}

// Avtomatik dəyişmə intervalını təyin edir
void FourDSevenS::set_interval(long int interval) {
  _interval = interval;  // Interval dəyərini saxla
}

// Tək bir rəqəmi müəyyən digitdə göstərir (xarici istifadə üçün)
void FourDSevenS::write_number(int number, int digit) {
  _write_one_number(number, digit);  // Daxili funksiyanı çağır
  delay(_time);                      // Gecikmə əlavə et
}