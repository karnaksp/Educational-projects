#include "s21_suppl.h"

int s21_getSign(s21_decimal value) {
  return S21_GET_BIT(value, SIGN_BIT, s21_decimal);
}

void s21_setSign(s21_decimal *value, int bit) {
  S21_SET_BIT(value, SIGN_BIT, bit, s21_decimal);
}

int s21_getScale(s21_decimal value) {
  int scale = 0;
  for (int i = 16; i < 24; i++) {
    if (S21_GET_BIT(value, i + 96, s21_decimal)) {
      scale += pow(2, i - 16);
    }
  }
  if (scale > 28) {
    scale = 28;
  }
  return scale;
}

void s21_setScale(s21_decimal *value, int scale) {
  value->bits[SCALE] &= MINUS;
  scale <<= 16;
  value->bits[SCALE] |= scale;
}

int s21_normalize(s21_decimal *value_1, s21_decimal *value_2) {
  int error = 0;
  int scale_value_1 = s21_getScale(*value_1);
  int scale_value_2 = s21_getScale(*value_2);
  if (scale_value_1 < scale_value_2) {
    s21_decimal temp = *value_1;
    *value_1 = *value_2;
    *value_2 = temp;
    int temp_scale = scale_value_1;
    scale_value_1 = scale_value_2;
    scale_value_2 = temp_scale;
  }
  while (scale_value_1 > scale_value_2) {
    if (S21_GET_BIT(*value_1, LAST_BIT_MANTISSA, s21_decimal)) {
      error = 1;
      break;
    }
    s21_multiplyBy10(value_2);
    scale_value_1--;
  }
  if (!error) {
    s21_setScale(value_1, scale_value_2);
  }
  return error;
}

void s21_multiplyBy10(s21_decimal *value) {
  for (int i = 0; i < D_SIZE - 1; i++) {
    value->bits[i] *= 10;
  }
}

void s21_microAdd(s21_decimal value_1, s21_decimal value_2,
                  s21_decimal *result) {
  int carry = 0;
  for (int i = 0; i < 96; i++) {
    int bit_1 = S21_GET_BIT(value_1, i, s21_decimal);
    int bit_2 = S21_GET_BIT(value_2, i, s21_decimal);
    int sum = bit_1 + bit_2 + carry;
    carry = 0;
    if (sum == 1 || sum == 3) {
      S21_SET_BIT(result, i, 1, s21_decimal);
    } else if (sum == 2) {
      S21_SET_BIT(result, i, 0, s21_decimal);
      carry = 1;
    }
  }
}

int s21_decIsZero(s21_decimal a) {
  int res = 1;
  for (int i = 0; i < 4; i++) {
    if (a.bits[i] != 0) res = 0;
  }
  return res;
}

int is_nan_or_inf(int n) {
  int result = 0;
  if ((n & 0x7f800000) == 0x7f800000) {
    result = 1;
  }
  return result;
}

int get_float_exponent(int number) {
  int result = 0;
  int offset = 23;
  result = (number & (0xFF << offset)) >> offset;
  return (result - 127);
}

int count_digits_in_int(float n) {
  int count = 0;
  // debug
  // printf("n original - %f\n", n);
  // debug

  if (n == 0.0) {
    count++;
  } else {
    float integer_part = 0.0;
    modff(n, &integer_part);
    for (; integer_part != 0.0; n /= 10) {
      modff(n, &integer_part);

      if (integer_part == 0.0) {
        break;
      }

      count++;

      // debug
      // printf("n - %f| integer_part - %f| count - %d\n", n, integer_part,
      // count); debug
    }
  }
  return count;
}

int get_last_digit_of_integer_part(float n) {
  int remainder = fmodf(n, 10.0);

  return remainder;
}
