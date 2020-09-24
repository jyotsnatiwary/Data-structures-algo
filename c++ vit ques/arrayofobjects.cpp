#include<stdio.h>
#include<iostream>
using namespace std;
class book
{
public:
char title[20];
int isbn;
char author[20];
char publisher[20];
book()
{
cout<<"\n New book has been created:";
cout<<" Enter the title, isbn,author,publisher:";
cin>>title>>isbn>>author>>publisher;
cout<<"\n Thank you!";
}

};
void display(book s)
{
cout<<"\n Book title:"<<s.title;
cout<<"\n Book title:"<<s.isbn;
cout<<"\n Book title:"<<s.author;
cout<<"\n Book title:"<<s.publisher;

}
int main()
{
book b1,b2;
book b[2];
display(b1);
display(b2);
display(b[0]);
display(b[1]);
printf("\n Thank you !");
return 0;
}

