#include <iostream>
#include <string>
using namespace std;

// Define the struct (creating our folder template)
struct Student {
    int age;
    string first_name;
    string last_name;
    int standard;
};

int main() {
    Student student;  // Create one student folder
    
    // Read the input and put it in our folder
    cin >> student.age;
    cin >> student.first_name;
    cin >> student.last_name;
    cin >> student.standard;
    
    // Take everything out of the folder and print it
    cout << student.age << " " 
         << student.first_name << " " 
         << student.last_name << " " 
         << student.standard;
    
    return 0;
}
