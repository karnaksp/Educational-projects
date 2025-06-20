/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "remove_space.check" instead.
 */

#include <check.h>

#line 1 "remove_space.check"
#include <check.h>

#include "../s21_calc.h"

START_TEST(test_remove_space_number1)
{
#line 6
char s[] = "   X   X   X   ";
char result[] = "XXX";
s21_remove_space(s);
ck_assert_str_eq(result, s);

}
END_TEST

START_TEST(test_remove_space_number2)
{
#line 12
char s[] = "XXX";
char result[] = "XXX";
s21_remove_space(s);
ck_assert_str_eq(result, s);

}
END_TEST

START_TEST(test_remove_space_number3)
{
#line 18
char s[] = "ok";
char result[] = "ok";
s21_remove_space(NULL);
ck_assert_str_eq(result, s);

}
END_TEST

START_TEST(test_remove_space_number4)
{
#line 24
char s[] = "";
char result[] = "";
s21_remove_space(s);
ck_assert_str_eq(result, s);

}
END_TEST

START_TEST(test_remove_space_number5)
{
#line 30
char s[] = " ";
char result[] = "";
s21_remove_space(s);
ck_assert_str_eq(result, s);

}
END_TEST

START_TEST(test_remove_space_number6)
{
#line 36
char s[] = "d DD  DDDDD              d   d d d";
char result[] = "dDDDDDDDdddd";
s21_remove_space(s);
ck_assert_str_eq(result, s);
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, test_remove_space_number1);
    tcase_add_test(tc1_1, test_remove_space_number2);
    tcase_add_test(tc1_1, test_remove_space_number3);
    tcase_add_test(tc1_1, test_remove_space_number4);
    tcase_add_test(tc1_1, test_remove_space_number5);
    tcase_add_test(tc1_1, test_remove_space_number6);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
