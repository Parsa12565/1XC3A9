/**
 * @file student.c
 * @author Unknown
 * @date April 6th, 2021.
 * @brief Function definitions for the student type.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

/**
 * Adds a grade to a student's grades
 * 
 * @param student the student who will have the grade
 * @param grade the grade to be added to the student's list of grades
 * 
 */
void add_grade(Student* student, double grade)
{
  student->num_grades++;
  if (student->num_grades == 1) student->grades = calloc(1, sizeof(double));//checks if the list of grades is empty (since it just added 1) and if so puts an empty array with 1 space at grades
  else 
  {
    student->grades = 
      realloc(student->grades, sizeof(double) * student->num_grades);//adds 1 more space to the array of grades
  }
  student->grades[student->num_grades - 1] = grade;
}

/**
 * Calculates and returns a student's grade average
 * 
 * @param student the student whose average will be calculated
 * @return the student's average
 * 
 */
double average(Student* student)
{
  if (student->num_grades == 0) return 0;//checks if there are no grades and returns 0 if so

  double total = 0;
  for (int i = 0; i < student->num_grades; i++) total += student->grades[i];//adds up all of the student's grades
  return total / ((double) student->num_grades);
}

/**
 * Prints the full name, the ID, the grades, and the average of a student
 * 
 * @param student the student whose information will be printed
 * 
 */
void print_student(Student* student)
{
  printf("Name: %s %s\n", student->first_name, student->last_name);
  printf("ID: %s\n", student->id);
  printf("Grades: ");
  for (int i = 0; i < student->num_grades; i++) //prints every grade of the student
    printf("%.2f ", student->grades[i]);
  printf("\n");
  printf("Average: %.2f\n\n", average(student));
}

/**
 * Creates a new student with a randomly generated name, ID, and grades
 * 
 * @param grades the number of grades the new student will have
 * @return a pointer to the generated student
 * 
 */
Student* generate_random_student(int grades)
{
  char first_names[][24] = 
    {"Shahrzad", "Leonti", "Alexa", "Ricardo", "Clara", "Berinhard", "Denzel",
     "Ali", "Nora", "Malcolm", "Muhammad", "Madhu", "Jaiden", "Helena", "Diana",
     "Julie", "Omar", "Yousef",  "Amir", "Wang", "Li", "Zhang", "Fen", "Lin"};

  char last_names[][24] = 
   {"Chen", "Yang", "Zhao", "Huang", "Brown", "Black", "Smith", "Williams", 
    "Jones", "Miller", "Johnson", "Davis", "Abbas", "Ali", "Bakir", "Ismat", 
    "Khalid", "Wahed", "Taleb", "Hafeez", "Hadid", "Lopez", "Gonzalez", "Moore"};
 
  Student *new_student = calloc(1, sizeof(Student));//allocates space for a new student type

  strcpy(new_student->first_name, first_names[rand() % 24]);
  strcpy(new_student->last_name, last_names[rand() % 24]);

  for (int i = 0; i < 10; i++) new_student->id[i] = (char) ((rand() % 10) + 48);//creats a random 10 character ID for the student
  new_student->id[10] = '\0';

  for (int i = 0; i < grades; i++) //creates (grades) random grades for the student
  {
    add_grade(new_student, (double) (25 + (rand() % 75)));
  }

  return new_student;
}