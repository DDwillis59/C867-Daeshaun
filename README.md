# Student Roster Management System

## Overview
This project is a command-line application written in C++ for managing a roster of students in a course. It demonstrates object-oriented programming concepts and includes features for parsing, managing, and displaying student data.

## Features
- **Display Course Information**: Outputs course name, programming language used, and author details.
- **Manage Student Data**: Handles student details such as ID, name, email, age, days in course, and degree program.
- **Validate Emails**: Detects and prints invalid email addresses.
- **Calculate Course Averages**: Computes and displays the average days spent in courses by each student.
- **Filter by Degree Program**: Filter and print students based on their degree program.
- **Remove Students**: Removes a student from the roster by their ID.

## Requirements
- A C++ compiler supporting C++11 or higher.

## Usage
1. Clone the repository.
2. Compile the program using your preferred C++ compiler:
   ```bash
   g++ -o roster main.cpp roster.cpp student.cpp

