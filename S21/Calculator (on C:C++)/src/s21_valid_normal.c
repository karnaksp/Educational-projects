#include "s21_calc.h"

/** @brief Функция удаляет все пробелы в строке
 * @param str строка
 */
void s21_remove_space(char *str) {
  if (str != NULL) {
    int i, j;
    for (i = j = 0; str[i] != '\0'; i++)
      if (str[i] != ' ' && str[i] != '\t') str[j++] = str[i];
    str[j] = '\0';
  }
}

/** @brief Функция переводит всю строку в нижний регистр
 * @param str строка
 */
void s21_to_lower(char *str) {
  if (str != NULL) {
    for (size_t i = 0; i < strlen(str); i++) {
      str[i] = tolower(str[i]);
    }
  }
}

/** @brief Функция проверяет символ на вхождение в набор допустимых символов
 * @param symbol проверяемый символ
 * @return 0 - входит в диапозон, 1 - не входит
 */
int s21_is_characters(char symbol) {
  int status = ERROR_NO;
  char character_set[] = ".()+-*/^modcsintaqrlgx";
  for (size_t i = 0; i < strlen(character_set); i++) {
    if (symbol == character_set[i]) {
      status = ERROR_NO;
      break;
    } else {
      status = ERROR_BAD_SYMBOL;
    }
  }
  return status;
}

/** @brief Функция проверяет, что строка состоит только из допустимого набора
 * символов
 * @param str строка, которую проверяем
 * @return 0 - ошибок нет и все символы допустимые, 1 - ошибка, в строке есть
 * недопустимый символ, 2 - на вход подана не строка
 */
int s21_valid_characters(char *str) {
  int err_flag = ERROR_NO;
  if (str != NULL) {
    for (size_t i = 0; i < strlen(str); i++) {
      if (isdigit(str[i]) || !(s21_is_characters(str[i]))) {
        err_flag = ERROR_NO;
      } else {
        err_flag = ERROR_BAD_SYMBOL;
        break;
      }
    }
  } else {
    err_flag = ERROR_BAD_STR;
  }
  return err_flag;
}

/** @brief Функция проверка, что строка выражения не пустая
 * @param str строка, которую проверяем
 * @return 0 - ошибок нет, строка не пустая, 3 - ошибка, строка пустая
 */
int s21_is_str_empty(char *str) {
  int err_flag = ERROR_NO;
  if (strlen(str) == 0) {
    err_flag = ERROR_EMPTY_STR;
  }
  return err_flag;
}

/** @brief Функция расшифровывает код ошибки
 * @param errnum код ошибки
 * @return возвращаем тектовое описание кода ошибки
 */
char *s21_strerror(int errnum) {
  char *const error[] = ERROR_BASE;
  static char *result;
  result = error[errnum];
  return result;
}

/** @brief Функция проверка длинны выражения
 * @param str строка, которую проверяем
 * @return 0 - в допутимых значениях, 4 - меньше 2 символов, 5 - более 255
 * символов
 */
int s21_expression_size(char *str) {
  int err_flag = ERROR_NO;
  if (strlen(str) < 2) {
    err_flag = ERROR_SHORT_STR;
  } else {
    if (strlen(str) > 255) {
      err_flag = ERROR_LONG_STR;
    }
  }
  return err_flag;
}

/** @brief Функция проверкb кол-ва открывающихся и закрывающихся скобок
 * @param str строка, которую проверяем
 * @return 0 - ошибок нет, кол-во скобок равно, 6 - кол-во скобок не равно
 */
int s21_brackets_count(char *str) {
  int err_flag = ERROR_NO;
  int left_brackets = 0;
  int right_brackets = 0;
  for (size_t i = 0; i < strlen(str); i++) {
    if (str[i] == '(') {
      left_brackets++;
    } else if (str[i] == ')') {
      right_brackets++;
    }
  }
  if (left_brackets != right_brackets) {
    err_flag = ERROR_BAD_BRACKETS;
  }
  return err_flag;
}

/** @brief Функция проверки точек в выражении
 * @param str строка, которую проверяем
 * @return 0 - ошибок нет, 7 - ошибка, не корректное выражение
 */
int s21_check_point(char *str) {
  int err_flag = ERROR_NO;
  if ((str[0] == '.') || (str[strlen(str) - 1] == '.')) {
    err_flag = ERROR_BAD_EXPRESSION;
  } else {
    for (size_t i = 0; i < strlen(str) - 1; i++) {
      if ((str[i] == '.') && (str[i + 1] == '.')) {
        err_flag = ERROR_BAD_EXPRESSION;
        break;
      } else {
        if (strlen(str) > 3) {
          for (size_t j = 1; j < strlen(str) - 1; j++) {
            if ((str[j] == '.') &&
                (!(isdigit(str[j - 1])) || !(isdigit(str[j + 1])))) {
              err_flag = ERROR_BAD_EXPRESSION;
              break;
            }
          }
        }
      }
    }
  }
  return err_flag;
}

