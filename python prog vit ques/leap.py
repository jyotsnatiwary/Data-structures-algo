n=int(input("enter year"))
if (n%4==0&n%400==0&n%100==0):
    print("its leap")
else:
    print("its not")
