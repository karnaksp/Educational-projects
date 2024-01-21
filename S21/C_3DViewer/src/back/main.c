#include "s21_3dparser.h"

int main() {
  Shape cube;
  if (s21_initShape(&cube, "./obj/tetrahedron.obj")) {
    fprintf(stderr, "Error initializing the cube.\n");
    return 1;  // В случае ошибки завершаем программу
  }

  // Выводим параметры куба
  printf("Cube parameters:\n");

  double angle_x = 45.0;
  double angle_y = 45.0;
  double angle_z = 45.0;
  figure_rotation(&cube, angle_x, angle_y, angle_z);

  // Выводим параметры куба после поворота
  printf("\nRotation 45:\n");
  // Освобождаем ресурсы
  s21_clearShape(&cube);

  return 0;
}
