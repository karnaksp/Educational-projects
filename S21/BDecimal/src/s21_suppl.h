#ifndef S21_SUPPL_H
#define S21_SUPPL_H

#include <limits.h>
#include <math.h>
#include <stdlib.h>

#include "s21_decimal.h"

//? ************ Supplementary variables declaration ************ ?//

#define MAX_INT_BITS 32
#define D_SIZE 4
#define BD_SIZE 8
#define SIGN_BIT 127
#define OK 0
#define FAIL 1
#define LAST_BIT_MANTISSA 96
#define MINUS 2147483648

#define DEC_MAX(value)                                             \
  ((value.bits[0] == 0xFFFFFFFF && value.bits[1] == 0xFFFFFFFF) && \
   value.bits[2] == 0xFFFFFFFF)

#define DEC_ZERO(value) ((!value.bits[0] && !value.bits[1]) && !value.bits[2])

// corrietr +
#define PLUS_MASK (int)0x7FFFFFFF   // 01111111111111111111111111111111
#define MINUS_MASK (int)0x80000000  // 10000000000000000000000000000000
#define UNSIGNED_MAX 4294967296
// corrietr -

//? ************ Supplementary structures declaration ************ ?//

enum { LOW, MID, HIGH, SCALE };
typedef enum { CALC_OK, CALC_ERR } CalcErr;

typedef union {
  float float_number;
  int int_number;
  struct {
    unsigned int fraction : 23;
    unsigned int exponenta : 8;
    unsigned int sign : 1;
  } parts;
} float_cast;

// ? ************ Def dec-bd chenged functions ************ ? //

// Определение макроса для функции определения размера массива bits в структуре
// struct_type
#define S21_BITS_SIZE(struct_type) \
  ((sizeof(struct_type) > MAX_INT_BITS) ? BD_SIZE : D_SIZE)

// Определение макроса для взятия бита
#define S21_GET_BIT(value, index, struct_type)                              \
  ((BD_SIZE) * (S21_BITS_SIZE(struct_type)) != MAX_INT_BITS                 \
       ? (((value).bits[(index) / (sizeof((value).bits[0]) * CHAR_BIT)] &   \
           (1lu << ((index) % (sizeof((value).bits[0]) * CHAR_BIT)))) != 0) \
       : (((value).bits[(index) / (sizeof((value).bits[0]) * CHAR_BIT)] &   \
           (1u << ((index) % (sizeof((value).bits[0]) * CHAR_BIT)))) != 0))

// Определение макроса для установки бита
#define S21_SET_BIT(value, index, bit, struct_type)                 \
  do {                                                              \
    const int _bit_size = (BD_SIZE) * (S21_BITS_SIZE(struct_type)); \
    const int _i = (index) / _bit_size;                             \
    const unsigned long _bit_mask =                                 \
        (_bit_size != MAX_INT_BITS) ? (1lu) : (1u);                 \
    const unsigned long _bit_shift = (index) % (_bit_size);         \
    if ((bit) == 1)                                                 \
      (value)->bits[_i] |= (_bit_mask << _bit_shift);               \
    else                                                            \
      (value)->bits[_i] &= ~(_bit_mask << _bit_shift);              \
  } while (0)

// Определение макроса для функции сдвига влево
#define S21_SHIFT_LEFT(value, position, shifted, struct_type)                \
  do {                                                                       \
    int _max_bit =                                                           \
        (BD_SIZE) * (S21_BITS_SIZE(struct_type)) != MAX_INT_BITS ? 512 : 96; \
    if (!S21_GET_BIT((*value), _max_bit, struct_type)) {                     \
      for (int i = _max_bit; i > 0; i--) {                                   \
        S21_SET_BIT((value), i, S21_GET_BIT((*value), i - 1, struct_type),   \
                    struct_type);                                            \
      }                                                                      \
      S21_SET_BIT((value), 0, 0, struct_type);                               \
    }                                                                        \
  } while (0)

// Определение макроса для функции сдвига вправо
#define S21_SHIFT_RIGHT(value, position, shifted, struct_type)               \
  do {                                                                       \
    int _max_bit =                                                           \
        (BD_SIZE) * (S21_BITS_SIZE(struct_type)) != MAX_INT_BITS ? 512 : 96; \
    if (!S21_GET_BIT((*value), 0, struct_type)) {                            \
      for (int i = 0; i < _max_bit; i++) {                                   \
        S21_SET_BIT((value), i, S21_GET_BIT((*value), i + 1, struct_type),   \
                    struct_type);                                            \
      }                                                                      \
      S21_SET_BIT((value), _max_bit, 0, struct_type);                        \
    }                                                                        \
  } while (0)

// Определение макроса для функции копирования структур
#define S21_COPY(source, destination, struct_type)                       \
  do {                                                                   \
    int _bits = (sizeof(struct_type) > MAX_INT_BITS) ? BD_SIZE : D_SIZE; \
    for (int i = 0; i < _bits; ++i) {                                    \
      (destination).bits[i] = (source).bits[i];                          \
    }                                                                    \
  } while (0)

// Определение макроса для функции определения знака в структуре биг децимал
#define S21_SET_SIGN(result, sign1, sign2)        \
  do {                                            \
    (result).sign = ((sign1) == (sign2)) ? 0 : 1; \
  } while (0)

//? ************ Supplementary functions declaration ************ ?//

int s21_getSign(s21_decimal value);
int s21_getScale(s21_decimal value);
void s21_setSign(s21_decimal *value, int bit);
void s21_setScale(s21_decimal *value, int scale);
int s21_normalize(s21_decimal *value_1, s21_decimal *value_2);
void s21_multiplyBy10(s21_decimal *value);
void s21_microAdd(s21_decimal value_1, s21_decimal value_2,
                  s21_decimal *result);

int s21_decIsZero(s21_decimal a);
int is_nan_or_inf(int n);
int get_float_exponent(int number);
int count_digits_in_int(float n);
int get_last_digit_of_integer_part(float n);

#endif  // S21_SUPPL_H
