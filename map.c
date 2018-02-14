#include "map.h"
#include "types.h"
#include "point.h"

struct _Map
{
  Point * datos[MAXPOINT];
  int nPoints;
  int nCol;
  int nRow;
  Point * input;
  Point * output;
};

Map * map_ini()
{
  Map * map;
  map = (Map *) malloc(sizeof(Map));

  if (!map) return NULL;
  return map;
}

void map_destroy(Map * map)
{
  if (!map) return;

  free(map);
}

int map_getNrows(const Map * map)
{
  if (!map) return -1;

  return map->nRow;
}

int map_getNcols(const Map * map)
{
  if (!map) return -1;

  return map->nCol;
}

Point * map_getInput(const Map * map)
{
  if (!map) return NULL;

  return map->input;
}

Point * map_getOutput(const Map * map)
{
  if (!map) return NULL;

  return map->output;
}

Point * map_getNeighborPoint(const Map * map, const Point * point, const Move move)
{
  int i, x, y, indi_c;

  if (!map) return NULL;

  i =  map_getNcols(map);

  x = point_getCoordinateX(point);
  y = point_getCoordinateY(point);

  indi_c = x * i + y;

  switch (move)
  {
    case UP:
      return map->datos[indi_c-i];
    case DOWN:
      return map->datos[indi_c+i];
    case LEFT:
      return map->datos[indi_c--];
    case RIGHT:
      return map->datos[indi_c++];
    case STAY:
      return map->datos[indi_c];
    default:
      return NULL;
  }
}
