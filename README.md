# Inheritance and OOP in C++

This project demonstrates the use of Object-Oriented Programming (OOP) principles in C++ through two inheritance-based tasks.

## Task 1: Student and Aspirant

The first task demonstrates inheritance between the `Student` and `Aspirant` classes.

### Student
Stores basic student information:
- Name
- Age
- University
- Speciality

### Aspirant
Inherits from `Student` and adds:
- Research project name
- Supervisor
- Enrollment year
- Dissertation status

Additional functionality:
- `showInfo()` — displays student and aspirant information.
- `workOnResearch()` — demonstrates the aspirant's research activity.

## Task 2: Passport and ForeignPassport

The second task demonstrates inheritance between the `Passport` and `ForeignPassport` classes.

### Passport
Stores basic passport information:
- Full name
- Date of birth
- Passport number
- Nationality
- Date of issue
- Expiry date
- Issuing authority

Includes basic input validation for dates, passport numbers, and issuing authority.

### ForeignPassport
Inherits from `Passport` and adds:
- Foreign passport number
- Visa countries
- Number of visas
- Biometric passport status

Includes validation of the foreign passport number and visa information.

## C++ Concepts Used

- Classes and Objects
- Inheritance
- Encapsulation
- Polymorphism
- Virtual Functions and Method Overriding
- Constructors and Destructors
- Copy Constructors
- Assignment Operator Overloading
- Dynamic Memory Allocation
- Deep Copying
- Rule of Three
- Input Validation
- Dynamic Arrays of C-Strings

## Memory Management

Both tasks use dynamic memory allocation for storing string data.

To manage memory correctly, the classes implement:
- Copy constructors
- Overloaded assignment operators
- Destructors

Deep copying is used to ensure that objects maintain independent copies of dynamically allocated data.

## Purpose

The purpose of this project is to practice inheritance, polymorphism, dynamic memory management, and other fundamental OOP concepts in C++.
