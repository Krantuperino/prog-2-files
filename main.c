#include "point.h"

int main()
{
  Point *p1, *p2;
  int x, y;
  char c;

  x = 1;
  y = 2;
  c = '+';

  p1 = point_ini(x, y, c);

  x = 3;
  y = 4;
  c = 'o';

  p2 = point_ini(x, y, c);

  point_print(stdout, p1);
  point_print(stdout, p2);
  printf("\n");

  printf("Son iguales?");
  if(point_equals(p1, p2))
    printf("Si\n");
  else
    printf("No\n");

  c = point_getSymbol(p1);
  printf("El símbolo del primer punto es: %c\n", c);

  x = point_getCoordinateX(p2);
  printf("La coordenada x del segundo punto es: %d\n", x);

  point_destroy(p2);

  p2 = point_copy(p1);

  point_print(stdout, p1);
  point_print(stdout, p2);
  printf("\n");

  printf("Son iguales?");
  if(point_equals(p1, p2))
    printf("Si\n");
  else
    printf("No\n");

  point_destroy(p1);
  point_destroy(p2);
  return 0;
}
