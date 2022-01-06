/**
 * @mainpage Creating courses with students demonstration.
 *  
 * 
 * 
 * @file main.c
 * @author Unknown
 * @date April 6th, 2021.
 * @brief Runs demonstration code for creating courses with students.
 * 
 */ 
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "time.h"
#include "course.h"

/**
 * Runs the demonstration code for creating courses with students.
 * 
 * Runs functions for generating students, enrolling students in courses, printing courses, and searching for students within courses based on grade
 * 
 * @return 0
 * 
 */ 
int main()
{
  srand((unsigned) time(NULL));

  Course *MATH101 = calloc(1, sizeof(Course));
  strcpy(MATH101->name, "Basics of Mathematics");
  strcpy(MATH101->code, "MATH 101");

  for (int i = 0; i < 20; i++) //enrolls 20 random students each with 8 different grades into MATH101
    enroll_student(MATH101, generate_random_student(8));
  
  print_course(MATH101);

  Student *student;
  student = top_student(MATH101);
  printf("\n\nTop student: \n\n");
  print_student(student);

  int total_passing;
  Student *passing_students = passing(MATH101, &total_passing);
  printf("\nTotal passing: %d\n", total_passing);
  printf("\nPassing students:\n\n");
  for (int i = 0; i < total_passing; i++) print_student(&passing_students[i]);//prints the information of every passing student
  
  return 0;
}