/*Code: Construct Tree from Preorder and Inorder
Send Feedback
For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
Note:
Assume that the Binary Tree contains only unique elements. 
Input Format:
The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total number of nodes the binary tree would have.

The second line of input contains N integers, all separated by a single space. It represents the preorder-traversal of the binary tree.

The third line of input contains N integers, all separated by a single space. It represents the inorder-traversal of the binary tree.
Output Format:
The given input tree will be printed in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space will separate them.
Constraints:
1 <= N <= 10^4
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
7
1 2 4 5 3 6 7 
4 2 5 1 6 3 7 
Sample Output 1:
1 
2 3 
4 5 6 7 
Sample Input 2:
6
5 6 2 3 9 10 
2 6 3 9 5 10 
Sample Output 2:
5 
6 10 
2 3 
9 */

BinaryTreeNode<int>* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE) {
	if (inS > inE ||  preS >preE) return NULL;
	int rootData = pre[preS];
    BinaryTreeNode<int>*  root = new BinaryTreeNode<int>(rootData);
	int rootIndex = 0;
	for (int i = inS; i <= inE; i++) {
		if (in[i] == rootData) {
			rootIndex = i;
			break;
		}
	}
	root->left = buildTreeHelper(in, pre,inS,rootIndex-1,preS+1,preS+(rootIndex-inS));    
	root->right = buildTreeHelper(in, pre, rootIndex+1,inE,preS+(rootIndex-inS)+1,preE);
	return root;
}

BinaryTreeNode<int>* buildTree(int* pre,int prelength , int* in , int inlength) {
    int preS=0;
    int preE=prelength-1;
    int inS=0;
    int inE=inlength-1;  
	return buildTreeHelper(in, pre, inS,inE,preS,preE);
}

