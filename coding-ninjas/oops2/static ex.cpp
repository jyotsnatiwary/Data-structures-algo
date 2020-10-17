#include <iostream>
using namespace std;
class Student {
    public :

    int rollNumber;
    static int totalStudents;

    Student() {
        totalStudents++;
    }
};

int Student::totalStudents = 20;

int main() {
    Student s1, s2, s3, s4;
    cout << Student :: totalStudents;
}
