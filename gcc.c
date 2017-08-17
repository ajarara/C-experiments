#include <stdio.h>


/* Does GCC impliticly include SIZEOF_VOID_P? Why is this a
preprocessor thing and not something that's compile time.  */

/* no inclusion of any standard libs, so I have to evaluate return
code after the run instead of relying on IO */


int main(void) {
  return 8 == SIZEOF_VOID_P;
}
