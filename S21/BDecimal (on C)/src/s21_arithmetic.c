#include <string.h>

#include "./BIG_DECIMAL/s21_bd.h"

// 0 - ok, 1 - inf, 2 - -inf, 3 - (x/0)
int s21_mul(s21_decimal a, s21_decimal b, s21_decimal* x) {
  int er = 0;
  memset(x->bits, 0, sizeof(x->bits));
  int scale_a = s21_getScale(a);
  int scale_b = s21_getScale(b);
  // int scale_x = scale_a + scale_b;
  int sign = s21_getSign(a) == s21_getSign(b) ? 0 : 1;

  if (DEC_ZERO(a) || DEC_ZERO(b)) {
    er = 0;
  } else if (DEC_MAX(a) || DEC_MAX(b)) {
    er = sign == 0 ? 1 : 2;
  } else {
    s21_bd bd_a = decimal_to_bd(a), bd_b = decimal_to_bd(b), tmp_x = {0};
    if (scale_a != scale_b) {
      equal_scale_bd(&bd_a, &bd_b);
      scale_b = scale_a = bd_a.scale;
    }
    s21_bdMicroMul(bd_a, bd_b, &tmp_x);
    // float result = 0.0;
    // bd_to_decimal(tmp_x, x);
    // s21_from_decimal_to_float(*x, &result);
    // printf("flot: %f\n", result);
    if (scale_a) {
      scale_b = scale_a;
      do {
        uint64_t remainder = bd_mod_10(tmp_x);
        if (remainder != 0) {
          scale_b--;
        } else {
          break;
        }
      } while (scale_b > 0);
    }

    s21_overflow(&tmp_x);
    tmp_x.scale = scale_a + scale_b;
    if (!er) {
      er = bd_to_decimal(tmp_x, x);
      s21_setSign(x, sign);
      // s21_setScale(x, scale_a);
      // printf("er: %d\n", er);
    }
  }
  return er;
}

int s21_div(s21_decimal a, s21_decimal b, s21_decimal* x) {
  int er = 0;
  for (int i = 0; i < 4; ++i) {
    x->bits[i] = 0;
  }
  if (s21_decIsZero(b)) {
    er = 3;
  } else if (s21_decIsZero(a)) {
    er = 0;
  } else {
    s21_bd bd_a = decimal_to_bd(a), bd_b = decimal_to_bd(b), bd_res;
    s21_bdDiv(bd_a, bd_b, &bd_res);
    er = bd_to_decimal(bd_res, x);
  }
  return er;
}

int s21_add(s21_decimal a, s21_decimal b, s21_decimal* x) {
  s21_bd a_bd = decimal_to_bd(a), b_bd = decimal_to_bd(b), res;
  s21_bd_add(a_bd, b_bd, &res);
  return bd_to_decimal(res, x);
}

int s21_sub(s21_decimal a, s21_decimal b, s21_decimal* x) {
  s21_bd a_bd = decimal_to_bd(a), b_bd = decimal_to_bd(b), res;
  b_bd.sign = !b_bd.sign;
  s21_bd_add(a_bd, b_bd, &res);
  return bd_to_decimal(res, x);
}
