/*Insertion Sort(Iteratively) LinkedList
Send Feedback
Sort a given linked list using Insertion Sort (iteratively).
You don't need to print the elements, just sort the elements and return the head of updated LL.
Input format : Linked list elements (separated by space and terminated by -1)`

Sample Input 1 :
1 4 5 2 -1
Sample Output 1 :
1 2 4 5*/


node* insertion_sort_LinkedList_itr(node* head)
{
	if(head==NULL)
	{
		return head;
	}
	node*curr=head->next;
	node*prev=head;
	while(curr!=NULL)
	{
		int k=0;
		node* temp=head,*p=head;
		while(temp!=curr){
			if(curr->data<temp->data){
				node*t=curr->next;
				if(temp==head)
				{
					head=curr;
					prev->next=t;
					curr->next=temp;
					curr=t;
				}
				else{
					p->next=curr;
					curr->next=temp;
					prev->next=t;
					curr=t;
				}
				k=1;
				break;
			}
		else{
			p=temp;
			temp=temp->next;
		}
	}
	if(k==0)
	{
		prev=curr;
		curr=curr->next;
	}
	}
    return head;
}
