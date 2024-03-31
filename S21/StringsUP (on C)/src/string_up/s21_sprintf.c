#include "s21_sprintf.h"

#include <stdlib.h>

FormatFlags s21_init_flags(void) {
  FormatFlags flags;
  flags.type = 0;
  flags.alignment = 0;
  flags.showSign = 0;
  flags.spaceBeforePositive = 0;
  flags.alternateForm = 0;
  flags.precision = -1;
  flags.zeroPadding = 0;
  flags.width = 0;
  flags.dynamicWidth = 0;
  flags.precision = 0;
  flags.lengthModifier = 0;
  flags.error = 0;
  flags.uppercase = 0;
  flags.is_format = 0;
  flags.char_count = 0;
  flags.is_suppressed = 0;
  flags.length = 0;
  flags.buffer = '0';
  flags.firstSpace = 0;
  flags.unformatting = 0;
  return flags;
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  str[0] = '\0';
  str[1] = '\0';
  int result;
  if (str == s21_NULL) {
    return -1;
  } else {
    va_start(args, format);
    result = s21_read_str(str, format, args);
    va_end(args);
  }
  result = s21_strlen(str);
  return result;
}

int s21_read_str(char *str, const char *format, va_list args) {
  int result = 0;
  int i = 0;
  int j = 0;
  while (format[i] != '\0') {
    FormatFlags flags;
    if (format[i] != '%') {
      while (*str) {
        str++;
      }
      *str = format[i];
      str++;
      *str = '\0';
      i++;
      j++;
    } else if (format[i] == '%') {
      i++;
      flags = s21_init_flags();
      s21_read_flags(format, &i, &flags, args);
      if (flags.type == 'n') {
        s21_handleNumSpecifier(j + result, args);
      }
      if (format[i + 1] != '\0') {
        i++;
        result += s21_translateSpecifier(flags.type, &flags, args, str);
      } else {
        result += s21_translateSpecifier(flags.type, &flags, args, str);
        i++;
      }
    }
  }
  result += j;
  return result;
}

void s21_read_flags(const char *format, int *i, FormatFlags *flags,
                    va_list args) {
  int hasWidth = 0;
  int hasPrecision = 0;

  if (hasWidth == 0 && hasPrecision == 0) {
    if (format[*i] == '-') {
      flags->alignment = 1;
      (*i)++;
    }
    if (format[*i] == '+') {
      flags->showSign = 1;
      (*i)++;
    }
    if (format[*i] == ' ') {
      flags->spaceBeforePositive = 1;
      (*i)++;
    }
    if (format[*i] == '#') {
      flags->alternateForm = 1;
      (*i)++;
    }
    if (format[*i] == '0') {
      flags->zeroPadding = 1;
      (*i)++;
    }
  }
  if ((s21_is_digit(format[*i]) || format[*i] == '*') && hasPrecision == 0 &&
      flags->width == 0) {
    hasWidth = 1;
    if (s21_is_digit(format[*i])) {
      flags->width = s21_get_number(format, i);
      (*i)++;
    } else {
      flags->width = va_arg(args, int);
      (*i)++;

      if (flags->width < 0) {
        flags->zeroPadding = 0;
        flags->alignment = 1;
        flags->width *= -1;
      }
    }
  }
  if (format[*i] == '.' && hasPrecision == 0) {
    hasPrecision = 1;
    if (!s21_is_digit(format[*i + 1]) && format[*i + 1] != '*') {
      flags->precision = 0;
    } else if (s21_is_digit(format[++(*i)])) {
      flags->precision = s21_get_number(format, i);
      (*i)++;

    } else {
      flags->precision = va_arg(args, int);
      (*i)++;

      if (flags->precision < 0) {
        flags->precision = -1;
      }
    }
  }
  if ((format[*i] == 'h' || format[*i] == 'l') &&
      (format[*i + 1] == 'i' || format[*i + 1] == 'd' ||
       format[*i + 1] == 'o' || format[*i + 1] == 'u' ||
       format[*i + 1] == 'x' || format[*i + 1] == 'X' ||
       format[*i + 1] == '%')) {
    flags->lengthModifier = format[*i];
    (*i)++;
  } else if (format[*i] == 'L' &&
             (format[*i + 1] == 'e' || format[*i + 1] == 'E' ||
              format[*i + 1] == 'f' || format[*i + 1] == 'g' ||
              format[*i + 1] == 'G' || format[*i + 1] == '%' ||
              format[*i + 1] == 'F')) {
    flags->lengthModifier = format[*i];
    (*i)++;
  }
  if (s21_specifier(format[*i])) {
    flags->type = format[*i];
    if (!s21_check_flags(flags)) flags->error = 1;
    s21_specifier_upper(flags);
  } else if (format[*i] == '\0') {
    exit(0);
  } else {
    flags->error = 1;
    exit(0);
  }
}

int s21_check_flags(FormatFlags *flags) {
  int res = 1;
  if (flags->alignment && flags->zeroPadding && flags->type != '%')
    res = 0;
  else if (flags->alignment && flags->zeroPadding && flags->type == '%')
    flags->zeroPadding = 0;
  else if (flags->showSign && flags->spaceBeforePositive && flags->type != '%')
    res = 0;
  return res;
}

int s21_is_digit(int c) { return (c >= '0' && c <= '9'); }

int s21_specifier(int c) {
  return (c == 'c' || c == 'd' || c == 'i' || c == 'e' || c == 'E' ||
          c == 'f' || c == 'g' || c == 'G' || c == 'o' || c == 's' ||
          c == 'u' || c == 'x' || c == 'X' || c == 'p' || c == 'n' ||
          c == '%' || c == 'F');
}

void s21_specifier_upper(FormatFlags *flags) {
  if (flags->type == 'F' || flags->type == 'E' || flags->type == 'G')
    flags->uppercase = 1;
}

int s21_get_number(const char *format, int *i) {
  int width = 0;
  width += format[*i] - '0';
  (*i)++;
  while (s21_is_digit(format[*i])) {
    width *= 10;
    width += format[*i] - '0';
    (*i)++;
  }
  (*i)--;
  return width;
}

void s21_creverse_string(char *str, int count) {
  int i, j;
  for (i = 0, j = count - 1; i < j; i++, j--) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}

int s21_citoa(long long int num, char *str) {
  int count = 0;
  int isNegative = 0;
  if (num == 0) {
    str[0] = '0';
    count++;
  } else {
    if (num < 0) {
      isNegative = 1;
      num = -num;
    }
    while (num != 0) {
      int digit = num % 10;
      str[count++] = digit + '0';
      num /= 10;
    }
    if (isNegative) {
      str[count++] = '-';
    }
    s21_creverse_string(str, count);
  }
  str[count] = '\0';
  return count;
}