/** @brief Функция проверки на наличие операторов или функций
 * @param str строка, которую проверяем
 * @return 0 - ошибок нет, 8 - ошибка, операторы или функции не найдены
 */
int s21_check_operators(char *str) {
  int err_flag = ERROR_NO;
  const char *operators[] = {"+",   "-",   "*",   "/",    "^",  "mod",
                             "cos", "sin", "tan", "sqrt", "ln", "log"};
  int count_operators = 0;
  for (size_t i = 0; i < sizeof(operators) / sizeof(operators[0]); ++i) {
    if (strstr(str, operators[i]) != NULL) count_operators++;
  }
  if (count_operators == 0) err_flag = ERROR_NO_OPERATORS;

  return err_flag;
}

/** @brief Функция находит и меняет в строке выражения переменную <x> на ее
 * значение
 * @param str строка выражения
 * @param x - значение переменной для подстановки
 */
void s21_replaceX(char *str, const char *x) {
  if (str != NULL) {
    size_t countX = 0;
    size_t lenSTR = strlen(str);
    size_t lenX = strlen(x);
    size_t i = 0;
    size_t j = 0;
    for (i = 0; i < lenSTR; i++) {
      if (str[i] == 'x') {
        countX++;
      }
    }
    size_t new_lenSTR = lenSTR + countX * (lenX + 2);
    char *newSTR = malloc(new_lenSTR + 1);
    // Проходим по исходной строке и заменяем переменную "x" на ее значение
    for (i = 0, j = 0; i < lenSTR; i++) {
      if (str[i] == 'x') {
        if (x[0] == '-') {
          newSTR[j++] = '(';
          newSTR[j++] = '0';
        }
        strcpy(newSTR + j, x);
        j += lenX;
        if (x[0] == '-') {
          newSTR[j++] = ')';
        }
      } else {
        newSTR[j++] = str[i];
      }
    }
    newSTR[j++] = '\0';
    strcpy(str, newSTR);
    free(newSTR);
  }
}

/** @brief Функция проверяет, что символ является оператором
 * @param oper проверяемый символ
 * @return 0 - не оператор, 1 - оператор
 */
int s21_is_operator(char oper) {
  int check = 0;
  if ((oper == '-') || (oper == '+') || (oper == '*') || (oper == '/') ||
      (oper == '^')) {
    check = 1;
  }
  return check;
}

/** @brief Функция проверяет, что выражение не заканчивается оператором и что не
 * используются два подряд идущих оператора
 * @param str строка-выражение
 * @return 0 - ошибок нет, 7 - ошибка, не корректное выражение
 */
int s21_correct_operators(char *str) {
  int err_flag = ERROR_NO;
  char last_ch = str[strlen(str) - 1];
  if ((last_ch == '-') || (last_ch == '+') || (last_ch == '*') ||
      (last_ch == '/') || (last_ch == '^') || (last_ch == 's') ||
      (last_ch == 'n') || (last_ch == 't') || (last_ch == 'g')) {
    err_flag = ERROR_BAD_EXPRESSION;
  } else {
    for (size_t i = 0; i < strlen(str) - 1; i++) {
      if (s21_is_operator(str[i]) && s21_is_operator(str[i + 1])) {
        err_flag = ERROR_BAD_EXPRESSION;
        break;
      }
    }
  }
  return err_flag;
}

/** @brief Функция проверяет что после функции следует открывающаяся скобока
 * @param token строка в которой есть функция
 * @param ch символ после которого должна быть скобка
 * @return 0 - скобка есть, 1 - скобки нет
 */
int s21_check_func(char *token, char ch) {
  int flag = 0;
  for (size_t i = 0; i < strlen(token) - 1; i++) {
    if ((token[i] == ch) && (token[i + 1] != '(')) {
      flag = 1;
      break;
    }
  }
  return flag;
}

/** @brief Функция проверяет, что после функции есть открывающаяся скобка
 * @param str строка-выражение
 * @return 0 - ошибок нет, 7 - ошибка, не корректное выражение
 */
int s21_correct_func(char *str) {
  char *tmpStr = strdup(str);
  char *savePtr;
  int err_flag = ERROR_NO;
  int err_count = 0;

  const char *functions[] = {"sin", "cos", "tan", "sqrt", "log", "ln"};

  char *token = strtok_r(tmpStr, "()-+/*^", &savePtr);

  while (token != NULL) {
    if (strlen(token) > 2) {
      for (size_t i = 0; i < sizeof(functions) / sizeof(functions[0]); ++i) {
        if (strstr(token, functions[i]) != NULL) {
          if (s21_check_func(token, functions[i][strlen(functions[i]) - 1])) {
            err_count++;
          }
        }
      }
    }
    token = strtok_r(NULL, "()-+/*^", &savePtr);
  }

  free(tmpStr);

  if (err_count > 0) {
    err_flag = ERROR_BAD_EXPRESSION;
  }

  return err_flag;
}

