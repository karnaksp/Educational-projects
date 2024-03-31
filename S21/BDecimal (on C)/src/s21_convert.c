#include "s21_suppl.h"

// int s21_from_int_to_decimal(int src, s21_decimal *dst) {
//   int error = OK;

//   if (dst != NULL) {
//     // null padding
//     for (int i = 0; i < 4; ++i) dst->bits[i] = 0;

//     if (src < 0) {
//       s21_setSign(dst, 1);
//       src *= -1;
//     }

//     if (!error) dst->bits[LOW] = (uint32_t)src;
//   } else {
//     error = FAIL;
//   }

//   return error;
// }

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int sign = 0, flag = 0;
  for (int i = 0; i < 4; ++i) dst->bits[i] = 0;
  if (src != 0) {
    if (src < 0) {
      sign = 1;
      src = -src;
    }
    dst->bits[0] = src;
    s21_setScale(dst, 0);
    s21_setSign(dst, sign);
  }
  return flag;  //
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error = OK;

  int sign = s21_getSign(src);

  // Преобразование невозможно
  if (src.bits[MID] || src.bits[HIGH] || dst == NULL ||
      (src.bits[0] > (((uint32_t)INT32_MAX) + sign))) {
    error = FAIL;
  } else {
    int scale = s21_getScale(src);
    while (scale > 0) {
      src.bits[LOW] /= 10;
      scale--;
    }
    *dst = src.bits[LOW];

    if (sign) {
      *dst = *dst * -1;
    }
  }

  return error;
}

int count_digits_after_decimal(float num) {
  if (num < 0) num *= -1;
  float integer_part = 0;
  float fractional_part = modff(num, &integer_part);

  int count = 0;
  while (fractional_part != 0.0) {
    // debug
    // printf("count - %d| num = %f| fractional_part = %f|\n", count, num,
    // fractional_part); debug

    count++;
    fractional_part *= 10;
    fractional_part = modff(fractional_part, &integer_part);
    if (count == 100) break;
  }
  return count;
}

