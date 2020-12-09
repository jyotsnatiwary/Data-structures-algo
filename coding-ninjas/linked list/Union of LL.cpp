/*Union of LL
Send Feedback
Given a two Linked Lists, find out union of both given input lists and return the new Linked List.
Order of elements are not important.
Note : You don't need to print the linked list, just return the head. It will be printed internally.
Input format :

Line 1 : Linked list 1 elements (separated by space and terminated by -1)

Line 2 : Linked list 2 elements (separated by space and terminated by -1)

Sample Input 1 :
1 2 3 4 -1
8 7 5 3 -1
Sample Output 1 :
1
2
3
4
8
7
5
Sample Input 2 :
1 2 1 1 -1
8 -1
Sample Output 2 :
1
2
1
1
8*/

ListNode<int> *merge2LinkedLists(ListNode<int> *head1, ListNode<int> *head2) {
    ListNode<int> *temp,*head=new ListNode<int>(0); 
    temp=head;
    while(head1!=NULL&&head2!=NULL) { 
        if(head1->data<head2->data) {
            head->next=head1;
            head1=head1->next;
        } 
        else {
            head->next=head2; 
            head2=head2->next;
        }
        head=head->next;
    } 
    if(head1==NULL) {
        head->next=head2;
    } 
    if(head2==NULL) {
        head->next=head1;
    } 
    return temp->next;
} 
ListNode<int> *sortList(ListNode<int> *head) {
    if(head==NULL||head->next==NULL) 
    	return head; 
    ListNode<int> *slow =head,*fast=head,*mid=head,*head1,*head2;
    while(fast!=NULL&&fast->next!=NULL) { 
        mid=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(fast!=NULL)
    {
        mid=slow; 
    }
    head1=head;
    head2=mid->next;
    mid->next=NULL; 
	head1=sortList(head1);
    head2=sortList(head2); 
    head=merge2LinkedLists(head1,head2);
    return head;
}
ListNode<int> *unionOf2LL(ListNode<int> *head1,ListNode<int> *head2) { 
    head1=sortList(head1); 
    head2=sortList(head2);
    ListNode<int> *head=new ListNode<int>(0),*temp;
    temp=head;
    while(head1!=NULL&&head2!=NULL) {
        if(head1->data<head2->data) { 
            temp->next=head1;
            head1=head1->next;
        } 
        else if(head1->data>head2->data) {
            temp->next=head2;
            head2=head2->next;
        } 
        else { 
            temp->next=head1;
            head1=head1->next;
            head2=head2->next;
        } temp=temp->next; } if(head1!=NULL) { temp->next=head1; } if(head2!=NULL) { temp->next=head2; } return head->next; }
