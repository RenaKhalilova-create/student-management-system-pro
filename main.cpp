#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Student{
    string name;
    int age;
};

vector<Student> students;

void addStudent(){
    Student s;
    cout<< "Enter name: ";
    cin>> s.name;
    cout<< "Enter age: ";
    cin>> s.age;
    students.push_back(s);
}

void showStudents(){
    for(const auto& s: students){
        cout<< s.name << " - " << s.age <<endl;
    }
}

void findStudent(){
    string name;
    cout<< "Enter name to search: ";
    cin>> name;

    for(const auto& s: students){
        if(s.name == name){
            cout<< "Found: " << s.name << " - " << s.age <<endl;
            return;
        }
    }
    cout<< "Student not found\n";
}

void deleteStudent(){
    string name;
    cout<< "Enter name to delete: ";
    cin>> name;

    for(int i = 0; i < students.size(); i++){
        if(students[i].name == name){
            students.erase(students.begin() + i);
            cout<< "Deleted successfully\n";
            return;
        }
    }
    cout<< "Student not found\n";
}

void saveToFile(){
    ofstream file("students.txt");

    for(const auto& s: students){
        file<< s.name << " " << s.age <<endl;
    }

    file.close();
    cout<< "Data saved to file\n";
}

void loadFromFile(){
    ifstream file("students.txt");

    students.clear();
    
    Student s;
    while(file>> s.name >> s.age){
        students.push_back(s);
    }

    file.close();
    cout<< "Data loaded from file\n";
}

int main(){
    int choice;

    while(true){
        cout<< "\n1. Add student\n";
        cout<< "2. Show students\n";
        cout<< "3. Find student\n";
        cout<< "4. Delete student\n";
        cout<< "5. Save to file\n";
        cout<< "6. Load from file\n";
        cout<< "7. Exit\n";

        cin>> choice;

        if(choice == 1) addStudent();
        else if(choice == 2) showStudents();
        else if(choice == 3) findStudent();
        else if(choice == 4) deleteStudent();
        else if(choice == 5) saveToFile();
        else if(choice == 6) loadFromFile();
        else if(choice == 7) break;
    }
    return 0;
}
