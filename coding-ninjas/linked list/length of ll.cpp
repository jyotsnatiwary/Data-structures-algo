/*Given a linked list, find and return the length of input LL. Do it iteratively.
Input format :
Linked list elements (separated by space and terminated by -1)
Output format :
Length of LL
Sample Input :
3 4 5 2 6 1 9 -1
Sample Output :
7*/


int length(Node *head) {
    int count=0;
    Node* temp=head;
    while (temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}




