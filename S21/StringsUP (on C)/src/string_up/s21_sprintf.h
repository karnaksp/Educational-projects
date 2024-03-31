#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <assert.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>

typedef struct flags {
  int type;       // тип спецификатора
  int alignment;  // 1 - Выравнивание по левому краю, 0 - Выравнивание по
                  // правому краю
  int showSign;  // 1 - Выводить знак (+ или -) даже для положительных чисел
  int spaceBeforePositive;  // 1 - Вставлять пробел перед положительными числами
  int alternateForm;  // 1 - Использовать альтернативную форму вывода
  int zeroPadding;  // 1 - Заполнять нулями вместо пробелов при указании ширины
  int width;        // Ширина (число)
  int dynamicWidth;  // 1 - Использовать динамическую ширину через звездочку
  int precision;     // Значение точности
  int lengthModifier;  // Модификатор длины аргумента
  int error;           // Флаг ошибки форматирования
  int uppercase;  // 1 - Использовать прописные буквы (для шестнадцатеричных
                  // форматов)
  int is_format;  // Флаг указывающий на то, что текущий символ является
                  // форматом
  long char_count;    // Счетчик символов
  int is_suppressed;  // Флаг указывающий на игнорирование присваивания (*)
  int length;         // Модификатор длины
  char buffer;  // Буфер для хранения символов формата
  int firstSpace;    // Пробелы в начале строки
  int unformatting;  // Неформаные символы, которые пропускаются и не идут в
                     // счет
} FormatFlags;

typedef unsigned long s21_size_t;

FormatFlags s21_init_flags(void);
int s21_sprintf(char *str, const char *format, ...);
int s21_read_str(char *str, const char *format, va_list args);
int s21_citoa(long long int num, char *str);
char *s21_ffcvt(double value, int ndigit, int *decpt, int *sign);
void s21_fcvt(long double b, FormatFlags *flags, int length_int, char *temp);
int s21_unsigned_itoa(unsigned long long int num, char *str);

int s21_translateSpecifier(char specifier, FormatFlags *flags, va_list args,
                           char *str);
void s21_read_flags(const char *format, int *i, FormatFlags *flags,
                    va_list args);
int s21_check_flags(FormatFlags *flags);
int s21_is_digit(int c);
int s21_specifier(int c);
void s21_specifier_upper(FormatFlags *flags);
int s21_get_number(const char *format, int *i);
void s21_creverse_string(char *str, int count);
int s21_fillWidth(int width, int length, int hasZeroFill, char *str);
int s21_appendCharToStr(char c, char *str);
void s21_appendCharSignToStr(FormatFlags *flags, int is_Negative, char *str);
int s21_getLengthofNumber(long long int n);
void s21_strUpdate(long long int u, char *str);
void s21_processFormattingFlags_u_d_i(long int u, FormatFlags *flags,
                                      char *str);
void s21_charStrloop1(int arg1, long long int arg2, int arg3, int *i, char fill,
                      char *str);
void s21_charStrloop2(int arg1, long long int arg2, int *i, char fill,
                      char *str);
void s21_charStrloop3(int arg1, int arg2, int arg3, int *i, char fill,
                      char *str);
char *s21_convertToBase(unsigned long long num, FormatFlags *flags);
void s21_concatPartsOfMantissa(char *final_str, char *left_part,
                               char *right_part, char *right_mantissa_part,
                               FormatFlags flags, int is_negative, int length);
void s21_rightMantissaPart(char *right_mantissa_part, char letter, int e);
int s21_lengthWithoutWidth(FormatFlags flags, int is_negative, int e);
int s21_createPartWithoutMantissa(char *right_part, long double right_digits,
                                  int precision, FormatFlags *flags);
unsigned long long s21_convertDoubleToLong(long double digits, int precision);
int s21_convertToMantissa(long double *number, int precision);

int s21_sprintf_u_d_i(va_list args, FormatFlags *flags, char *str);
int s21_sprintf_x(unsigned long c, char specifier, FormatFlags *flags,
                  char *str);
int s21_sprintf_o(unsigned long c, FormatFlags *flags, char *str);
int s21_sprintf_nan_inf(FormatFlags *flags, char *str, int nan,
                        int is_negative);
int s21_sprintf_e(long double number, int letter_flag, FormatFlags *flags,
                  char *str);
int s21_sprintf_f(long double number, FormatFlags *flags, char *str);
int s21_sprintf_g(long double b, FormatFlags *flags, char *str);

int s21_handleCharSpecifier(int value, FormatFlags *flags, char *str);
int s21_handleStringSpecifier(char *value, FormatFlags *flags, char *str);
int s21_handleIntegerSpecifier(va_list args, FormatFlags *flags, char *str);
int s21_handlePointerSpecifier(void *ptr, FormatFlags *flags, char *str);
int s21_handleUnsignedSpecifier(va_list args, char specifier,
                                FormatFlags *flags, char *str);
int s21_handlePercentSpecifier(FormatFlags *flags, char *str);
int s21_handleFloatSpecifier(va_list args, char specifier, FormatFlags *flags,
                             char *str);
void s21_handleNumSpecifier(int i, va_list args);

#include "s21_string.h"
#endif  // S21_SPRINTF_H
