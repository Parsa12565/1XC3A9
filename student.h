/**
 * @file student.h
 * @author Unknown
 * @date April 6th, 2021.
 * @brief Function declarations for the student type.
 * 
 */

/**
 * Student
 * 
 */ 
typedef struct _student 
{ 
  char first_name[50];/**< First name of the student */
  char last_name[50];/**< Last name of the student */
  char id[11];/**< ID of the student */
  double *grades; /**< An array of the different grades that the student has */
  int num_grades;/**< Number of different grades that the student has */
} Student;

void add_grade(Student *student, double grade);
double average(Student *student);
void print_student(Student *student);
Student* generate_random_student(int grades); 
