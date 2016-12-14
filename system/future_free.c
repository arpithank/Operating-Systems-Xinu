#include <future.h>

syscall future_free(future* f)
{
  freemem(f,sizeof(f));
  f = NULL;
  return 0;
}
