#ifndef CVECTOR_H
#define CVECTOR_H

#include <stdlib.h>

#define CVECTOR(TYPE) \
struct \
{ \
  TYPE *data; \
  unsigned int size; \
  unsigned int max_size;\
}

#define CVECTOR_AT(VEC, INDEX) VEC.data[INDEX]

#define CVECTOR_BACK(VEC) VEC.data[VEC.size - 1]

#define CVECTOR_CLEAR(VEC) \
{ \
  VEC.size = 0; \
  VEC.max_size = 0; \
  free(VEC.data); \
}

#define CVECTOR_DATA(VEC) VEC.data;

#define CVECTOR_EMPTY(VEC) VEC.size == 0

#define CVECTOR_FRONT(VEC) VEC.data[0];

#define CVECTOR_INIT(VEC, CAP) \
{ \
  VEC.data = malloc(CAP * sizeof(*(VEC).data)); \
  VEC.size = 0; \
  VEC.max_size = CAP; \
}

#define CVECTOR_CAPACITY(VEC) VEC.max_size

#define CVECTOR_POPBACK(VEC) --VEC.size

#define CVECTOR_PUSHBACK(VEC, ELEMENT) \
{ \
  if (VEC.size + 1 == VEC.max_size) \
  { \
    VEC.max_size *= 2; \
    VEC.data = realloc(VEC.data, VEC.max_size * sizeof(*(VEC).data)); \
  } \
  VEC.data[VEC.size] = ELEMENT; \
  ++VEC.size; \
}

#define CVECTOR_SIZE(VEC) VEC.size

#define CVECTOR_SWAP(VEC1, VEC2) \
{ \
  void* tmp = VEC1.data; \
  unsigned int tmpSize = VEC1.size; \
  unsigned int tmpMaxSize = VEC1.max_size; \
  VEC1.data = VEC2.data; \
  VEC1.size = VEC2.size; \
  VEC1.max_size = VEC2.max_size; \
  VEC2.data = tmp; \
  VEC2.size = tmpSize; \
  VEC2.max_size = tmpMaxSize; \
}

#endif
