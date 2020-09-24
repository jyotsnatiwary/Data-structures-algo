#include<fstream.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<stdio.h>
#include<dos.h>
class account
{
unsigned long int acno,bal;
char name[30],pass[20],type;
public:
void crtacc();		       	 //function to get data from user
void accno_gen();                //function to randomly generate an account number
void display() 		const;	 //function to show data on screen
void modify();			 //function to add new data
void deposit(int);		 //function to accept amount and add to balance amount
void withdraw(int);		 //function to accept amount and subtract from balance amount
void report(int)	const;	 //function to show data in tabular format
int retacno() 		const;	 //function to return account number
int retbal() 		const;	 //function to return balance amount
char rettype() 		const;	 //function to return type of account
int chkpass(char[])	const;   //function to verify password

};		//class ends here

void write_account();	         //function to write record in binary file
void display_sp(int);	         //function to display account details given by user
void modify_account(int);	 //function to modify record of file
void delete_account(int);	 //function to delete record of file
void display_all();		 //function to display all account details
void deposit_withdraw(int, int); // function to desposit/withdraw amount for given account
void intro();			 //introductory screen function
void loader(int);		 //function for loading animation
int otp();			 //security function
void thanks();			 //exit function

void account::crtacc()
{
char rp[20];
cout<<"\n\nEnter The Name of The account Holder:\t";
cin.ignore();
gets(name);
cout<<"\nEnter Type of The account (C/S):\t";
cin>>type;
type=toupper(type);
redo:cout<<"\nEnter a password for your account:\t";
gets(pass);
cout<<"\nRe-Enter password (focussed):\t\t";
gets(rp);
	if(strcmp(rp,pass)!=0)
	{
	cout<<"\nThe password does not match.Try again.\n";
	goto redo;
	}
cout<<"\nEnter The Initial amount:\t\t ";
cin>>bal;
loader(3);
accno_gen();
cout<<"\nYour Account no is:"<<acno<<"\n\n\nPlease note it down for future refrence.";
cout<<"\n\n\nAccount Created..";
}

void account::accno_gen()
{
randomize();
int a;
	for(int i=0;i<8;i++)
	{
	a=random(10);
	acno+=a;
	acno*=10;
	}
}

void account::display() const
{
cout<<"\nAccount No. : "<<acno;
cout<<"\nAccount Holder Name : ";
cout<<name;
cout<<"\nType of Account : "<<type;
cout<<"\nBalance amount : "<<bal;
}

void account::modify()
{
cout<<"\nModify Account Holder Name : ";
cin.ignore();
gets(name);
cout<<"\nModify Type of Account : ";
cin>>type;
type=toupper(type);
loader(3);
}

void account::deposit(int x)
{
bal+=x;
}

void account::withdraw(int x)
{
bal-=x;
}

void account::report(int i) const
{
gotoxy(1,i);cout<<acno;
gotoxy(20,i);cout<<name;
gotoxy(47,i);cout<<type;
gotoxy(67,i);cout<<bal;
gotoxy(77,i);cout<<".Cr";
}

int account::retacno() const
{
return acno;
}

int account::retbal() const
{
return bal;
}

int account::chkpass(char p[20]) const
{
	if(strcmp(p,pass)==0)
	return 1;
return 0;
}

char account::rettype() const
{
return type;
}

void write_account()
{
account ac;
ofstream outFile;
outFile.open("account.dat",ios::binary|ios::app);
ac.crtacc();
outFile.write((char*)&ac, sizeof(account));
outFile.close();
}

void display_sp(int n)
{
account ac;
char flag[]="false";
ifstream inFile;
inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
	cout<<"File could not be open !! Press any Key...";
	return;
	}
cout<<"\nBALANCE DETAILS\n";
	while(inFile.read((char*)&ac, sizeof(account)))
	{
		if(ac.retacno()==n)
		{
		cout<<"\nEnter password:\t";
		char p[20];
		gets(p);
			if(ac.chkpass(p)==1)
			{
			ac.display();
			strcpy(flag,"true");
			}
			else
			{
			cout<<"Wrong Password\n\nExiting to Main Menu ";
			delay(2500);
			inFile.close();
			return;
			}
		}
	}
