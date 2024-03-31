#include "s21_suppl.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int calc_err = CALC_OK;

  for (int i = 0; i < D_SIZE; i++) {
    result->bits[i] = 0;
  }

  if (s21_getScale(value) <= 28) {
    if (s21_getSign(value) == 0) {
      value.bits[3] |= MINUS_MASK;
    } else {
      value.bits[3] &= PLUS_MASK;
    }
    *result = value;
  } else {
    calc_err = CALC_ERR;
  }
  return calc_err;
}