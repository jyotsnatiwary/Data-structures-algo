def rec(l,b):
    a1=l*b
    return a1
def sq(l,b):
    a2=l*l
    return a2
def main():
    l=int(input("enter length"))
    b=int(input("entr breadth"))
    a1=rec(l,b)
    a2=sq(l,b)
    print("area=",a1)
    print("area=",a2)