inFile.close();
	if(strcmp(flag,"false")==0)
	cout<<"\n\nAccount number does not exist";
}

void modify_account(int n)
{
char found[]="false";
account ac;
fstream File;
File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
	cout<<"File could not be open !! Press any Key...";
	return;
	}
	while(!File.eof() && strcmp(found,"false")==0)
	{
	File.read((char *)&ac, sizeof(account));
		if(ac.retacno()==n)
		{
		cout<<"\nEnter password:\t";
		char p[20];
		gets(p);
			if(ac.chkpass(p)==1)
			{
			clrscr();
			ac.display();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*(int)(sizeof(account));
			File.seekp(pos,ios::cur);
			File.write((char*)&ac, sizeof(account));
			cout<<"\n\n\t Record Updated";
			strcpy(found,"true");
			}
			else
			{
			cout<<"Wrong Password\n\nExiting to Main Menu ";
			delay(2500);
			return;
			}
		}
	}
File.close();
	if(strcmp(found,"false")==0)
	cout<<"\n\n Record Not Found ";
}

void delete_account(int n)
{
char flag[]="false";
account ac;
ifstream inFile;
ofstream outFile;
inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
	cout<<"File could not be opened !!\n\n";
	system("pause");
	return;
	}
outFile.open("Temp.dat",ios::binary);
inFile.seekg(0,ios::beg);
	while(inFile.read((char *)&ac, sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
		outFile.write((char *)&ac, sizeof(account));
		}
		else
		{
		cout<<"\nEnter password:\t";
		char p[20];
		gets(p);
			if(ac.chkpass(p)==1)
			{
			strcpy(flag,"true");
			}
			else
			{
			strcpy(flag,"wrong");
			cout<<"Wrong Passwword";
			outFile.write((char *)&ac, sizeof(account));
			}
		}
	}
inFile.close();
outFile.close();
remove("account.dat");
rename("Temp.dat","account.dat");
	if(strcmp(flag,"true")==0)
	cout<<"\n\n\tRecord Deleted ...";
	else if(strcmp(flag,"false")==0)
	cout<<"\n\n\tRecord not found ...";
}

void display_all()
{
char adminp[20]="psp1729",admind[20]="db*4104",ap[20],ad[20];
clrscr();
cout<<"Access to this page is denied!!!\n\nEnter administrative passwords to continue.";
cout<<"\n\n\nPassword 1:\t";
gets(ap);
cout<<"\nPassword 2:\t";
gets(ad);
	if((strcmp(ap,adminp)!=0)&&(strcmp(ad,admind)!=0))
	{
	cout<<"\nOne or more passwords is/are wrong!!!\n\nExiting from program.";
	delay(2500);
	thanks();
	}
cout<<"\nAccess Granted";
getch();
clrscr();
account ac;
ifstream inFile;
inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
	cout<<"File could not be open !! Press any Key...";
	return;
	}
gotoxy(31,1);
cout<<"ACCOUNT HOLDER LIST\n\n";
cout<<"================================================================================\n";
cout<<"A/c no.            NAME                       Type                Balance\n";
cout<<"================================================================================";
int i=7;
	while(inFile.read((char *)&ac, sizeof(account)))
	{
	ac.report(i);
	i++;
	}
inFile.close();
}

