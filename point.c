#include <stdlib.h>
#include "point.h"

struct _Point
{
  char symbol;
  int x;
  int y;
};

Point * point_ini (int x, int y, char s)
{
  Point * point;

  point = (Point *) calloc(1, sizeof(Point));
  if (!point) return NULL;

  point->x = x;
  point->y = y;
  point->symbol = s;

  return point;
}

int point_getCoordinateX(const Point * p)
{
  if (!p) return -1;

  return p->x;
}

int point_getCoordinateY(const Point * p)
{
  if (!p) return -1;

  return p->y;
}

char point_getSymbol(const Point * p)
{
  if (!p) return -1;

  return p->symbol;
}

Bool point_isInput(Point * p)
{
  if (p->symbol == 'i')
    return TRUE;
  else
    return FALSE;
}

Bool point_isOutput(Point * p)
{
  if (p->symbol == 'o')
    return TRUE;
  else
    return FALSE;
}

Bool point_isBarrier(Point * p)
{
  if (p->symbol == '+')
    return TRUE;
  else
    return FALSE;
}

Bool point_isSpace(Point * p)
{
  if (p->symbol == ' ')
    return TRUE;
  else
    return FALSE;
}

Status point_setCoordinateX(Point * p, const int n)
{
  if (!p)
    return ERROR;

  p->x = n;

  return OK;
}

Status point_setCoordinateY(Point * p, const int n)
{
  if (!p)
    return ERROR;

  p->y = n;

  return OK;
}

Status point_setSymbol(Point * p, const char n)
{
  if (!p)
    return ERROR;

  p->symbol = n;

  return OK;
}

Bool point_equals(const Point *p1, const Point *p2)
{
  if((p1->x == p2->x) && (p1->y == p2->y) && (p1->symbol == p2->symbol))
    return TRUE;
  else
    return FALSE;
}

Point * point_copy(const Point * p)
{
  if(!p)
    return NULL;

  return point_ini(p->x, p->y, p->symbol);
}

void point_destroy(Point * p)
{
  if(!p)
  {
    return;
  }

  free(p);
}

int point_print(FILE * f, const Point * p)
{
  return fprintf(f, "[(%d,%d):%c]", p->x, p->y, p->symbol);
}
