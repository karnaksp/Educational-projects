#include <check.h>
#include <math.h>

#include "../s21_decimal.h"
#include "../s21_suppl.h"

START_TEST(multiplication_10) {
  float f_value_1 = 20.5;
  float f_value_2 = 30.0;
  s21_decimal res = {{0x00000001, 0, 0, 0x001C0000}};
  float flot = 0;
  s21_from_decimal_to_float(res, &flot);
  printf("flot: %f\n", flot);
  float inp = 321213143.8323;  // 24

  float_cast num_cast;
  num_cast.float_number = inp;

  // Вывод в двоичной системе
  printf("Binary representation: ");
  printf("%d ", num_cast.parts.sign);
  for (int i = 7; i >= 0; i--) {
    printf("%d", (num_cast.parts.exponenta >> i) & 1);
  }
  for (int i = 22; i >= 0; i--) {
    printf("%d", (num_cast.parts.fraction >> i) & 1);
  }
  printf("\n");

  // Вывод в шестнадцатеричной системе
  printf("Hexadecimal representation: %08X\n", num_cast.int_number);
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  s21_from_float_to_decimal(inp, &out);
  s21_decimal resu = {{0x13255310, 0, 0, 0}};
  float resuf = 0.0;
  s21_from_decimal_to_float(resu, &resuf);
  printf("test bits: %f ", resuf);
  for (int i = 3; i >= 0; --i) {
    printf("%08x ", resu.bits[i]);
  }
  puts("");
  printf("decimal from temp: ");
  for (int i = 3; i >= 0; --i) {
    printf("%08x ", out.bits[i]);
  }
  puts("");
  s21_from_decimal_to_float(out, &flot);
  printf("flot: %f\n", flot);
  float_cast num_cast1;
  num_cast1.float_number = flot;
  // Вывод в двоичной системе
  printf("Binary representation result: ");
  printf("%d ", num_cast1.parts.sign);
  for (int i = 7; i >= 0; i--) {
    printf("%d", (num_cast1.parts.exponenta >> i) & 1);
  }
  for (int i = 22; i >= 0; i--) {
    printf("%d", (num_cast1.parts.fraction >> i) & 1);
  }
  printf("\n");

  // Вывод в шестнадцатеричной системе
  printf("Hexadecimal representation result: %08X\n", num_cast1.int_number);
  s21_decimal value_1, value_2, result_dec;
  s21_from_float_to_decimal(f_value_1, &value_1);
  s21_from_float_to_decimal(f_value_2, &value_2);
  float expected_result = f_value_1 * f_value_2;
  int return_value = s21_mul(value_1, value_2, &result_dec);
  float result = 0.0;
  s21_from_decimal_to_float(result_dec, &result);
  printf("result of multiplication: %f\n", result);
  ck_assert_msg(return_value == 0, "Multiplication failed: return value=%d",
                return_value);
  ck_assert_msg(fabs(result - expected_result) <= 1e-6,
                "Multiplication failed: expected %.6f, got %.6f",
                expected_result, result);
}
END_TEST

Suite *lib_suite(void) {
  Suite *s;
  s = suite_create("Check");

  TCase *multiplication;
  multiplication = tcase_create("multiplication");
  suite_add_tcase(s, multiplication);
  tcase_add_test(multiplication, multiplication_10);

  return s;
}

int main(void) {
  Suite *s;
  SRunner *sr;
  s = lib_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, 2);
  srunner_free(sr);
  return 0;
}