void deposit_withdraw(int n, int option)
{
int amt;
char found[]="false";
account ac;
fstream File;
File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
	cout<<"File could not be open !! Press any Key...";
	return;
	}
	while(!File.eof() && strcmp(found,"false")==0)
	{
	File.read((char *)&ac, sizeof(account));
		if(ac.retacno()==n)
		{
		cout<<"\nEnter password:\t";
		char p[20];
		gets(p);
			if(ac.chkpass(p)==1)
				{
				ac.display();
				if(option==1)
				{
				cout<<"\n\n\tTO DEPOSIT AMOUNT ";
					if(otp()==0)
					return;
				cout<<"\n\nEnter The amount to be deposited";
				cin>>amt;
				ac.deposit(amt);
				}
				if(option==2)
				{
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
					if(otp()==0)
					return;
				cout<<"\n\nEnter The amount to be withdraw";
				cin>>amt;
					if(amt>ac.retbal())
					cout<<"Insufficient balance";
					else
					ac.withdraw(amt);
				}
			}
			else
			{
			cout<<"Wrong Password\n\nExiting to Main Menu ";
			delay(2500);
			return;
			}
		int pos=(-1)*(int)(sizeof(ac));
		File.seekp(pos,ios::cur);
		File.write((char *)&ac, sizeof(account));
		loader(2);
		cout<<"\n\n\t Record Updated";
		strcpy(found,"true");
		}
	}
File.close();
	if(strcmp(found,"false")==0)
	cout<<"\n\n Record Not Found ";
}

void intro()
{
clrscr();
gotoxy(27,3);
cout<<"BANK MANAGEMENT SYSTEM";
delay(500);
gotoxy(1,10);
cout<<"\tMADE BY :DIVYANSH BHATIA,PRAKHAR SINGH PALHARYA";
cout<<"\n\n\tSCHOOL : ST.PAUL H.S. SCHOOL,INDORE";
delay(2500);
}

void loader(int x)
{
clrscr();
	for(int i=0;i<x;i++)
	{
	gotoxy(40,12);delay(60);cout<<"$";
	gotoxy(39,11);delay(60);cout<<"$";
	gotoxy(38,10);delay(60);cout<<"$";
	gotoxy(37,10);delay(60);cout<<"$";
	gotoxy(36,10);delay(60);cout<<"$";
	gotoxy(35,10);delay(60);cout<<"$";
	gotoxy(34,10);delay(60);cout<<"$";
	gotoxy(33,11);delay(60);cout<<"$";
	gotoxy(32,12);delay(60);cout<<"$";
	gotoxy(33,13);delay(60);cout<<"$";
	gotoxy(34,14);delay(60);cout<<"$";
	gotoxy(35,14);delay(60);cout<<"$";
	gotoxy(36,14);delay(60);cout<<"$";
	gotoxy(37,14);delay(60);cout<<"$";
	gotoxy(38,14);delay(60);cout<<"$";
	gotoxy(39,13);delay(60);cout<<"$";
	gotoxy(40,12);delay(60);cout<<"$";
	gotoxy(41,11);delay(60);cout<<"$";
	gotoxy(42,10);delay(60);cout<<"$";
	gotoxy(43,10);delay(60);cout<<"$";
	gotoxy(44,10);delay(60);cout<<"$";
	gotoxy(45,10);delay(60);cout<<"$";
	gotoxy(46,10);delay(60);cout<<"$";
	gotoxy(47,11);delay(60);cout<<"$";
	gotoxy(48,12);delay(60);cout<<"$";
	gotoxy(47,13);delay(60);cout<<"$";
	gotoxy(46,14);delay(60);cout<<"$";
	gotoxy(45,14);delay(60);cout<<"$";
	gotoxy(44,14);delay(60);cout<<"$";
	gotoxy(43,14);delay(60);cout<<"$";
	gotoxy(42,14);delay(60);cout<<"$";
	gotoxy(41,13);delay(60);cout<<"$";
	gotoxy(40,12);delay(60);cout<<"$";
	gotoxy(39,11);delay(60);cout<<" ";
	gotoxy(38,10);delay(60);cout<<" ";
	gotoxy(37,10);delay(60);cout<<" ";
	gotoxy(36,10);delay(60);cout<<" ";
	gotoxy(35,10);delay(60);cout<<" ";
	gotoxy(34,10);delay(60);cout<<" ";
	gotoxy(33,11);delay(60);cout<<" ";
	gotoxy(32,12);delay(60);cout<<" ";
	gotoxy(33,13);delay(60);cout<<" ";
	gotoxy(34,14);delay(60);cout<<" ";
	gotoxy(35,14);delay(60);cout<<" ";
	gotoxy(36,14);delay(60);cout<<" ";
	gotoxy(37,14);delay(60);cout<<" ";
	gotoxy(38,14);delay(60);cout<<" ";
	gotoxy(39,13);delay(60);cout<<" ";
	gotoxy(40,12);delay(60);cout<<" ";
	gotoxy(41,11);delay(60);cout<<" ";
	gotoxy(42,10);delay(60);cout<<" ";
	gotoxy(43,10);delay(60);cout<<" ";
	gotoxy(44,10);delay(60);cout<<" ";
	gotoxy(45,10);delay(60);cout<<" ";
	gotoxy(46,10);delay(60);cout<<" ";
	gotoxy(47,11);delay(60);cout<<" ";
	gotoxy(48,12);delay(60);cout<<" ";
	gotoxy(47,13);delay(60);cout<<" ";
	gotoxy(46,14);delay(60);cout<<" ";
	gotoxy(45,14);delay(60);cout<<" ";
	gotoxy(44,14);delay(60);cout<<" ";
	gotoxy(43,14);delay(60);cout<<" ";
	gotoxy(42,14);delay(60);cout<<" ";
	gotoxy(41,13);delay(60);cout<<" ";
	gotoxy(40,12);delay(60);cout<<" ";
	}
gotoxy(1,1);
system("pause");
}