char *s21_ffcvt(double value, int ndigit, int *decpt, int *sign) {
  char *buf = s21_NULL;
  int bufsize = 0;
  union {
    uint64_t l;
    double f;
  } x;
  x.f = value;
  int exp2 = (0x7ff & (x.l >> 52)) - 1023;  // Экспонента двоичного числа
  uint64_t mant = x.l & 0x000fffffffffffffULL;  // Мантисса числа
  if ((*sign = x.l >> 63)) value = -value;
  if (exp2 == 0x400) {
    *decpt = 0;
    return mant ? "nan" : "inf";
  }
  int exp10 = (value == 0)
                  ? 1
                  : (int)ceil(log10(value));  // Экспонента десятичного числа
  if (exp10 < -307) exp10 = -307;  // Проверка на переполнение в pow()
  value *= pow(10.0, -exp10);  // Приведение числа к десятичному формату
  if (value) {
    while (value < 0.1) {
      value *= 10;
      --exp10;
    }
    while (value >= 1.0) {
      value /= 10;
      ++exp10;  // Нормализация числа
    }
  }
  assert(value == 0 || (0.1 <= value && value < 1.0));
  if (bufsize < ndigit + 2) {
    bufsize = ndigit + 2;
    char *new_buf = malloc(bufsize + 2);
    if (new_buf == s21_NULL) {
      return 0;
    } else {
      buf = new_buf;
    }
  }
  int ptr = 0;
  while (ptr <= ndigit) {
    double i;
    value = modf(value * 10, &i);
    buf[ptr++] = '0' + (int)i;
  }
  if (value >= 0.5) {
    while (ptr > 0 && ++buf[ptr - 1] > '9') {
      buf[ptr - 1] = '0';  // Округление
      --ptr;
    }
  }
  if (ptr) {
    buf[ndigit + 1] = 0;
    return buf;
  }
  buf[0] = '1';
  buf[ndigit] = 0;
  *decpt = exp10 + ndigit;
  return buf;
}

void s21_fcvt(long double b, FormatFlags *flags, int length_int, char *temp) {
  int null_arg = 0, null_arg2 = 0;
  long double b_copy = b;
  if (b >= 1) flags->precision += length_int;
  char *fractional_part = s21_ffcvt(b, flags->precision, &null_arg, &null_arg2);
  if (fractional_part[0] == '0') {
    temp[length_int] = '\0';
  } else {
    int i, j;
    for (j = 0; j < length_int; j++) {
      if (b < 1) {
        temp[j] = '0';
        b *= 10;
      } else {
        temp[j] = fractional_part[j];
      }
    }
    temp[length_int] = '.';
    flags->precision -= length_int;
    if (b_copy < 1) flags->precision++;
    for (i = 0; i < flags->precision; i++, j++) {
      while (b < 1) {
        temp[length_int + i + 1] = '0';
        i++;
        b *= 10;
      }
      if (b_copy < 1) {
        temp[length_int + i + 1] = fractional_part[j - 1];
      } else
        temp[length_int + i + 1] = fractional_part[j];
    }
    if (fractional_part[j - 1] > temp[length_int + i]) temp[length_int + i]++;
    temp[length_int + 1 + i] = '\0';
  }
  if (flags->precision > -2 && fractional_part != s21_NULL) {
    free(fractional_part);  // Освобождение памяти, выделенной в s21_ffcvt
  }
}

int s21_appendCharToStr(char c, char *str) {
  int length = s21_strlen(str);
  str[length] = c;
  str[length + 1] = '\0';
  return 1;
}

void s21_appendCharSignToStr(FormatFlags *flags, int is_Negative, char *str) {
  if (is_Negative)
    s21_appendCharToStr('-', str);
  else if (flags->showSign == 1)
    s21_appendCharToStr('+', str);
  else if (flags->spaceBeforePositive == 1)
    s21_appendCharToStr(' ', str);
}

int s21_fillWidth(int width, int length, int hasZeroFill, char *str) {
  int remaining = width - length;
  if (remaining < 0) {
    remaining = 0;
  }

  for (int i = 0; i < remaining; i++) {
    if (hasZeroFill == 1) {
      s21_appendCharToStr('0', str);
    } else {
      s21_appendCharToStr(' ', str);
    }
  }

  return remaining;
}

int s21_getLengthofNumber(long long int n) {
  char dummy[21];
  return s21_citoa(n, dummy);
}

void s21_strUpdate(long long int u, char *str) {
  char *temp;
  int length = s21_getLengthofNumber(u);
  temp = malloc((length + 1) * sizeof(char));
  length = s21_citoa(u, temp);
  s21_strcat(str, temp);
  free(temp);
}

void s21_charStrloop1(int arg1, long long int d, int arg3, int *i, char fill,
                      char *str) {
  while (*i < (arg1 - s21_getLengthofNumber(d) + arg3)) {
    s21_appendCharToStr(fill, str);
    *i = *i + 1;
  }
}

void s21_charStrloop2(int arg1, long long int u, int *i, char fill, char *str) {
  while (*i < (arg1 - s21_getLengthofNumber(u))) {
    s21_appendCharToStr(fill, str);
    *i = *i + 1;
  }
}

void s21_charStrloop3(int arg1, int arg2, int arg3, int *i, char fill,
                      char *str) {
  if ((arg1 - arg2 + arg3) == 0) {
    s21_appendCharToStr(fill, str);
    *i = *i + 1;
  } else {
    while (*i < (arg1 - arg2 + arg3)) {
      s21_appendCharToStr(fill, str);
      *i = *i + 1;
    }
  }
}

char *s21_convertToBase(unsigned long long num, FormatFlags *flags) {
  static char DecimalSymbolSet[] = "0123456789";
  static char HexLowercaseSymbolSet[] = "0123456789abcdef";
  static char HexUppercaseSymbolSet[] = "0123456789ABCDEF";
  static char OctalSymbolSet[] = "01234567";
  static char *symbolSet;

  char buffer[50];
  int base = 0;
  char *ptr = &buffer[sizeof(buffer) - 1];
  *ptr = '\0';

  if (flags->type == 'o') {
    symbolSet = OctalSymbolSet;
    base = 8;
  } else if (flags->type == 'x' || flags->type == 'p' || flags->type == 'X') {
    symbolSet =
        (flags->type == 'X') ? HexUppercaseSymbolSet : HexLowercaseSymbolSet;
    base = 16;
  } else {
    symbolSet = DecimalSymbolSet;
    base = 10;
  }

  if (num == 0) {
    *--ptr = symbolSet[0];
  } else {
    while (num != 0) {
      *--ptr = symbolSet[num % base];
      num /= base;
    }
  }
  s21_size_t length = s21_strlen(ptr);
  char *result = (char *)malloc((length + 1) * sizeof(char));
  if (result != NULL) {
    s21_memcpy(result, ptr, length);
    result[length] = '\0';
  }
  return result;
}

