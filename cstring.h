#ifndef CSTRING_H
#define CSTRING_H

#include <stdlib.h>
#include <string.h>

typedef struct CSTRING
{
  unsigned int _length;
  char* _data;
} CSTRING;

const char* CSTRING_DATA(const CSTRING* const CS)
{
  return CS->_data;
}

void CSTRING_DELETE(CSTRING* const CS)
{
  CS->_length = 0;
  free(CS->_data);
  CS->_data = NULL;
}

void CSTRING_INIT(CSTRING* const CS, const char* TEXT)
{
  char* tmp = NULL;
  CS->_length = strlen(TEXT);
  tmp = malloc(sizeof(char) * (CS->_length + 1));
  if (tmp)
  {
    CS->_data = tmp;
    memcpy(CS->_data, TEXT, CS->_length + 1);
  }
}

unsigned int CSTRING_SIZE(const CSTRING* const CS)
{
  return CS->_length;
}

void CSTRING_SWAP(CSTRING* const CS1, CSTRING* const CS2)
{
  CSTRING tmp;
  tmp._length = CS1->_length;
  tmp._data = CS1->_data;
  CS1->_length = CS2->_length;
  CS1->_data = CS2->_data;
  CS2->_length = tmp._length;
  CS2->_data = tmp._data;
}

#endif
