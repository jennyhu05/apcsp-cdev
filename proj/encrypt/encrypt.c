//
// encrypt.c
//

#include <string.h>

#include "encrypt.h"


char CHARS[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int CHARS_LEN = 62;


char shiftChar(char c, int shift, int direction)
{
  // implement the character shift here:
  //  given a char c shift it either forwards (direction == 1) or backwards (direction == 0)
  //  use the CHARS array above
  //  return the newly shifted char
  //
  // eg.
  //   shiftChar('c', 3, 1) : 'f'
  //   shiftChar('S', 2, 0) : 'P'
  //   shiftChar('b', 3, 0) : '8'
  int index;
  char shiftC;
  int newIndex; 

  //number 
  if (c < 58)
  {
      index = c + 4;
  }
  //upper case
  else if (c < 91 && c > 64)
  {
      index = c - 39;
  }
  //lower case
  else if (c > 96)
  {
       index = c - 97;
  }


  if (direction == 1)
  {
      newIndex = index + shift;

      if (newIndex > 61)
      {
          newIndex = newIndex - 62;
      }

      shiftC = CHARS[newIndex];
     
      return shiftC;
  } 
  else if (direction == 0)
  {
      newIndex = index - shift;

      if (newIndex < 0)
      {
          newIndex = newIndex + 62;
      }

      shiftC = CHARS[newIndex];

      return shiftC;
  }

}


void encrypt(char str[], int shifts[], int shiftslen)
{
  for (int i = 0; i < strlen(str); i++) 
  {
    char c = str[i];

    str[i] = shiftChar(c, shifts[i%shiftslen], 1);
  }
}


void decrypt(char str[], int shifts[], int shiftslen)
{
  for (int i = 0; i < strlen(str); i++) 
  {
    char c = str[i];

    str[i] = shiftChar(c, shifts[i%shiftslen], 0);
  }
}


void caesarEncrypt(char str[], int shift)
{
  int shifts[] = { shift };
  encrypt(str, shifts, 1);
}


void caesarDecrypt(char str[], int shift)
{
  int shifts[] = { shift };
  decrypt(str, shifts, 1);
}


