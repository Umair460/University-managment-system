University Management System
Overview
The University Management System is a console-based application designed to manage student and teacher records. It provides functionalities for adding, searching, updating, and deleting records for both students and teachers, with file-based storage for persistence.

Features
Add Student: Add new student records with details such as roll number, name, subject, and address.
Search Student: Retrieve student records by roll number.
Update Student: Modify existing student records.
Delete Student: Remove student records from the system.
Show All Students: Display all student records.
Add Teacher: Add new teacher records with details like name, qualification, phone number, and address.
Update Teacher: Modify existing teacher records.
Delete Teacher: Remove teacher records from the system.
Show All Teachers: Display all teacher records.
File Structure
record.txt: Stores student records.
teachers.txt: Stores teacher records.
main.cpp: Contains the main application code and logic.
Usage
Compile the main.cpp file using a C++ compiler to generate the executable. The executable accepts the following actions:

1: Add a student (requires roll number, name, subject, and address)
2: Search for a student by roll number
3: Update a student record
4: Delete a student record
5: Show all student records
6: Add a teacher (requires name, qualification, phone number, and address)
7: Update a teacher record
8: Delete a teacher record
9: Show all teacher records
Example Commands
Add Student: ./test.exe 1 101 John Math "123 Elm St"
Search Student: ./test.exe 2 101
Update Student: ./test.exe 3 101 "John Doe" "Math" "456 Oak St"
Delete Student: ./test.exe 4 101
Show All Students: ./test.exe 5
Add Teacher: ./test.exe 6 "Dr. Smith" "PhD" "555-1234" "789 Pine St"
Update Teacher: ./test.exe 7 "Dr. Smith" "DSc" "555-5678" "123 Maple St"
Delete Teacher: ./test.exe 8 "Dr. Smith"
Show All Teachers: ./test.exe 9
Compilation
To compile the C++ code, use the following command (adjust paths as necessary):

sh
Copy code
g++ -o test.exe main.cpp
License
This project is licensed under the MIT License.
