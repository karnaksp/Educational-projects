#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *ptr = str;
  int flag = 0;
  s21_size_t i = 0;
  for (; i < n; i++) {
    if (ptr[i] == (unsigned char)c) {
      flag = 1;
      break;
    }
  }
  return (flag) ? (void *)&ptr[i] : s21_NULL;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *str_k1 = str1;
  const unsigned char *str_k2 = str2;
  int flag = 0;
  int res = 0;
  for (s21_size_t i = 0; i < n; i++) {
    res = str_k1[i] - str_k2[i];
    if (res != 0) {
      flag = 1;
      break;
    }
  }
  return (flag) ? res : 0;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *tmp = (char *)dest;
  const char *s = (const char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    tmp[i] = s[i];
  }
  return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *s = (char *)src;
  char *d = (char *)dest;
  if (d < s) {
    for (s21_size_t i = 0; i < n; i++) {
      d[i] = s[i];
    }
  } else {
    for (s21_size_t i = n; i > 0; i--) {
      d[i - 1] = s[i - 1];
    }
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *str_ptr = (unsigned char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    *str_ptr++ = (unsigned char)c;
  }
  return str;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *dest_ptr = dest;
  while (*dest_ptr != '\0') {
    dest_ptr++;
  }
  for (s21_size_t i = 0; i < n && *src != '\0'; i++) {
    *dest_ptr = *src;
    dest_ptr++;
    src++;
  }
  *dest_ptr = '\0';
  return dest;
}

char *s21_strchr(const char *str, int c) {
  s21_size_t i = s21_strlen(str);
  if (c == '\0' && i > 0) {
    i++;
  }
  while (i > 0) {
    if (*str == c) {
      return (char *)str;
    }
    i--;
    if (i != 0) str++;
  }
  return s21_NULL;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int flag = 0;
  s21_size_t i = 0;
  for (; i < n; i++) {
    if (str1[i] != str2[i]) {
      flag = 1;
      break;
    }
    if (str1[i] == '\0') {
      break;
    }
  }
  return (flag) ? str1[i] - str2[i] : 0;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  while (i < n && src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  if (i < n) {
    for (; i < n; i++) {
      dest[i] = '\0';
    }
  }
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t i = 0;
  s21_size_t j = 0;
  int flag = 0;
  for (; str1[i] != '\0'; ++i) {
    for (; str2[j] != '\0'; ++j) {
      if (str1[i] == str2[j]) {
        flag = 1;
        break;
      }
    }
    if (flag) {
      break;
    }
  }
  return i;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t i = 0;
  for (; str[i] != '\0'; ++i)
    ;
  return i;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  const char *p1 = str1;
  const char *p2 = str2;
  int flag = 0;
  for (; *p1 != '\0'; ++p1) {
    for (; *p2 != '\0'; ++p2) {
      if (*p1 == *p2) {
        flag = 1;
        break;
      }
    }
    if (flag) {
      break;
    }
    p2 = str2;
  }
  return (flag) ? (char *)p1 : s21_NULL;
}

char *s21_strrchr(const char *str, int c) {
  char *last = s21_NULL;
  char *found;
  while ((found = s21_strchr(str, c)) != s21_NULL) {
    last = found;
    if (*found != '\0') {
      str = found + 1;
    } else {
      break;
    }
  }
  return last;
}

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t needle_length = s21_strlen(needle);
  int flag = 1;
  if (needle_length) {
    flag = 0;
    s21_size_t haystack_length = s21_strlen(haystack);
    for (; haystack_length >= needle_length; haystack_length--) {
      if (!s21_memcmp(haystack, needle, needle_length)) {
        flag = 1;
        break;
      }
      haystack++;
    }
  }

  return flag ? (char *)haystack : s21_NULL;
}

char *s21_strtok(char *str, const char *delim) {
  static char *rest_to_string;
  char *token = s21_NULL;
  if (str) {
    rest_to_string = str;
    for (; *rest_to_string && s21_strchr(delim, *rest_to_string);
         ++rest_to_string) {
      *rest_to_string = '\0';
    }
  }
  if (rest_to_string && *rest_to_string) {
    str = rest_to_string;

    for (; *rest_to_string && !s21_strchr(delim, *rest_to_string);
         ++rest_to_string) {
    }

    for (; *rest_to_string && s21_strchr(delim, *rest_to_string);
         ++rest_to_string) {
      *rest_to_string = '\0';
    }

    token = str;
  }
  return token;
}

char *s21_itoa(int num) {
  static char result[20];
  int i = 0;
  if (num == 0) {
    result[i++] = '0';
  } else {
    int is_negative = 0;
    if (num < 0) {
      is_negative = 1;
      num = -num;
    }
    while (num != 0) {
      result[i] = (num % 10) + '0';
      num /= 10;
      i++;
    }
    if (is_negative) {
      result[i] = '-';
      i++;
    }
  }
  result[i] = '\0';
  s21_reverse_string(result);
  return result;
}

