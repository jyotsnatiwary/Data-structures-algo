def rowWiseSum(arr):
    sum = 0  
    for i in range(n) : 
        for j in range(m) :   
            sum =sum+ arr[i][j] 
        print(*sum)  
        #return sum
        sum = 0
    pass

#Main
m, n=(int(i) for i in input().strip().split(' '))
l=[int(i) for i in input().strip().split(' ')]
arr = [ [ l[(j*n)+i] for i in range(n)] for j in range(m)]
l=rowWiseSum(arr)
#print(*l)
