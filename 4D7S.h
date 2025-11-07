#ifndef __4D7S__
#define __4D7S__
#include <Arduino.h>

// 7 seqmentli 4 rəqəmli displey üçün sinif
class FourDSevenS {
public:
  // Konstruktor: seqment və rəqəm pinlərini, həmçinin bağlantı tipini qəbul edir (default: POSITIVE)
  FourDSevenS(int segments[], int digits[], int type = 0);

  // Rəqəm mövqeləri üçün enum (istifadəçi üçün oxunaqlı adlar)
  enum {
    DIGIT_1,  // Birinci rəqəm (soldan sağa)
    DIGIT_2,  // İkinci rəqəm
    DIGIT_3,  // Üçüncü rəqəm
    DIGIT_4,  // Dördüncü rəqəm
  };

  // Bağlantı tipləri üçün enum
  enum {
    NEGATIVE,  // Ortaq anod (HIGH = söndür, LOW = yandır)
    POSITIVE   // Ortaq katod (HIGH = yandır, LOW = söndür)
  };

  // 4 rəqəmli string-i displeydə göstərir
  void write_numbers(String fnum);

  // Tək rəqəmi müəyyən mövqedə göstərir
  void write_number(int number, int digit);

  // Nömrəni "qutuya" əlavə edir (avtomatik oynatma üçün)
  void add_number(String number);

  // Qutuda neçə nömrə olduğunu qaytarır
  int readBoxIndex();

  // Avtomatik oynatma rejimi: intervala görə nömrələri dəyişir
  void play();

  // Rəqəmlər arası keçid gecikməsini təyin edir (millisaniyə)
  void refresh(int time);

  // Qutunu təmizləyir (bütün nömrələri silir)
  void clear_box();

  // Avtomatik oynatma intervalını təyin edir (millisaniyə)
  void set_interval(long int interval);

private:
  // Nömrələri saxlamaq üçün qutu (maksimum 10000 ədəd)
  String _number_box[10000] = {};

  // Qutudakı nömrələrin sayı (indeks)
  int _box_index = 0;

  // Hazırda göstərilən nömrənin indeksi
  int _current_number = 0;

  // Son dəyişmə vaxtı (millis üçün)
  unsigned long _last_time = 0;

  // Avtomatik oynatma intervalı (millisaniyə, default 1000)
  long int _interval = 1000;

  // Hər rəqəm üçün 7 seqmentin vəziyyəti (1 = yanır, 0 = sönür)
  int _numbers[10][7] = {
    { 1, 1, 1, 1, 1, 1, 0 },  // 0 — a,b,c,d,e,f seqmentləri yanır
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

  // Daxili funksiya: tək rəqəmi göstərir
  void _write_one_number(int set_number, int digit);

  // Rəqəm pinləri (digit selection)
  int _digits[4] = {};

  // Seqment pinləri (a, b, c, d, e, f, g)
  int _segments[7] = {};

  // Bağlantı tipi (NEGATIVE və ya POSITIVE)
  int _type = 0;

  // Rəqəmlər arası keçid üçün gecikmə (millisaniyə)
  int _time = 0;
};
#endif