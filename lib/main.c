
#include <dlfcn.h>

int main()
{
  void *handle = dlopen("./lib.so", RTLD_NOW);

  if (handle)
    {
      void(*p)() = dlsym(handle, "entry_point");
      p();
      dlclose(handle);
    }
}
