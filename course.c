/**
 * @file course.c
 * @author Unknown
 * @date April 6th, 2021.
 * @brief Function definitions for the course type.
 * 
 */
#include "course.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Adds a student to a course's list of enrolled students
 * 
 * @param course the course to which the student will be added
 * @param student the student who will be added to the course
 * 
 */
void enroll_student(Course *course, Student *student)
{
  course->total_students++;
  if (course->total_students == 1) //checks if the list of students is empty (since it just added 1)
  {
    course->students = calloc(1, sizeof(Student));//puts an empty array with 1 space at students
  }
  else 
  {
    course->students = 
      realloc(course->students, course->total_students * sizeof(Student)); //adds 1 more space to the array of students
  }
  course->students[course->total_students - 1] = *student;
}

/**
 * Prints the name, code, number of total students, and list of students of a course
 * 
 * @param course the course whose information will be printed
 * 
 */
void print_course(Course* course)
{
  printf("Name: %s\n", course->name);
  printf("Code: %s\n", course->code);
  printf("Total students: %d\n\n", course->total_students);
  printf("****************************************\n\n");
  for (int i = 0; i < course->total_students; i++) //calls the function print_student for every student
    print_student(&course->students[i]);
}

/**
 * Finds and returns the student with the highest average within the students enrolled in a course
 * 
 * @param course the course in which the student with the highest average is found
 * @return a points to the student with the highest average in the course
 * 
 */
Student* top_student(Course* course)
{
  if (course->total_students == 0) return NULL;//checks if there are no students and returns NULL if so
 
  double student_average = 0;
  double max_average = average(&course->students[0]);
  Student *student = &course->students[0];
 
  for (int i = 1; i < course->total_students; i++)//loops through for every student in the list of students in the course and calculates their average
  {
    student_average = average(&course->students[i]);
    if (student_average > max_average) //checks if the student at students[i] has a greater average than the average being stored
    {
      max_average = student_average;
      student = &course->students[i];
    }   
  }

  return student;
}

/**
 * Creates and returns a list of students with a passing average (an average equal to or above 50)
 * 
 * @param course the course in which the passing students will be found
 * @param total_passing a pointer to the number of students passing the course
 * @return an array of students who have passed the course
 * 
 */
Student *passing(Course* course, int *total_passing)
{
  int count = 0;
  Student *passing = NULL;
  
  for (int i = 0; i < course->total_students; i++) //loops through for every student in the list of students in the course
    if (average(&course->students[i]) >= 50) count++;//checks if the student at students[i] passes and if so increases count by 1
  
  passing = calloc(count, sizeof(Student));

  int j = 0;
  for (int i = 0; i < course->total_students; i++)//loops through for every student in the list of students in the course
  {
    if (average(&course->students[i]) >= 50)//checks if the student at students[i] passes and if so adds them to the array passing
    {
      passing[j] = course->students[i];
      j++; 
    }
  }

  *total_passing = count;

  return passing;
}