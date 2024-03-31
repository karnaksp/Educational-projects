#include "s21_sscanf.h"

void s21_isspace(char **temp, FormatFlags *flags) {
  while (isspace(**temp)) {
    (*temp)++;
    flags->char_count++;
  }
}

int s21_determineBase(char **str, FormatFlags *flags) {
  int base = 0;

  if (**str == '0') {
    (*str)++;
    if (**str == 'x' || **str == 'X') {
      base = 16;
      (*str)++;
    } else {
      base = 8;
    }
  } else {
    if (flags->type == 'x' || flags->type == 'X') {
      base = 16;
    } else if (flags->type == 'o') {
      base = 8;
    } else {
      base = 10;
    }
  }
  return base;
}

void s21_process_sign(char **temp, FormatFlags *flags) {
  if (**temp == '+') {
    flags->showSign = 1;
    (*temp)++;
  } else if (**temp == '-') {
    flags->showSign = -1;
    (*temp)++;
  }
}

void s21_process_hex_prefix(char **temp, char *digits, int *digitCount) {
  if ((*temp)[0] == '0' && ((*temp)[1] == 'x' || (*temp)[1] == 'X')) {
    digits[*digitCount] = (*temp)[0];
    digits[*digitCount + 1] = (*temp)[1];
    (*temp) += 2;
    (*digitCount) += 2;
  }
}

void s21_process_nan_prefix(char **temp, char *digits, int *digitCount) {
  digits[*digitCount] = **temp;
  digits[*digitCount + 1] = (*temp)[1];
  digits[*digitCount + 2] = (*temp)[2];
  (*temp) += 3;
  (*digitCount) += 3;
  digits[*digitCount] = '\0';
}

void s21_process_digit(char **temp, char *digits, int *digitCount) {
  digits[*digitCount] = **temp;
  (*digitCount)++;
  (*temp)++;
}

void s21_process_null_flags(FormatFlags *flags) {
  flags->is_format = 0;
  flags->width = 0;
  flags->showSign = 1;
}

long s21_atoi(char *str, FormatFlags *flags) {
  long result = 0;
  int base = 0, char_count = 0;
  int str_len = s21_strlen(str);
  if (flags->showSign == 0) flags->showSign = 1;
  if (flags->width < str_len) flags->width = str_len;
  if (base == 0) base = s21_determineBase(&str, flags);

  while (*str && (char_count < flags->width)) {
    int digit;
    if (*str >= '0' && *str <= '9')
      digit = *str - '0';
    else if (*str >= 'A' && *str <= 'F')
      digit = *str - 'A' + 10;
    else if (*str >= 'a' && *str <= 'f')
      digit = *str - 'a' + 10;
    else
      break;
    result = result * base + digit;
    str++;
    char_count++;
  }
  return flags->showSign * result;
}

unsigned long s21_strtoul(char *str, FormatFlags *flags) {
  unsigned long long result = 0;
  int base = 0;
  int char_count = 0;
  int str_len = s21_strlen(str);
  s21_isspace(&str, flags);
  if (base == 0) base = s21_determineBase(&str, flags);
  if (flags->width < base) flags->width = base;
  str_len = s21_strlen(str);
  int digit;
  while (char_count < base && char_count < str_len) {
    if (s21_is_digit(*str))
      digit = *str - '0';
    else
      digit = s21_tolower(*str) - 'a' + 10;
    result = result * base + digit;
    str++;
    char_count++;
  }
  if (flags->showSign == -1) {
    result *= flags->showSign;
    flags->showSign = 1;
  }
  return result;
}