/** @brief Функция проверяет что выражение заканчивается скобкой или цифрой
 * @param str строка-выражение
 * @return 0 - ошибок нет, 7 - ошибка, не корректное выражение
 */
int s21_last_symbol(char *str) {
  int err_flag = ERROR_NO;
  int flag = isdigit(str[strlen(str) - 1]);
  if (str[strlen(str) - 1] != ')') {
    if (flag == 0) {
      err_flag = ERROR_BAD_EXPRESSION;
    }
  }
  return err_flag;
}

/** @brief Функцияищет подстроки и меняет их во всей строке на заданное значение
 * @param dst указать на строку срезультатом
 * @param num максимальная длинна выходной строки
 * @param str строка в которой будем искать
 * @param orig подстрока которую ищем
 * @param rep подстрока на которую производим замену
 * @return адрес на строку в которой будет храниться результат.
 */
char *s21_str_replace(char *dst, int num, const char *str, const char *orig,
                      const char *rep) {
  const char *ptr;
  size_t len1 = strlen(orig);
  size_t len2 = strlen(rep);
  char *tmp = dst;

  num -= 1;
  while ((ptr = strstr(str, orig)) != NULL) {
    num -= (ptr - str) + len2;
    if (num < 1) break;

    strncpy(dst, str, (size_t)(ptr - str));
    dst += ptr - str;
    strncpy(dst, rep, len2);
    dst += len2;
    str = ptr + len1;
  }

  for (; (*dst = *str) && (num > 0); --num) {
    ++dst;
    ++str;
  }
  return tmp;
}

/** @brief Функцияобнуляет строку выражения и копируют в нее другую строку
 * @param str строка в которую копируем
 * @param buf строка из которой копируем
 */
void s21_clear_str(char *str, char *buf) {
  memset(str, 0, strlen(str));
  strcpy(str, buf);
}

/** @brief Функция меняет в строке выражения функции на символьные заменители
 * @param str строка-выражение
 */
void s21_replace_functions(char *str) {
  char buf[1024];

  const char *functionMappings[][2] = {
      {"mod", "%"},  {"acos", "C"}, {"cos", "c"},  {"asin", "S"}, {"sin", "s"},
      {"atan", "T"}, {"tan", "t"},  {"sqrt", "q"}, {"log", "l"},  {"ln", "L"}};

  for (size_t i = 0; i < sizeof(functionMappings) / sizeof(functionMappings[0]);
       ++i) {
    memset(buf, 0, sizeof(buf));
    s21_str_replace(buf, sizeof(buf) - 1, str, functionMappings[i][0],
                    functionMappings[i][1]);
    s21_clear_str(str, buf);
  }
}

/** @brief Функцияпроверяет что выражение не начинается с мод, степени или
 * операторов не равных плюс и минус, подставляет 0 перед унарным плюсом или
 * минусом
 * @param str строка выражение
 * @return 0 - ошибок нет, 7 - ошибка не корректного выражения, а так же
 * измененная строка выражение
 */
int s21_first_operator_and_sign(char *str) {
  int err_flag = ERROR_NO;
  if ((str[0] == 'm') || (str[0] == '^') || (str[0] == '/') ||
      (str[0] == '*')) {
    err_flag = ERROR_BAD_EXPRESSION;
  } else {
    char buf[1024];
    int buf_step = 0;
    if ((str[0] == '+') || (str[0] == '-')) {
      buf[buf_step] = '0';
      buf_step++;
    }
    for (size_t i = 0; i < strlen(str) - 1; i++) {
      if ((str[i] == '(') && ((str[i + 1] == '-') || (str[i + 1] == '+'))) {
        buf[buf_step] = str[i];
        buf_step++;
        buf[buf_step] = '0';
        buf_step++;
      } else {
        buf[buf_step] = str[i];
        buf_step++;
      }
    }
    buf[buf_step] = str[strlen(str) - 1];
    buf_step++;
    buf[buf_step] = '\0';
    memset(str, 0, strlen(str));
    strcpy(str, buf);
    memset(buf, 0, strlen(buf));
  }

  return err_flag;
}

/** @brief Функция проверяет, что внутри скобок не пусто
 * @param str строка-выражение
 * @return 0 - ошибок нет, 10 - ошибка внутри скобок пусто
 */
int s21_empty_brackets(char *str) {
  int err_flag = ERROR_NO;
  for (size_t i = 0; i < strlen(str) - 1; i++) {
    if ((str[i] == '(') && ((str[i + 1] == ')'))) {
      err_flag = ERROR_EMPTY_BRACKETS;
    }
  }
  return err_flag;
}

