#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    float marks;
};

vector<Student> records;

void addStudent() {
    Student s;
    cout << "\nEnter Roll No: ";
    cin >> s.roll;
    cout << "Enter Name: ";
    cin >> s.name;
    cout << "Enter Marks: ";
    cin >> s.marks;
    records.push_back(s);
    cout << "\nStudent Added Successfully!\n";
}

void viewStudents() {
    if (records.empty()) {
        cout << "\nNo Records Found!\n";
        return;
    }
    cout << "\n--- Student Records ---\n";
    for (auto &s : records) {
        cout << "Roll: " << s.roll
             << "  Name: " << s.name
             << "  Marks: " << s.marks << endl;
    }
}

void searchStudent() {
    int r;
    cout << "\nEnter Roll No to Search: ";
    cin >> r;

    for (auto &s : records) {
        if (s.roll == r) {
            cout << "\nRecord Found!\n";
            cout << "Roll: " << s.roll
                 << "  Name: " << s.name
                 << "  Marks: " << s.marks << endl;
            return;
        }
    }
    cout << "\nStudent Not Found!\n";
}

void updateStudent() {
    int r;
    cout << "\nEnter Roll No to Update: ";
    cin >> r;

    for (auto &s : records) {
        if (s.roll == r) {
            cout << "\nEnter New Name: ";
            cin >> s.name;
            cout << "Enter New Marks: ";
            cin >> s.marks;
            cout << "\nRecord Updated!\n";
            return;
        }
    }
    cout << "\nRecord Not Found!\n";
}

void deleteStudent() {
    int r;
    cout << "\nEnter Roll No to Delete: ";
    cin >> r;

    for (int i = 0; i < records.size(); i++) {
        if (records[i].roll == r) {
            records.erase(records.begin() + i);
            cout << "\nRecord Deleted!\n";
            return;
        }
    }
    cout << "\nRecord Not Found!\n";
}

bool login() {
    string user, pass;
    cout << "\n--- Login ---\n";
    cout << "Username: ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;

    return (user == "admin" && pass == "1234");
}

int main() {
    if (!login()) {
        cout << "\nInvalid Credentials! Exiting...";
        return 0;
    }

    int choice;
    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n2. View Students\n3. Search Student\n4. Update Student\n5. Delete Student\n6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addStudent(); break;
        case 2: viewStudents(); break;
        case 3: searchStudent(); break;
        case 4: updateStudent(); break;
        case 5: deleteStudent(); break;
        case 6: cout << "\nExiting...\n"; break;
        default: cout << "\nInvalid Choice!\n";
        }
    } while (choice != 6);

    return 0;
}