void s21_processFormattingFlags_u_d_i(long int u, FormatFlags *flags,
                                      char *str) {
  int i = 0;
  if (u < 0 && flags->type != 'u') flags->showSign = 1;
  if (((flags->showSign == 1 || flags->spaceBeforePositive == 1 ||
        flags->alternateForm == 1) &&
       flags->type == 'u') ||
      (flags->type == 'd' && flags->alternateForm == 1)) {
    flags->error = 1;
  }
  if (flags->alignment == 1 && flags->width > flags->precision &&
      flags->precision != -1) {
    s21_charStrloop1(flags->precision, u, 0, &i, '0', str);
    s21_strUpdate(u, str);
    i = s21_strlen(str);
    s21_charStrloop3(flags->width, 0, 0, &i, ' ', str);
  } else if (flags->alignment == 0 && flags->width > flags->precision &&
             flags->precision != -1 &&
             flags->width > s21_getLengthofNumber(u) &&
             flags->precision < s21_getLengthofNumber(u) &&
             flags->zeroPadding == 0) {
    if (flags->spaceBeforePositive == 1 && u > 0) s21_appendCharToStr(' ', str);
    s21_charStrloop2(flags->width, u, &i, ' ', str);
    s21_strUpdate(u, str);
  } else if (flags->alignment == 0 && flags->width > flags->precision &&
             flags->precision != -1 && flags->zeroPadding == 0 &&
             flags->width > s21_getLengthofNumber(u)) {
    if (flags->showSign != 1 && flags->spaceBeforePositive == 1 && u > 0)
      s21_appendCharToStr(' ', str);
    s21_charStrloop3(flags->width, flags->precision, 0, &i, ' ', str);
    s21_charStrloop1(flags->width, u, 0, &i, '0', str);
    s21_strUpdate(u, str);
  } else if (flags->alignment == 0 && flags->width > flags->precision &&
             flags->precision != -1 && flags->zeroPadding == 1) {
    if (flags->precision <= s21_getLengthofNumber(u)) {
      s21_charStrloop2(flags->width, u, &i, '0', str);
      s21_strUpdate(u, str);
    } else {
      s21_charStrloop3(flags->width, flags->precision, 0, &i, ' ', str);
      s21_charStrloop1(flags->width, u, 0, &i, '0', str);
      s21_strUpdate(u, str);
    }
  } else if (flags->precision == -1 &&
             flags->width > s21_getLengthofNumber(u) &&
             flags->zeroPadding == 0 && flags->alignment == 0) {
    s21_charStrloop2(flags->width, u, &i, ' ', str);
    s21_strUpdate(u, str);
  } else if (flags->precision == -1 &&
             flags->width > s21_getLengthofNumber(u) &&
             flags->zeroPadding == 0 && flags->alignment == 1) {
    s21_strUpdate(u, str);
    s21_charStrloop2(flags->width, u, &i, ' ', str);
  } else if (flags->precision == -1 &&
             flags->width > s21_getLengthofNumber(u) &&
             flags->zeroPadding == 1) {
    s21_charStrloop2(flags->width, u, &i, '0', str);
    s21_strUpdate(u, str);
  } else if (flags->precision == -1 &&
             flags->width <= s21_getLengthofNumber(u)) {
    s21_strUpdate(u, str);
  } else if (flags->precision > s21_getLengthofNumber(-u) ||
             flags->precision > s21_getLengthofNumber(u)) {
    if (flags->spaceBeforePositive == 1 && u > 0) s21_appendCharToStr(' ', str);
    if (flags->showSign == 1) {
      if (u < 0) {
        s21_appendCharToStr('-', str);
        u = -1 * u;
      }
    }
    s21_charStrloop2(flags->precision, u, &i, '0', str);
    s21_strUpdate(u, str);
  } else if (flags->precision < s21_getLengthofNumber(-u)) {
    if (flags->spaceBeforePositive == 1 && u > 0) s21_appendCharToStr(' ', str);
    s21_strUpdate((long long int)u, str);
  } else if (flags->width > flags->precision) {
    flags->width = s21_getLengthofNumber(u);
    s21_charStrloop2(flags->width, u, &i, ' ', str);
    s21_strUpdate(u, str);
  } else {
    s21_charStrloop2(flags->precision, u, &i, '0', str);
    s21_strUpdate(u, str);
  }
}

int s21_convertToMantissa(long double *number, int precision) {
  if (*number == 0) {
    return 0;
  }
  int exponent = 0;
  if (*number >= 10) {
    while (*number >= 10) {
      *number /= 10;
      exponent++;
    }
  } else if (*number < 1 && *number != 0) {
    while (*number < 1) {
      *number *= 10;
      exponent--;
    }
  }
  long double scale = powl(10, precision);
  *number = roundl(*number * scale) / scale;

  if (*number >= 10) {
    *number /= 10;
    exponent++;
  } else if (*number < 1) {
    *number *= 10;
    exponent--;
  }
  return exponent;
}

unsigned long long s21_convertDoubleToLong(long double digits, int precision) {
  long long rounded_digits = llround(digits * powl(10, precision));
  return (long long)rounded_digits;
}

int s21_createPartWithoutMantissa(char *right_part, long double right_digits,
                                  int precision, FormatFlags *flags) {
  int counter = 0;
  long double right_digits_copy = right_digits;
  right_part[0] = '\0';
  while (counter < precision) {
    right_digits_copy *= 10;
    if ((unsigned long int)right_digits_copy != 0) {
      break;
    }
    s21_appendCharToStr('0', right_part);
    counter++;
  }
  char *right_part_no_zeros;
  unsigned long long right_digits_long =
      s21_convertDoubleToLong(right_digits, precision);
  right_part_no_zeros = s21_convertToBase(right_digits_long, flags);
  counter = 0;
  while (right_part_no_zeros[counter]) {
    if (right_part_no_zeros[counter] == '.') {
      right_part_no_zeros[counter] = '\0';
      break;
    }
    counter++;
  }
  int is_right_part_null = 1;
  int right_part_no_zeros_len = s21_strlen(right_part_no_zeros);
  if ((right_part_no_zeros[0] == '0' && right_part_no_zeros_len == 1) ||
      (right_part_no_zeros[0] == '-' && right_part_no_zeros[1] == '0' &&
       right_part_no_zeros_len == 2)) {
    is_right_part_null = 0;
  }
  int result = 0;
  if (flags->type == 'g' && flags->alternateForm == 0) {
    int i = s21_strlen(right_part_no_zeros) - 1;
    while (i >= 0 && right_part_no_zeros[i] == '0') {
      right_part_no_zeros[i] = '\0';
      i--;
      result++;
    }

    if (is_right_part_null == 0) {
      i = s21_strlen(right_part) - 1;
      while (i >= 0 && right_part[i] == '0') {
        right_part[i] = '\0';
        i--;
        result++;
      }
    }
  }

  if (is_right_part_null == 1) {
    s21_strcat(right_part, right_part_no_zeros);
  }
  free(right_part_no_zeros);
  return result;
}

