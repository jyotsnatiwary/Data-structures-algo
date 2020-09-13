class Emp:
    def __init__(self, first, last):
        self.first = first
        self.last = last
        self.email = first + '.' + last + '@engineerons.com'
    def fullname(self):
    #def fullname():
        return'{} {}'.format(emp1.first,self.last)
emp1 = Emp('om','Singh')
emp2 = Emp('Som','Singh')
print(emp1.email)
#print('{} {}'.format(emp1.first, emp1.last, emp1.email))
#print(emp2.fullname())
#print(Emp.fullname(emp1))
print(emp1.__dict__)
