#include <check.h>
#include <limits.h>
#include <string.h>

#include "../s21_string/s21_string.h"
#define BUFF_SIZE 512

START_TEST(S21_STRLEN) {
  ck_assert_msg(s21_strlen("") == strlen(""), "FAILURE! Test \"\" failed!");
  ck_assert_msg(s21_strlen("abc") == strlen("abc"),
                "FAILURE! Test \"abc\" failed!");
  ck_assert_msg(s21_strlen("123 ") == strlen("123 "),
                "FAILURE! Test \"123 \" failed!");
  ck_assert_msg(s21_strlen("l") == strlen("l"), "FAILURE! Test \"l\" failed!");
}
END_TEST

START_TEST(S21_STRCHR) {
  char *msg = "Hello, World!";
  ck_assert_ptr_eq(s21_strchr("", '\0'), s21_NULL);
  ck_assert_ptr_eq(s21_strchr(msg, '\0'), strchr(msg, '\0'));
  ck_assert_ptr_eq(s21_strchr(msg, ','), strchr(msg, ','));
  ck_assert_ptr_eq(s21_strchr(msg, 'z'), s21_NULL);
}
END_TEST

START_TEST(S21_STRCAT) {
  char msg_1[50] = "";
  char msg_2[50] = "";
  ck_assert_msg(strcmp(s21_strcat(msg_1, ""), strcat(msg_2, "")) == 0,
                "FAILURE! Test \"\" + \"\" failed!");
  ck_assert_msg(
      strcmp(s21_strcat(msg_1, "Hello, "), strcat(msg_2, "Hello, ")) == 0,
      "FAILURE! Test ");
  ck_assert_msg(
      strcmp(s21_strcat(msg_1, "World!"), strcat(msg_2, "World!")) == 0,
      "FAILURE! Test ");
  ck_assert_msg(strcmp(s21_strcat(msg_1, ""), strcat(msg_2, "")) == 0,
                "FAILURE! Test ");
}
END_TEST

START_TEST(S21_STRNCAT) {
  char msg_1[50] = "";
  char msg_2[50] = "";

  s21_strncat(msg_1, "", sizeof(msg_1));
  strncat(msg_2, "", sizeof(msg_2));
  ck_assert_msg(strcmp(msg_1, msg_2) == 0, "FAILURE! Test \"\" + \"\" failed!");

  char str1[] = "Hello, ";
  char str2[] = "World!";
  size_t n = sizeof(msg_1) - strlen(msg_1) - 1;
  s21_strncat(msg_1, str1, n);
  strncat(msg_2, str1, n);
  ck_assert_msg(strcmp(msg_1, msg_2) == 0, "FAILURE! Test str1 failed!");

  n = sizeof(msg_1) - strlen(msg_1) - 1;
  s21_strncat(msg_1, str2, n);
  strncat(msg_2, str2, n);
  ck_assert_msg(strcmp(msg_1, msg_2) == 0, "FAILURE! Test str2 failed!");

  char str3[] = " This is a longer string";
  n = sizeof(msg_1) - strlen(msg_1) - 1;
  s21_strncat(msg_1, str3, n);
  strncat(msg_2, str3, n);
  ck_assert_msg(strcmp(msg_1, msg_2) == 0, "FAILURE! Test str3 failed!");
}
END_TEST

START_TEST(S21_strncmp) {
  ck_assert_msg(s21_strncmp("", "", 0) == strncmp("", "", 0),
                "FAILURE! Test \"\" + \"\" failed!");
  ck_assert_int_eq(s21_strncmp("11", "1", 2), strncmp("11", "1", 2));
  ck_assert_int_eq(s21_strncmp("1", "11", 2), strncmp("1", "11", 2));
  ck_assert_int_eq(s21_strncmp("12", "11", 2), strncmp("12", "11", 2));
  ck_assert_int_eq(s21_strncmp("1a", "1", 2), strncmp("1a", "1", 2));
  char c[10] = "abcde";
  char nc[10] = "ab";
  int res_norm = 0;
  res_norm = strncmp(c, nc, 2) > 0 ? 1 : strncmp(c, nc, 2) < 0 ? -1 : 0;
  ck_assert_int_eq(s21_strncmp(c, nc, 2), res_norm);
}
END_TEST

START_TEST(S21_STRCPY) {
  char msg_1[50] = "";
  char msg_2[50] = "";
  ck_assert_msg(strcmp(s21_strcpy(msg_1, ""), strcpy(msg_2, "")) == 0,
                "FAILURE! Test ");
  ck_assert_msg(strcmp(s21_strcpy(msg_1, "TEST?"), strcpy(msg_2, "TEST?")) == 0,
                "FAILURE! Test ");
  ck_assert_msg(
      strcmp(s21_strcpy(msg_1, "HAhaHA"), strcpy(msg_2, "HAhaHA")) == 0,
      "FAILURE! Test ");
  ck_assert_msg(strcmp(s21_strcpy(msg_1, ""), strcpy(msg_2, "")) == 0,
                "FAILURE! Test copy \"\" failed!");
}
END_TEST

START_TEST(S21_STRNCPY) {
  char msg_1[50] = "";
  char msg_2[50] = "";
  ck_assert_msg(strcmp(s21_strncpy(msg_1, "", 1), strncpy(msg_2, "", 1)) == 0,
                "FAILURE! Test ");
  ck_assert_msg(
      strcmp(s21_strncpy(msg_1, "TEST?", 6), strncpy(msg_2, "TEST?", 6)) == 0,
      "FAIL");
  ck_assert_msg(
      strcmp(s21_strncpy(msg_1, "HAhaHA", 8), strncpy(msg_2, "HAhaHA", 8)) == 0,
      "FAI");
  ck_assert_msg(strcmp(s21_strncpy(msg_1, "", 2), strncpy(msg_2, "", 2)) == 0,
                "FAILURE! Test ");
}
END_TEST

START_TEST(S21_strcspn) {
  ck_assert_msg(s21_strcspn("", "") == strcspn("", ""),
                "FAILURE! Test \"\" in \"\" failed!");
  ck_assert_msg(s21_strcspn("", "TEST24") == strcspn("", "TEST24"),
                "FAILURE! Test \"TEST24\" fai");
  ck_assert_msg(s21_strcspn("test was success!", "TEST24") ==
                    strcspn("test was success!", "TEST24"),
                "FAI");
  ck_assert_msg(s21_strcspn("test was success!", "test24") ==
                    strcspn("test was success!", "test24"),
                "FAI");
  ck_assert_msg(
      s21_strcspn("test was success!", "") == strcspn("test was success!", ""),
      "FAILURE! Test ");
}
END_TEST

START_TEST(S21_STRCSPN) {
  ck_assert_msg(s21_strcspn("", "") == strcspn("", ""),
                "FAILURE! Test \"\" in \"\" ");
  ck_assert_msg(s21_strcspn("", "TEST24") == strcspn("", "TEST24"),
                "FAILURE! Test ");
  ck_assert_msg(s21_strcspn("test was suc", "TEST24") ==
                    strcspn("test was suc", "TEST24"),
                "FAI");
  ck_assert_msg(s21_strcspn("test was suc", "test24") ==
                    strcspn("test was suc", "test24"),
                "F");
  ck_assert_msg(
      s21_strcspn("test was success!", "") == strcspn("test was success!", ""),
      "FAILURE! ");
}
END_TEST

START_TEST(S21_STRPBRK) {
  ck_assert_int_eq(
      strcmp(s21_strpbrk("this is", "abs"), strpbrk("this is", "abs")), 0);
  ck_assert_int_eq(
      strcmp(s21_strpbrk("this is", "th"), strpbrk("this is", "th")), 0);
  ck_assert_int_eq(
      strcmp(s21_strpbrk("this is", "hi"), strpbrk("this is", "hi")), 0);
  ck_assert_msg(s21_strpbrk("this is", "") == strpbrk("this is", ""),
                "FAILURE! Test");
  ck_assert_msg(s21_strpbrk("this is", "dplf") == strpbrk("this is", "dplf"),
                "Fail");
}
END_TEST