int s21_lengthWithoutWidth(FormatFlags flags, int is_negative, int e) {
  int length = 5;
  length += (e / 10) >= 10;
  int precision = flags.precision == -1 ? 6 : flags.precision;
  if ((flags.type == 'g' || flags.type == 'G') && precision != 0) precision--;
  if (is_negative || (!is_negative && flags.showSign) ||
      (!is_negative && flags.spaceBeforePositive && !flags.showSign))
    length++;
  if (precision != 0) length += precision + 1;
  if (precision == 0 && flags.alternateForm == 1) length++;
  return length;
}

void s21_rightMantissaPart(char *right_mantissa_part, char letter, int e) {
  right_mantissa_part[0] = letter;
  right_mantissa_part[1] = (e < 0) ? '-' : '+';
  int abs_e = abs(e);
  if (abs_e < 10) {
    right_mantissa_part[2] = '0';
    right_mantissa_part[3] = abs_e + '0';
  } else {
    right_mantissa_part[2] = (abs_e / 10) + '0';
    right_mantissa_part[3] = (abs_e % 10) + '0';
  }
  right_mantissa_part[4] = '\0';
}

void s21_concatPartsOfMantissa(char *concat_str, char *left_part,
                               char *right_part, char *right_mantissa_part,
                               FormatFlags flags, int is_negative, int length) {
  int precision = flags.precision == 0 ? 6 : flags.precision;
  if ((flags.type == 'g' || flags.type == 'G') && precision != 0) precision--;
  if (!flags.alignment) {
    if ((is_negative || (!is_negative && flags.showSign)) &&
        flags.zeroPadding) {
      s21_appendCharToStr((is_negative ? '-' : '+'), concat_str);
    }
    if (flags.spaceBeforePositive && !is_negative) {
      s21_appendCharToStr(' ', concat_str);
    }
    s21_fillWidth(flags.width, length, flags.zeroPadding, concat_str);
  }
  if (flags.alignment) {
    if (is_negative || (!is_negative && flags.showSign)) {
      s21_appendCharToStr((is_negative ? '-' : '+'), concat_str);
    }
    if (flags.spaceBeforePositive && !is_negative) {
      s21_appendCharToStr(' ', concat_str);
    }
  }
  s21_strcpy(concat_str, left_part);
  if (flags.alternateForm || precision) {
    s21_appendCharToStr('.', concat_str);
    s21_strcat(concat_str, right_part);
    s21_strcat(concat_str, right_mantissa_part);
  }
  if (flags.alignment) {
    s21_fillWidth(flags.width, length, flags.zeroPadding, concat_str);
  }
}

int s21_sprintf_u_d_i(va_list args, FormatFlags *flags, char *str) {
  int result = 0;
  if (flags->type == 'd' || flags->type == 'i') {
    if (flags->lengthModifier == 'h') {
      int temp = va_arg(args, int);
      if (temp < INT16_MIN || temp > INT16_MAX) {
        s21_appendCharToStr('-', str);
        s21_appendCharToStr('1', str);
        s21_appendCharToStr('\0', str);
        flags->error = 1;
        return 0;
      }
      s21_processFormattingFlags_u_d_i((long)temp, flags, str);

    } else if (flags->lengthModifier == 'l') {
      long int temp = va_arg(args, long int);
      s21_processFormattingFlags_u_d_i(temp, flags, str);

    } else {
      int temp = va_arg(args, int);
      if (temp < INT_MIN || temp > INT_MAX) {
        s21_appendCharToStr('-', str);
        s21_appendCharToStr('1', str);
        s21_appendCharToStr('\0', str);
        flags->error = 1;
        return 0;
      }
      s21_processFormattingFlags_u_d_i((long)temp, flags, str);
    }
  } else if (flags->type == 'u') {
    if (flags->lengthModifier == 'h') {
      unsigned int temp = va_arg(args, unsigned int);
      if (temp > INT16_MAX) {
        s21_appendCharToStr('-', str);
        s21_appendCharToStr('1', str);
        s21_appendCharToStr('\0', str);
        flags->error = 1;
        return 0;
      }
      s21_processFormattingFlags_u_d_i((long)temp, flags, str);
    } else if (flags->lengthModifier == 'l') {
      unsigned long int temp = va_arg(args, unsigned long int);
      if (temp > ULONG_MAX) {
        s21_appendCharToStr('-', str);
        s21_appendCharToStr('1', str);
        s21_appendCharToStr('\0', str);
        flags->error = 1;
        return 0;
      }
      s21_processFormattingFlags_u_d_i((long)temp, flags, str);
    } else {
      unsigned int temp = va_arg(args, unsigned int);
      if (temp > INT32_MAX) {
        s21_appendCharToStr('-', str);
        s21_appendCharToStr('1', str);
        s21_appendCharToStr('\0', str);
        flags->error = 1;
        return 0;
      }
      s21_processFormattingFlags_u_d_i((long)temp, flags, str);
    }
  }

  result = s21_strlen(str);

  return result;
}

