#include <stdio.h>
#include <string.h>

int main()
{
  //creating two strings
  char str1[27];
  char str2[] = "abcdefghijklmnopqrstuvwxyz";
  
  for(int i = 0; i < 26; i++)
  {
      str1[i] = 'a' + i;
  }
  str1[26] = '\0';

  //comparing strings
  if (strcmp(str1, str2) == 0) 
      printf("the first and second string are identical\n");
  else 
      printf("the first and second string are different\n"); 

  //updating first string
  for(int i = 0; i < 26; i++)
  {
      str1[i] = str1[i] - 32;
  }
  str1[26] = '\0';

  //comparing strings
  if (strcmp(str1, str2) == 0) 
      printf("the updated first and second string are identical\n");
  else 
      printf("the updated first and second string are different\n");
  

  //printing strings
  printf("updated first string: %s\n", str1);
  printf("second string: %s\n", str2);

  //joining both strings together
  printf("combined: %s\n", strcat(str1, str2)); 
}
