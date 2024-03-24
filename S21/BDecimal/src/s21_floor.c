#include "s21_suppl.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int calc_status = CALC_OK;

// инициализируем переменную как новое десятичное число, значение-0 скейл-0
  for (int i = 0; i < D_SIZE; i++) {
    result->bits[i] = 0;
  }
// получаем знак
  int sign = s21_getSign(value);
// если скейл больше 28, до свиданья!
  if (s21_getScale(value) > 28) {
    calc_status = CALC_ERR;
// если скейл не равен 0, проверяем знак
    } else if (s21_getScale(value) != 0) {
    if (sign == SIGN_BIT) {
      calc_status = s21_truncate(value, result);
// если отрицательное - вычитаем 1 из числа value, обрезаем value - 1 с сохранением знака
    } else {
      s21_decimal minus = {{1, 0, 0, 0}};
      s21_decimal buf;
      calc_status = s21_truncate(value, &buf);
      calc_status = s21_sub(buf, minus, result);
    }
// число итак целое
  } else {
    *result = value;
  }

  return calc_status;
}