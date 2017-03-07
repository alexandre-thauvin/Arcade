#include <stdio.h>
__attribute__((constructor))
void constructor()
{
  printf("cons\n");
}

__attribute__((destructor))
void destructor()
{
  printf("dest\n");
}

void entry_point()
{
  printf("entry\n");
}
