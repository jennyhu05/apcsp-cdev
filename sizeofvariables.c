#include<stdio.h>

int main()
{
  int a = 545;
  char b = 'x';
  float c = 3.14;
  double d = 3.1415;
  unsigned int e = 10;
  signed int f = 5;

  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));
  printf("char b value: %c and size: %lu bytes\n", b, sizeof(b));
  printf("float c value: %f and size: %lu bytes\n", c, sizeof(c));
  printf("double d value: %f and size: %lu bytes\n", d, sizeof(d));
  printf("unsigned int e value: %d and size: %lu bytes\n", e, sizeof(e));
  printf("signed int f value: %d and size: %lu bytes\n", f, sizeof(f));
}

