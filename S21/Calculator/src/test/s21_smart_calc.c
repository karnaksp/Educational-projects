#include "s21_calc.h"

/**
 * @brief Функция для выполнения вычислений в польской нотации.
 *
 * @param topPtr Указатель на вершину стека с польской нотацией.
 * @param error_code Код ошибки (0 - ошибок нет, >0 - ошибка вычисления).
 * @return Результат вычисления.
 */
double s21_smart_calc(StackDataPtr *topPtr, int *error_code) {
  double result = NAN;
  *error_code = 0;
  StackDataPtr digitStack = NULL;
  stack_t result_item = {0.0, 0, '\0', 0, NULL};

  while (*topPtr != NULL && *error_code == ERROR_NO) {
    stack_t stack_item = s21_stack_pop(topPtr);

    if (stack_item.type == NUMBER) {
      s21_stack_push(&digitStack, stack_item);
    } else if (stack_item.type == OPERATION) {
      double right_value = s21_stack_pop(&digitStack).value;
      double left_value = s21_stack_pop(&digitStack).value;

      switch (stack_item.symbols) {
        case '-':
          result_item.value = left_value - right_value;
          break;
        case '+':
          result_item.value = left_value + right_value;
          break;
        case '*':
          result_item.value = left_value * right_value;
          break;
        case '/':
          if (right_value == 0) {
            *error_code = ERROR_DIV_BY_0;
            result_item.value = NAN;
          } else {
            result_item.value = left_value / right_value;
          }
          break;
        case '^':
          result_item.value = pow(left_value, right_value);
          break;
        case '%':
          result_item.value = fmod(left_value, right_value);
          break;
        default:
          *error_code = ERORR_UNKNOWN_OPERATION;
          break;
      }

      s21_stack_push(&digitStack, result_item);
    } else if (stack_item.type == FUNCTION) {
      double argument = s21_stack_pop(&digitStack).value;

      switch (stack_item.symbols) {
        case 's':
          result_item.value = sin(argument);
          break;
        case 'S':
          result_item.value = asin(argument);
          break;
        case 'c':
          result_item.value = cos(argument);
          break;
        case 'C':
          result_item.value = acos(argument);
          break;
        case 't':
          result_item.value = tan(argument);
          break;
        case 'T':
          result_item.value = atan(argument);
          break;
        case 'q':
          result_item.value = sqrt(argument);
          break;
        case 'l':
          result_item.value = log10(argument);
          break;
        case 'L':
          result_item.value = log(argument);
          break;
        default:
          *error_code = ERORR_UNKNOWN_OPERATION;
          break;
      }

      s21_stack_push(&digitStack, result_item);
    }
  }

  result_item = s21_stack_pop(&digitStack);
  if (digitStack != NULL || result_item.type != NUMBER) {
    *error_code = ERROR_BAD_EXPRESSION;
    result = NAN;
  } else
    result = result_item.value;

  s21_stack_clear(&digitStack);
  return result;
}

/**
 * @brief Функция-калькулятор считывает выражение, нормализует, переводит в
 * польскую нотацию и вычисляет результат.
 *
 * @param expression Строка с математическим выражением.
 * @param x Значение переменной x.
 * @param error_code Указатель на переменную для сохранения кода ошибки.
 * @return Результат вычисления выражения. Если возникает ошибка, возвращается
 * NaN.
 */
double s21_calculation(char *expression, char *x, int *error_code) {
  *error_code = ERROR_NO;
  double result = NAN;

  s21_normalize_expression(expression, x, error_code);

  if (*error_code == ERROR_NO) {
    char lexems[500][256];
    int lexems_count = s21_lexems(expression, lexems);
    StackDataPtr stack_item = NULL;
    *error_code = s21_convert_to_stack(lexems, lexems_count, &stack_item);

    if (*error_code == ERROR_NO) {
      s21_stack_revers(&stack_item);
      *error_code = s21_polish_postfix(&stack_item);
      if (*error_code == ERROR_NO) {
        s21_stack_revers(&stack_item);
        result = s21_smart_calc(&stack_item, error_code);
        s21_stack_clear(&stack_item);
      }
    }
  }

  return result;
}
