#include<iostream>
using namespace std;

class Test {
private:
    int x, y, z;

public:

    void input() {
        cout << "Enter Two Numbers :";
        cin >> x>>y;
    }

    friend void add(Test &t);

    void display() {

        cout << "\nThe sum is :" << z;
    }
};

void add(Test &t) {

    t.z = t.x + t.y;
}

int main() {

    Test t;

    t.input();
    add(t);

    t.display();

    return 0;
}
