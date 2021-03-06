/*Maximum Path Sum Between Two Leaves
Send Feedback
Given a binary tree of N nodes, find and return the maximum sum path between two leaves of the given tree.
Given binary tree contains positive values only.
Note: If there is only one leaf in the tree, then return 0 as answer.
Input format :
Line 1 : Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place
Output format :
Maximum sum path between two leaves
Constraints :
1 <= N <= 10^5
Sample Input :
10 9 4 3 1 5 8 -1 -1 -1 -1 -1 6 -1 -1 3 -1 -1 -1
Sample Output :
40*/


#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll ;

long long int lsum(BinaryTreeNode<int>* root){    
    if(root==NULL)
        return 0;    
    return root->data+max(lsum(root->left),lsum(root->right));
}

void trav(BinaryTreeNode<int> *root,long long int &msum){    
    if(root==NULL)
        return;    
    long long ans=root->data+lsum(root->left)+lsum(root->right);
    msum=max(msum,ans);    
    trav(root->left,msum);
    trav(root->right,msum);
}

long long int maximumSumLeafpath(BinaryTreeNode<int> *root){
    long long int msum=0;
    trav(root,msum);    
    return msum;
    
}