int s21_sprintf_x(unsigned long c, char s21_specifier, FormatFlags *flags,
                  char *str) {
  int result = 0, i = 0, length = 0;
  if (flags->lengthModifier == 'h' && c > 65535)  // 32-bit
    flags->error = 1;
  else if (flags->lengthModifier == 'l' && c > 4294967295)  // 32-bit
    flags->error = 1;

  char *tmp = s21_convertToBase(c, flags);
  int temp_len = (int)s21_strlen(tmp);
  if (flags->width < temp_len || flags->width < flags->precision) {
    flags->width = 0;
  }

  if (flags->precision < temp_len) {
    flags->precision = (int)s21_strlen(tmp);
  }

  if (flags->showSign == 1 || flags->spaceBeforePositive == 1) {
    flags->error = 1;

  } else {
    if (flags->alignment == 1) {
      if (flags->alternateForm == 1 && c != 0) {
        result += s21_appendCharToStr('0', str);
        result += s21_appendCharToStr(s21_specifier, str);
      }
      if (flags->precision > (int)s21_strlen(tmp)) {
        result += s21_fillWidth(flags->precision, s21_strlen(tmp), 1, str);
      }
      while (i < (int)s21_strlen(tmp)) {
        result += s21_appendCharToStr(tmp[i], str);
        i++;
      }
      if (flags->width != 0) {
        result += s21_fillWidth(flags->width, result, 0, str);
      }
    } else {
      if (flags->alternateForm == 1) {
        length = 2;
      }
      if (flags->width != 0) {
        result +=
            s21_fillWidth(flags->width, flags->precision + length, 0, str);
      }
      if (flags->alternateForm == 1 && c != 0) {
        result += s21_appendCharToStr('0', str);
        result += s21_appendCharToStr(s21_specifier, str);
      }
      if (flags->precision > temp_len) {
        result += s21_fillWidth(flags->precision, temp_len, 1, str);
      }
      while (i < temp_len) {
        char *tmp_copy = s21_convertToBase(c, flags);
        result += s21_appendCharToStr(tmp_copy[i], str);
        i++;
        free(tmp_copy);
      }
    }
  }
  free(tmp);
  result = s21_strlen(str);
  return result;
}

int s21_sprintf_o(unsigned long c, FormatFlags *flags, char *str) {
  int result = 0, i = 0, length = 0;
  if (flags->lengthModifier == 'h' && c > 65535)  // 32-bit
    flags->error = 1;
  else if (flags->lengthModifier == 'l' && c > 4294967295)  // 32-bit
    flags->error = 1;
  char *tmp = s21_convertToBase(c, flags);

  if (flags->width < (int)s21_strlen(tmp) || flags->width < flags->precision) {
    flags->width = 0;
  }

  if (flags->precision < flags->width &&
      flags->precision <= (int)s21_strlen(tmp)) {
    flags->precision = (int)s21_strlen(tmp);
  }
  if (flags->showSign == 1 || flags->spaceBeforePositive == 1) {
    flags->error = 1;
  } else {
    if (flags->alignment == 1) {
      if (flags->alternateForm == 1) {
        length = 1;
      }
      if (flags->alternateForm == 1 && c != 0) {
        result += s21_appendCharToStr('0', str);
      }
      if (flags->precision > (int)s21_strlen(tmp)) {
        result +=
            s21_fillWidth(flags->precision, s21_strlen(tmp) + length, 1, str);
      }
      while (i < (int)s21_strlen(tmp)) {
        result += s21_appendCharToStr(tmp[i], str);
        i++;
      }
      if (flags->width != 0) {
        result += s21_fillWidth(flags->width, result, 0, str);
      }
    } else {
      if (flags->alternateForm == 1 && c != 0) {
        length = 1;
        if (flags->precision == (int)s21_strlen(tmp) && flags->width == 0) {
          result += s21_appendCharToStr('0', str);
        }
      }
      if (flags->zeroPadding == 1 && flags->precision < flags->width &&
          flags->precision > (int)s21_strlen(tmp)) {
        result += s21_fillWidth(flags->width, flags->precision, 0, str);
        result +=
            s21_fillWidth(flags->width, result + flags->precision, 1, str);
      }
      if (flags->zeroPadding == 0 && flags->width != 0) {
        result +=
            s21_fillWidth(flags->width, flags->precision + length, 0, str);
      }
      if (flags->precision > (int)s21_strlen(tmp)) {
        result += s21_fillWidth(flags->precision, s21_strlen(tmp), 1, str);
      }

      int lenghth_loop = (int)s21_strlen(tmp);
      int i = 0;
      while (i < lenghth_loop) {
        result += s21_appendCharToStr(tmp[i], str);
        i++;
      }
    }
  }
  free(tmp);
  result = s21_strlen(str);
  return result;
}

int s21_sprintf_nan_inf(FormatFlags *flags, char *str, int nan,
                        int is_negative) {
  int length_str;
  if (is_negative > 0)
    length_str = 4;
  else
    length_str = 3;
  int len = length_str;
  char *temp = (char *)calloc(length_str + 1, sizeof(char));
  if (temp == s21_NULL) {
    flags->error = 1;
    exit(0);
  }

  if (flags->uppercase && nan) {
    s21_strcpy(temp, "NAN");
  } else if (!flags->uppercase && nan) {
    s21_strcpy(temp, "nan");
  } else if (flags->uppercase == 0 && !nan) {
    s21_strcpy(temp, "inf");
  } else if (flags->uppercase && !nan) {
    s21_strcpy(temp, "INF");
  }

  if (flags->alignment) {
    if (len == 4) s21_appendCharToStr('-', str);
    s21_strcat(str, temp);
  }
  if (flags->width > length_str) {
    length_str += s21_fillWidth(flags->width, length_str, 0, str);
  }

  if (!flags->alignment) {
    if (len == 4) s21_appendCharToStr('-', str);
    s21_strcat(str, temp);
  }

  free(temp);
  int result = 0;
  result = s21_strlen(str);
  return result;
}

int s21_sprintf_e(long double number, int letter_flag, FormatFlags *flags,
                  char *str) {
  s21_size_t buffer_size = 100;
  long double original_number = number;
  char *final_str = (char *)calloc(buffer_size, sizeof(char));

  int precision = flags->precision == 0 ? 6 : flags->precision;
  if ((flags->type == 'g' || flags->type == 'G') && precision != 0) precision--;
  int is_negative = number < 0 || (number == 0 && (1 / number) < 0);
  if (is_negative) {
    flags->showSign = 1;
    number *= -1;
  }
  char letter = letter_flag ? 'e' : 'E';
  int result = 0;
  int e = s21_convertToMantissa(&number, precision);

  char left_part[2];
  char *convertedString =
      s21_convertToBase(s21_convertDoubleToLong(number, 1), flags);
  left_part[0] = convertedString[0];
  left_part[1] = '\0';

  char right_part[50] = "";
  int length_diff = 0;

  long double right_digits = fmodl(number, 1.0);
  long double temp = right_digits;
  for (int i = 0; i < precision; i++) {
    temp *= 10.0;
  }
  if (!(flags->type == 'g' && flags->alternateForm == 0) || temp != 0) {
    length_diff += s21_createPartWithoutMantissa(right_part, right_digits,
                                                 precision, flags);
  } else
    flags->precision = 0;

  int length = s21_lengthWithoutWidth(*flags, is_negative, e) - length_diff;
  char right_mantissa_part[6];
  s21_rightMantissaPart(right_mantissa_part, letter, e);
  s21_concatPartsOfMantissa(final_str, left_part, right_part,
                            right_mantissa_part, *flags, is_negative, length);
  if ((s21_size_t)result + 1 > buffer_size) {
    buffer_size *= 2;
    final_str = (char *)realloc(final_str, buffer_size * sizeof(char));
  }

  if (flags->error)
    result = 0;
  else {
    if (flags->spaceBeforePositive == 1 && flags->showSign == 0 &&
        original_number >= 0) {
      s21_appendCharToStr(' ', str);
    }
    if (flags->showSign == 1) {
      original_number > 0 ? s21_appendCharToStr('+', str)
                          : s21_appendCharToStr('-', str);
    }
    s21_strcat(str, final_str);
  }
  result += s21_strlen(str);

  free(final_str);
  free(convertedString);
  result = s21_strlen(str);
  return result;
}

