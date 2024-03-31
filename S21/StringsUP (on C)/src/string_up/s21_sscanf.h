#ifndef S21_SSCANF_H
#define S21_SSCANF_H

#include <ctype.h>
#include <stdbool.h>
#include <wchar.h>

#include "s21_sprintf.h"

void s21_isspace(char **temp, FormatFlags *flags);
void s21_process_sign(char **temp, FormatFlags *flags);
void s21_process_hex_prefix(char **temp, char *digits, int *digitCount);
void s21_process_digit(char **temp, char *digits, int *digitCount);
void s21_process_null_flags(FormatFlags *flags);
void s21_process_nan_prefix(char **temp, char *digits, int *digitCount);
int s21_determineBase(char **str, FormatFlags *flags);

long s21_atoi(char *str, FormatFlags *flags);
double s21_atof(char *str, FormatFlags *flags);
unsigned long s21_strtoul(char *str, FormatFlags *flags);

int s21_sscanf_xou(va_list args, FormatFlags *flags, char **temp);
int s21_sscanf_cs(va_list args, FormatFlags *flags, char **temp);
int s21_sscanf_di(va_list args, FormatFlags *flags, char **temp);
int s21_sscanf_p(va_list args, FormatFlags *flags, char **temp);
int s21_sscanf_s(va_list args, FormatFlags *flags, char **temp);
void s21_sscanf_n(va_list args, FormatFlags *flags, char **temp);
int s21_sscanf_efg(va_list args, FormatFlags *flags, char **temp);
void s21_sscanf_percent(char **temp, FormatFlags *flags);

int s21_sscanfReader(va_list args, FormatFlags *flags, char *temp,
                     char *format);
int s21_sscanfTranslater(va_list args, FormatFlags *flags, char **temp,
                         char *format);

int s21_sscanf(const char *str, char *format, ...);

#endif  // S21_SSCANF_H
