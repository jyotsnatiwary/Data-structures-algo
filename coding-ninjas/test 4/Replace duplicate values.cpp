/*Replace duplicate values
Send Feedback
Given a linked list that contain some random integers from 1 to n with many duplicates. You need to replace each duplicate element that is present in the linked list with the values n+1, n+2, and so on (starting from left to right in given LL).
For eg. if input linked list is
1 3 1 4 4 2 1 -1
updated linked list should be -
1 3 5 4 6 2 7
n in the list is 4, so I have to replace each duplicate from left to right with 4, 5 and so on. In that way, element 1 (which is at index 2) will be replaced by 5, element 4 (which is present at index 4) by 6 and element 1 (which is present at index 6) by 7.
You don't need to print the elements, just update the elements in LL.
Input format :
Linked list elements (separated by space and terminated by-1)
Output Format :
Updated LL elements (separated by space)
Sample Input 1 :
1 3 1 4 4 2 1 -1
Sample Output 1 :
1 3 5 4 6 2 7*/

void changeLL(Node<int>* head) {
    if(head->next==NULL){
        return;
    }
    unordered_map<int, int> mymap; 
  
    Node<int>* temp = head; 
    int maxNum = 0; 
    while (temp) { 
        mymap[temp->data]++; 
        if (maxNum < temp->data) 
            maxNum = temp->data; 
        temp = temp->next; 
    } 
    while (head) {
        if (mymap[head->data] > 1) 
            mymap[head->data] = -1; 

        else if (mymap[head->data] == -1) 
            head->data = ++maxNum; 
  
        head = head->next; 
    }
}