double s21_atof(char *str, FormatFlags *flags) {
  double result = 0;
  int char_count = 0;
  int str_len = s21_strlen((const char *)str);
  if (flags->width < str_len) flags->width = str_len;
  if (flags->showSign == 0) flags->showSign = 1;

  while (char_count < flags->width) {
    int i = 0;
    if (*str == '.' && char_count == 0) {
      result = 0;
      char_count++;
      i++;
    }
    while (s21_is_digit(*str)) {
      result = result * 10 + (*str - '0');
      str++;
      char_count++;
      i++;
    }
    if (*str == '.' && s21_is_digit(str[1])) {
      double fraction = 10;
      str++;
      char_count++;
      while (s21_is_digit(*str)) {
        result += (*str - '0') / fraction;
        fraction *= 10.0;
        str++;
        char_count++;
        i++;
      }
    }
    if ((*str == 'e' || *str == 'E') &&
        (s21_is_digit(str[2]) || s21_is_digit(str[1]))) {
      int exponent = 0;
      int exponentSign = 1;
      str++;
      char_count++;
      if (*str == '+') {
        str++;
        char_count++;
      } else if (*str == '-') {
        exponentSign = -1;
        str++;
        char_count++;
      }
      int str_len = s21_strlen(str);
      if (i > 0) {
        if (exponentSign < 0)
          flags->width = i + 1 + str_len;
        else
          flags->width = i + str_len;
      }
      while (str_len > 0) {
        exponent = exponent * 10 + (*str - '0');
        str++;
        char_count++;
        str_len--;
      }
      result *= pow(10, exponentSign * exponent);
    }
    if ((*str == 'n' || *str == 'N') && (str[1] == 'a' || str[1] == 'A') &&
        (str[2] == 'n' || str[2] == 'N')) {
      str += 3;
      char_count += 3;
      flags->width = 3;
      result = NAN;
    }
    if ((*str == 'i' || *str == 'I') && (str[1] == 'n' || str[1] == 'N') &&
        (str[2] == 'f' || str[2] == 'F')) {
      str += 3;
      char_count += 3;
      flags->width = 3;
      result = INFINITY;
    }
  }
  return result * flags->showSign;
}

int s21_sscanf_xou(va_list args, FormatFlags *flags, char **temp) {
  int result = 0;
  char *digits = s21_NULL;
  int digitCount = 0;
  s21_isspace(temp, flags);
  digits = malloc((s21_strlen((const char *)*temp) + 1) * sizeof(char));
  const char *HexLowercaseSymbolSet = "0123456789abcdef";
  const char *HexUppercaseSymbolSet = "0123456789ABCDEF";

  if (*temp) {
    s21_process_sign(temp, flags);
    if (!s21_is_digit(**temp)) {
      flags->error = 1;
      free(digits);
      return 0;
    }
    s21_process_hex_prefix(temp, digits, &digitCount);
    while (**temp != '\0' &&
           (s21_is_digit(**temp) ||
            (flags->type == 'x' &&
             s21_strchr(HexLowercaseSymbolSet, **temp) != s21_NULL) ||
            (flags->type == 'X' &&
             s21_strchr(HexUppercaseSymbolSet, **temp) != s21_NULL))) {
      s21_process_digit(temp, digits, &digitCount);
    }
    digits[digitCount] = '\0';
  }

  if (!flags->dynamicWidth) {
    if (flags->lengthModifier == 'h') {
      *(short unsigned *)va_arg(args, void *) =
          (unsigned long)s21_atoi(digits, flags);
    } else if (flags->lengthModifier == 'l') {
      *(long unsigned *)va_arg(args, void *) =
          (unsigned long)s21_atoi(digits, flags);
    } else {
      *(unsigned *)va_arg(args, void *) =
          (unsigned long)s21_atoi(digits, flags);
    }
  } else {
    (unsigned long)s21_atoi(digits, flags);
    flags->dynamicWidth = 0;
  }

  free(digits);
  result++;
  s21_process_null_flags(flags);
  return result;
}

int s21_sscanf_di(va_list args, FormatFlags *flags, char **temp) {
  int result = 0;
  char *digits = s21_NULL;
  int digitCount = 0;
  s21_isspace(temp, flags);
  digits = malloc((s21_strlen((const char *)*temp) + 1) * sizeof(char));

  if (*temp) {
    s21_process_sign(temp, flags);
    if (!s21_is_digit(**temp)) {
      flags->error = 1;
      free(digits);
      return 0;
    }
    s21_process_hex_prefix(temp, digits, &digitCount);
    while (s21_is_digit(**temp)) {
      s21_process_digit(temp, digits, &digitCount);
    }
    digits[digitCount] = '\0';
  }
  if (!flags->dynamicWidth) {
    if (flags->lengthModifier == 'h') {
      *(short int *)va_arg(args, void *) = s21_atoi(digits, flags);
    } else if (flags->lengthModifier == 'l') {
      *(long int *)va_arg(args, void *) = s21_atoi(digits, flags);
    } else {
      *(int *)va_arg(args, void *) = s21_atoi(digits, flags);
    }
  } else {
    s21_atoi(digits, flags);
    flags->dynamicWidth = 0;
  }
  free(digits);
  result++;
  s21_process_null_flags(flags);
  return result;
}

