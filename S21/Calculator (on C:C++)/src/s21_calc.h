#ifndef SRC_S21_CALC_H_
#define SRC_S21_CALC_H_

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_err_base.h"

/******************************************************
 * !!Определение макросов!!
 ******************************************************/

#define ERROR_NO 0         /**< Ошибок нет */
#define ERROR_BAD_SYMBOL 1 /**< Не корректный символ */
#define ERROR_BAD_STR 2    /**< Не корректная строка */
#define ERROR_EMPTY_STR 3  /**< Строка пустая */
#define ERROR_SHORT_STR 4  /**< Строка слишком короткая */
#define ERROR_LONG_STR 5   /**< Строка слишком длинная */
#define ERROR_BAD_BRACKETS 6   /**< Скобки не корректные */
#define ERROR_BAD_EXPRESSION 7 /**< Некорректное выражание */
#define ERROR_NO_OPERATORS 8 /**< В выражении нет операторов */
#define ERROR_MEMORY_ALLOCATION 9 /**< Ошибка выделения памяти */
#define ERROR_EMPTY_BRACKETS 10 /**< В скобках пусто */
#define ERROR_BAD_CONVERT 11 /**< Ошибка конвенртирования в стек */
#define ERORR_UNKNOWN_FUNCTION 12  /**< Неизветная функция */
#define ERORR_UNKNOWN_OPERATION 13 /**< Неизветная операция */
#define ERROR_DIV_BY_0 14          /**< Деление на ноль */

/******************************************************
 * !!Определение структур!!
 ******************************************************/

/**
 * @struct stackBracket
 * @brief Структура для проверки корректности парности скобок
 */
typedef struct stackBracket {
  char barcket;                 /**< Одна скобка */
  struct stackBracket *nextPtr; /**< Указатель на следующую скобку */
} StackBracket;

/**
 * @typedef StackBracketPtr
 * @brief Указатель на структуру stackBracket
 */
typedef StackBracket *StackBracketPtr;

/**
 * @enum type_t
 * @brief Типы лексем
 */
typedef enum {
  NUMBER = 0,        /**< Число */
  OPERATION = 1,     /**< Операция */
  FUNCTION = 2,      /**< Функция */
  LEFT_BRACKET = 3,  /**< Левая скобка */
  RIGHT_BRACKET = 4, /**< Правая скобка */
  ERROR = 5          /**< Ошибка */
} type_t;

/**
 * @struct stack_data
 * @brief Структура элемента стека
 */
typedef struct stack_data {
  double value; /**< Значение числа */
  int priority; /**< Приоритет */
  char symbols; /**< Значение символа */
  type_t type;  /**< Информация о лексеме */
  struct stack_data *nextPtr; /**< Указатель на следующий элемент стека */
} stack_t;

/**
 * @typedef StackDataPtr
 * @brief Указатель на структуру stack_data
 */
typedef stack_t *StackDataPtr;

/******************************************************
 * !!Функции для валидации и нормализации строки выражения!!
 ******************************************************/

void s21_remove_space(char *str);
void s21_to_lower(char *str);
int s21_valid_characters(char *str);
int s21_is_characters(char symbol);
int s21_is_str_empty(char *str);
char *s21_strerror(int errnum);
int s21_expression_size(char *str);
int s21_brackets_count(char *str);
int s21_check_point(char *str);
int s21_check_operators(char *str);
void s21_replaceX(char *str, const char *x);
int s21_is_operator(char oper);
int s21_correct_operators(char *str);
int s21_check_brackets(char *str);
int s21_check_func(char *token, char ch);
int s21_correct_func(char *str);
int s21_last_symbol(char *str);
int s21_empty_brackets(char *str);
int s21_sing_before_func(char *str);
int s21_first_operator_and_sign(char *str);
char *s21_str_replace(char *dst, int num, const char *str, const char *orig,
                      const char *rep);
void s21_clear_str(char *str, char *buf);
void s21_replace_functions(char *str);
int s21_expression_check(char *expression);
void s21_add_separator(char *str);
int s21_lexems(char *str, char lexems[][256]);
void s21_normalize_expression(char *expression, char *x, int *error_code);

/******************************************************
 * !!Проверка баланса скобок через стек!!
 ******************************************************/

int bracket_push(StackBracketPtr *topPtr, char bracket);
void bracket_pop(StackBracketPtr *topPtr);
int bracket_isEmpty(const StackBracketPtr topPtr);

/******************************************************
 * !!Функции для управления основной структурой стека!!
 ******************************************************/

int s21_stack_push(StackDataPtr *topPtr, stack_t stack_data);
int s21_isEmpty(const StackDataPtr topPtr);
stack_t s21_stack_pop(StackDataPtr *topPtr);
void s21_stack_clear(StackDataPtr *topPtr);
void s21_stack_revers(StackDataPtr *topPtr);
stack_t s21_stack_peek(const StackDataPtr *topPtr);
int s21_convert_to_stack(const char lexems[][256], const int lexems_count,
                         StackDataPtr *topPtr);
stack_t s21_create_item(const char *value, const int priority,
                        const char symbols, const type_t type);
int s21_isOperation(const char oper);
int s21_get_priority(const char oper);
int s21_valid_function(const char func);

/******************************************************
 * !!Польская нотация и вычисления!!
 ******************************************************/

int s21_polish_postfix(StackDataPtr *topPtr);
void s21_handle_OF(StackDataPtr *postfix_stack, StackDataPtr *support_stack,
                   stack_t stack_item);
void s21_handle_R_Bracket(StackDataPtr *postfix_stack,
                          StackDataPtr *support_stack, int *err_flag);
void s21_handle_Other_Support(StackDataPtr *postfix_stack,
                              StackDataPtr *support_stack, int *err_flag);

/******************************************************
 * !!Связь с фронтом - основные функции калькулятора!!
 ******************************************************/

double s21_smart_calc(StackDataPtr *topPtr, int *error_code);
double s21_calculation(char *expression, char *x, int *err_code);

#endif  // SRC_S21_CALC_H_
