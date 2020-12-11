/*Move To Last
Send Feedback
Given a linked list and a key in it, the task is to move all occurrences of given key to end of linked list, keeping order of all other elements same.
Return the updated head of LL.
Input Format :
Line 1 : Elements of the linked list ending with -1 (-1 not included)
Line 2 : Key n, Element which has to shifted
Output Format :
Updated linked list
Constraints :
1 <= size of list <= 100
Sample Input 1:
1 2 2 3 4 5 -1
2
Sample Output 1:
1 3 4 5 2 2 
Sample Input 2:
1 1 2 3 4 -1
1
Sample Output 2:
2 3 4 1 1*/


Node<int>* func(Node<int> *head,int key) {
    node* pCrawl=head;
    node* pKey=head;
    
    while(pCrawl!=NULL){
        if(pCrawl!=pKey && pCrawl->data!=key){
            pKey->data=pCrawl->data;
            pCrawl->data=key;
            pKey=pKey->next;
            
        }
        if(pKey->data!=key) pKey=pKey->next;
        pCrawl=pCrawl->next;
    }
    return head;    
    
}
