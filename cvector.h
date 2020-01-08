#ifndef CVECTOR_H
#define CVECTOR_H

#include <stdlib.h>

#define CVECTOR(TYPE) \
struct \
{ \
  TYPE* _data; \
  unsigned int _size; \
  unsigned int _capacity;\
}

#define CVECTOR_AT(VEC, INDEX) VEC._data[INDEX]

#define CVECTOR_BACK(VEC) VEC._data[VEC._size - 1]

#define CVECTOR_CLEAR(VEC) \
{ \
  VEC._size = 0; \
  VEC._capacity = 0; \
  free(VEC._data); \
}

#define CVECTOR__data(VEC) VEC._data;

#define CVECTOR_EMPTY(VEC) VEC._size == 0

#define CVECTOR_FRONT(VEC) VEC._data[0]

#define CVECTOR_INIT(VEC, CAP) \
{ \
  VEC._data = malloc(CAP * sizeof(*(VEC)._data)); \
  VEC._size = 0; \
  VEC._capacity = CAP; \
}

#define CVECTOR_CAPACITY(VEC) VEC.max__size

#define CVECTOR_EMPTY(VEC) VEC._size == 0

#define CVECTOR_POPBACK(VEC) --VEC._size

#define CVECTOR_PUSHBACK(VEC, ELEMENT) \
{ \
  if (VEC._size + 1 == VEC._capacity) \
  { \
    VEC._capacity *= 2; \
    VEC._data = realloc(VEC._data, VEC._capacity * sizeof(*(VEC)._data)); \
  } \
  VEC._data[VEC._size] = ELEMENT; \
  ++VEC._size; \
}

#define CVECTOR__size(VEC) VEC._size

#define CVECTOR_SWAP(VEC1, VEC2) \
{ \
  void* tmp = VEC1._data; \
  unsigned int tmp_size = VEC1._size; \
  unsigned int tmpMax_size = VEC1._capacity; \
  VEC1._data = VEC2._data; \
  VEC1._size = VEC2._size; \
  VEC1._capacity = VEC2._capacity; \
  VEC2._data = tmp; \
  VEC2._size = tmp_size; \
  VEC2._capacity = tmpMax_size; \
}

#endif
