

Node *reverseLinkedList(Node *head) 
{
    //write your iterative code here
    Node* prev=NULL;
    Node* next=NULL;
    Node* cur=head;
    while(cur!=NULL){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    return prev;
}
