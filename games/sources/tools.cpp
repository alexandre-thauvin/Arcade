//
// Created by thauvi_a on 3/20/17.
//

#include <cstdlib>
#include <iostream>
#include "tools.h"



int 	*find_tale(int value, int tab[WIDTH][WIDTH])
{
  int 	i = 0;
  int 	j = 0;
  int 	*tabi;

  tabi = (int*)malloc(2 * sizeof(int));
  std::cout << "je suis value : " << value << std::endl;
  //print_map()
  for (i = 0 ; i < WIDTH - 1 ; i++) {
    for (j = 0; j < WIDTH - 1; j++)
    {
      if (tab[i][j] == value) {
	tabi[0] = i;
	tabi[1] = j;
	return (tabi);
      }
    }
  }
  return (tabi);
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
