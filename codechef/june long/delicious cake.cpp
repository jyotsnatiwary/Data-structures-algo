/*It is Chefina's birthday and Chef wants to prepare a cake for her. He has N points (X1,Y1),(X2,Y2),…,(XN,YN) in a 2D plane, and a candle which he wants to place at some point in this plane.

The cake is made up of a non-negative number of layers. Chef considers the deliciousness of the cake to be equal to the number of layers in the cake. A layer is a simple polygon whose vertices are some of Chef's N points. It is not required for each of Chef's points to belong to a layer. Furthermore, the layers must satisfy the following conditions:

For each layer, the candle must lie strictly inside it.
Each of Chef's N points that lies strictly inside some layer must belong to some other layer or be the candle point.
No two layers may touch or intersect.
The layers must be chosen in such a way that the deliciousness of the cake is maximum possible.
Now, Chef is wondering about how the deliciousness of the cake depends on where he places the candle. You should answer Q queries. In each query, you are given a point p=(x,y) where Chef wants to place the candle and you have to find the deliciousness of the cake.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and Q.
N lines follow. For each valid i, the i-th of these lines contains two space-separated integers Xi and Yi.
Each of the following Q lines contains two space-separated integers x and y describing a query.
Output
For each query, print a single line containing one integer ? the deliciousness of the cake.

Constraints
1=T=100
1=N=5,000
1=Q=2,000
|Xi|,|Yi|=109 for each valid i
|x|,|y|=109
the sum of N over all test cases does not exceed 5,000
the sum of Q over all test cases does not exceed 2,000
Subtasks
Subtask #1 (15 points): N=12
Subtask #2 (20 points): for each valid i, Xi=0 or Yi=0
Subtask #3 (65 points): original constraints

Example Input
1
6 2
0 0
6 0
3 4
2 1
4 1
3 3
6 6
3 3
Example Output
0
1
Explanation
Example case 1:

In the first query, p=(6,6). The cake cannot have any layers, so its deliciousness is 0.
In the second query, p=(3,3). The cake can have only one layer, e.g. a triangle with vertices (2,1),(4,1),(3,4). Other choices of this layer are also possible, but the cake can never have more than one layer.*/