int s21_sscanf_p(va_list args, FormatFlags *flags, char **temp) {
  int result = 0;
  char *digits = s21_NULL;
  int digitCount = 0;
  s21_isspace(temp, flags);
  digits = malloc((s21_strlen((const char *)*temp) + 1) * sizeof(char));
  if (*temp) {
    s21_process_sign(temp, flags);
    if ((*temp)[0] == '0' && ((*temp)[1] == 'x' || (*temp)[1] == 'X')) {
      digits[digitCount] = (*temp)[0];
      digits[digitCount + 1] = (*temp)[1];
      (*temp) += 2;
      digitCount += 2;
      while (!isspace(**temp) && **temp != '\0' &&
             (isxdigit(**temp) || **temp == '-' || **temp == '+')) {
        digits[digitCount] = **temp;
        digitCount++;
        (*temp)++;
      }
      digits[digitCount] = '\0';
    } else {
      flags->error = 1;
      free(digits);
      return 0;
    }
    result++;
  }
  if (!flags->dynamicWidth) {
    *(void **)va_arg(args, void **) = (void *)s21_strtoul(digits, flags);
  } else {
    s21_strtoul(digits, flags);
    flags->dynamicWidth = 0;
  }

  free(digits);
  s21_process_null_flags(flags);
  return result;
}

void s21_sscanf_n(va_list args, FormatFlags *flags, char **temp) {
  int digitCount = s21_strlen((const char *)temp) + flags->char_count +
                   flags->spaceBeforePositive - flags->firstSpace - 1;

  if (flags->lengthModifier == 'h') {
    *(short int *)va_arg(args, void *) = digitCount;
  } else if (flags->lengthModifier == 'l') {
    *(long int *)va_arg(args, void *) = digitCount;
  } else {
    *(int *)va_arg(args, void *) = digitCount;
  }
  flags->is_format = 0;
}

void s21_sscanf_percent(char **temp, FormatFlags *flags) {
  while (isspace(**temp)) {
    (*temp)++;
    flags->char_count++;
    flags->spaceBeforePositive++;
  }
  if (flags->type == **temp) {
    (*temp)++;
  } else {
    flags->error = 1;
  }
  flags->is_format = 0;
}

int s21_sscanf_efg(va_list args, FormatFlags *flags, char **temp) {
  int result = 0;
  char *digits = s21_NULL;
  int digitCount = 0;
  s21_isspace(temp, flags);
  digits = malloc((s21_strlen((const char *)*temp) + 1) * sizeof(char));

  if (*temp) {
    s21_process_sign(temp, flags);
    if ((**temp == 'n' || **temp == 'N') &&
        ((*temp)[1] == 'a' || (*temp)[1] == 'A') &&
        ((*temp)[2] == 'n' || (*temp)[2] == 'N')) {
      s21_process_nan_prefix(temp, digits, &digitCount);
    } else if ((**temp == 'i' || **temp == 'I') &&
               ((*temp)[1] == 'n' || (*temp)[1] == 'N') &&
               ((*temp)[2] == 'f' || (*temp)[2] == 'F')) {
      s21_process_nan_prefix(temp, digits, &digitCount);
    } else if ((s21_is_digit(**temp) ||
                (**temp == '.' && s21_is_digit((*temp)[1]))) &&
               digits != s21_NULL) {
      int pt = 0;
      while (**temp != '\0' &&
             (s21_is_digit(**temp) || **temp == '.' || **temp == 'e' ||
              **temp == 'E' || **temp == '-' || **temp == '+')) {
        if (**temp == '.') {
          pt++;
          if (pt == 2) break;
        }
        s21_process_digit(temp, digits, &digitCount);
      }
      digits[digitCount] = '\0';
    } else {
      flags->error = 1;
      free(digits);
      return 0;
    }
  }
  if (!flags->dynamicWidth) {
    if (flags->lengthModifier == 'L') {
      *(long double *)va_arg(args, void *) = s21_atof(digits, flags);
    } else if (flags->lengthModifier == 'l') {
      *(double *)va_arg(args, void *) = s21_atof(digits, flags);
    } else {
      *(float *)va_arg(args, void *) = (float)s21_atof(digits, flags);
    }
  } else {
    s21_atof(digits, flags);
    flags->dynamicWidth = 0;
  }
  free(digits);
  result++;
  s21_process_null_flags(flags);
  return result;
}