int get_first_digit_after_decimal_point(float num) {
  if (num < 0) num *= -1;
  float integer_part = 0;
  float fractional_part = modff(num, &integer_part);

  int first_digit = (int)(fractional_part * 10);

  // debug
  // printf("num - %f| fractional_part - %f| first_digit - %d\n", num,
  //        fractional_part, first_digit);
  // debug
  // printf("first_digit: %d\n", first_digit);
  return first_digit;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  if (dst == NULL) {
    return 1;
  }

  for (int i = 0; i < 4; i++) {
    dst->bits[i] = 0;
  }

  int result = 0;
  int scale = 0;
  int is_small = 0;
  int is_sign = 0;
  float_cast n;
  n.float_number = src;
  int number = n.int_number;

  int integer_size = 0;
  int last_digit = 0;
  int seventh_digit = 0;
  float integer_part = 0.0;
  int temp_size = 0;

  // debug
  // printf("0-scale - %d, float - %f\n", scale, src);
  // debug

  if (n.parts.sign == 1) {
    is_sign = 1;
    src *= -1;
  }
  if (is_nan_or_inf(number) == 1) {
    result = 1;
  } else {
    int float_exponent = get_float_exponent(number);

    // debug
    // printf("float_exponent - %d, float - %f\n", float_exponent, src);
    // debug

    if (float_exponent > 95) {
      result = 1;
    } else if (src == 0.0) {
      // ?
    } else {
      integer_size = count_digits_in_int(src);

      if (float_exponent < -95) {
        for (; !((long long int)src); src *= 10, scale++) {
        }
      }

      // debug
      // printf("1-float_exponent - %d, float - %f\n", float_exponent, src);
      // debug
      // int res = 0;
      for (; integer_size < 6; src *= 10, scale++) {
        integer_size = count_digits_in_int(src);
        if (integer_size == 0) temp_size++;

        // debug
        // printf("integer size: %d\n", integer_size);
        // printf("temp_size size: %d\n", temp_size);
        // printf("1-scale - %d, float - %f| *10 = %f\n", scale, src, src * 10);
        // debug

        seventh_digit =
            get_first_digit_after_decimal_point(modff(src, &integer_part) * 10);

        // res++;
        // if (res == 100) {
        //   break;
        // }
      }
      integer_size = count_digits_in_int(src);

      // printf("11-scale - %d, float - %f\n", scale, src);
      // debug
      // printf("2-float_exponent - %d, float - %f\n", float_exponent, src);
      // debug

      if (integer_size <= 7) {
        // Добавляем округление для 7ой цифры после запятой

        if (get_first_digit_after_decimal_point(src) != 0) {
          seventh_digit = get_first_digit_after_decimal_point(src);
        }

        // debug
        // printf("integer_size <= 7 - %d| src - %f| seventh_digit - %d\n",
        //        integer_size, src, seventh_digit);
        // debug

        if (seventh_digit > 0) {
          src += 1;

          // debug
          // printf("1. integer_size <= 7 - %d| src - %f| seventh_digit - %d\n",
          //        integer_size, src, seventh_digit);
          // debug

        } else if (seventh_digit == 5 &&
                   (get_last_digit_of_integer_part(src) % 2 != 0)) {
          src += 1;

          // debug
          // printf("3. integer_size <= 7 - %d| src - %f| seventh_digit - %d\n",
          // integer_size, src, seventh_digit);
          // debug
        }
        // else if (scale > 10 && seventh_digit > 0) {
        //   src += 1;
        // }
      } else {
        // debug
        // printf("before - integer_size - %d| src - %f|\n", integer_size, src);
        // debug

        if (integer_size == 8) {
          last_digit = get_last_digit_of_integer_part(src);

          // debug
          // printf("integer_size == 8. src - %f| last_digit - %d\n", src,
          //        last_digit);
          // debug

        } else {
          src = src / pow(10, integer_size - 7 - 1);
          last_digit = get_last_digit_of_integer_part(src);

          // debug
          // printf("else | src - %f| last_digit - %d\n", src, last_digit);
          // debug
        }

        // debug
        // printf("middle1 - integer_size - %d| src - %f|\n", integer_size,
        // src); debug

        src /= 10;

        // debug
        // printf("middle2 - integer_size - %d| src - %f|\n", integer_size,
        // src); debug

        if (last_digit > 5) {
          src += 1;

          // debug
          // printf("1. src - %f| last_digit - %d\n", src, last_digit);
          // debug

        } else if (last_digit == 5 && count_digits_after_decimal(src) >= 1) {
          src += 1;

          // debug
          // printf("2. src - %f| last_digit - %d\n", src, last_digit);
          // debug

        } else if (last_digit == 5 &&
                   (get_last_digit_of_integer_part(src) % 2 != 0)) {
          src += 1;

          // debug
          // printf("3. src - %f| last_digit - %d\n", src, last_digit);
          // debug
        }
        // debug
        // printf("after  - integer_size - %d| src - %f|\n", integer_size, src);
        // debug
      }

      // debug
      // printf("2-scale - %d, float - %f\n", scale, src);
      // debug

      n.float_number = src;
      number = n.int_number;
      float_exponent = get_float_exponent(number);
      if (temp_size == 28)
        scale = temp_size;
      else if (temp_size != 0)
        scale++;

      // printf("int number of float - %d, number - %d, float_exp - %d\n",
      //        (int)n.float_number, number, float_exponent);

      if ((scale > 28 && temp_size == 0) || float_exponent < -94 ||
          (temp_size > 28 && scale > 33)) {
        // printf("scale: %d, float_exp: %d\n", scale, float_exponent);
        is_small = 1;
        result = 1;
      } else {
        // S21_SET_BIT(dst, float_exponent, 1, s21_decimal);
        // float_exponent--;
        // unsigned int mask = 0x00400000;
        // for (int i = 0; i < 23 && float_exponent >= 0; i++, float_exponent--)
        // {
        //   if ((number & mask) == mask) {
        //     S21_SET_BIT(dst, float_exponent, 1, s21_decimal);
        //   }
        //   mask >>= 1;
        // }
        s21_from_int_to_decimal((int)n.float_number, dst);
      }
    }
  }
  // if (temp_size) scale = temp_size;
  // printf("scale: %d\n", scale);

  // for (int i = 0; i < integer_size - 7; i++) {
  //   s21_decimal ten = {{0xa, 0x0, 0x0, 0x0}};
  //   s21_mul(*dst, ten, dst);
  // }
  // float intulya = 0.0;
  s21_setScale(dst, scale);
  // s21_from_decimal_to_float(*dst, &intulya);
  // printf("float number: %f\n", intulya);

  if (is_sign == 1) {
    dst->bits[3] |= MINUS;
  }
  // printf("decimal in function: ");
  // for (int i = 3; i >= 0; --i) {
  //   printf("%08x ", dst->bits[i]);
  // }
  // puts("");

  if (is_small == 1) {
    for (int i = 0; i < 4; i++) {
      dst->bits[i] = 0;
    }
  }
  return result;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  *dst = 0.0;
  for (int i = 0; i < 96; i++) {
    if (S21_GET_BIT(src, i, s21_decimal) == 1) {
      *dst += pow(2.0, i);
    }
  }

  int scale = s21_getScale(src);
  for (; scale != 0; scale--) {
    *dst /= 10;
  }

  if (s21_getSign(src) == 1) {
    *dst = -*dst;
  }

  return 0;
}
