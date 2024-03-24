#include "s21_calc.h"

/**
 * @brief Функция перевода выражения в обратную польскую нотацию.
 *
 * @param topPtr Указатель на вершину стэка.
 * @return err_flag: 0 - ошибок нет, другое - в выражении допущена ошибка.
 */
int s21_polish_postfix(StackDataPtr *topPtr) {
  int err_flag = ERROR_NO;
  StackDataPtr postfix_stack = NULL;
  StackDataPtr support_stack = NULL;

  while (*topPtr != NULL && err_flag == ERROR_NO) {
    stack_t stack_item = s21_stack_pop(topPtr);

    if (stack_item.type == NUMBER) {
      s21_stack_push(&postfix_stack, stack_item);
    } else if (stack_item.type == LEFT_BRACKET) {
      s21_stack_push(&support_stack, stack_item);
    } else if (stack_item.type == OPERATION || stack_item.type == FUNCTION) {
      s21_handle_OF(&postfix_stack, &support_stack, stack_item);
    } else if (stack_item.type == RIGHT_BRACKET) {
      s21_handle_R_Bracket(&postfix_stack, &support_stack, &err_flag);
    }
  }

  s21_handle_Other_Support(&postfix_stack, &support_stack, &err_flag);

  *topPtr = postfix_stack;
  s21_stack_clear(&support_stack);
  return err_flag;
}

/**
 * @brief Обрабатывает операции и функции, пока их приоритет больше или равен
 * текущей лексеме.
 *
 * Эта функция выполняет выталкивание операций и функций из стека
 * `support_stack`, пока их приоритет больше или равен приоритету текущей
 * лексемы `stack_item`, и помещает их в стек `postfix_stack`.
 *
 * @param postfix_stack Указатель на стек, куда помещаются лексемы в обратной
 * польской записи.
 * @param support_stack Указатель на стек операций и функций.
 * @param stack_item Текущая лексема, которая сравнивается с операциями и
 * функциями в стеке.
 */
void s21_handle_OF(StackDataPtr *postfix_stack, StackDataPtr *support_stack,
                   stack_t stack_item) {
  while ((*support_stack) != NULL &&
         (*support_stack)->priority >= stack_item.priority &&
         (*support_stack)->priority != 5) {
    s21_stack_push(postfix_stack, s21_stack_pop(support_stack));
  }
  s21_stack_push(support_stack, stack_item);
}

/**
 * @brief Обрабатывает правую скобку в выражении.
 *
 * Эта функция выполняет обработку правой скобки, выталкивая операции и функции
 * из стека `support_stack` в стек `postfix_stack` до нахождения левой скобки.
 * В случае ошибки, устанавливает флаг `err_flag`.
 *
 * @param postfix_stack Указатель на стек, куда помещаются лексемы в обратной
 * польской записи.
 * @param support_stack Указатель на стек операций и функций.
 * @param err_flag Указатель на флаг ошибки, который устанавливается в случае
 * ошибки.
 */
void s21_handle_R_Bracket(StackDataPtr *postfix_stack,
                          StackDataPtr *support_stack, int *err_flag) {
  if (*support_stack == NULL) {
    *err_flag = ERROR_BAD_EXPRESSION;
  } else {
    while (*support_stack != NULL) {
      stack_t support_item = s21_stack_pop(support_stack);
      if (support_item.type == LEFT_BRACKET) {
        break;
      }
      s21_stack_push(postfix_stack, support_item);
    }
  }
}

/**
 * @brief Обрабатывает оставшиеся операции и функции в стеке `support_stack`.
 *
 * Эта функция выполняет выталкивание оставшихся операций и функций из стека
 * `support_stack` в стек `postfix_stack`. В случае обнаружения непарной левой
 * скобки, устанавливает флаг `err_flag`.
 *
 * @param postfix_stack Указатель на стек, куда помещаются лексемы в обратной
 * польской записи.
 * @param support_stack Указатель на стек операций и функций.
 * @param err_flag Указатель на флаг ошибки, который устанавливается в случае
 * ошибки.
 */
void s21_handle_Other_Support(StackDataPtr *postfix_stack,
                              StackDataPtr *support_stack, int *err_flag) {
  while (*support_stack != NULL) {
    stack_t support_item = s21_stack_pop(support_stack);
    if (support_item.type == LEFT_BRACKET) {
      *err_flag = ERROR_BAD_EXPRESSION;
      break;
    }
    s21_stack_push(postfix_stack, support_item);
  }
}
