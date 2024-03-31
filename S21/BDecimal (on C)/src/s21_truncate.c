#include "./BIG_DECIMAL/s21_bd.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int calc_status = CALC_OK;
  // for (int i = 0; i < D_SIZE; i++) {
  //   result->bits[i] = 0;
  // }
  int scale = s21_getScale(value);
  if (scale > 28)
    calc_status = CALC_ERR;
  else if (scale > 0) {
    s21_setScale(&value, 28);
    for (int i = 0; i < scale; i++) {
    s21_div(value, (s21_decimal){{10, 0, 0, 0}}, &value);   
    }
    S21_COPY(value, *result, s21_decimal);
    s21_setScale(result, 0);
    //s21_setSign(result, s21_getSign(value));
  } else {
    *result = value;
  }

  return calc_status;
}