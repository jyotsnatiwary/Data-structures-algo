/*Kth smallest node in BST
Send Feedback
Given a BST and an integer K, you need to find the Kth smallest element present in the BST. Return INT_MIN if that is not present in the BST.
Input format :
Line 1: Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Output Format:
Line 1: Kth smallest node
Sample Input :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
3
Sample Output :
6*/
int numNodes(BinaryTreeNode<int>* root){
	if (root==NULL) return 0;
	return 1+numNodes(root->left)+numNodes(root->right);
}
int findNode(BinaryTreeNode<int>* root, int k) {
		// Write your code here
    if (root==NULL) return INT_MIN;
    int leftCount=numNodes(root->left);
    if( leftCount>=k) return findNode(root->left,k);
    else if (leftCount==k-1) return root->data;
    else return findNode(root->right, k-leftCount-1);
		
}
