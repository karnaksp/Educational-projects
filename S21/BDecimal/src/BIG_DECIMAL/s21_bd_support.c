#include "s21_bd.h"
// переносим переполнение в старшие биты
void s21_overflow(s21_bd *src) {
  uint32_t overflow = 0;
  for (int i = 0; i < BD_SIZE; i++) {
    src->bits[i] += overflow;
    overflow = src->bits[i] >> 32;
    src->bits[i] &= UINT_BITS_FULL;
  }
}
// чистим структуру
void clear_bd(s21_bd *src) {
  src->scale = 0;
  src->sign = 0;
  for (int i = 0; i < BD_SIZE; i++) {
    src->bits[i] = 0;
  }
}

// домножает структуру на 10 не меняя scale
void mul_bd_10(s21_bd *value) {
  for (int i = 0; i < BD_SIZE; i++) {
    value->bits[i] *= 10;
  }
  s21_overflow(value);
}

// приводим нашу структуру к единому scale
void equal_scale_bd(s21_bd *bd_a, s21_bd *bd_b) {
  if (bd_a->scale < bd_b->scale) {
    while (bd_a->scale < bd_b->scale) {
      mul_bd_10(bd_a);
      bd_a->scale++;
    }
  } else if (bd_a->scale > bd_b->scale) {
    while (bd_a->scale > bd_b->scale) {
      mul_bd_10(bd_b);
      bd_b->scale++;
    }
  }
}
// модуль биг децимала
// void s21_bd_abs_value(s21_bd *src) { src->sign = 0; }

int s21_bd_is_less_abs(s21_bd bd_a, s21_bd bd_b) {
  int res = 0;
  int i = BD_SIZE - 1;
  for (; i > 0 && bd_a.bits[i] == bd_b.bits[i];) {
    i--;
  }
  if ((bd_a.bits[i] < bd_b.bits[i])) {
    res = 1;
  }
  return res;
}

int bd_is_zero(s21_bd value) {
  int res = 1;
  for (int i = 0; i < BD_SIZE; i++) {
    if (value.bits[i] != 0) {
      res = 0;
    }
  }
  return res;
}

// делим биг децимал на 10 и возвращаем остаток
uint64_t bd_div_10(s21_bd *value) {
  uint64_t remainder = 0;
  if (bd_is_zero(*value)) {
    // Если число 0, тогда ничего не делаем
    value->scale = 0;
  } else {
    value->scale--;
    for (int i = BD_SIZE - 1; i >= 0; i--) {
      value->bits[i] += remainder << 32;
      remainder = value->bits[i] % 10;
      value->bits[i] /= 10;
    }
  }
  return remainder;
}

// возвращаем остаток не меняя value во внешних функциях
uint64_t bd_mod_10(s21_bd value) {
  uint64_t remainder = 0;
  for (int i = BD_SIZE - 1; i >= 0; i--) {
    value.bits[i] += remainder << 32;
    remainder = value.bits[i] % 10;
    value.bits[i] /= 10;
  }
  return remainder;
}

int s21_lastBit(s21_bd value) {
  int last_bit = 512;
  while (last_bit >= 0) {
    if (S21_GET_BIT(value, last_bit, s21_bd)) {
      break;
    }
    last_bit--;
  }
  return last_bit;
}

int s21_isEqualBd(s21_bd bd_a, s21_bd bd_b) {
  int result = 1, isZero = 1;
  for (int i = 512; i >= 0; i--) {
    if (S21_GET_BIT(bd_a, i, s21_bd) != S21_GET_BIT(bd_b, i, s21_bd))
      result = 0;
    if (isZero &&
        (S21_GET_BIT(bd_a, i, s21_bd) || S21_GET_BIT(bd_b, i, s21_bd)))
      isZero = 0;
  }
  if (bd_a.sign != bd_b.sign) {
    if (!isZero)
      result = 0;
    else
      result = 1;
  }
  return result;
}

int s21_isLessBd(s21_bd bd_a, s21_bd bd_b) {
  int result = 1, flag = 0;
  if (s21_isEqualBd(bd_a, bd_b) || (!bd_a.sign && bd_b.sign)) {
    result = 0;
  } else if (bd_a.sign == bd_b.sign) {
    for (int i = 512; i >= 0 && flag == 0; i--) {
      int bit_1 = S21_GET_BIT(bd_a, i, s21_bd);
      int bit_2 = S21_GET_BIT(bd_b, i, s21_bd);
      if (bit_1 > bit_2) {
        result = 0;
        flag = 1;
      } else if (bit_2 > bit_1) {
        result = 1;
        flag = 1;
      }
    }
    if ((bd_a.sign && bd_b.sign)) {
      if (result)
        result = 0;
      else
        result = 1;
    }
  }
  return result;
}