int otp()
{
randomize();
int aotp,botp;
ofstream ofile("otp.txt");
aotp=random(9001)+1000;
ofile<<"Your OTP is : "<<aotp;
ofile.close();
cout<<"\nYou have recieved an OTP.\n\nEnter OTP(Check your bin folder for otp) : ";
cin>>botp;
remove("otp.txt");
	if(aotp==botp)
	{
	cout<<"Verified\n";
	getch();
	clrscr();
	return 1;
	}
	else
	{
	cout<<"Not Verified\n";
	getch();
	clrscr();
	return 0;
	}
}

void thanks()
{
gotoxy(7,12);
cout<<"\t\tThanks for using bank managemnt system";
delay(2000);
exit(0);
}

int main()
{
clrscr();
char ch;
int num;
intro();
	do
	{
	clrscr();
	cout<<"\n\n\n\tMAIN MENU";
	cout<<"\n\n\t01. NEW ACCOUNT";
	cout<<"\n\n\t02. DEPOSIT AMOUNT";
	cout<<"\n\n\t03. WITHDRAW AMOUNT";
	cout<<"\n\n\t04. BALANCE ENQUIRY";
	cout<<"\n\n\t05. ALL ACCOUNT HOLDER LIST";
	cout<<"\n\n\t06. CLOSE AN ACCOUNT";
	cout<<"\n\n\t07. MODIFY AN ACCOUNT";
	cout<<"\n\n\t08. EXIT";
	cout<<"\n\n\tSelect Your Option (1-8) ";
	cin>>ch;
	clrscr();
		switch(ch)
		{
		case '1':write_account();
			 break;
		case '2':cout<<"\n\nEnter The account No. : "; cin>>num;
			 deposit_withdraw(num, 1);
			 break;
		case '3':cout<<"\n\nEnter The account No. : "; cin>>num;
			 deposit_withdraw(num, 2);
			 break;
		case '4':cout<<"\n\nEnter The account No. : "; cin>>num;
			 display_sp(num);
			 break;
		case '5':display_all();
			 break;
		case '6':cout<<"\n\nEnter The account No. : "; cin>>num;
			 delete_account(num);
			 break;
		case '7':cout<<"\n\nEnter The account No. : "; cin>>num;
			 modify_account(num);
			 break;
		case '8':thanks();
			 break;
		default :cout<<"\a";
		}
	cin.ignore();
	cin.get();
	}while(ch!='8');
return 0;
}
