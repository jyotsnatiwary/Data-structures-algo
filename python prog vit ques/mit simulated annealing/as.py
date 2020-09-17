import random;
import math;
from math import *;
LIMIT=100000;



def update_temperature(T,k):
    T1=T/log(k+1);
#   print "temp now is " + str(T1);
    return T1;

def get_neighbors(i,l):
    if(l>1):
        if(0<=i and i<l):
            if(i==0):
                return [1];
            if(i==l-1):
                return [l-2];
            return [i-1,i+1];
    return [];

def make_move(x,A,T):
    nhbs=get_neighbors(x,len(A));

    nhb=nhbs[random.choice(range(0,len(nhbs)))];


    delta=A[nhb]-A[x];


    if(delta < 0):
        return nhb;
    else:
        r=random.random();
        if(r <= (e**(-1*delta)/(T*1.0))):
            return nhb;

    return x;


def simulated_annealing(A):
    l=len(A);
    init_pos=random.choice(xrange(0,l));
    T=10000**30;
    k=1;

    x_best=init_pos;
    x=x_best;

    while(T>0.0000001 ):
        x=make_move(x,A,T);
        if(A[x] < A[x_best]):
            x_best=x;
        T=update_temperature(T,k);
        k+=1;

    return [x,x_best,init_pos];



def isminima_local(p,A):
    l=len(A);
    if(l==1 and p==0):
        return True;
    if(l>1):
        if(p==0):
            if(A[0] <=A[1]):
                return True;
        if(p==l-1):
            if(A[p-1] >=A[p]):
                return True;
        if(0<=p and p<l and A[p-1]>=A[p] and A[p]<=A[p+1]):
            return True;
    return False;


def func(x):
    F=sin(x);
    return F;

def initialize(l):
    A=[0]*l;
    for i in xrange(0,l):
        A[i]=func(i);
    return A;

def main():
    A=initialize(LIMIT);


    local_minima=[];
    for i in xrange(0,LIMIT):
        if( isminima_local(i,A)):
            local_minima.append([i,A[i]]);  
    sols=simulated_annealing(A);

    m,p=A[0],0;
    for i in xrange(1,LIMIT):
        if(m>A[i]):
            m=A[i];
            p=i;

    print ("Global Minima at \n");
    print (p,m);


    print ("After annealing\n");

    print ("Solution is " + str(sols[0]) + " " + str(A[sols[0]]));
    print ("Best Solution is " + str(sols[1]) + " " + str(A[sols[1]]));
    print ("Start Solution is " + str(sols[2]) + " " + str(A[sols[2]]));

    for i in xrange(0,len(local_minima)):
        if([sols[0],A[sols[0]]]==local_minima[i]):
            print ("Solution in local Minima");
        if([sols[1],A[sols[1]]]==local_minima[i]):
            print ("Best Solution in local Minima");
    for i in local_minima:
        print (i);

main();