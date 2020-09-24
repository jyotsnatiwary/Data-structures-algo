// Hybrid Inheritance
// Having more than one inheritance type used

#include<iostream>
using namespace std;
class dep
{
public:
char d_name[25];
int d_id;
dep()
{
cout<<"\n Enter dept. Name:";
cin>>d_name;
cout<<"\n Enter dept.id:";
cin>>d_id;
cout<<"\n Inputs Received!!";
}
};
class course:public dep
{
public:
char c_name[25];
int c_id;
course()
{
cout<<"\n Enter course name:";
cin>>c_name;
cout<<"\n Enter course id:";
cin>>c_id;
cout<<"\n Course information Received!!";
}
};
class address
{
public:
char ad_sn[100];
char ad_phno[12];
char ad_email[25];
address()
{
cout<<"\n Enter the address: Street Name:";
cin>>ad_sn;
cout<<"\n Enter the address: Phone Number:";
cin>>ad_phno;
cout<<"\n Enter the address: email id:";
cin>>ad_email;
cout<<"\n address received!!";
}
};
class faculty:public address
{
public:
int f_reg;
char f_name[25];
faculty()
{
cout<<"\n Enter faculty name:";
cin>>f_name;
cout<<"\n Enter faculty id:";
cin>>f_reg;
cout<<"\n faculty information received";
}
};
class student:virtual public address,public faculty
{
public:
int st_reg;
char st_name[25];
student()
{
cout<<"\n Enter student name:";
cin>>st_name;
cout<<"\n Enter student id:";
cin>>st_reg;
cout<<"\n Student information received";
}
};


class exam:public student, public course
{
public:
char ex_hall[10];
char ex_date[10];
char ex_slot[10];
exam()
{
cout<<"\n Enter the exam hall name:";
cin>>ex_hall;
cout<<"\n Enter date of the exam:";
cin>>ex_date;
cout<<"\n Enter slot name:";
cin>>ex_slot;
cout<<"\n Exam information received";
}
void display()
{
cout<<"\n Name of the student:"<<st_name;
cout<<"\n Register Number:"<<st_reg;
cout<<"\n Name of the department:"<<d_name;
cout<<"\n Register Number:"<<d_id;
cout<<"\n Name of the faculty:"<<f_name;
cout<<"\n Faculty id:"<<f_reg;
cout<<"\n Exam Hall Name:"<<ex_hall;
cout<<"\n Exam date:"<<ex_date;
cout<<"\n Exam Slot:"<<ex_slot;
cout<<"\n Display done!!";
}
};
int main()
{
exam e1;
e1.display();
}