START_TEST(S21_STRRCHR) {
  char str1[] = "Abcdefg";
  int symbol1 = 'd';
  char *ach1 = s21_strrchr(str1, symbol1);
  ck_assert_ptr_ne(ach1, s21_NULL);
  ck_assert_str_eq(ach1, "defg");

  char str2[] = "Abcdefg";
  int symbol2 = 'd';
  char *ach2 = strrchr(str2, symbol2);
  ck_assert_ptr_ne(ach2, s21_NULL);
  ck_assert_str_eq(ach1, ach2);

  char str3[] = "Abcdefg";
  int symbol3 = '\0';
  char *ach3 = s21_strrchr(str3, symbol3);
  ck_assert_ptr_ne(ach3, s21_NULL);

  char str4[] = "Abcdefg";
  int symbol4 = '\0';
  char *ach4 = strrchr(str4, symbol4);
  ck_assert_ptr_ne(ach4, s21_NULL);
  ck_assert_str_eq(ach3, ach4);
}
END_TEST

START_TEST(S21_STRSTR) {
  ck_assert_msg(strcmp(s21_strstr("abc", ""), strstr("abc", "")) == 0,
                "FAILURE! ");
  ck_assert_msg(strcmp(s21_strstr("abc", "a"), strstr("abc", "a")) == 0,
                "FAILURE! ");
  ck_assert_msg(strcmp(s21_strstr("hello", "el"), strstr("hello", "el")) == 0,
                "FAILURE! ");
  char msg[50] = "abcdef";
  ck_assert_msg(strcmp(s21_strstr(msg, "ab"), strstr(msg, "ab")) == 0,
                "FAILURE! Test ");
  ck_assert_msg(s21_strstr(msg, "1") == strstr(msg, "1"),
                "FAILURE! Test \"Hello, World!\" \'h\' failed!");
}
END_TEST

START_TEST(S21_STRTOK) {
  char str[30] = "abc cde,llf.ggg";
  char str2[30] = "abc cde,llf.ggg";
  ck_assert_int_eq(strcmp(s21_strtok(str, " .,"), strtok(str2, " .,")), 0);
  ck_assert_int_eq(strcmp(s21_strtok(NULL, " .,"), strtok(NULL, " .,")), 0);
  ck_assert_int_eq(strcmp(s21_strtok(NULL, " .,"), strtok(NULL, " .,")), 0);
  ck_assert_int_eq(strcmp(s21_strtok(NULL, " .,"), strtok(NULL, " .,")), 0);
  ck_assert_msg(s21_strtok(NULL, " .,") == strtok(NULL, " .,"), "FAILURE!");
}
END_TEST

START_TEST(S21_MEMCHR) {
  char str1[] = "abc\nabc";
  int a = 'a';
  size_t n1 = 3;
  ck_assert_ptr_eq(memchr(str1, a, n1), s21_memchr(str1, a, n1));

  char str2[] = "abcabc";
  int b = 'a';
  size_t n2 = 0;
  ck_assert_ptr_eq(memchr(str2, b, n2), s21_memchr(str2, b, n2));

  char str3[] = "abcabc";
  int c = 'a';
  size_t n3 = 0;
  ck_assert_ptr_eq(memchr(str3, c, n3), s21_memchr(str3, c, n3));

  const char str4[5] = "";
  int c1 = '\0';
  size_t n4 = 4;
  ck_assert_ptr_eq(memchr(str4, c1, n4), s21_memchr(str4, c1, n4));
}
END_TEST

START_TEST(S21_MEMCMP) {
  ck_assert_int_eq(s21_memcmp("", "", 0), memcmp("", "", 0));
  ck_assert_msg(s21_memcmp("", "", 0) == memcmp("", "", 0),
                "FAILURE! Test \'\' in \'\' failed!");
  ck_assert_msg(s21_memcmp("abc", "abc", 3) == memcmp("abc", "abc", 3),
                "FAILURE! Test ");
  ck_assert_msg(s21_memcmp("abcd", "abcd", 4) == memcmp("abcd", "abcd", 4),
                "FAILURE! Test ");
  ck_assert_msg(s21_memcmp("cba", "cba", 3) == memcmp("cba", "cba", 3),
                "FAILURE! Test ");
  ck_assert_msg(s21_memcmp("tall", "small", 4) == memcmp("tal", "small", 4),
                "FAILURE! ");
  ck_assert_msg(s21_memcmp("small", "tall", 4) == memcmp("small", "tall", 4),
                "FAILURE!");
  char *a = "at";
  char *b = "atb";
  int result = memcmp(a, b, 2);
  result = result > 0 ? 1 : (result == 0) ? 0 : -1;
  ck_assert_msg(s21_memcmp(a, b, 2) == result,
                "FAILURE! Test \"at\" in \"atb\" failed!");
  result = memcmp(b, a, 2);
  result = result > 0 ? 1 : (result == 0) ? 0 : -1;
  ck_assert_msg(s21_memcmp(b, a, 2) == result,
                "FAILURE! Test \"atb\" in \"at\" failed!");
}
END_TEST

START_TEST(S21_MEMCPY) {
  char src1[] = "Hello, World!";
  char dest1[20];
  memcpy(dest1, src1, 14);
  s21_memcpy(src1, dest1, 14);
  ck_assert_int_eq(memcmp(src1, dest1, 14), 0);

  char src2[] = "Hello, World!";
  char src3[] = "Hello, World!";
  memcpy(src2, src3, 5);
  s21_memcpy(src2, src3, 5);
  ck_assert_int_eq(memcmp(src2, "Hello, World!", 13), 0);

  memcpy(src3, src3, 0);
  s21_memcpy(src3, src3, 0);
  ck_assert_int_eq(memcmp(src3, "Hello, World!", 13), 0);

  char src4[10000];
  char dest4[10000];
  for (int i = 0; i < 10000; ++i) {
    src4[i] = i;
  }
  memcpy(dest4, src4, 10000);
  s21_memcpy(src4, dest4 + 100, 9800);
  ck_assert_int_eq(memcmp(src4, dest4 + 100, 9800), 0);
}
END_TEST

START_TEST(S21_MEMMOVE) {
  char dest[100] = "abcdef";
  char dest2[100] = "abcdef";
  ck_assert_msg(
      memcmp(s21_memmove(dest, "ba", 2), memmove(dest2, "ba", 2), 99) == 0,
      "FAILURE!");
  ck_assert_msg(memcmp(s21_memmove(dest, dest + 2, 2),
                       memmove(dest2, dest2 + 2, 2), 99) == 0,
                "FAILURE!");
  ck_assert_msg(
      memcmp(s21_memmove(dest, "", 0), memmove(dest2, "", 0), 99) == 0,
      "FAILURE! Test ");
}
END_TEST

START_TEST(S21_MEMSET) {
  char dest[100] = "abcdef";
  char dest2[100] = "abcdef";
  ck_assert_msg(
      memcmp(s21_memset(dest, 'a', 2), memset(dest2, 'a', 2), 99) == 0,
      "FAILURE! ");
  ck_assert_msg(
      memcmp(s21_memset(dest, dest[2], 6), memset(dest2, dest2[2], 6), 99) == 0,
      "FAILURE!");
  ck_assert_msg(
      memcmp(s21_memset(dest, ' ', 2), memset(dest2, ' ', 2), 99) == 0,
      "FAILURE! Test  ");
}
END_TEST

