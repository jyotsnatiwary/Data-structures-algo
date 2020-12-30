/*Second Largest Element In Tree
Send Feedback
Given a generic tree, find and return the node with second largest value in given tree. Return NULL if no node with required value is present.
Input format :
Elements in level order form separated by space (as per done in class). Order is - 

Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
Output format:
Second Largest node data
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40*/


template <typename T>
class SecondLargestReturnType {
public :
TreeNode<T> *largest;
TreeNode<T> *secondLargest;
SecondLargestReturnType(TreeNode<T> *first, TreeNode<T> *second) {
this -> largest = first;
this -> secondLargest = second;
}
};
SecondLargestReturnType<int>* secondLargestHelper(TreeNode<int> *root) {
if(root == NULL) {
SecondLargestReturnType<int> *ans = new SecondLargestReturnType<int>(NULL,
NULL);
return ans;
}
SecondLargestReturnType<int> *ans = new SecondLargestReturnType<int>(root, NULL);
for(int i = 0; i < root -> numChildren(); i++) {
SecondLargestReturnType<int> *childAns = secondLargestHelper(root ->
getChild(i));
if(childAns -> largest -> data > ans -> largest -> data ) {
if(childAns -> secondLargest == NULL) {
ans -> secondLargest = ans -> largest;
ans -> largest = childAns -> largest;
}
else {
if(childAns -> secondLargest -> data > ans -> largest ->
data) {
ans -> secondLargest = childAns -> secondLargest;
ans -> largest = childAns -> largest;
}
else {
ans -> secondLargest = ans -> largest;
ans -> largest = childAns -> largest;
}
}
}
else if (ans -> largest -> data == childAns -> largest -> data && childAns
-> secondLargest != NULL) {
ans -> secondLargest = childAns -> secondLargest;
}
else if(ans -> largest -> data != childAns -> largest -> data && (ans ->
secondLargest == NULL || childAns -> largest -> data > ans -> secondLargest -> data)) {
ans->secondLargest = childAns -> largest;
}
}
return ans;
}
TreeNode <int>* secondLargest(TreeNode<int> *root) {
return secondLargestHelper(root) -> secondLargest;
}
