/*Print diagonal
Send Feedback
Given a binary tree, print all the diagonal elements in a binary tree belonging to same line with slope equal to -1.
For eg.
Alt text

Input format :
Elements in level order form (separated by space) 
(If any node does not have left or right child, take -1 in its place) 
Output Format :
Elements are printed diagonally,(separated by space). Each diagonal level in new line.
Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1 
Sample Output 1:
8 10 14
3 6 7 13
1 4*/

void diagonalPrintUtil(BinaryTreeNode<int>* root, int d,
                map<int, vector<int>> &diagonalPrint)
{
    // Base case
    if (!root)
        return;
 
    // Store all nodes of same 
    // line together as a vector
    diagonalPrint[d].push_back(root->data);
 
    // Increase the vertical 
    // distance if left child
    diagonalPrintUtil(root->left, 
                      d + 1, diagonalPrint);
 
    // Vertical distance remains 
    // same for right child
    diagonalPrintUtil(root->right, 
                         d, diagonalPrint);
}
void PrintDiagonal(BinaryTreeNode<int>* root) {
	// Don't write main().
	// Write your code here.
    map<int, vector<int> > diagonalPrint;
    diagonalPrintUtil(root, 0, diagonalPrint);
 
    //cout << "Diagonal Traversal of binary tree : \n";
    for (auto it :diagonalPrint)
    {
        vector<int> v=it.second;
        for(auto it:v)
          cout<<it<<" ";
        cout<<endl;
    }
}


