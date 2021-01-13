#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// student structure
//struct Student...
struct Student {
     char firstname[100];
     char lastname[100];
     int age;
};

void printStudent(struct Student* student)
{
  printf("---------Student---------\n");
  printf("First Name: %s\n", student->firstname);
  printf("Last Name: %s\n", student->lastname);
  printf("Age: %d\n", student->age);
}


void printAllStudents(struct Student student[], int num)
{
  // call printStudent for each student in students
  for (int i = 0; i < num; i++)
  {
       printStudent(&student[i]); 
  }

}


int main(int argc, char* argv[])
{

  // an array of students
  struct Student student[100];
 
  char input[256];
  int numStudents = 0;
  char firstInput[100];
  char lastInput[100];
  int ageInput;

  while (1)
  {
    char c;
    printf("\nEnter a to add, p to print, q to quit:");

    fgets(input, 256, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q') 
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(student, numStudents);
      continue;
    }
    else if (c == 'a')
    {
      // enter a new student
      printf("First Name:");
      while (1)
      {
        strcpy(firstInput, fgets(input, 256, stdin));
        break;
      }

      printf("Last Name:");
      while (1)
      {
        strcpy(lastInput, fgets(input, 256, stdin));
        break;
      }

      printf("Age:");
      while (1) 
      {
       fgets(input, 256, stdin);
       if (sscanf(input, "%d", &ageInput) == 1) break;
       printf("Not a valid age - try again\n");
      }

      strcpy(student[numStudents].firstname, firstInput);
      strcpy(student[numStudents].lastname, lastInput);
      student[numStudents].age = ageInput;

      numStudents++;
    }
  }
  
  printf("\nGoodbye!\n");
}
