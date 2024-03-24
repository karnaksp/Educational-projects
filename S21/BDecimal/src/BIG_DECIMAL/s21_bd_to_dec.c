#include "s21_bd.h"
// перевод обычного децимала в расширенный
s21_bd decimal_to_bd(s21_decimal src) {
  s21_bd result;
  clear_bd(&result);
  result.scale = s21_getScale(src);
  result.sign = s21_getSign(src);
  result.bits[0] = src.bits[0];
  result.bits[1] = src.bits[1];
  result.bits[2] = src.bits[2];
  return result;
}

// перевод расширенного децимала в обычный
int bd_to_decimal(s21_bd src, s21_decimal* result) {
  int flag = 0, number = 0, check = 0;
  // флаг для итоговой проверки, number будет хранить остаток
  // чек смотрит были ли отличные от 0 цифры после 5
  s21_bd dec_max = {{0}, 0, 0}, one;
  clear_bd(&one);
  one.bits[0] = 1;
  for (int i = 0; i < D_SIZE - 1; i++) {
    dec_max.bits[i] = UINT_BITS_FULL;
  }
  while (src.scale > 0 && bd_mod_10(src) == 0) {  // отбрасываем незначащие нули
    bd_div_10(&src);
  }
  // уменьшаем наше число до приемлимого скейла
  while (src.scale > 28) {
    number = bd_div_10(&src);
    if (number) {
      check = 1;
    }
  }
  // умеьшаем наше число пока есть скейл и оно больше чем dec_max
  while (src.scale > 0 && s21_bd_is_less_abs(dec_max, src)) {
    number = bd_div_10(&src);
    if (number) {
      check = 1;
    }
  }
  if (number > 5 || (number == 5 && (bd_mod_10(src) % 2 == 1 || check))) {
    one.scale = src.scale;  // меняем последний знак не зависимо от скейла
    one.sign = src.sign;
    s21_bd_add(src, one, &src);
    s21_overflow(&src);
  }
  while (src.scale > 0 &&
         bd_mod_10(src) == 0) {  // отбрасываем незначащие нули после округления
    bd_div_10(&src);
  }
  if (s21_bd_is_less_abs(dec_max, src)) {
    if (src.sign) {
      flag = 2;  // слишком маленькое
    } else {
      flag = 1;  // слишком большое
    }
  } else {
    for (int i = 0; i < 3; i++) {
      result->bits[i] = src.bits[i];
    }
    s21_setScale(result, src.scale);
    s21_setSign(result, src.sign);
  }
  return flag;
}