int s21_sprintf_f(long double number, FormatFlags *flags, char *str) {
  int is_Negative = 0, sign = 0, length_int = 0, length_digit = 0;
  int length_for_str = 0;
  if (flags->spaceBeforePositive != 0 || flags->showSign != 0 || number < 0)
    sign = 1;
  if (flags->precision == 0) flags->precision = 6;
  if (number < 0) {
    is_Negative = 1;
    number *= -1;
  }

  length_int = s21_getLengthofNumber((int)number);
  length_digit = length_int + flags->precision + sign;
  if (flags->precision != 0 || flags->alternateForm != 0) length_digit++;
  length_for_str = (flags->width > length_digit) ? flags->width : length_digit;
  char *temp_convert = s21_NULL, *temp = s21_NULL;
  temp = (char *)calloc(length_for_str + 1, sizeof(char));
  if (!temp) {
    exit(0);
  }
  if (flags->precision == 0) {
    temp_convert = s21_convertToBase((int)number, flags);
    int counter = 0;
    while (temp_convert[counter]) {
      s21_appendCharToStr(temp_convert[counter], temp);
      counter++;
    }
    if (flags->alternateForm == 1) temp[length_int] = '.';
  } else {
    s21_fcvt(number, flags, length_int, temp);
  }

  if ((flags->type == 'g' || flags->type == 'G') && flags->alternateForm == 0) {
    int remove_zero = 0;
    for (int i = s21_strlen(temp) - 1; i >= length_int; i--) {
      if (temp[i] == '0' || temp[i] == '.') {
        temp[i] = '\0';
        remove_zero++;
      } else {
        break;
      }
    }
    flags->precision -= remove_zero;
    length_digit = s21_strlen(temp) + sign;
    length_for_str =
        (flags->width > length_digit) ? flags->width : length_digit;
  }

  int has_sign = 0;
  if (flags->alignment == 1) {
    s21_appendCharSignToStr(flags, is_Negative, str);
    for (int i = 0; i < length_digit; i++) {
      s21_appendCharToStr(temp[i], str);
    }
  }

  if (length_for_str - length_digit > 0) {
    if (flags->alignment == 0 && flags->zeroPadding == 1) {
      s21_appendCharSignToStr(flags, is_Negative, str);
      has_sign = 1;
    }
    s21_fillWidth(flags->width, length_digit, flags->zeroPadding, str);
  }
  if (flags->alignment == 0) {
    if (!has_sign) s21_appendCharSignToStr(flags, is_Negative, str);
    for (int i = 0; i < length_digit; i++) {
      s21_appendCharToStr(temp[i], str);
    }
  }

  free(temp);
  int result = 0;
  result = s21_strlen(str);
  return result;
}

int s21_sprintf_g(long double b, FormatFlags *flags, char *str) {
  int res;
  if (flags->precision == -1)
    flags->precision = 6;
  else if (flags->precision == 0)
    flags->precision = 1;

  long double b_copy = b;
  if (b_copy < 0) b_copy *= -1;

  int e = s21_convertToMantissa(&b_copy, flags->precision);
  if (flags->precision > e && e >= -4) {
    flags->precision -= (e + 1);
    res = s21_sprintf_f(b, flags, str);
  } else {
    res = s21_sprintf_e(b, flags->type == 'g', flags, str);
  }
  return res;
}

int s21_handleCharSpecifier(int value, FormatFlags *flags, char *str) {
  int result = 1;
  if (flags->alignment == 1) {
    s21_appendCharToStr((char)value, str);
  }
  result += s21_fillWidth(flags->width, 1, flags->zeroPadding, str);
  if (flags->alignment == 0) {
    s21_appendCharToStr((char)value, str);
  }
  return result;
}

int s21_handleStringSpecifier(char *value, FormatFlags *flags, char *str) {
  int result = 0, i = 0, len_s = s21_strlen(value);
  if (flags->zeroPadding == 1 || flags->alternateForm == 1 ||
      flags->showSign == 1 || flags->spaceBeforePositive == 1) {
    flags->error = 1;
    result = 0;
  } else {
    if (flags->precision > len_s || flags->precision < 0) {
      flags->precision = len_s;
    } else if (flags->precision > 0) {
      len_s = flags->precision;
    }
    if (flags->alignment == 1) {
      for (i = 0; i < len_s; i++) {
        s21_appendCharToStr(value[i], str);
      }
      result += len_s;
    }
    if (flags->width > len_s || flags->width < 0) {
      result += s21_fillWidth(flags->width, len_s, flags->zeroPadding, str);
    }
    if (flags->alignment == 0) {
      while (i < len_s) {
        result += s21_appendCharToStr(value[i], str);
        i++;
      }
    }
  }
  result = s21_strlen(str);
  return result;
}

