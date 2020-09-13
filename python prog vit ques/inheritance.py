class A:
    def d(self):
        print("a")
    def c(self):
        print("c from A class")

class B(A):
    def __init__(self):
        print('B')

a=A()
b=B()
a.c()
b.c()
a.d()
b.__init__