int s21_isLessOrEqualBd(s21_bd bd_a, s21_bd bd_b) {
  return (s21_isEqualBd(bd_a, bd_b) == 1 || s21_isLessBd(bd_a, bd_b) == 1) ? 1
                                                                           : 0;
}

void s21_bdDiv(s21_bd bd_a, s21_bd bd_b, s21_bd *bd_x) {
  clear_bd(bd_x);
  equal_scale_bd(&bd_a, &bd_b);
  s21_bdTenDiv(bd_a, bd_b, bd_x);
  S21_SET_SIGN(*bd_x, bd_a.sign, bd_b.sign);
}

void s21_bdTenDiv(s21_bd bd_a, s21_bd bd_b, s21_bd *bd_x) {
  s21_bd ten = {{10}, 0, 0};
  s21_bd tmp = {0};
  int tempPower = 0;
  s21_bd mod = s21_bdMicroDiv(bd_a, bd_b, bd_x);
  while (s21_lastBit(mod) > -1 && tempPower != 27) {
    tempPower++;
    s21_bdMicroMul(*bd_x, ten, bd_x);
    s21_bdMicroMul(mod, ten, &mod);
    if (s21_isLessOrEqualBd(bd_b, mod)) {
      mod = s21_bdMicroDiv(mod, bd_b, &tmp);
      s21_bd_add(*bd_x, tmp, bd_x);
    }
  }
  if (tempPower > bd_a.scale) {
    bd_x->scale = tempPower;
  } else {
    bd_x->scale = bd_a.scale;
  }
}

s21_bd s21_bdMicroDiv(s21_bd bd_a, s21_bd bd_b, s21_bd *bd_x) {
  clear_bd(bd_x);
  s21_bd tmp = {0};
  int last_bit_a = s21_lastBit(bd_a);  // ? +1
  // "Умножение и вычитание":
  for (int i = last_bit_a; i >= 0; i--) {
    S21_SET_BIT(&tmp, 0, S21_GET_BIT(bd_a, i, s21_bd), s21_bd);
    if (s21_isLessOrEqualBd(bd_b, tmp)) {
      s21_bdMicroSub(tmp, bd_b, &tmp);
      S21_SET_BIT(bd_x, 0, 1, s21_bd);
    } else {
      S21_SET_BIT(bd_x, 0, 0, s21_bd);
    }
    S21_SHIFT_LEFT(bd_x, 1, bd_x, s21_bd);
    S21_SHIFT_LEFT(&tmp, 1, &tmp, s21_bd);
  }
  S21_SHIFT_RIGHT(&tmp, 1, &tmp, s21_bd);
  S21_SHIFT_RIGHT(bd_x, 1, bd_x, s21_bd);
  return tmp;
}

void s21_bdMicroMul(s21_bd bd_a, s21_bd bd_b, s21_bd *bd_x) {
  clear_bd(bd_x);
  int flag = 0;
  int num = 0;
  // "Умножение младших разрядов":
  for (int i = 0; i < 512 && !flag; i++) {
    if (S21_GET_BIT(bd_b, i, s21_bd)) {
      for (int j = 0; j < i - num; j++) {
        S21_SHIFT_LEFT(&bd_a, 1, &bd_a, s21_bd);
        flag = S21_GET_BIT(bd_a, 0, s21_bd);
      }
      s21_bd_add(bd_a, *bd_x, bd_x);
      num = i;
    }
  }
}

void s21_bdMicroSub(s21_bd bd_a, s21_bd bd_b, s21_bd *bd_x) {
  clear_bd(bd_x);
  int borrow = 0;
  int last_b = 1 + s21_lastBit(bd_a);
  for (int i = 0; i < last_b; i++) {
    int bit1 = S21_GET_BIT(bd_a, i, s21_bd);
    int bit2 = S21_GET_BIT(bd_b, i, s21_bd);
    int diff = bit1 - bit2 - borrow;
    borrow = (diff < 0) ? 1 : 0;
    S21_SET_BIT(bd_x, i, (diff & 1), s21_bd);
  }
}
