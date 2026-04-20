#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Student {
    string name;
    int age;
};

vector<Student> students;

void addStudent() {
    Student s;
    cout << "Enter name: ";
    cin >> s.name;
    cout << "Enter age: ";
    cin >> s.age;
    students.push_back(s);
}

void showStudents() {
    for (const auto& s : students) {
        cout << s.name << " - " << s.age << endl;
    }
}
