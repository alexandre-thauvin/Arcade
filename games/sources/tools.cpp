//
// Created by thauvi_a on 3/20/17.
//

#include <cstdlib>
#include "tools.h"

int 	*find_tale(int value, int tab[WIDTH][WIDTH])
{
  int 	i = 0;
  int 	j = 0;
  int 	tabi[2];

  for (i = 0 ; i < WIDTH ; i++) {
    for (j = 0; j < WIDTH ; j++)
    {
      if (tab[i][j] == value) {
	tabi[0] = i;
	tabi[1] = j;
	return (tabi);
      }
      j++;
    }
  }
}

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
