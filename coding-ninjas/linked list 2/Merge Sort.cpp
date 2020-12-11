/*Code: Merge Sort
Send Feedback
 Given a singly linked list of integers, sort it using 'Merge Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 
 Sample Output 2 :
2
-1
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90 */

node* merge(node *head1, node *head2) {
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    node* fh=NULL;
    node* ft=NULL;
    
    while(head1!=NULL && head2!=NULL){
        if(head1->data<=head2->data){
            if(fh==NULL){
                fh=head1;
                ft=head1;
            }else{
               ft->next=head1;
                ft=head1;
            }
            head1=head1->next;
        }else{
            if(fh==NULL){
                fh=head2;
                ft=head2;
            }else{
                ft->next=head2;
                ft=head2;
            }
            head2=head2->next;
        }
        
    }
    
    while(head1!=NULL){
        ft->next=head1;
        ft=head1;
        head1=head1->next;
    }
    
    while(head2!=NULL){
        ft->next=head2;
        ft=head2;
        head2=head2->next;
    }
    
    return fh;
}

node* mergeSort(node *head) {
    if(head==NULL || head->next==NULL) return head;
    //write your code here
    node* slow=head;
    node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    node* second=mergeSort(slow->next);
    slow->next=NULL;
    node* first=mergeSort(head);
    node* ans=merge(first,second);
    return ans;
}
