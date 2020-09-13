class Emp:
    def __init__(self,first,last):
        self.first=first
        self.last=last
        self.email=first+'.'+last+'@engons'
    def fullname(self):
        return'{} {}'.format(self.first,self.last)
emp1 = Emp('om','singh')
emp2= Emp('som','singh')
print(emp1.email)
print(emp1.fullname())
print(Emp.fullname(emp1))
