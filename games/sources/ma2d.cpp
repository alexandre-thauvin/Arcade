//
// Created by thauvi_a on 3/20/17.
//

#include <cstdlib>
#include "Snake.h"

int 	**ma2d(int **dest)
{
  int	z = 0;
  if ((dest = (int **)malloc((WIDTH + 1) * sizeof(int*))) == NULL)
    exit(1);
  while (z < WIDTH)
   {
     if ((dest[z] = (int *)malloc((WIDTH + 1) * sizeof(int))) == NULL)
       exit(1);
     z++;
   }
  dest[z] = NULL;
  return (dest);
}
