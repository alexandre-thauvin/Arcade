//
// Created by thauvi_a on 3/20/17.
//

#include <cstdlib>
#include "Snake.h"

char 	**ma2d(char **dest)
{
  int	z = 0;
  if ((dest = (char **)malloc((WIDTH + 1) * sizeof(char*))) == NULL)
    exit(1);
  while (z < WIDTH)
   {
     if ((dest[z] = (char *)malloc((WIDTH + 1) * sizeof(char))) == NULL)
       exit(1);
     z++;
   }
  dest[z] = NULL;
  return (dest);
}
