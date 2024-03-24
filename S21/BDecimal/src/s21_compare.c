#include "s21_suppl.h"

int s21_is_equal(s21_decimal a, s21_decimal b) {
  int isEqual = 1;
  int is_overflow = s21_normalize(&a, &b);
  if (!is_overflow) {
    for (int i = 0; i < 3 && isEqual; i++) {
      if ((a.bits[i] ^ b.bits[i])) {
        isEqual = 0;
      }
    }
  } else
    isEqual = 0;
  return isEqual;
}

int s21_is_not_equal(s21_decimal a, s21_decimal b) {
  return !s21_is_equal(a, b);
}

int s21_is_less(s21_decimal a, s21_decimal b) {
  int flag = 0;
  int is_overflow = s21_normalize(&a, &b);
  s21_decimal const zero = {0};
  if (s21_is_equal(a, zero) && s21_is_equal(b, zero)) {
    flag = 0;
  } else if (!is_overflow) {
    if (s21_getSign(a) > s21_getSign(b)) {
      flag = 1;
    } else if (s21_getSign(a) == s21_getSign(b)) {
      int i = 96;
      while (((S21_GET_BIT(a, i, s21_decimal)) ==
              (S21_GET_BIT(b, i, s21_decimal))) &&
             i != 0) {
        i--;
      }
      if ((S21_GET_BIT(a, i, s21_decimal)) < (S21_GET_BIT(b, i, s21_decimal))) {
        flag = 1;
      }
      if (s21_getSign(a)) {
        flag = !flag;
      }
    } else {
      flag = 0;
    }
  } else if (s21_getScale(a) > s21_getScale(b)) {
    flag = 1;
  } else {
    flag = 0;
  }
  return flag;
}

int s21_is_less_or_equal(s21_decimal a, s21_decimal b) {
  return (!s21_is_greater(a, b));
}

int s21_is_greater(s21_decimal a, s21_decimal b) {
  return (!s21_is_less(a, b) && s21_is_not_equal(a, b));
}

int s21_is_greater_or_equal(s21_decimal a, s21_decimal b) {
  return (!s21_is_less(a, b));
}
