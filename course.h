/**
 * @file course.h
 * @author Unknown
 * @date April 6th, 2021.
 * @brief Function declarations for the course type.
 * 
 */
#include "student.h"
#include <stdbool.h>

/**
 * Course
 * 
 */ 
typedef struct _course 
{
  char name[100];/**< Name of the course */
  char code[10];/**< The course's code */
  Student *students;/**< The students enrolled in the course */
  int total_students;/**< The total number of students enrolled in the course */
} Course;

void enroll_student(Course *course, Student *student);
void print_course(Course *course);
Student *top_student(Course* course);
Student *passing(Course* course, int *total_passing);


