#include<iostream>
using namespace std;

int main()
{
	float basic_salary, gross_salary, HRA, DA;
	cout<<"Enter basic salary of Employee : ";
	cin>>basic_salary;

	if (basic_salary<1500)
	{
		HRA=0.1*basic_salary;
		DA=0.9*basic_salary;
	}
	else
	{	
		HRA=500;
		DA=0.98*basic_salary;
	}

	gross_salary=basic_salary+HRA+DA;
	cout<<"Gross salary is : "<<gross_salary;

	
	return 0;
}
 
