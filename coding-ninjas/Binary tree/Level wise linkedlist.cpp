/*Level wise linkedlist
Send Feedback
Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format :
Each level linked list is printed in new line (elements are separated by space).
Constraints:
Time Limit: 1 second
Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
5 
6 10 
2 3 
9*/

#include <bits/stdc++.h>
using namespace std;

void insert(Node<int>* head,Node<int>* head1){
    if(head1==NULL) return;
    if(head==NULL){
        head=head1;
        return;
    }
    Node<int>* temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=head1;
    return;
}
void dfs(BinaryTreeNode<int>* root,vector<Node<int>*> &ans,int depth){
    if (root==NULL) return;
    if(depth>ans.size()){
        Node<int>* head1=new Node<int>(root->data);
        ans.push_back(head1);
    }
    else{
        Node<int>* head1=new Node<int>(root->data);
        insert(ans[depth-1],head1);        
    }
    dfs(root->left,ans,depth+1);
    dfs(root->right,ans,depth+1);
    return ;
}
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    vector<Node<int>*> ans;
    dfs(root,ans,1);
    return ans;
}


