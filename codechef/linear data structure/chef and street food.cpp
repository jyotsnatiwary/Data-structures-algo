/*in Chefland, there is a very famous street where N types of street food (numbered 1 through N) are offered. For each valid i, there are Si stores that offer food of the i-th type, the price of one piece of food of this type is Vi (the same in each of these stores) and each day, Pi people come to buy it; each of these people wants to buy one piece of food of the i-th type.

Chef is planning to open a new store at this street, where he would offer food of one of these N types. Chef assumes that the people who want to buy the type of food he'd offer will split equally among all stores that offer it, and if this is impossible, i.e. the number of these people p is not divisible by the number of these stores s, then only ?ps? people will buy food from Chef.

Chef wants to maximise his daily profit. Help Chef choose which type of food to offer and find the maximum daily profit he can make.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
N lines follow. For each i (1=i=N), the i-th of these lines contains three space-separated integers Si, Pi and Vi.
Output
For each test case, print a single line containing one integer ? the maximum profit.

Constraints
1=T=100
1=N=100
1=Si,Vi,Pi=10,000 for each valid i
Subtasks
Subtask #1 (100 points): original constraints

Example Input
2
3
4 6 8
2 6 6
1 4 3
1
7 7 4
Example Output
12
0
Explanation
Example case 1: Chef should offer food of the second type. On each day, two people would buy from him, so his daily profit would be 12.

Example case 2: Chef has no option other than to offer the only type of food, but he does not expect anyone to buy from him anyway, so his daily profit is 0.*/

#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int profit = 0;
        for(int i=0; i<n; i++){
            int s, p, v;
            cin>>s>>p>>v;

            profit = max(profit, v*(p/(s+1)));

        }
        cout<<profit<<"\n";
    }
}