int s21_handleIntegerSpecifier(va_list args, FormatFlags *flags, char *str) {
  int result = 0, i = 0;
  va_list argsCopy;
  va_copy(argsCopy, args);
  int value = va_arg(argsCopy, long long int);
  if (value < 0 || flags->showSign == 1 || value == 0) {
    if (value == 0) {
      if (flags->alignment == 1) {
        if (flags->showSign == 1) s21_appendCharToStr('+', str);
        flags->precision--;
        s21_sprintf_u_d_i(args, flags, str);
      } else if (flags->alignment == 0 && flags->zeroPadding == 0 &&
                 flags->showSign == 0) {
        if (flags->spaceBeforePositive == 1 && flags->width <= flags->precision)
          s21_appendCharToStr(' ', str);
        if (flags->spaceBeforePositive == 1 && flags->width == 0 &&
            flags->precision == -1)
          s21_appendCharToStr(' ', str);
        flags->precision--;
        flags->width--;
        s21_sprintf_u_d_i(args, flags, str);
      } else if (flags->zeroPadding == 1 && flags->showSign == 0) {
        flags->precision--;
        s21_charStrloop3(flags->width, 0, 0, &i, '0', str);
      } else if (flags->showSign == 1) {
        if (flags->width != 0 && flags->precision != -1 &&
            flags->width > flags->precision) {
          if (flags->precision == 0 && flags->zeroPadding == 0)
            s21_charStrloop3(flags->width - 2, flags->precision, 0, &i, ' ',
                             str);
          if (flags->precision > 0)
            s21_charStrloop3(flags->width - 1, flags->precision, 0, &i, ' ',
                             str);
          s21_appendCharToStr('+', str);
          s21_charStrloop3(flags->width - 1, 0, 0, &i, '0', str);
        } else if (flags->precision > flags->width) {
          s21_appendCharToStr('+', str);
          s21_charStrloop3(flags->precision, 0, 0, &i, '0', str);
        } else if (flags->width > 0 && flags->precision == -1 &&
                   flags->zeroPadding == 0) {
          s21_charStrloop2(flags->width - 1, 2, &i, ' ', str);
          s21_appendCharToStr('+', str);
          s21_appendCharToStr('0', str);
        } else if (flags->width > 0 && flags->precision == -1 &&
                   flags->zeroPadding == 1) {
          s21_appendCharToStr('+', str);
          s21_charStrloop3(flags->width, 1, 0, &i, '0', str);
        } else if (flags->precision != -1) {
          s21_appendCharToStr('+', str);
          s21_charStrloop3(flags->precision, 0, 0, &i, '0', str);
        } else {
          s21_appendCharToStr('+', str);
          s21_appendCharToStr('0', str);
        }
      }
    } else if (flags->width > s21_getLengthofNumber(value) &&
               flags->precision <= s21_getLengthofNumber(value) &&
               flags->alignment == 0 && flags->precision != -1 &&
               flags->zeroPadding != 1) {
      if (flags->precision != s21_getLengthofNumber(value)) {
        if (flags->showSign == 1 && value > 0) {
          s21_charStrloop2(flags->width - 1, value, &i, ' ', str);
          s21_appendCharToStr('+', str);
          s21_strUpdate(value, str);
        } else {
          s21_charStrloop2(flags->width, value, &i, ' ', str);
          s21_strUpdate(value, str);
        }
      } else {
        if (flags->showSign == 1 && value > 0) {
          s21_charStrloop1(flags->width, value, -1, &i, ' ', str);
          s21_appendCharToStr('+', str);
          s21_strUpdate(value, str);
        } else {
          s21_charStrloop1(flags->width, value, -1, &i, ' ', str);
          s21_appendCharToStr('-', str);
          s21_appendCharToStr('0', str);
          value *= -1;
          s21_strUpdate(value, str);
        }
      }
    } else if (flags->width > s21_getLengthofNumber(value) &&
               flags->zeroPadding == 0 &&
               flags->precision > s21_getLengthofNumber(value) &&
               flags->alignment == 0 && flags->width > flags->precision) {
      if (flags->showSign == 1 && value > 0) {
        s21_charStrloop3(flags->width, flags->precision, -1, &i, ' ', str);
        s21_appendCharToStr('+', str);
        s21_charStrloop2(flags->width - 1, value, &i, '0', str);
        s21_strUpdate(value, str);
      } else {
        s21_charStrloop3(flags->width, flags->precision, -1, &i, ' ', str);
        s21_appendCharToStr('-', str);
        s21_charStrloop2(flags->width, value, &i, '0', str);
        s21_strUpdate(-value, str);
      }
    } else if (flags->zeroPadding == 1 && flags->width > flags->precision &&
               flags->precision > s21_getLengthofNumber(value)) {
      if (flags->showSign == 1 && value > 0) {
        s21_charStrloop3(flags->width, flags->precision, -1, &i, ' ', str);
        s21_appendCharToStr('+', str);
        s21_charStrloop2(flags->width - 1, value, &i, '0', str);
        s21_strUpdate(value, str);
      } else {
        s21_charStrloop3(flags->width, flags->precision, -1, &i, ' ', str);
        s21_appendCharToStr('-', str);
        s21_charStrloop2(flags->width, value, &i, '0', str);
        s21_strUpdate(value, str);
      }
    } else if (flags->zeroPadding == 1 && flags->width > flags->precision &&
               flags->precision < s21_getLengthofNumber(value) &&
               flags->precision != -1) {
      if (flags->showSign == 1 && value > 0) {
        s21_appendCharToStr('+', str);
        s21_charStrloop2(flags->width - 1, value, &i, '0', str);
        s21_strUpdate(value, str);
      } else {
        if (flags->width > s21_getLengthofNumber(-value)) {
          s21_appendCharToStr('-', str);
          s21_charStrloop2(flags->width, value, &i, '0', str);
          s21_charStrloop3(flags->precision, -value, 1, &i, '0', str);
          s21_strUpdate(-value, str);
        } else {
          s21_charStrloop3(flags->precision, -value, 1, &i, '0', str);
          s21_strUpdate(value, str);
        }
      }
    } else if (flags->width <= flags->precision) {
      if (flags->showSign == 1 &&
          (value > 0 || flags->lengthModifier == 'l' || flags->type == 'u')) {
        s21_appendCharToStr('+', str);
        s21_sprintf_u_d_i(args, flags, str);
      } else {
        s21_sprintf_u_d_i(args, flags, str);
      }
    } else if (flags->width <= s21_getLengthofNumber(value)) {
      if (flags->showSign == 1 && value > 0) {
        s21_appendCharToStr('+', str);
        s21_strUpdate(value, str);
      } else {
        s21_strUpdate(value, str);
      }
    } else if (flags->alignment == 1 && flags->width > flags->precision) {
      if (flags->precision < s21_getLengthofNumber(value)) {
        if (flags->showSign == 1 && value > 0) {
          s21_appendCharToStr('+', str);
          s21_strUpdate(value, str);
          i += s21_getLengthofNumber(value);
          s21_charStrloop1(flags->width, 0, 0, &i, ' ', str);
        } else {
          s21_strUpdate(value, str);
          i += s21_getLengthofNumber(value);
          s21_charStrloop1(flags->width + 1, 0, 0, &i, ' ', str);
        }
      } else {
        if (flags->showSign == 1 && value > 0) {
          s21_appendCharToStr('+', str);
          i++;
          s21_charStrloop1(flags->precision, value, 1, &i, '0', str);
          s21_strUpdate(value, str);
          i += s21_getLengthofNumber(value);
          s21_charStrloop2(flags->width + 1, 0, &i, ' ', str);
        } else {
          s21_appendCharToStr('-', str);
          flags->width++;
          i++;
          s21_charStrloop1(flags->precision, -value, 1, &i, '0', str);
          if (value < 0) value = -value;
          s21_strUpdate(value, str);
          i += s21_getLengthofNumber(value);
          s21_charStrloop2(flags->width, 0, &i, ' ', str);
        }
      }
    } else if (flags->precision == -1 &&
               flags->width > s21_getLengthofNumber(value) &&
               flags->zeroPadding == 1 && flags->showSign == 1) {
      if (value < 0) {
        s21_appendCharToStr('-', str);
        s21_charStrloop2(flags->width, value, &i, '0', str);
        s21_strUpdate(value, str);
      } else {
        s21_appendCharToStr('+', str);
        i++;
        s21_charStrloop2(flags->width, value, &i, '0', str);
        s21_strUpdate(value, str);
      }
    } else if (flags->precision == -1 &&
               flags->width > s21_getLengthofNumber(value) &&
               flags->zeroPadding == 0) {
      if (flags->showSign == 1 && value > 0) {
        s21_charStrloop2(flags->width - 1, value, &i, ' ', str);
        s21_appendCharToStr('+', str);
        s21_strUpdate(value, str);
      } else {
        s21_charStrloop2(flags->width, value, &i, ' ', str);
        s21_strUpdate(value, str);
      }
    } else if (flags->precision == -1 &&
               flags->width > s21_getLengthofNumber(value) && value < 0 &&
               flags->zeroPadding == 1) {
      s21_appendCharToStr('-', str);
      i++;
      s21_charStrloop2(flags->width, -value, &i, '0', str);
      s21_strUpdate(value, str);
    }
  } else {
    if (flags->spaceBeforePositive == 1 &&
        flags->width > s21_getLengthofNumber(value)) {
      flags->width = flags->width - 1;
    }
    result = s21_sprintf_u_d_i(args, flags, str);
  }
  result = s21_strlen(str);
  va_end(argsCopy);
  return result;
}

