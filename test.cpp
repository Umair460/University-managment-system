#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;

class University {
private:
    string RollNo, Name, Subject, Address;
public:
    University() : RollNo(""), Name(""), Subject(""), Address("") {}

    void setRollNo(string rollNo) { RollNo = rollNo; }
    void setName(string name) { Name = name; }
    void setSubject(string subject) { Subject = subject; }
    void setAddress(string address) { Address = address; }

    string getRollNo() const { return RollNo; }
    string getName() const { return Name; }
    string getSubject() const { return Subject; }
    string getAddress() const { return Address; }

    void fromString(const string& line) {
        stringstream ss(line);
        getline(ss, RollNo, ':');
        getline(ss, Name, ':');
        getline(ss, Subject, ':');
        getline(ss, Address);
    }

    string toString() const {
        return RollNo + " : " + Name + " : " + Subject + " : " + Address;
    }
};

class Teacher {
private:
    string Name;
    string Qualification;
    string PhoneNumber;
    string Address;
public:
    Teacher() : Name(""), Qualification(""), PhoneNumber(""), Address("") {}

    void setName(const string& name) { Name = name; }
    void setQualification(const string& qualification) { Qualification = qualification; }
    void setPhoneNumber(const string& phoneNumber) { PhoneNumber = phoneNumber; }
    void setAddress(const string& address) { Address = address; }

    string getName() const { return Name; }
    string getQualification() const { return Qualification; }
    string getPhoneNumber() const { return PhoneNumber; }
    string getAddress() const { return Address; }

    void fromString(const string& line) {
        stringstream ss(line);
        getline(ss, Name, ':');
        getline(ss, Qualification, ':');
        getline(ss, PhoneNumber, ':');
        getline(ss, Address);
    }

    string toString() const {
        return Name + " : " + Qualification + " : " + PhoneNumber + " : " + Address;
    }
};

void add_student(const string& rollNo, const string& name, const string& subject, const string& address) {
    University student;
    student.setRollNo(rollNo);
    student.setName(name);
    student.setSubject(subject);
    student.setAddress(address);

    ofstream out("C:/Users/O/Desktop/University_Managment_system/record.txt", ios::app);
    if (!out) {
        cout << "Error: File can't open!!!" << endl;
    } else {
        out << student.toString() << endl;
    }
    out.close();
    cout << "Student Added Successfully" << endl;
}

void search_student(const string& rollNo) {
    ifstream in("C:/Users/O/Desktop/University_Managment_system/record.txt");
    if (!in) {
        cout << "Error: File can't open!!!" << endl;
    }
    string student;
    bool found = false;
    while (getline(in, student)) {
        if (student.find(rollNo) != string::npos) {
            cout << student << endl;
            found = true;
        }
    }
    in.close();

    if (!found) {
        cout << "Student Not Found!!" << endl;
    }
}

void update_student(const string& rollNo, const string& newName, const string& newSubject, const string& newAddress) {
    ifstream infile("C:/Users/O/Desktop/University_Managment_system/record.txt");
    ofstream outfile("C:/Users/O/Desktop/University_Managment_system/temp_record.txt");

    if (!infile || !outfile) {
        cout << "Error: File can't open!!!" << endl;
        return;
    }

    string line;
    bool found = false;
    University student;

    while (getline(infile, line)) {
        if (line.find(rollNo) != string::npos) {
            found = true;
            student.fromString(line);

            if (!newName.empty()) student.setName(newName);
            if (!newSubject.empty()) student.setSubject(newSubject);
            if (!newAddress.empty()) student.setAddress(newAddress);

            outfile << student.toString() << endl;
        } else {
            outfile << line << endl;
        }
    }

    infile.close();
    outfile.close();

    remove("C:/Users/O/Desktop/University_Managment_system/record.txt");
    rename("C:/Users/O/Desktop/University_Managment_system/temp_record.txt", "C:/Users/O/Desktop/University_Managment_system/record.txt");

    if (found) {
        cout << "Student Data Updated" << endl;
    } else {
        cout << "Student Not Found!!" << endl;
    }
}

void delete_student(const string& rollNo) {
    ifstream infile("C:/Users/O/Desktop/University_Managment_system/record.txt");
    ofstream outfile("C:/Users/O/Desktop/University_Managment_system/temp_record.txt");

    if (!infile || !outfile) {
        cout << "Error: File can't open!!!" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(infile, line)) {
        if (line.find(rollNo) == string::npos) {
            outfile << line << endl;
        } else {
            found = true;
        }
    }

    infile.close();
    outfile.close();

    remove("C:/Users/O/Desktop/University_Managment_system/record.txt");
    rename("C:/Users/O/Desktop/University_Managment_system/temp_record.txt", "C:/Users/O/Desktop/University_Managment_system/record.txt");

    if (found) {
        cout << "Student Record Deleted Successfully" << endl;
    } else {
        cout << "Student Not Found!!" << endl;
    }
}

void show_all_students() {
    ifstream infile("C:/Users/O/Desktop/University_Managment_system/record.txt");
    if (!infile) {
        cout << "Error: File can't open!!!" << endl;
        return;
    }

    string line;
    cout << "All Students Records:" << endl;
    cout << "***************************************" << endl;
    while (getline(infile, line)) {
        cout << line << endl;
    }

    infile.close();
}

