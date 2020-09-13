class Circle():
    def __init__(self,r):
        self.radius=r
    def ar(self):
        return self.radius**2*3.14
    def pe(self):
        return 2*self.radius*3.14

obj=Circle(10)
print(obj.ar())
print(obj.pe())