int s21_handlePointerSpecifier(void *ptr, FormatFlags *flags, char *str) {
  if (ptr == s21_NULL) {
    s21_strcat(str, "(nil)");
    return 5;
  }
  unsigned long long int p = (unsigned long long int)ptr;
  static const char HexLowercaseSymbolSet[] = "0123456789abcdef";
  char buffer[50];
  char *temp = &buffer[sizeof(buffer) - 1];
  *temp = '\0';

  if (p == 0) {
    *--temp = '0';
  } else {
    while (p != 0 && temp > buffer) {
      *--temp = HexLowercaseSymbolSet[p % 16];
      p /= 16;
    }
  }
  int length = s21_strlen(temp) + 2;
  if (flags->zeroPadding == 1 || flags->showSign == 1 ||
      flags->spaceBeforePositive == 1 || flags->alternateForm == 1 ||
      flags->lengthModifier == 1) {
    flags->error = 1;
  } else {
    if (length < flags->width && flags->alignment == 1) {
      s21_appendCharToStr('0', str);
      s21_appendCharToStr('x', str);
      s21_strcat(str, temp);
      if (flags->alignment == 1) {
        s21_fillWidth(flags->width, length, flags->zeroPadding, str);
      }
    } else {
      if (length < flags->width && flags->alignment == 0) {
        s21_fillWidth(flags->width, length, flags->zeroPadding, str);
      }
      s21_appendCharToStr('0', str);
      s21_appendCharToStr('x', str);
      s21_strcat(str, temp);
    }
  }

  return s21_strlen(str);
}

int s21_handleUnsignedSpecifier(va_list args, char s21_specifier,
                                FormatFlags *flags, char *str) {
  switch (s21_specifier) {
    case 'u':
      return s21_sprintf_u_d_i(args, flags, str);
    case 'x':
    case 'X':
      return s21_sprintf_x(va_arg(args, unsigned long int), s21_specifier,
                           flags, str);
    case 'o':
      return s21_sprintf_o(va_arg(args, unsigned long int), flags, str);
    default:
      return 0;
  }
}

int s21_handlePercentSpecifier(FormatFlags *flags, char *str) {
  int res = 1;
  if (flags->width > 1) res = flags->width;
  if (flags->alignment == 1) {
    s21_appendCharToStr('%', str);
  }
  s21_fillWidth(flags->width, 1, flags->zeroPadding, str);

  if (flags->alignment == 0) s21_appendCharToStr('%', str);

  return res;
}

int s21_handleFloatSpecifier(va_list args, char s21_specifier,
                             FormatFlags *flags, char *str) {
  long double number;
  if (flags->lengthModifier != 'L') {
    number = (long double)va_arg(args, double);
  } else {
    number = va_arg(args, long double);
  }
  if (isnan(number) || isinf(number)) {
    int isNegative = signbit(number);
    return s21_sprintf_nan_inf(flags, str, isnan(number), isNegative);
  }
  switch (s21_specifier) {
    case 'f':
    case 'F':
      return s21_sprintf_f(number, flags, str);
    case 'g':
    case 'G':
      return s21_sprintf_g(number, flags, str);
    case 'e':
    case 'E':
      return s21_sprintf_e(number, flags->type == 'e', flags, str);
    default:
      return 0;
  }
}

void s21_handleNumSpecifier(int i, va_list args) { *(va_arg(args, int *)) = i; }

int s21_translateSpecifier(char s21_specifier, FormatFlags *flags, va_list args,
                           char *str) {
  int result = 0;
  flags->type = s21_specifier;
  switch (s21_specifier) {
    case 'c':
      result += s21_handleCharSpecifier(va_arg(args, int), flags, str);
      break;
    case 's':
      result += s21_handleStringSpecifier(va_arg(args, char *), flags, str);
      break;
    case 'd':
    case 'i':
      result += s21_handleIntegerSpecifier(args, flags, str);
      break;
    case 'p':
      result += s21_handlePointerSpecifier(va_arg(args, void *), flags, str);
      break;
    case 'u':
    case 'x':
    case 'X':
    case 'o':
      result += s21_handleUnsignedSpecifier(args, s21_specifier, flags, str);
      break;
    case '%':
      result += s21_handlePercentSpecifier(flags, str);
      break;
    case 'e':
    case 'g':
    case 'E':
    case 'G':
    case 'f':
    case 'F':
      result += s21_handleFloatSpecifier(args, s21_specifier, flags, str);
      break;
  }
  return result;
}
