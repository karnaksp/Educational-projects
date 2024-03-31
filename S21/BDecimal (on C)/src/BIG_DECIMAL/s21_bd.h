#ifndef _S21_BD_
#define _S21_BD_

#include "../s21_decimal.h"
#include "../s21_suppl.h"
#define BD_SIZE 8
#define UINT_BITS_FULL 0xffffffff
#define _UINT64_BITS_FIRST 0xffffffff00000000

typedef struct {
  uint64_t bits[BD_SIZE];
  uint16_t scale;
  char sign;
} s21_bd;

s21_bd decimal_to_bd(s21_decimal src);
void s21_overflow(s21_bd *src);
void clear_bd(s21_bd *src);
void mul_bd_10(s21_bd *value);
void equal_scale_bd(s21_bd *value_1, s21_bd *value_2);
int s21_bd_is_less_abs(s21_bd value_1, s21_bd value_2);
void s21_bd_abs_value(s21_bd *src);
int bd_is_zero(s21_bd value);
uint64_t bd_div_10(s21_bd *value);
uint64_t bd_mod_10(s21_bd value);
void s21_bd_add(s21_bd value_1, s21_bd value_2, s21_bd *result);
int bd_to_decimal(s21_bd src, s21_decimal *result);
void s21_bdMicroSub(s21_bd bd_a, s21_bd bd_b, s21_bd *bd_x);
void s21_bdMicroMul(s21_bd bd_a, s21_bd bd_b, s21_bd *bd_x);
s21_bd s21_bdMicroDiv(s21_bd bd_a, s21_bd bd_b, s21_bd *bd_x);
void s21_bdTenDiv(s21_bd bd_a, s21_bd bd_b, s21_bd *bd_x);
void s21_bdDiv(s21_bd bd_a, s21_bd bd_b, s21_bd *bd_x);
int s21_lastBit(s21_bd a);
int s21_isEqualBd(s21_bd value_1, s21_bd value_2);
int s21_isLessBd(s21_bd value_1, s21_bd value_2);
int s21_isLessOrEqualBd(s21_bd value_1, s21_bd value_2);

#endif