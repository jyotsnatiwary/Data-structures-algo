## Read input as specified in the question.
## Print output as specified in the question.
n=int(input())
a=0
i=0
m=0
while n>0:
    r=n%10
    m=r*(2^i)
    i=i+1
    a=a+m
    n=n//10
print(a)
