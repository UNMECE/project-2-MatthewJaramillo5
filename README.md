[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/ZLDaAvmS)
# Project 2
This project is due 04/20/2025 by 11:59 PM.  No late submissions will be accepted.  All work must be done on your own.  Discussion is encouraged, but your code must be your own.

# Overview
In this project, you will demonstrate knowledge of object oriented programming.  You are tasked with designing and implementing a base and two derived classes for tracking students in different degree programs.  Make a base class Student and two derived classes called "Art_Student" and "Physics_Student".  Make the base class contain all variables that you believe will be common between the base class and derived classes (e.g. name).  In total, one should have variables for storing 
  - name (first and last)
  - gpa
  - graduation year
  - graduation semester
  - enrolled year
  - enrolled semester
  - undergrad/grad
  
For "Art_Student" keep track of additional information that includes "art_emphasis" that can be one of three values, "Art Studio", "Art History", and "Art Education".  For "Physics_Student" add an additional field of "concentration" that can take on values of, "Biophysics" and "Earth and Planetary Sciences".
  
# Tasks
  - Implement a default constructor that initializes variables to default values that make sense
  - Implement a destructor that deletes any thing allocated
  - Make appropriate Getter and Setter functions
  - Create 5 objects of type "Art_Student" and store them in a std::vector - Use pointers and allocate space
  - Create 5 objects of type "Physics Student" and store them in a different std::vector - Use pointers and allocate space
  - Assign various values for the variables
  - Write the student information you made to a single file by looping over the students in each vector
  
# Some example code
Some of the expected functionality of the program is shown below:

```
int main()
{
  std::vector<Art_Student *> art_students;
  art_students.push_back(new Art_Student);
  art_students[0]->setName("some","name");
  art_students[0]->setGPA("3.9");
  
  .
  .
  outfile = open("student_info.dat",std::ios::write);
  for(int i = 0; i < art_students.size(); i++)
  .
  .
  
  return 0;
}
```

# Grading Scale
 - 30% All features of Base Class Implemented and Working
 - 40% All features of Derived Classes Implemented and Working
 - 20% Output to a file
 - 10% Code produces expected output
  
