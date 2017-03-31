#include <dlfcn.h>
#include "include/libSDL.hpp"
#include "include/IGFX.hpp"

int main()
{
  void* handle = dlopen("./lib_arcade_sdl.so", RTLD_LAZY);
  if (!handle) {
    std::cerr << "Cannot open library: " << dlerror() << '\n';
    return 1;
  }
  void (*mySDL) = (void *) dlsym(handle, "display");
  test.display();
}
