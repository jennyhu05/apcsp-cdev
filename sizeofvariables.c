#include<stdio.h>

int main()
{
  int a = 545;
  char b = 'x';
  float c = 3.14;
  double d = 3.1415;
  short int e = 10;
  long int f = 100;

  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));
  printf("char b value: %c and size: %lu bytes\n", b, sizeof(b));
  printf("float c value: %f and size: %lu bytes\n", c, sizeof(c));
  printf("double d value: %f and size: %lu bytes\n", d, sizeof(d));
  printf("short int e value: %d and size: %lu bytes\n", e, sizeof(e));
  printf("long int f value: %d and size: %lu bytes\n", f, sizeof(f));
}