/** @brief Функция проверяет что за фунцией не идет оператор
 * @param str  строка-выражение
 * @return 0 - ошибок нет, 7 - ошибка выражение не корректно
 */
int s21_sing_before_func(char *str) {
  int err_flag = ERROR_NO;
  for (size_t i = 0; i < strlen(str) - 1; i++) {
    if ((str[i] == 's' || str[i] == 'n' || str[i] == 't' || str[i] == 'g' ||
         str[i] == 'd') &&
        s21_is_operator(str[i + 1])) {
      err_flag = ERROR_BAD_EXPRESSION;
      break;
    }
  }
  return err_flag;
}

/** @brief Общая проверка корректности математического выражения.
 *
 * @param expression Строка с математическим выражением.
 * @return Код ошибки: 0 - ошибок нет, коды ошибок от 1 до 9 в случае
 * обнаружения ошибок.
 */
int s21_expression_check(char *expression) {
  // Массив функций проверки
  int (*checks[])(char *) = {s21_is_str_empty,
                             s21_expression_size,
                             s21_valid_characters,
                             s21_brackets_count,
                             s21_check_point,
                             s21_check_operators,
                             s21_correct_operators,
                             s21_check_brackets,
                             s21_correct_func,
                             s21_last_symbol,
                             s21_first_operator_and_sign,
                             s21_empty_brackets,
                             s21_sing_before_func};

  int err_code = 0;

  for (long unsigned int i = 0; i < sizeof(checks) / sizeof(checks[0]); i++) {
    err_code = checks[i](expression);
    if (err_code != ERROR_NO) break;
  }

  return err_code;
}

/** @brief Функция добавляет в строку-выражение пробелы сепараторы
 * @param str строка-выражение
 */
void s21_add_separator(char *str) {
  char buf[1024];
  int buf_step = 0;
  for (size_t i = 0; i < strlen(str); i++) {
    if ((str[i] == ')') || (str[i] == '%') || (str[i] == '+') ||
        (str[i] == '-') || (str[i] == '*') || (str[i] == '/') ||
        (str[i] == '^')) {
      buf[buf_step] = ' ';
      buf_step++;
      buf[buf_step] = str[i];
      buf_step++;
      buf[buf_step] = ' ';
    } else {
      if ((str[i] == 'c') || (str[i] == 'C') || (str[i] == 's') ||
          (str[i] == 'S') || (str[i] == 't') || (str[i] == 'T') ||
          (str[i] == 'l') || (str[i] == 'L') || (str[i] == 'q') ||
          (str[i] == '(')) {
        buf[buf_step] = str[i];
        buf_step++;
        buf[buf_step] = ' ';
      } else {
        buf[buf_step] = str[i];
      }
    }
    buf_step++;
  }
  buf[buf_step] = '\0';
  memset(str, 0, strlen(str));
  strcpy(str, buf);
  memset(buf, 0, strlen(buf));
}

/** @brief Функция разбивает выражение на лексемы и формирует массив лексем
 * @param str - преобразоованная функцией s21_add_separator строка выражения
 * @param lexems массив, в которым помещаем лексемы
 * @return кол-во лексем
 */
int s21_lexems(char *str, char lexems[][256]) {
  char *tmpStr = strdup(str);
  char *savePtr;
  int lexems_count = 0;
  int i = 0;
  char **strarray = NULL;
  char **tmp = NULL;
  char *token = __strtok_r(tmpStr, " ", &savePtr);
  while (token != NULL) {
    tmp = (char **)realloc(strarray, (lexems_count + 1) * sizeof(char *));
    if (tmp) {
      strarray = tmp;
      strarray[lexems_count] = strdup(token);
      lexems_count++;
      token = __strtok_r(NULL, " ", &savePtr);
    }
  }
  for (i = 0; i < lexems_count; i++) {
    strcpy(lexems[i], strarray[i]);
  }
  for (i = 0; i < lexems_count; i++) free(strarray[i]);
  free(strarray);
  free(tmpStr);
  return lexems_count;
}

/** @brief Нормализует строку выражения.
 *
 * @param expression Строка с математическим выражением.
 * @param x Значение переменной x.
 * @param error_code Указатель на переменную для сохранения кода ошибки.
 */
void s21_normalize_expression(char *expression, char *x, int *error_code) {
  *error_code = ERROR_NO;
  s21_to_lower(expression);
  s21_remove_space(expression);
  s21_replaceX(expression, x);
  int expression_check = s21_expression_check(expression);
  if (expression_check != ERROR_NO) {
    *error_code = expression_check;
  } else {
    s21_replace_functions(expression);
    s21_add_separator(expression);
  }
}