START_TEST(S21_TO_UPPER) {
  char *ptr = s21_to_upper("abcde");
  ck_assert_msg(memcmp(ptr, "ABCDE", 5) == 0,
                "FAILURE! Test \'abcdef\'  failed!");
  free(ptr);
  ptr = s21_to_upper("abcde1");
  ck_assert_msg(memcmp(ptr, "ABCDE1", 6) == 0,
                "FAILURE! Test \'abcdef\' failed!");
  free(ptr);
  ptr = s21_to_upper("!?123");
  ck_assert_msg(memcmp(ptr, "!?123", 5) == 0,
                "FAILURE! Test \'!?123\'  failed!");
  free(ptr);
  ptr = s21_to_upper(" ");
  ck_assert_msg(memcmp(ptr, " ", 1) == 0,
                "FAILURE! Test \'\' in \" \" failed!");
  free(ptr);
  ptr = s21_to_upper("!?123a");
  ck_assert_msg(memcmp(ptr, "!?123A", 6) == 0,
                "FAILURE! Test \'!?123a\' ifailed!");
  free(ptr);
}
END_TEST

START_TEST(S21_TO_LOWER) {
  char *ptr = s21_to_lower("ABCDE");
  ck_assert_msg(memcmp(ptr, "abcde", 5) == 0,
                "FAILURE! Test \'abcdef\' failed!");
  free(ptr);
  ptr = s21_to_lower("ABCDE1");
  ck_assert_msg(memcmp(ptr, "abcde1", 6) == 0,
                "FAILURE! Test \'abcdef\' failed!");
  free(ptr);
  ptr = s21_to_lower("!?123");
  ck_assert_msg(memcmp(ptr, "!?123", 5) == 0,
                "FAILURE! Test \'abcdef\'  failed!");
  free(ptr);
  ptr = s21_to_lower(" ");
  ck_assert_msg(memcmp(ptr, " ", 1) == 0, "FAILURE! Test \'abcdef\' failed!");
  free(ptr);
  ptr = s21_to_lower("!?123A");
  ck_assert_msg(memcmp(ptr, "!?123a", 6) == 0,
                "FAILURE! Test \'abcdef\' failed!");
  free(ptr);
}
END_TEST

START_TEST(S21_INSERT) {
  char *ptr = s21_insert("abc", "pp", 1);
  ck_assert_msg(memcmp(ptr, "appbc", 5) == 0, "FAILURE! Test \'abc\' failed!");
  free(ptr);
  ptr = s21_insert("abc", "pp", 0);
  ck_assert_msg(memcmp(ptr, "ppabc", 5) == 0, "FAILURE! Test \'abc\' failed!");
  free(ptr);
  ptr = s21_insert("abc", "pp", 3);
  ck_assert_msg(memcmp(ptr, "abcpp", 5) == 0, "FAILURE! Test \'abc\'  failed!");
  free(ptr);
  ptr = s21_insert("abc", "pp", 2);
  ck_assert_msg(memcmp(ptr, "abppc", 5) == 0,
                "FAILURE! Test \'abcdef\' failed!");
  free(ptr);
  ptr = s21_insert("15", "234", 1);
  ck_assert_msg(memcmp(ptr, "12345", 5) == 0, "FAILURE! Test \'15\' failed!");
  free(ptr);
  ck_assert_msg(s21_insert("15", "234", 3) == NULL,
                "FAILURE! Test \'15\' failed!");
}
END_TEST

START_TEST(S21_TRIM) {
  char *ptr = s21_trim("abc", "a");
  ck_assert_msg(memcmp(ptr, "bc", 2) == 0, "FAILURE! Test \'abc\' failed!");
  free(ptr);
  ptr = s21_trim("abacdef", "afb");
  ck_assert_msg(memcmp(ptr, "cde", 3) == 0,
                "FAILURE! Test \'abacdef\' failed!");
  free(ptr);
  ptr = s21_trim("*aaaabbbb*", "ab");
  ck_assert_msg(memcmp(ptr, "*aaaabbbb*", 5) == 0,
                "FAILURE! Test \'*aaaabbbb*\'  failed!");
  free(ptr);
  ptr = s21_trim("abc", "p");
  ck_assert_msg(memcmp(ptr, "abc", 3) == 0, "FAILURE! Test \'abcdef\' failed!");
  free(ptr);
  ptr = s21_trim("555151555", "5");
  ck_assert_msg(memcmp(ptr, "151", 3) == 0, "FAILURE! Test \'15\' failed!");
  free(ptr);
}
END_TEST

START_TEST(S21_STRERROR) {
  char *err1 = s21_strerror(0);
  char *err2 = strerror(0);
  ck_assert_int_eq(strcmp(err1, err2), 0);
  char *err3 = s21_strerror(106);
  char *err4 = strerror(106);
  ck_assert_int_eq(strcmp(err3, err4), 0);
  char *err5 = s21_strerror(29925917);
  char *err6 = strerror(29925917);
  ck_assert_int_eq(strcmp(err5, err6), 0);
  char *err7 = s21_strerror(-29925917);
  char *err8 = strerror(-29925917);
  ck_assert_int_eq(strcmp(err7, err8), 0);
}
END_TEST

START_TEST(s21_sprintf_f_g_n_prc_test) {
  char str[80];

  int n_1, n_2;
  double f_1 = 1.0, f_2 = -0.1234567890;

  int res_1 =
      s21_sprintf(str, "qwerty%n %10.5f %#.4g %n", &n_1, f_1, f_2, &n_2);

  ck_assert_int_eq(res_1, 26);
  ck_assert_int_eq(n_1, 6);
  ck_assert_int_eq(n_2, 26);
  ck_assert_str_eq(str, "qwerty    1.00000 -0.1235 ");
  char percent['%'];
  res_1 = s21_sprintf(str, "qwerty%n %% %10.5f %#.4g %n", &n_1, percent, f_1,
                      f_2, &n_2);
  ck_assert_str_eq(str, "qwerty %    1.00000 -0.1235 ");
  ck_assert_int_eq(res_1, 28);
}
END_TEST

START_TEST(s21_sprintf_test) {
  char str[80];
  char str_origin[80];
  const char *format_str1 = "Hello";
  char c = 'X';
  char d = 'Y';
  int result1 = s21_sprintf(str, format_str1, c);
  int result_origin1 = sprintf(str_origin, format_str1, c);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(str, str_origin);

  const char *format_str2 = "Hello, %c %c";
  int result2 = s21_sprintf(str, format_str2, c, d);
  int result_origin2 = sprintf(str_origin, format_str2, c, d);
  ck_assert_int_eq(result2, result_origin2);
  ck_assert_str_eq(str, str_origin);

  char *s1 = "world!";
  char *s2 = "Hello world!";
  const char *format_str3 = "Hello, %10s %10.15s";
  int result3 = s21_sprintf(str, format_str3, s1, s2);
  int result_origin3 = sprintf(str_origin, format_str3, s1, s2);
  ck_assert_int_eq(result3, result_origin3);
  ck_assert_str_eq(str, str_origin);
}
END_TEST

START_TEST(s21_sprintf_e_test) {
  char str[80];
  char str_origin[80];
  const char *format_str1 = "% 10.15LE yo";
  long double mantissa1 = 0.0000003044058697058435;
  int result1 = s21_sprintf(str, format_str1, mantissa1);
  int result_origin1 = sprintf(str_origin, format_str1, mantissa1);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(str, str_origin);

  const char *format_str2 = "%-20.7e yo";
  double mantissa2 = -4044050;
  int result2 = s21_sprintf(str, format_str2, mantissa2);
  int result_origin2 = sprintf(str_origin, format_str2, mantissa2);
  ck_assert_int_eq(result2, result_origin2);
  ck_assert_str_eq(str, str_origin);

  const char *format_str3 = "%-.5E yo";
  double mantissa3 = -0.00;
  int result3 = s21_sprintf(str, format_str3, mantissa3);
  int result_origin3 = sprintf(str_origin, format_str3, mantissa3);
  ck_assert_int_eq(result3, result_origin3);
  ck_assert_str_eq(str, str_origin);

  const char *format_str4 = "Hello %+020.15E %LE yo";
  double mantissa4 = 1.004554367;
  long double mantissa5 = -432432455454;
  int result4 = s21_sprintf(str, format_str4, mantissa4, mantissa5);
  int result_origin4 = sprintf(str_origin, format_str4, mantissa4, mantissa5);
  ck_assert_int_eq(result4, result_origin4);
  ck_assert_str_eq(str, str_origin);

  const char *format_str5 = "This is infinite: %-20.5e and this is nan: %20e";
  double infinite = 1.0 / 0.0;
  double not_a_number = infinite * 0.0;
  int result5 = s21_sprintf(str, format_str5, infinite, not_a_number);
  int result_origin5 = sprintf(str_origin, format_str5, infinite, not_a_number);
  ck_assert_int_eq(result5, result_origin5);
  ck_assert_str_eq(str, str_origin);
}
END_TEST

