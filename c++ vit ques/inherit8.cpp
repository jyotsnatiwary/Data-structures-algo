// Virtual functions
#include<iostream>
using namespace std;
class father
{
public:
virtual void celebrate()
{
cout<<"\n Visit temple";
cout<<"\n Celebrate with family";
}
};
class son:public father
{
public:
void celebrate()
{
cout<<"\n Visit mall";
cout<<"\n Celebrate with friends";
}
};

class grandson:public son
{
	public:
		void celebrate()
		{
			cout<<"\n Visit club";
			cout<<"\n Celebrate with fam";
		}
};

int main()
{
father f1, *m1; //Note, its is applicable to dynamic objects;
son s1;
grandson g1;


m1=&f1;
m1->celebrate();

m1=&s1;
m1->celebrate();

m1=&g1;
m1->celebrate();

return 0;
}
