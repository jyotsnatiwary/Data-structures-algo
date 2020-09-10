/*It was Stefan's first day at school. His teacher Elena Gilbert asked the students to meet every other student in the class and introduce about themselves. 
The teacher asked them to handshake with each other when they meet. 
If there are n number of students in the class then find the total number of handshakes made by the students.
First input corresponds to the total number of students. The output consists of 1 integer indicating the total number of handshakes.

Test case 1 : 
Sample input :  15 
Sample output :  105

Test case 2 : 
Sample input : 4 
Sample output : 6

Test case 3 : 
Sample input : 3 
Sample output : 3
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int ans=(n*(n-1))/2;
	cout<<ans;
}


class handshake  
{  
    static int maxHandshake(int n) 
    { 
        return (n * (n - 1)) / 2; 
    } 
    public static void main (String[] args) 
    { 
        int n = 10; 
        System.out.println( maxHandshake(n)); 
    } 
} 
