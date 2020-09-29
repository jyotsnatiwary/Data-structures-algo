#include <iostream>
#include <vector>
using namespace std;

void main() {
vector<int> v(4,12);
v.push_back(15);
cout << v.size() <<” “ v.capacity() << " ";
v.push_back(25);
cout << v.size() <<” “ v.capacity();
}
	
