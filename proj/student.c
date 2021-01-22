//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"


const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};


void createStudent(char* fname, char* lname, int age, int id)
{
  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  //    based on the size of the fname and lname args
  Student* newStudent= (Student*)malloc(sizeof(Student));

  students[numStudents] = newStudent;
  students[numStudents]->firstName = (char*)malloc(sizeof(fname)); 
  students[numStudents]->lastName = (char*)malloc(sizeof(fname)); 
  
  strcpy(students[numStudents]->firstName, fname);
  strcpy(students[numStudents]->lastName, lname);
  students[numStudents]->age = age;
  students[numStudents]->id = id;

  numStudents++;
}


void deleteStudent(Student* student)
{
  // free the memory associated with a student including the strings
  free(student->lastName);
  free(student->firstName);
  free(student);

}


void deleteStudents()
{
  // iterate over the students array deleting every student and setting te pointer
  // values to 0 and adjusting the numStudents to 0
   for (int i = 0; i < numStudents; i++)
  {
      deleteStudent(students[i]);
      students[i] = 0;
  }
  numStudents = 0;


}


void saveStudents(int key)
{
  // save all students in the student array to a file 'studentdata.txt' overwriting
  // any existing file
  //   - the format of the file is one line per student as follows fname lname age id:
  //       tom thumb 15 1234 
  //       james dean 21 2345 
  //       katy jones 18 4532
  // the best way to do this is to convert the student data to a string using sprintf and then
  // (optionally) encrypt the whole string before writing it to disk (see cdemo/fileio3.c)
   FILE* fp;

  char stringAge[100];
  char stringID[100];

  fp = fopen("studentdata.txt", "w");
  if (fp)
  {
      for (int i = 0; i < numStudents; i++)
      {
          sprintf(stringAge, "%d", students[i]->age);
          sprintf(stringID, "%ld", students[i]->id);

          if (key != 0 )
          {
              caesarEncrypt(students[i]->firstName, key);
              caesarEncrypt(students[i]->lastName, key);
              caesarEncrypt(stringAge, key);
              caesarEncrypt(stringID, key);
          }
          fprintf(fp, "%s %s %s %s\n", students[i]->firstName, students[i]->lastName, stringAge, stringID); 

          printf("saving: %s %s %s %s\n", students[i]->firstName, students[i]->lastName, stringAge, stringID);
      }
      fclose(fp);
  }

  printf("saved %d students\n", numStudents);
}


void loadStudents(int key)
{
  // load the students from the data file overwriting all exisiting students in memory
  //  - make sure you first deleteStudents before loading new ones
  //  - when loading it is best to load data into four strings and then (optionally) decrypt the
  //    strings
  //  - call createStudent to correctly create the students
  deleteStudents();

  FILE* fp;


  fp = fopen("studentdata.txt", "r");

  int loadNumber = 0;

  if (fp)
  {
      while (1)
      {
           int id;
           int age;
           char stringAge[256];
           char stringID[256];
           char firstname[256]; 
           char lastname[256];

           if (fscanf(fp, "%s %s %s %s\n", firstname, lastname, stringAge, stringID) == 4) 
           {
               if (key != 0 )
               {
                   caesarDecrypt(firstname, key);
                   caesarDecrypt(lastname, key);
                   caesarDecrypt(stringAge, key);
                   caesarDecrypt(stringID, key);
               }

               sscanf(stringAge, "%d", &age);
               sscanf(stringID, "%d", &id);

               createStudent(firstname, lastname, age, id);
               loadNumber++;
           }
           else
           {
              break;
           }
      }
      fclose(fp);

      printf("loaded %d students\n", loadNumber);
  }
}


void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id); 
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}