int s21_sscanf_cs(va_list args, FormatFlags *flags, char **temp) {
  int result = 0;
  char *tmp = s21_NULL;
  if (flags->type == 's') {
    int i = 0;
    while (!isspace(**temp) && **temp != '\0') {
      i++;
      (*temp)++;
    }
    *temp -= i;
    tmp = malloc((i + 1) * sizeof(char));
    if (tmp != s21_NULL) {
      s21_strncpy(tmp, *temp, i);
      tmp[i] = '\0';
    } else {
      flags->error = 1;
      return 0;
    }
  } else {
    tmp = *temp;
  }
  int len_s = s21_strlen((const char *)tmp);
  if (flags->width == 0) {
    if (flags->type == 'c')
      flags->width = 1;
    else
      flags->width = len_s;
  }
  if (!flags->dynamicWidth) {
    char *dest = malloc((flags->width + 1) * sizeof(char));
    s21_strncpy(dest, tmp, flags->width);
    dest[flags->width] = '\0';
    if (flags->type == 'c') {
      char c = dest[0];
      char *arg = va_arg(args, char *);
      *arg = c;
    } else {
      char *arg = va_arg(args, char *);
      s21_strncpy(arg, dest, flags->width + 1);
    }
    free(dest);
  } else {
    flags->dynamicWidth = 0;
  }
  if (flags->type == 's') {
    (*temp) += len_s;
    while (isspace(**temp)) {
      ++(*temp);
      flags->spaceBeforePositive++;
    }
    *temp -= 1;
    free(tmp);
  } else {
    (*temp) += flags->width;
  }
  flags->is_format = 0;
  flags->width = 0;
  result++;
  return result;
}

int s21_sscanfTranslater(va_list args, FormatFlags *flags, char **temp,
                         char *format) {
  int result = 0;
  if (format != s21_NULL) {
    flags->type = *format;
    switch (*format) {
      case 'x':
      case 'X':
      case 'o':
      case 'u':
        result += s21_sscanf_xou(args, flags, temp);
        break;
      case 'p':
        result += s21_sscanf_p(args, flags, temp);
        break;
      case 'e':
      case 'E':
      case 'f':
      case 'g':
      case 'G':
        result += s21_sscanf_efg(args, flags, temp);
        break;
      case 'c':
        result += s21_sscanf_cs(args, flags, temp);
        break;
      case 'd':
      case 'i':
        result += s21_sscanf_di(args, flags, temp);
        break;
      case 's':
        result += s21_sscanf_cs(args, flags, temp);
        break;
      case 'n':
        s21_sscanf_n(args, flags, temp);
        break;
      case '%':
        s21_sscanf_percent(temp, flags);
        break;
      case 'h':
      case 'l':
      case 'L':
        flags->lengthModifier = *format;
        break;
      default:
        flags->error = 1;
        result = -1;
        break;
    }
  }
  return result;
}

int s21_sscanfReader(va_list args, FormatFlags *flags, char *temp,
                     char *format) {
  int result = 0;
  int format_length = s21_strlen(format);

  while (isspace(format[flags->char_count])) {
    flags->char_count++;
    flags->firstSpace++;
  }

  while (flags->char_count < format_length) {
    if (flags->error) {
      result = -1;
      break;
    }
    if (format[flags->char_count] == '%' && !flags->is_format &&
        format[flags->char_count + 1] != '\0') {
      flags->is_format = 1;
      flags->char_count++;
    }
    if (flags->is_format) {
      if (format[flags->char_count] == '*') {
        flags->dynamicWidth = 1;
        flags->char_count++;
      }
      if (s21_is_digit(format[flags->char_count])) {
        flags->alignment = 1;
        while (s21_is_digit(format[flags->char_count])) {
          flags->width = flags->width * 10 + format[flags->char_count] - '0';
          flags->char_count++;
        }
      }
      while (isspace(*temp)) temp++;
      result +=
          s21_sscanfTranslater(args, flags, &temp, &format[flags->char_count]);
      flags->char_count++;
    } else {
      if (isspace(format[flags->char_count])) {
        flags->char_count++;
      } else {
        if ((*temp) == format[flags->char_count]) temp++;
        flags->char_count++;
      }
    }
  }

  return result;
}

int s21_sscanf(const char *str, char *format, ...) {
  FormatFlags flags = s21_init_flags();
  int result = 0;
  char *temp = malloc((s21_strlen(str) + 1) * sizeof(char));
  if (str == s21_NULL || temp == s21_NULL) {
    flags.error = 1;
    free(temp);
    return -1;
  } else {
    temp = s21_strcpy(temp, str);
    va_list args;
    va_start(args, format);
    result = s21_sscanfReader(args, &flags, temp, format);
    va_end(args);
  }
  free(temp);
  return result;
}
