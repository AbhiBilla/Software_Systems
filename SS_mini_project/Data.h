#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ADMIN_FILE "admins.dat"
#define STUDENT_FILE "students.dat"
#define FACULTY_FILE "faculty.dat"
#define COURSE_FILE "courses.dat"

typedef struct Admin {
    // Add course details (e.g., ID, name, seats)
    int id;
    char[100] a_name;
    char[100] a_password;
    Student* student;
    Faculty* Faculty;
} Admin;


// Define data structures to hold student, faculty, and course information
typedef struct Student {
    // Add student details (e.g., ID, name, courses)
    int id;
    char[100] s_name;
    char[100] s_password;
    Faculty* faculty;
    Course* course;
} Student;


typedef struct Faculty {
    // Add faculty details (e.g., ID, name, courses)
    int id;
    char[100] f_name;
    char[100] f_password;
    Student* student;
    Course* course;
} Faculty;


typedef struct Course {
    // Add course details (e.g., ID, name, seats)
    int id;
    char[100] c_name;
} Course;