void s21_reverse_string(char *str) {
  int length = s21_strlen(str);
  for (int start = 0, end = length - 1; start < end; start++, end--) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
  }
}

char *s21_strerror(int errnum) {
  static char error_result[STRERR_MAX] = {0};
  char *array_errors[] = ERRORLIST;
  if (errnum >= 0 && errnum <= ERR_MAX) {
    s21_strcpy(error_result, array_errors[errnum]);
  } else {
    s21_strcpy(error_result, ERROR);
    s21_strcat(error_result, s21_itoa(errnum));
  }
  return error_result;
}

char *s21_strcat(char *destination, const char *source) {
  char *dest_end = destination + s21_strlen(destination);
  while ((*dest_end++ = *source++))
    ;
  return destination;
}

char *s21_strcpy(char *dest, const char *src) {
  char *destination = dest;
  while ((*destination++ = *src++) != '\0') {
  }
  return dest;
}

void *s21_to_upper(const char *str) {
  char *result = s21_NULL;
  if (str != s21_NULL) {
    s21_size_t len_str = s21_strlen(str);
    result = (char *)malloc((len_str + 1) * sizeof(char));
    s21_size_t i = 0;
    for (; i < len_str; i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        result[i] = str[i] - OFFSET_LOWER_UPPER;
      } else {
        result[i] = str[i];
      }
    }
    result[len_str] = '\0';
  }
  return result;
}

void *s21_to_lower(const char *str) {
  char *result = s21_NULL;
  if (str != s21_NULL) {
    s21_size_t len_str = s21_strlen(str);
    result = (char *)malloc((len_str + 1) * sizeof(char));
    s21_size_t i = 0;
    for (; i < len_str; i++) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        result[i] = str[i] + OFFSET_LOWER_UPPER;
      } else {
        result[i] = str[i];
      }
    }
    result[len_str] = '\0';
  }
  return result;
}

int s21_tolower(int c) {
  if (c >= 'A' && c <= 'Z') {
    return c + ('a' - 'A');
  } else {
    return c;
  }
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = s21_NULL;
  if (src != s21_NULL && str != s21_NULL && s21_strlen(src) >= start_index) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t str_len = s21_strlen(str);
    s21_size_t res_len = src_len + str_len;
    result = (char *)malloc((res_len + 1) * sizeof(char));
    if (result != s21_NULL) {
      s21_memcpy(result, src, start_index);
      s21_memcpy(result + start_index, str, str_len);
      s21_memcpy(result + start_index + str_len, src + start_index,
                 src_len - start_index);
      result[res_len] = '\0';
    }
  }

  return result;
}

void *s21_trim(const char *src, const char *trim_chars) {
  int is_error = 0;
  char *result = s21_NULL;
  if (src) {
    char default_chars[7] = " \t\n\v\r\f\0";
    if (trim_chars == s21_NULL || s21_strlen(trim_chars) == 0)
      trim_chars = default_chars;
    result = (char *)calloc(s21_strlen(src) + 10, sizeof(char));
    if (result == s21_NULL) {
      is_error = 1;
    }
    s21_strcpy(result, (char *)src);
    delete_left_part(result, src, trim_chars);
    delete_right_part(result, src, trim_chars);
  } else {
    is_error = 1;
  }
  return is_error ? s21_NULL : (void *)result;
}

void delete_first_letter(char *str) {
  s21_size_t counter = 0;
  while (str[counter]) {
    str[counter] = str[counter + 1];
    counter++;
  }
}

void delete_left_part(char *result, const char *src, const char *trim_chars) {
  s21_size_t format_length = s21_strlen(trim_chars);
  s21_size_t str_length = s21_strlen(src);
  for (s21_size_t i = 0; i < str_length; i++) {
    int is_break = 0;
    for (s21_size_t j = 0; j < format_length; j++) {
      if (src[i] == trim_chars[j]) {
        delete_first_letter(result);
        break;
      }
      if (j == format_length - 1 && src[i] != trim_chars[format_length]) {
        is_break = 1;
      }
    }
    if (is_break) break;
  }
}

void delete_right_part(char *result, const char *src, const char *trim_chars) {
  s21_size_t format_length = s21_strlen(trim_chars);
  s21_size_t result_length = s21_strlen(result);
  for (int i = (int)result_length - 1; i >= 0; i--) {
    int is_break = 0;
    for (s21_size_t j = 0; j < format_length; j++) {
      if (result[i] == trim_chars[j]) {
        result[i] = '\0';
        break;
      }
      if (j == format_length - 1 && src[i] != trim_chars[format_length]) {
        is_break = 1;
      }
    }
    if (is_break) break;
  }
}
