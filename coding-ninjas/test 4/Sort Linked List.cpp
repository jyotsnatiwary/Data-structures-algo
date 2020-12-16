/*Sort Linked List
Send Feedback
Given a Linked List, which has nodes in alternating ascending and descending orders. Sort the list efficiently and space complexity should be O(1).
You just need to return the head of sorted linked list, don't print the elements.
Input format :
Line 1 : Linked list elements of length L (separated by space and terminated by -1)
Line 2 : Integer n
Output format :
Updated list elements (separated by space)
Sample Input 1 :
10 40 53 30 67 12 89 -1
Sample Output 1 :
10 12 30 40 53 67 89*/


Node<int>* Merge(Node<int>* h1,Node<int>* h2){
  Node<int>* head=NULL;
  Node<int>* tail=NULL;
  while(h1!=NULL&&h2!=NULL){
    if(h1->data>h2->data){
      if(head==NULL){
        head=h2;
        tail=h2;
      }
      else{
        tail->next=h2;
        tail=h2;
      }
      h2=h2->next;
    }
    else{
      if(head==NULL){
        head=h1;
        tail=h1;
      }
      else{
        tail->next=h1;
        tail=h1;
      }
      h1=h1->next;
    }
  }
  while(h1!=NULL){
    tail->next=h1;
    tail=h1;
    h1=h1->next;
  }
  while(h2!=NULL){
    tail->next=h2;
    tail=h2;
    h2=h2->next;
  }
  return head;
}

Node<int>* sort(Node<int>* head)
{ 
    if(head==NULL || head->next==NULL) return head;
    //write your code here
    Node<int>* slow=head;
    Node<int>* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node<int>* second=sort(slow->next);
    slow->next=NULL;
    Node<int>* first=sort(head);
    Node<int>* ans=Merge(first,second);
    return ans;
} 
