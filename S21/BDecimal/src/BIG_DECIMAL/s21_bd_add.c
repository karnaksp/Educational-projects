#include "s21_bd.h"

void s21_bd_add(s21_bd value_1, s21_bd value_2, s21_bd *result) {
  clear_bd(result);
  equal_scale_bd(&value_1, &value_2);
  result->scale = value_1.scale;
  if (value_1.sign == value_2.sign) {  // если знаки одинаковые, то все просто)
    result->sign = value_1.sign;
    for (int i = 0; i < BD_SIZE; i++) {
      result->bits[i] = value_1.bits[i] + value_2.bits[i];
    }
    s21_overflow(result);
  } else {
    if (!s21_bd_is_less_abs(
            value_2, value_1))  // если абсолютное значение второй переменной не
                                // меньше первого то меняем их местами
    {
      s21_bd buff = value_2;
      value_2 = value_1;
      value_1 = buff;
    }
    uint32_t unit = 0;  // займ у старших битов
    for (int i = 0; i < BD_SIZE; i++) {  // Вычитаем из большего (value_1)
      result->bits[i] =
          (__uint32_t)value_1.bits[i] - (__uint32_t)value_2.bits[i] - unit;
      if (value_1.bits[i] - value_2.bits[i] - unit > value_1.bits[i]) {
        unit = 1;
      } else {
        unit = 0;
      }
    }
    if (bd_is_zero(*result)) {
      result->sign = 0;
      result->scale = 0;
    } else {
      result->sign =
          value_1.sign;  // Присваивается знак большего значения (value_1)
    }
  }
}