START_TEST(s21_sprintf_p_test) {
  char str[80];
  char str_origin[80];
  int a = 10;
  char *format_str1 = "This is the pointer: %p\n";
  int result1 = s21_sprintf(str, format_str1, &a);
  int result_origin1 = sprintf(str_origin, format_str1, &a);

  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(str, str_origin);

  char *pointer = "Test";
  double double_pointer = 84759375969;

  char *format_str2 = "To the left: %-20p!\nTo the right %20p!";

  int result2 = s21_sprintf(str, format_str2, pointer, &double_pointer);
  int result_origin2 =
      sprintf(str_origin, format_str2, pointer, &double_pointer);
  ck_assert_int_eq(result2, result_origin2);
  ck_assert_str_eq(str, str_origin);

  int *empty_pointer = s21_NULL;
  char *format_str3 = "This is empty pointer %p\n";
  int result3 = s21_sprintf(str, format_str3, empty_pointer);
  int result_origin3 = sprintf(str_origin, format_str3, empty_pointer);
  ck_assert_int_eq(result3, result_origin3);
  ck_assert_str_eq(str, str_origin);
}
END_TEST

START_TEST(s21_sprintf_o_test) {
  int arr1[] = {0, -1, 1, 123, 1234, -1383, 9387};
  char str[80];
  char str1[80];
  int res = s21_sprintf(str, "%o", arr1[0]);
  int res1 = sprintf(str1, "%o", arr1[0]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%-12.3lo", (unsigned long)arr1[4]);
  res1 = sprintf(str1, "%-12.3lo", (unsigned long)arr1[4]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%010.5o", arr1[5]);
  ck_assert_str_eq(str, "37777775231");
  ck_assert_int_eq(res, 11);

  res = s21_sprintf(str, "%-.4o gterth", arr1[6]);
  res1 = sprintf(str1, "%-.4o gterth", arr1[6]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%-#.9o gterth", arr1[6]);
  res1 = sprintf(str1, "%-#.9o gterth", arr1[6]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "hello %0.o gterth", arr1[6]);
  ck_assert_str_eq(str, "hello 22253 gterth");
  ck_assert_int_eq(res, 18);

  res = s21_sprintf(str, "hello %#o gterth", arr1[6]);
  res1 = sprintf(str1, "hello %#o gterth", arr1[6]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "hello %*.o gterth", 5, arr1[6]);
  res1 = sprintf(str1, "hello %*.o gterth", 5, arr1[6]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "hello %010.7o gterth", arr1[6]);
  ck_assert_str_eq(str, "hello    0022253 gterth");
  ck_assert_int_eq(res, 23);

  res = s21_sprintf(str, "%010.7ho", (unsigned short)arr1[6]);
  ck_assert_str_eq(str, "   0022253");
  ck_assert_int_eq(res, 10);
}
END_TEST

START_TEST(s21_sprintf_x_X_test) {
  int arr1[] = {0, -1, 1, 123, 1234, -1383, 9387};
  char str[80];
  char str1[80];
  int res = s21_sprintf(str, "%x", arr1[0]);
  int res1 = sprintf(str1, "%x", arr1[0]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%#10.7hx", (unsigned short)arr1[3]);
  res1 = sprintf(str1, "%#10.7hx", (unsigned short)arr1[3]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%-#10.3lx", (unsigned long)arr1[3]);
  res1 = sprintf(str1, "%-#10.3lx", (unsigned long)arr1[3]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%X", arr1[0]);
  res1 = sprintf(str1, "%X", arr1[0]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%#10.7lX", (unsigned long)arr1[3]);
  res1 = sprintf(str1, "%#10.7lX", (unsigned long)arr1[3]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%-#10.3hX", (unsigned short)arr1[3]);
  res1 = sprintf(str1, "%-#10.3hX", (unsigned short)arr1[3]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%-#*.3hX", 10, (unsigned short)arr1[3]);
  res1 = sprintf(str1, "%-#*.3hX", 10, (unsigned short)arr1[3]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_c_test) {
  char str[80];
  char str1[80];
  char x = 'c';
  int res = s21_sprintf(str, "%-10c", x);
  int res1 = sprintf(str1, "%-10c", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%10c", x);
  res1 = sprintf(str1, "%10c", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_s_test) {
  char str[80];
  char str1[80];
  char *x = "blablabla";
  int res = s21_sprintf(str, "%-11.10s", x);
  int res1 = sprintf(str1, "%-11.10s", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%11.8s", x);
  res1 = sprintf(str1, "%11.8s", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_u_test) {
  char str[80];
  char str_orig[80];
  unsigned int a = 2345;

  int res_1 = s21_sprintf(str, "%10.5u", a);
  int res_1_orig = sprintf(str_orig, "%10.5u", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "%10.5u", a);
  int res_2_orig = sprintf(str_orig, "%10.5u", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5u", a);
  int res_3_orig = sprintf(str_orig, "%3.5u", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%0u", a);
  int res_4_orig = sprintf(str_orig, "%0u", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%-u", a);
  int res_5_orig = sprintf(str_orig, "%-u", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%u", a);
  int res_6_orig = sprintf(str_orig, "%u", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%5u", a);
  int res_7_orig = sprintf(str_orig, "%5u", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "%05u", a);
  int res_8_orig = sprintf(str_orig, "%05u", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%-5u", a);
  int res_9_orig = sprintf(str_orig, "%-5u", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%.5u", a);
  int res_10_orig = sprintf(str_orig, "%.5u", a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%.5u", a);
  int res_11_orig = sprintf(str_orig, "%.5u", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%-.5u", a);
  int res_12_orig = sprintf(str_orig, "%-.5u", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "%-10.5u", a);
  int res_13_orig = sprintf(str_orig, "%-10.5u", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%3.5u", a);
  int res_14_orig = sprintf(str_orig, "%3.5u", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%-3.5u", a);
  int res_15_orig = sprintf(str_orig, "%-3.5u", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "%6.2u", a);
  int res_16_orig = sprintf(str_orig, "%6.2u", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%3.2u", a);
  int res_17_orig = sprintf(str_orig, "%3.2u", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%01u", a);
  int res_18_orig = sprintf(str_orig, "%01u", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%hu", (unsigned short)a);
  int res_19_orig = sprintf(str_orig, "%hu", (unsigned short)a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%lu", (unsigned long)a);
  int res_20_orig = sprintf(str_orig, "%lu", (unsigned long)a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test) {
  char str[80];
  char str_orig[80];
  int a = 2345;

  int res_1 = s21_sprintf(str, "%10.5d", a);
  int res_1_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%05d", a);
  int res_10_orig = sprintf(str_orig, "%05d", a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%05d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);

  int res_26 = s21_sprintf(str, "%hd", (unsigned short)a);
  int res_26_orig = sprintf(str_orig, "%hd", (unsigned short)a);

  ck_assert_int_eq(res_26, res_26_orig);
  ck_assert_str_eq(str, str_orig);

  int res_27 = s21_sprintf(str, "%ld", (unsigned long)a);
  int res_27_orig = sprintf(str_orig, "%ld", (unsigned long)a);

  ck_assert_int_eq(res_27, res_27_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_2) {
  char str[80];
  char str_orig[80];
  int a = -23454546;

  int res_1 = s21_sprintf(str, "%10.*d", 5, a);
  int res_1_orig = sprintf(str_orig, "%10.*d", 5, a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%0*d", 5, a);
  int res_10_orig = sprintf(str_orig, "%0*d", 5, a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%.5d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_3) {
  char str[80];
  char str_orig[80];
  int a = 234;

  int res_1 = s21_sprintf(str, "%10.5d", a);
  int res_1_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%05d", a);
  int res_10_orig = sprintf(str_orig, "%05d", a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%.5d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);

  int res_26 = s21_sprintf(str, "%+6.2d", a);
  int res_26_orig = sprintf(str_orig, "%+6.2d", a);

  ck_assert_int_eq(res_26, res_26_orig);
  ck_assert_str_eq(str, str_orig);

  int res_27 = s21_sprintf(str, "%+6.3d", a);
  int res_27_orig = sprintf(str_orig, "%+6.3d", a);

  ck_assert_int_eq(res_27, res_27_orig);
  ck_assert_str_eq(str, str_orig);

  int res_28 = s21_sprintf(str, "%+6.4d", a);
  int res_28_orig = sprintf(str_orig, "%+6.4d", a);

  ck_assert_int_eq(res_28, res_28_orig);
  ck_assert_str_eq(str, str_orig);

  int res_29 = s21_sprintf(str, "%-6.2d", -a);
  int res_29_orig = sprintf(str_orig, "%-6.2d", -a);

  ck_assert_int_eq(res_29, res_29_orig);
  ck_assert_str_eq(str, str_orig);

  int res_30 = s21_sprintf(str, "%+05d", a);
  int res_30_orig = sprintf(str_orig, "%+05d", a);

  ck_assert_int_eq(res_30, res_30_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_4) {
  char str[80];
  char str_orig[80];
  int a = -23;

  int res_1 = s21_sprintf(str, "%10.5d", a);
  int res_1_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%05d", a);
  int res_10_orig = sprintf(str_orig, "%05d", a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%.5d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);

  int res_26 = s21_sprintf(str, "%+05d", a);
  int res_26_orig = sprintf(str_orig, "%+05d", a);

  ck_assert_int_eq(res_26, res_26_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_5) {
  char str[80];
  char str_orig[80];
  int a = -2344;

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%05d", a);
  int res_10_orig = sprintf(str_orig, "%05d", a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%.5d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);

  int res_26 = s21_sprintf(str, "%+05d", a);
  int res_26_orig = sprintf(str_orig, "%+05d", a);

  ck_assert_int_eq(res_26, res_26_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_6) {
  char str[80];
  char str_orig[80];
  int a = 23;

  int res_1 = s21_sprintf(str, "%+10.5d", a);
  int res_1_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%+3.5d", a);
  int res_3_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%+d", a);
  int res_4_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%+0d", a);
  int res_5_orig = sprintf(str_orig, "%+0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-+d", a);
  int res_6_orig = sprintf(str_orig, "%-+d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%+5d", a);
  int res_9_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-+5d", a);
  int res_11_orig = sprintf(str_orig, "%-+5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%+.5d", a);
  int res_14_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%+.5d", a);
  int res_15_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-+.5d", a);
  int res_18_orig = sprintf(str_orig, "%-+.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-+10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-+10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%+3.5d", a);
  int res_22_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-+3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-+3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);

  int res_26 = s21_sprintf(str, "%+05d", a);
  int res_26_orig = sprintf(str_orig, "%+05d", a);

  ck_assert_int_eq(res_26, res_26_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_0) {
  char str[80];
  char str_orig[80];
  int a = 0;

  int res_1 = s21_sprintf(str, "%+10.5d", a);
  int res_1_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%+3.5d", a);
  int res_3_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%+d", a);
  int res_4_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%05d", a);
  int res_5_orig = sprintf(str_orig, "%05d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%+5d", a);
  int res_9_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%+.5d", a);
  int res_14_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%+.5d", a);
  int res_15_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%+3.5d", a);
  int res_22_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_26 = s21_sprintf(str, "%+05d", a);
  int res_26_orig = sprintf(str_orig, "%+05d", a);

  ck_assert_int_eq(res_26, res_26_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(SPRINTF_FLOAT_PREC) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%.5f";
  float f = 7.891233;
  sprintf(result, format_str, f);
  s21_sprintf(result_s21, format_str, f);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_FLOAT_H) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%5f";
  float f = 7.891233;
  sprintf(result, format_str, f);
  s21_sprintf(result_s21, format_str, f);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_FLOAT_H_PREC) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%5.5f";
  float f = 7.891233;
  sprintf(result, format_str, f);
  s21_sprintf(result_s21, format_str, f);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_FLOAT_MINUS) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%-5f";
  float f = 7.891233;
  sprintf(result, format_str, f);
  s21_sprintf(result_s21, format_str, f);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_FLOAT_MINUS_DIGIT) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%f";
  float f = -7.891233;
  sprintf(result, format_str, f);
  s21_sprintf(result_s21, format_str, f);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_FLOAT_SPACE) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%f";
  float f = 7.891233;
  sprintf(result, format_str, f);
  s21_sprintf(result_s21, format_str, f);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_FLOAT_PLUS_H) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%+5f";
  float f = 7.891233;
  sprintf(result, format_str, f);
  s21_sprintf(result_s21, format_str, f);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_DECIMAL) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%d";
  int d = 5;
  sprintf(result, format_str, d);
  s21_sprintf(result_s21, format_str, d);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_DECIMAL_PREC) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%5d";
  int d = 5;
  sprintf(result, format_str, d);
  s21_sprintf(result_s21, format_str, d);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_DECIMAL_L) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%ld";
  long long d = LONG_MAX;
  sprintf(result, format_str, d);
  s21_sprintf(result_s21, format_str, d);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_DECIMAL_H) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%hd";
  int d = INT_MAX;
  sprintf(result, format_str, d);
  s21_sprintf(result_s21, format_str, d);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_DECIMAL_MINUS_DIGIT) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%d";
  int d = -5;
  sprintf(result, format_str, d);
  s21_sprintf(result_s21, format_str, d);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_DECIMAL_MINUS_H) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%-5d";
  int d = -5;
  sprintf(result, format_str, d);
  s21_sprintf(result_s21, format_str, d);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_DECIMAL_PLUS_DIGIT) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%+d";
  int d = 5;
  sprintf(result, format_str, d);
  s21_sprintf(result_s21, format_str, d);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_DECIMAL_SPACE) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%d";
  int d = 5;
  sprintf(result, format_str, d);
  s21_sprintf(result_s21, format_str, d);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_UNSIGNED) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%u";
  unsigned int u = 5;
  sprintf(result, format_str, u);
  s21_sprintf(result_s21, format_str, u);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_UNSIGNED_H) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%5u";
  unsigned int u = 5;
  sprintf(result, format_str, u);
  s21_sprintf(result_s21, format_str, u);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_UNSIGNED_MINUS_H) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%-5u";
  unsigned int u = 5;
  sprintf(result, format_str, u);
  s21_sprintf(result_s21, format_str, u);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_UNSIGNED_SPACE) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%u";
  unsigned int u = 5;
  sprintf(result, format_str, u);
  s21_sprintf(result_s21, format_str, u);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_CHAR) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%c";
  char c = 'c';
  sprintf(result, format_str, c);
  s21_sprintf(result_s21, format_str, c);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_CHAR_DIGIT) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%c";
  int c = 48;
  sprintf(result, format_str, c);
  s21_sprintf(result_s21, format_str, c);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_CHAR_H) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%5c";
  int c = 48;
  sprintf(result, format_str, c);
  s21_sprintf(result_s21, format_str, c);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_CHAR_MINUS_H) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%-5c";
  int c = 48;
  sprintf(result, format_str, c);
  s21_sprintf(result_s21, format_str, c);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_STRING) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%s";
  char s[] = "ABOBA";
  sprintf(result, format_str, s);
  s21_sprintf(result_s21, format_str, s);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_STRING_SYMBOLS) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%s";
  char s[] = "A\nB\tO\vB\rA\0C";
  sprintf(result, format_str, s);
  s21_sprintf(result_s21, format_str, s);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_STRING_H) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%5s";
  char s[] = "ABOBA";
  sprintf(result, format_str, s);
  s21_sprintf(result_s21, format_str, s);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_STRING_MINUS_H) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%-5s";
  char s[] = "ABOBA";
  sprintf(result, format_str, s);
  s21_sprintf(result_s21, format_str, s);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_I_DEC) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%i";
  int i = 5;
  sprintf(result, format_str, i);
  s21_sprintf(result_s21, format_str, i);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_I_OCTAL) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%i";
  int i = 05;
  sprintf(result, format_str, i);
  s21_sprintf(result_s21, format_str, i);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_I_HEX) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%i";
  int i = 0xF;
  sprintf(result, format_str, i);
  s21_sprintf(result_s21, format_str, i);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_I_H) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%5i";
  int i = 05;
  sprintf(result, format_str, i);
  s21_sprintf(result_s21, format_str, i);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_I_MINUS_H) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%-5i";
  int i = 05;
  sprintf(result, format_str, i);
  s21_sprintf(result_s21, format_str, i);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_I_PLUS) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%+i";
  int i = 05;
  sprintf(result, format_str, i);
  s21_sprintf(result_s21, format_str, i);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_I_PLUS_H) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%+5i";
  int i = 05;
  sprintf(result, format_str, i);
  s21_sprintf(result_s21, format_str, i);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(SPRINTF_I_SPACE) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "% i";
  int i = 05;
  sprintf(result, format_str, i);
  s21_sprintf(result_s21, format_str, i);
  ck_assert_str_eq(result, result_s21);
}
END_TEST

START_TEST(s21_sprintf_star) {
  char *s21_test_str = (char *)malloc(sizeof(char) * 256);
  char *lib_test_str = (char *)malloc(sizeof(char) * 256);

  int lib_res = sprintf(lib_test_str, "%.d\n", 5);
  int s21_res = s21_sprintf(s21_test_str, "%.d\n", 5);

  ck_assert_str_eq(s21_test_str, lib_test_str);
  ck_assert_int_eq(s21_res, lib_res);

  free(s21_test_str);
  free(lib_test_str);
}
END_TEST

START_TEST(s21_sprintf_cs) {
  char *s21_test_str = (char *)malloc(sizeof(char) * 256);
  char *lib_test_str = (char *)malloc(sizeof(char) * 256);

  char *str0 = "User";
  char *str1 = "";
  int lib_res = sprintf(lib_test_str, "Hello, %-13s, i%c, %s a great day!",
                        str0, 't', str1);
  int s21_res = s21_sprintf(s21_test_str, "Hello, %-13s, i%c, %s a great day!",
                            str0, 't', str1);

  ck_assert_str_eq(s21_test_str, lib_test_str);
  ck_assert_int_eq(s21_res, lib_res);

  free(s21_test_str);
  free(lib_test_str);
}
END_TEST

START_TEST(SPRINTFTestdogletho282) {
  char data[100];
  char data1[100];

  s21_sprintf(data, "%s ", "hello world");
  sprintf(data1, "%s ", "hello world");
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTFTestdogletho283) {
  char data[100];
  char data1[100];
  s21_sprintf(data, "%-3.1s", "\0");
  sprintf(data1, "%-3.1s", "\0");
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTFTestRleonard1) {
  char data[200];
  char data1[200];
  s21_sprintf(data, "%li", 100000000000000000);
  sprintf(data1, "%li", 100000000000000000);
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTFTestRleonard3) {
  char data[200];
  char data1[200];
  s21_sprintf(data, "%lu", 100000000000000000);
  sprintf(data1, "%lu", 100000000000000000);
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTFTestRleonard6) {
  char data[200];
  char data1[200];
  s21_sprintf(data, "%ld", 100000000000000000);
  sprintf(data1, "%ld", 100000000000000000);
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTFTestRleonard7) {
  char data[200];
  char data1[200];
  short int i = -30000;
  s21_sprintf(data, "%hi", i);
  sprintf(data1, "%hi", i);

  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTFTestRleonard9) {
  char data[200];
  char data1[200];
  short int i = 30000;
  s21_sprintf(data, "%hu", i);
  sprintf(data1, "%hu", i);

  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTFTestRleonard12) {
  char data[200];
  char data1[200];
  short int i = -30000;
  s21_sprintf(data, "%hd", i);
  sprintf(data1, "%hd", i);

  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTFTestRleonard13) {
  char data[200];
  char data1[200];
  s21_sprintf(data, "%lc", 'c');
  sprintf(data1, "%lc", 'c');

  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(simple_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple value %d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(precise_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(minus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(plus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+12d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(padding_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%12i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_long_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+5.31li";
  long int val = 698518581899;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_short_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16.9hi";
  short int val = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-15.9s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s%s%s%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_width_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(all_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(empty_format_and_parameters) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                   sprintf(str2, "%s", "Drop Sega PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
      sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                   sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                   sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
      sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                   sprintf(str2, "%u", (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                   sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                           (unsigned)666, (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%10ld";

  ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%1.1f";

  ck_assert_int_eq(s21_sprintf(str1, format, 1.1), sprintf(str2, format, 1.1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%8.3c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+5.5d aboba";

  int val = 10000;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);
  ck_assert_int_eq(a, b);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf7) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7.4s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
                   sprintf(str2, format, "aboba floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf8) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%6.6u";

  ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
                   sprintf(str2, format, 12341151));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf9) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%li%ld%lu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
                   sprintf(str2, format, 666666666666, 777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf10) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%hi%hd%hu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111),
                   sprintf(str2, format, 666, -777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(printf_cTest) {
  short length = 100;
  char *str1 = calloc(length, sizeof(char));
  char *str2 = calloc(length, sizeof(char));
  int res1 = 0, res2 = 0;
  res1 = s21_sprintf(str1, "%c %c %c", ' ', '#', '@');
  res2 = sprintf(str2, "%c %c %c", ' ', '#', '@');
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(printf_iTest) {
  short length = 100;
  char *str1 = calloc(length, sizeof(char));
  char *str2 = calloc(length, sizeof(char));
  int res1 = 0, res2 = 0;
  short int n = 11;
  res1 = s21_sprintf(str1, "%hi %.5i %i", n, -46, 57);
  res2 = sprintf(str2, "%hi %.5i %i", n, -46, 57);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(printf_sTest) {
  short length = 100;
  char *str1 = calloc(length, sizeof(char));
  char *str2 = calloc(length, sizeof(char));
  int res1 = 0, res2 = 0;
  res1 = s21_sprintf(str1, "%.s %.3s %s", "Hello", " world", "!");
  res2 = sprintf(str2, "%.s %.3s %s", "Hello", " world", "!");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(printf_uTest) {
  short length = 100;
  char *str1 = calloc(length, sizeof(char));
  char *str2 = calloc(length, sizeof(char));
  int res1 = 0, res2 = 0;
  unsigned short n = 2;
  unsigned long m = 33;
  res1 = s21_sprintf(str1, "%hu %lu %u", n, m, (unsigned)58432322);
  res2 = sprintf(str2, "%hu %lu %u", n, m, (unsigned)58432322);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(S21_SSCANF) {
  char a, b, c = 0;  // chars
  char a1, b1, c1 = 0;
  s21_sscanf("abcdefABCDEF", "%c %*c %c %c   ", &a, &b, &c);
  sscanf("abcdefABCDEF", "%c %*c %c %c   ", &a1, &b1, &c1);
  s21_sscanf("ab", "%2c", &c);
  s21_sscanf("ab", "%2c", &c1);
  ck_assert_int_eq(a, a1);
  ck_assert_int_eq(b, b1);
  ck_assert_int_eq(c, c1);

  int x, x1 = 0;
  short int y, y1 = 0;
  long int z, z1 = 0;  // ints
  s21_sscanf("+12 -23 54", "%3d %hd%ld", &x, &y, &z);
  sscanf("+12 -23 54", "%3d %hd %ld", &x1, &y1, &z1);
  ck_assert_int_eq(x, x1);
  ck_assert_int_eq(y, y1);
  ck_assert_int_eq(z, z1);

  s21_sscanf("+0775 1-0x1324--123", " %i %*i %hi-  %li", &x, &y, &z);
  sscanf("+0775 1-0x1324--123", " %i %*i %hi- %li", &x1, &y1, &z1);
  ck_assert_int_eq(x, x1);
  ck_assert_int_eq(y, y1);
  ck_assert_int_eq(z, z1);

  unsigned short usx, usx1;
  unsigned int ux, ux1;
  unsigned long ulx, ulx1;
  unsigned long long ullx, ullx1;
  s21_sscanf("0 +2112 -12324", "%o %lo %llo", &ux, &ulx, &ullx);
  sscanf("0 +2112 -12324", "%o %lo %llo", &ux1, &ulx1, &ullx1);
  ck_assert_int_eq(ux, ux1);
  ck_assert_int_eq(ulx, ulx1);
  ck_assert_int_eq(ullx, ullx1);

  s21_sscanf("0 0x211a 0x1", "%x %lx %hx", &ux, &ulx, &usx);
  sscanf("0 0x211a 0x1", "%x %lx %hx", &ux1, &ulx1, &usx1);
  ck_assert_int_eq(usx, usx1);
  ck_assert_int_eq(ux, ux1);
  ck_assert_int_eq(ulx, ulx1);
  ck_assert_int_eq(ullx, ullx1);

  x = 0, x1 = 0;  // errors
  s21_sscanf("a21", "%d", &x);
  sscanf("a21", "%d", &x1);
  ck_assert_int_eq(x, x1);
  s21_sscanf("a21", "b%d", &x);
  sscanf("a21", "b%d", &x1);
  ck_assert_int_eq(x, x1);
  s21_sscanf("--a21", "%d", &x);
  sscanf("--a21", "%d", &x1);
  ck_assert_int_eq(x, x1);
  s21_sscanf("-21", "%%%1d", &x);
  sscanf("-21", "%%%1d", &x1);
  ck_assert_int_eq(x, x1);
  s21_sscanf("-21   ", "%d %hd", &x, &y);
  sscanf("-21   ", "%d %hd", &x1, &y1);
  ck_assert_int_eq(x, x1);

  float fx, fx1;  // floats
  double lfx, lfx1;
  long double llfx, llfx1;
  s21_sscanf("1 2 -123232.001 .995123 999.99.1", "%*E %*G %g %le %Lf", &fx,
             &lfx, &llfx);
  sscanf("1 2 -123232.001 .995123 999.99.1", "%*E %*G %g %le %Lf", &fx1, &lfx1,
         &llfx1);
  ck_assert_msg(fx == fx1, "FAILURE! Floats are not equal!");
  ck_assert_msg(lfx == lfx1, "FAILURE! Doubles are not equal!");

  char str[100], str1[100];  // strings
  char p_str[100], p_str1[100];
  s21_sscanf("abc\n\r\t%%cba\faaa?.123", "%*s %%%s%s%n", str, str1, &x);
  sscanf("abc\n\r\t%%cba\faaa?.123", "%*s %%%s%s%n", p_str, p_str1, &x1);
  ck_assert_msg(strcmp(str, p_str) == 0, "str fail");
  ck_assert_msg(strcmp(str1, p_str1) == 0, "str1 fail");

  void *addr1 = s21_NULL, *addr2 = s21_NULL, *addr3 = s21_NULL;
  void *paddr1 = NULL, *paddr2 = NULL, *paddr3 = NULL;
  s21_sscanf("0x1abcd -0xfffffffff +0xffffffffffffffffffaaa", "%p %n%p %p",
             &addr1, &x, &addr2, &addr3);
  sscanf("0x1abcd -0xfffffffff +0xffffffffffffffffffaaa", "%p %n%p %p", &paddr1,
         &x1, &paddr2, &paddr3);

  float af1 = 0, af2 = 0, bf1 = 0, bf2 = 0, cf1 = 0, cf2 = 0, df1 = 0, df2 = 0;

  const char strf[] =
      "nAN           INF                   -0.1111         1e-10";
  char fstr[] = "%G %G %G %G";

  int res1 = s21_sscanf(strf, fstr, &af1, &bf1, &cf1, &df1);
  int res2 = sscanf(strf, fstr, &af2, &bf2, &cf2, &df2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_ne(isnan(af1), 0);
  ck_assert_int_ne(isnan(af2), 0);
  ck_assert_msg(bf1 == bf2, "FAILURE! Expression is not true!");
  ck_assert_msg(cf1 == cf2, "FAILURE! Expression is not true!");
  ck_assert_msg(df1 == df2, "FAILURE! Expression is not true!");

  const char strf2[] = "-inF InF inF INF";

  res1 = s21_sscanf(strf2, fstr, &af1, &bf1, &cf1, &df1);
  res2 = sscanf(strf2, fstr, &af2, &bf2, &cf2, &df2);
  ck_assert_msg(bf1 == bf2, "FAILURE! Expression is not true!");
  ck_assert_msg(cf1 == cf2, "FAILURE! Expression is not true!");
  ck_assert_msg(df1 == df2, "FAILURE! Expression is not true!");

  long double al1 = 0, al2 = 0, bl1 = 0, bl2 = 0, cl1 = 0, cl2 = 0, dl1 = 0,
              dl2 = 0;
  const char strf3[] = "1.4441 1.31e3 -3.31e-2 0.444e-1";

  res1 = s21_sscanf(strf3, "%LG %LG %LG %LG", &al1, &bl1, &cl1, &dl1);
  res2 = sscanf(strf3, "%LG %LG %LG %LG", &al2, &bl2, &cl2, &dl2);

  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(al1, al2);
  ck_assert_uint_eq(bl1, bl2);
  ck_assert_uint_eq(cl1, cl2);
  ck_assert_uint_eq(dl1, dl2);
}
END_TEST

Suite *make_s21string_suite() {
  Suite *suite = suite_create("TESTING - s21_string.h");
  TCase *group_core = tcase_create("CORE");
  tcase_add_test(group_core, S21_STRERROR);
  tcase_add_test(group_core, S21_STRNCPY);
  tcase_add_test(group_core, S21_STRLEN);
  tcase_add_test(group_core, S21_strncmp);
  tcase_add_test(group_core, S21_STRCAT);
  tcase_add_test(group_core, S21_STRNCAT);
  tcase_add_test(group_core, S21_STRRCHR);
  tcase_add_test(group_core, S21_STRCHR);
  tcase_add_test(group_core, S21_STRCPY);
  tcase_add_test(group_core, S21_strcspn);
  tcase_add_test(group_core, S21_STRCSPN);
  tcase_add_test(group_core, S21_MEMCHR);
  tcase_add_test(group_core, S21_MEMCMP);
  tcase_add_test(group_core, S21_MEMCPY);
  tcase_add_test(group_core, S21_MEMMOVE);
  tcase_add_test(group_core, S21_MEMSET);
  tcase_add_test(group_core, S21_STRPBRK);
  tcase_add_test(group_core, S21_STRSTR);
  tcase_add_test(group_core, S21_TO_UPPER);
  tcase_add_test(group_core, S21_TO_LOWER);
  tcase_add_test(group_core, S21_INSERT);
  tcase_add_test(group_core, S21_TRIM);
  tcase_add_test(group_core, S21_STRTOK);
  tcase_add_test(group_core, S21_SSCANF);
  tcase_add_test(group_core, s21_sprintf_f_g_n_prc_test);
  tcase_add_test(group_core, s21_sprintf_test);
  tcase_add_test(group_core, s21_sprintf_e_test);
  tcase_add_test(group_core, s21_sprintf_p_test);
  tcase_add_test(group_core, s21_sprintf_o_test);
  tcase_add_test(group_core, s21_sprintf_x_X_test);
  tcase_add_test(group_core, s21_sprintf_c_test);
  tcase_add_test(group_core, s21_sprintf_s_test);
  tcase_add_test(group_core, s21_sprintf_u_test);
  tcase_add_test(group_core, s21_sprintf_d_test);
  tcase_add_test(group_core, s21_sprintf_d_test_0);
  tcase_add_test(group_core, s21_sprintf_d_test_2);
  tcase_add_test(group_core, s21_sprintf_d_test_3);
  tcase_add_test(group_core, s21_sprintf_d_test_4);
  tcase_add_test(group_core, s21_sprintf_d_test_5);
  tcase_add_test(group_core, s21_sprintf_d_test_6);
  tcase_add_test(group_core, SPRINTF_FLOAT_PREC);
  tcase_add_test(group_core, SPRINTF_FLOAT_H);
  tcase_add_test(group_core, SPRINTF_FLOAT_H_PREC);
  tcase_add_test(group_core, SPRINTF_FLOAT_MINUS);
  tcase_add_test(group_core, SPRINTF_FLOAT_MINUS_DIGIT);
  tcase_add_test(group_core, SPRINTF_FLOAT_SPACE);
  tcase_add_test(group_core, SPRINTF_FLOAT_PLUS_H);

  tcase_add_test(group_core, SPRINTF_DECIMAL);
  tcase_add_test(group_core, SPRINTF_DECIMAL_PREC);
  tcase_add_test(group_core, SPRINTF_DECIMAL_L);
  tcase_add_test(group_core, SPRINTF_DECIMAL_H);
  tcase_add_test(group_core, SPRINTF_DECIMAL_MINUS_DIGIT);
  tcase_add_test(group_core, SPRINTF_DECIMAL_PLUS_DIGIT);
  tcase_add_test(group_core, SPRINTF_DECIMAL_MINUS_H);
  tcase_add_test(group_core, SPRINTF_DECIMAL_SPACE);

  tcase_add_test(group_core, SPRINTF_UNSIGNED);
  tcase_add_test(group_core, SPRINTF_UNSIGNED_MINUS_H);
  tcase_add_test(group_core, SPRINTF_UNSIGNED_H);
  tcase_add_test(group_core, SPRINTF_UNSIGNED_SPACE);

  tcase_add_test(group_core, SPRINTF_CHAR);
  tcase_add_test(group_core, SPRINTF_CHAR_DIGIT);
  tcase_add_test(group_core, SPRINTF_CHAR_H);
  tcase_add_test(group_core, SPRINTF_CHAR_MINUS_H);

  tcase_add_test(group_core, SPRINTF_STRING);
  tcase_add_test(group_core, SPRINTF_STRING_SYMBOLS);
  tcase_add_test(group_core, SPRINTF_STRING_MINUS_H);
  tcase_add_test(group_core, SPRINTF_STRING_H);

  tcase_add_test(group_core, SPRINTF_I_DEC);
  tcase_add_test(group_core, SPRINTF_I_OCTAL);
  tcase_add_test(group_core, SPRINTF_I_HEX);
  tcase_add_test(group_core, SPRINTF_I_H);
  tcase_add_test(group_core, SPRINTF_I_MINUS_H);
  tcase_add_test(group_core, SPRINTF_I_PLUS);
  tcase_add_test(group_core, SPRINTF_I_PLUS_H);
  tcase_add_test(group_core, SPRINTF_I_SPACE);
  tcase_add_test(group_core, s21_sprintf_cs);
  tcase_add_test(group_core, s21_sprintf_star);
  tcase_add_test(group_core, SPRINTFTestdogletho282);
  tcase_add_test(group_core, SPRINTFTestdogletho283);
  tcase_add_test(group_core, SPRINTFTestRleonard1);
  tcase_add_test(group_core, SPRINTFTestRleonard3);
  tcase_add_test(group_core, SPRINTFTestRleonard6);
  tcase_add_test(group_core, SPRINTFTestRleonard7);
  tcase_add_test(group_core, SPRINTFTestRleonard9);
  tcase_add_test(group_core, SPRINTFTestRleonard12);
  tcase_add_test(group_core, SPRINTFTestRleonard13);
  tcase_add_test(group_core, simple_int);
  tcase_add_test(group_core, precise_int);
  tcase_add_test(group_core, width_int);
  tcase_add_test(group_core, minus_width_int);
  tcase_add_test(group_core, plus_width_int);
  tcase_add_test(group_core, padding_int);
  tcase_add_test(group_core, flags_long_int);
  tcase_add_test(group_core, flags_short_int);
  tcase_add_test(group_core, unsigned_val);
  tcase_add_test(group_core, unsigned_val_width);
  tcase_add_test(group_core, unsigned_val_flags);
  tcase_add_test(group_core, unsigned_val_precision);
  tcase_add_test(group_core, unsigned_val_short);
  tcase_add_test(group_core, unsigned_val_long);
  tcase_add_test(group_core, unsigned_val_many);
  tcase_add_test(group_core, octal_short);
  tcase_add_test(group_core, unsigned_zero);
  tcase_add_test(group_core, one_char);
  tcase_add_test(group_core, one_precision);
  tcase_add_test(group_core, one_width);
  tcase_add_test(group_core, one_many);
  tcase_add_test(group_core, one_many_flags);
  tcase_add_test(group_core, string);
  tcase_add_test(group_core, string_precision);
  tcase_add_test(group_core, string_width);
  tcase_add_test(group_core, string_flags);
  tcase_add_test(group_core, string_long);
  tcase_add_test(group_core, string_many);
  tcase_add_test(group_core, string_width_huge);
  tcase_add_test(group_core, all_empty);
  tcase_add_test(group_core, empty_format_and_parameters);
  tcase_add_test(group_core, test_one_char);
  tcase_add_test(group_core, test_many_char);
  tcase_add_test(group_core, test_one_string);
  tcase_add_test(group_core, test_many_string);
  tcase_add_test(group_core, test_one_dec);
  tcase_add_test(group_core, test_many_dec);
  tcase_add_test(group_core, test_one_int);
  tcase_add_test(group_core, test_many_int);
  tcase_add_test(group_core, test_one_float);
  tcase_add_test(group_core, test_many_float);
  tcase_add_test(group_core, test_one_unsigned_dec);
  tcase_add_test(group_core, test_many_unsigned_dec);
  tcase_add_test(group_core, test_one_char_with_alignment_left);
  tcase_add_test(group_core, test_sprintf1);
  tcase_add_test(group_core, test_sprintf2);
  tcase_add_test(group_core, test_sprintf3);
  tcase_add_test(group_core, test_sprintf4);
  tcase_add_test(group_core, test_sprintf7);
  tcase_add_test(group_core, test_sprintf8);
  tcase_add_test(group_core, test_sprintf9);
  tcase_add_test(group_core, test_sprintf10);
  tcase_add_test(group_core, printf_cTest);
  tcase_add_test(group_core, printf_iTest);
  tcase_add_test(group_core, printf_sTest);
  tcase_add_test(group_core, printf_uTest);
  suite_add_tcase(suite, group_core);
  return suite;
}

int main() {
  setlocale(LC_ALL, "Rus");

  SRunner *suite_runner = srunner_create(make_s21string_suite());
  srunner_run_all(suite_runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return failed_count ? EXIT_FAILURE : EXIT_SUCCESS;
}
