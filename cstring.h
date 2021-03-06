#ifndef CSTRING_H
#define CSTRING_H

 /* a string of length < 15, is considered as a small string in this case */
#define SMALL_STR_SIZE 15
#define EMPTY_STR ""

#include <stdlib.h>
#include <string.h>

typedef struct CSTRING
{
  unsigned int _length;
  char* _data;
  char _small_data[SMALL_STR_SIZE];
} CSTRING;

const char* CSTRING_DATA(const CSTRING* const CS)
{
  if (CS->_data)
  {
    return CS->_data;
  }
  else
  {
    return CS->_small_data;
  }
}

void CSTRING_DELETE(CSTRING* const CS)
{
  /* in case _small_string is under use, no need to call free */
  if (CS->_data)
  {
    free(CS->_data);
    CS->_data = NULL;
  }
  CS->_length = 0;
}

void CSTRING_INIT(CSTRING* const CS, const char* TEXT)
{
  CS->_length = strlen(TEXT);
  /* stores the string in _small_data array */
  if (CS->_length < SMALL_STR_SIZE)
  {
    strcpy(CS->_small_data, TEXT);
    CS->_data = NULL;
  }
  else
  {
    char* tmp = (char*)malloc(sizeof(char) * (CS->_length + 1));
    if (tmp)
    {
      CS->_data = tmp;
      memcpy(CS->_data, TEXT, CS->_length + 1);
      strcpy(CS->_small_data, EMPTY_STR); 
    }
  }
}

unsigned int CSTRING_SIZE(const CSTRING* const CS)
{
  return CS->_length;
}

/*
  GET and SET methods for last character in the string
*/
char CSTRING_GET_BACK(const CSTRING* const CS)
{
  if (CS->_data)
  {
    return CS->_data[CS->_length - 1];
  }
  else
  {
    return CS->_small_data[CS->_length - 1];
  }
}

void CSTRING_SET_BACK(CSTRING* CS, char C)
{
  if (CS->_data)
  {
    CS->_data[CS->_length - 1] = C;
  }
  else
  {
    CS->_small_data[CS->_length - 1] = C;
  }
}

/*
  GET and SET methods for first character in the string
*/
char CSTRING_GET_FRONT(const CSTRING* const CS)
{
  if (CS->_data)
  {
    return CS->_data[0];
  }
  else
  {
    return CS->_small_data[0];
  }
}

void CSTRING_SET_FRONT(CSTRING* CS, char C)
{
  if (CS->_data)
  {
    CS->_data[0] = C;
  }
  else
  {
    CS->_small_data[0] = C;
  }
}

/* Access elements by index */
char CSTRING_GET_AT(const CSTRING* const CS, unsigned int INDEX)
{
  if (CS->_data)
  {
    return CS->_data[INDEX];
  }
  else
  {
    return CS->_small_data[INDEX];
  }
}

void CSTRING_SET_AT(CSTRING* CS, unsigned int INDEX, char C)
{
  if (CS->_data)
  {
    CS->_data[INDEX] = C;
  }
  else
  {
    CS->_small_data[INDEX] = C;
  }
}

void CSTRING_SWAP(CSTRING* const CS1, CSTRING* const CS2)
{
  /* using the updated syntax for struct */
  CSTRING tmp;
  tmp._data = CS1->_data;
  tmp._length = CS1->_length;
  strcpy(tmp._small_data, CS1->_small_data);

  CS1->_length = CS2->_length;
  CS1->_data = CS2->_data;
  strcpy(CS1->_small_data, CS2->_small_data);

  CS2->_length = tmp._length;
  CS2->_data = tmp._data;
  strcpy(CS2->_small_data, tmp._small_data);
}

#endif
