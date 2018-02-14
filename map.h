#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "point.h"

#define MAXPOINT 4096

/* Movimientos posibles en un mapa*/
typedef enum
{
  RIGHT=0,
  UP=1,
  LEFT=2,
  DOWN=3,
  STAY=4
} Move;

typedef struct _Map Map;
/* Inicializa un
mapa, reservando memoria y devolviendo el mapa
inicializado si lo ha hecho correctamente o NULL
si no */
Map* map_ini();
/* Libera la memoria dinámica reservada para un
mapa */
void map_destroy(Map* );
/* Devuelve el número de filas de un
mapa dado, o -1 si se
produce algún error */
int map_getNrows(const Map* );
/* Devuelve el número de columnas de un
mapa dado, o -1 si se produce algún error */
int map_getNcols(const Map* );
/* Devuelve el punto de entrada en un
mapa dado, o NULL si se produce algún error
o no existe un punto de ese tipo */
Point * map_getInput(const Map* );
/* Devuelve el punto de salida en un
mapa dado, o NULL si se produce algún error
o no existe un punto de ese tipo */
Point * map_getOutput(const Map* );
/* Devuelve el punto resultante al realizar un movimiento en un
mapa a partir de un punto inicial, o NULL si se
produce algún error */
Point * map_getNeighborPoint(const Map*, const Point *, const Move mov);
/* Indica el tamaño de un mapa, devuelve NULL si se produce algún error */
Status map_setSize(Map* , int nrow, int ncol);
/* Añade un punto a un mapa dado reservando nueva memoria
(de ahí que el argumento sea declarado como const),
o modifica el punto si ya se encuentra. Debe comprobar si el punto es de tipo
Output o Input para guardarlo como corresponda.
Devuelve OK si todo ha ido correctamente
(se ha podido incluir/actualizar el punto).
*/
Status map_setPoint(Map* , const Point* );
/* Imprime en un fichero dado los datos de un mapa. Además,
devolverá el número de caracteres que se han
escrito con éxito (mirar documentación de fprintf) */
int map_print(FILE *, const Map* );
#endif
