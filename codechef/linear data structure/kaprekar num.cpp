/*To check if an n-digit number k is a Kaprekar number or not. Square it and add the right n digits to the left n or n-1 digits. 
If the resultant sum is k, then k is called a Kaprekar number. For example, 9 is a Kaprekar number since 92 = 81 & 8 + 1 = 9 
297 is a Kaprekar number as 2972 = 88209 & 88 + 209 = 297 ). Write a Java program to find whether the given number is a Kaprekar number or not.

Test case 1 :
Sample input : 9

Sample output : Kaprekar Number

Test case 2 :
Sample input : 45

Sample output : Kaprekar Number

Test case 3 :
Sample input : 25

Sample output : Not a Kaprekar Number*/

#include<bits/stdc++.h>
using namespace std;

bool kap(int k){
	int c=0;
	if (k==1) return true;
	int sq=k*k;
	while(sq){
		c++;
		sq/=10;
	}
	sq=k*k;
	for(int i=1; i<c;i++){
		int parts=pow(10,i);
		if(parts==k) continue;
		int sum=sq/parts+sq%parts;
		if(sum==k) return true;
	}
return false;
}
int main(){
	int n; cin>>n;
	if(kap(n)) cout<<"Kaprekar num \n";
	else cout<<"Not";
}




import java.util.Scanner;
 
public class KaprekarNumberTest {
 
   public static void main(String[] args) {
	Scanner scanner = new Scanner(System.in);
	System.out.println("Enter a number");
	// read user input
	int number = scanner.nextInt();
	scanner.close();
	// check for Kaprekar number
	boolean checkKaprekar = new KaprekarNumberTest().checkKaprekar(number);
	if (checkKaprekar) {
		System.out.println(number + " is a Kaprekar number");
	} else {
		System.out.println(number + " is not Kaprekar number");
	}
   }
 
 
   boolean checkKaprekar(int n) {
	// calculate square of number
	int square = n * n;
	// make copy of square
	int squareCopy = square;
	int len = 0;
	// determine length of square of number
	while (squareCopy != 0) {
		len++;
		squareCopy /= 10;
	}
	boolean isKaprekar = false;
	// iterate over square
	for (int i = 1; i < len; i++) {
	   // divide square by 10, 100, 1000...etc
	   int divisor = (int) Math.pow(10, i);
	   // get left part of number
	   int quotient = square / divisor;
	   // get right part
	   int remainder = square % divisor;
	   // add left and right parts and compare it with number
	   if (quotient + remainder == n) {
	  	// it is Kaprekar number
		isKaprekar = true;
	   }
	}
	return isKaprekar;
   }
}
