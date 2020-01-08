## Scalper (CHelper)
--------------------
### What is it about?
- A personal project that I wrote to make the lives of C programmers easier.
- Mostly will be about rewriting C++ STL containers into ANSI C.
- This is still C, so it is still not safe, definitely not for beginners.
- Conversion is not going to be perfect, but I will strive to achieve it as close as possible.
- Will be adding comments ASAP.

### Donation 
- [![Donate](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://www.paypal.com/paypalme2/LamWeiLun/1)
- Send me a cup of coffee, deeply appreciate it. Shall turn caffeine into more code!

### Basic Usage
#### CVector
```C
#include "scalper.h"

int main()
{
  /* Creates an integer vector of max size 3 */
  CVECTOR(int) int_vector;
  CVECTOR_INIT(int_vector, 3);
  
  /* Pushes 5 into the vector, then removing it */
  CVECTOR_PUSHBACK(int_vector, 5);
  CVECTOR_POPBACK(int_vector);
  
  /* Deallocates the vector, call CVECTOR_INIT to use this vector again */
  CVECTOR_CLEAR(int_vector);
  
  return 0;
}
```