void add_teacher(const string& name, const string& qualification, const string& phoneNumber, const string& address) {
    Teacher teacher;
    teacher.setName(name);
    teacher.setQualification(qualification);
    teacher.setPhoneNumber(phoneNumber);
    teacher.setAddress(address);

    ofstream out("C:/Users/O/Desktop/University_Managment_system/teachers.txt", ios::app);
    if (!out) {
        cout << "Error: File can't open!!!" << endl;
    } else {
        out << teacher.toString() << endl;
    }
    out.close();
    cout << "Teacher Added Successfully" << endl;
}

void update_teacher(const string& name, const string& newQualification, const string& newPhoneNumber, const string& newAddress) {
    ifstream infile("C:/Users/O/Desktop/University_Managment_system/teachers.txt");
    ofstream outfile("C:/Users/O/Desktop/University_Managment_system/temp_teachers.txt");

    if (!infile || !outfile) {
        cout << "Error: File can't open!!!" << endl;
        return;
    }

    string line;
    bool found = false;
    Teacher teacher;

    while (getline(infile, line)) {
        if (line.find(name) != string::npos) {
            found = true;
            teacher.fromString(line);

            if (!newQualification.empty()) teacher.setQualification(newQualification);
            if (!newPhoneNumber.empty()) teacher.setPhoneNumber(newPhoneNumber);
            if (!newAddress.empty()) teacher.setAddress(newAddress);

            outfile << teacher.toString() << endl;
        } else {
            outfile << line << endl;
        }
    }

    infile.close();
    outfile.close();

    remove("C:/Users/O/Desktop/University_Managment_system/teachers.txt");
    rename("C:/Users/O/Desktop/University_Managment_system/temp_teachers.txt", "C:/Users/O/Desktop/University_Managment_system/teachers.txt");

    if (found) {
        cout << "Teacher Data Updated" << endl;
    } else {
        cout << "Teacher Not Found!!" << endl;
    }
}

void delete_teacher(const string& name) {
    ifstream infile("C:/Users/O/Desktop/University_Managment_system/teachers.txt");
    ofstream outfile("C:/Users/O/Desktop/University_Managment_system/temp_teachers.txt");

    if (!infile || !outfile) {
        cout << "Error: File can't open!!!" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(infile, line)) {
        if (line.find(name) == string::npos) {
            outfile << line << endl;
        } else {
            found = true;
        }
    }

    infile.close();
    outfile.close();

    remove("C:/Users/O/Desktop/University_Managment_system/teachers.txt");
    rename("C:/Users/O/Desktop/University_Managment_system/temp_teachers.txt", "C:/Users/O/Desktop/University_Managment_system/teachers.txt");

    if (found) {
        cout << "Teacher Record Deleted Successfully" << endl;
    } else {
        cout << "Teacher Not Found!!" << endl;
    }
}

void show_all_teachers() {
    ifstream infile("C:/Users/O/Desktop/University_Managment_system/teachers.txt");
    if (!infile) {
        cout << "Error: File can't open!!!" << endl;
        return;
    }

    string line;
    cout << "All Teachers Records:" << endl;
    cout << "***************************************" << endl;
    while (getline(infile, line)) {
        cout << line << endl;
    }

    infile.close();
}
int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Invalid action" << endl;
        return 1;
    }

    int action = atoi(argv[1]);

    switch (action) {
        case 1:
            // Call the function for adding a student
            if (argc != 6) {
                cout << "Invalid number of arguments for adding a student" << endl;
                return 1;
            }
            add_student(argv[2], argv[3], argv[4], argv[5]);
            break;
        case 2:
            // Call the function for searching a student
            if (argc != 3) {
                cout << "Invalid number of arguments for searching a student" << endl;
                return 1;
            }
            search_student(argv[2]);
            break;
        case 3:
            // Call the function for updating a student
            if (argc != 6) {
                cout << "Invalid number of arguments for updating a student" << endl;
                return 1;
            }
            update_student(argv[2], argv[3], argv[4], argv[5]);
            break;
        case 4:
            // Call the function for deleting a student
            if (argc != 3) {
                cout << "Invalid number of arguments for deleting a student" << endl;
                return 1;
            }
            delete_student(argv[2]);
            break;
        case 5:
            // Call the function for showing all students
            if (argc != 2) {
                cout << "Invalid number of arguments for showing all students" << endl;
                return 1;
            }
            show_all_students();
            break;
        case 6:
            // Call the function for adding a teacher
            if (argc != 5) {
                cout << "Invalid number of arguments for adding a teacher" << endl;
                return 1;
            }
            add_teacher(argv[2], argv[3], argv[4], argv[5]);
            break;
        case 7:
            // Call the function for updating a teacher
            if (argc != 5) {
                cout << "Invalid number of arguments for updating a teacher" << endl;
                return 1;
            }
            update_teacher(argv[2], argv[3], argv[4], argv[5]);
            break;
        case 8:
            // Call the function for deleting a teacher
            if (argc != 3) {
                cout << "Invalid number of arguments for deleting a teacher" << endl;
                return 1;
            }
            delete_teacher(argv[2]);
            break;
        case 9:
            // Call the function for showing all teachers
            if (argc != 2) {
                cout << "Invalid number of arguments for showing all teachers" << endl;
                return 1;
            }
            show_all_teachers();
            break;
        default:
            cout << "Invalid action" << endl;
            return 1;
    }

    return 0;
}
