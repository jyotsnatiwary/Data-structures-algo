/*Dequeue
Send Feedback
You need to implement a class for Dequeue i.e. for double ended queue. In this queue, elements can be inserted and deleted from both the ends.
You don't need to double the capacity.
You need to implement the following functions -
1. constructor
You need to create the appropriate constructor. Size for the queue passed is 10.
2. insertFront -
This function takes an element as input and insert the element at the front of queue. Insert the element only if queue is not full. And if queue is full, print -1 and return.
3. insertRear -
This function takes an element as input and insert the element at the end of queue. Insert the element only if queue is not full. And if queue is full, print -1 and return.
4. deleteFront -
This function removes an element from the front of queue. Print -1 if queue is empty.
5. deleteRear -
This function removes an element from the end of queue. Print -1 if queue is empty.
6. getFront -
Returns the element which is at front of the queue. Return -1 if queue is empty.
7. getRear -
Returns the element which is at end of the queue. Return -1 if queue is empty.
*/

/**********
 
 Following is the main function we are using internally.
 Refer this for completing the Dequeue class.
 
 
 int main()
 {
 Deque dq(10);
 int choice,input;
 while(true) {
 cin >> choice;
 switch (choice) {
 case 1:
 cin >> input;
 dq.insertfront(input);
 break;
 case 2:
 cin >> input;
 dq.insertrear(input);
 break;
 case 3:
 dq.deletefront();
 break;
 case 4:
 dq.deleterear();
 break;
 case 5:
 cout << dq.getFront() << "\n";
 break;
 case 6:
 cout << dq.getRear() << "\n";
 break;
 default:
 return 0;
 }
 }
 
 return 0;
 }
 
 ************/

class Deque {
    // Complete this class
    int* deq;
    int front;
    int rear;
    int si;
    
    public:
    
    Deque(int size){
        deq=new int[size];
        si=size;
        front=-1;
        rear=-1;
    }
    
    void insertFront(int ele){
        
        if(front==-1 && rear==-1)
        {
            front=0;
            rear=0;
            deq[front]=ele;
            return;
        }
        //cout<<"front="<<front<<" rear="<<rear<<endl;
        if((front+1)%si==rear){
            cout<<(-1)<<endl;
            return;
        }
        front=(front+1)%si; 
        deq[front]=ele;
        
    }
    
    void insertRear(int ele){
        if(front==-1 && rear==-1)
        {
            front=0;
            rear=0;
            deq[rear]=ele;
            return;
        }
        //cout<<"front="<<front<<" rear="<<rear<<endl;
        if(front==rear-1 || rear==0 && front==si-1){
            cout<<(-1)<<endl;
            return;
        }
        if(rear==0)
            rear=si-1;
        else
            rear--;
        deq[rear]=ele;
        
    }
    void deleteFront(){
        if(front==-1 && rear==-1){
            cout<<(-1)<<endl;
            return;
        }
        if(rear==front){
            rear=-1;
            front=-1;
            return;
        }
        if(front==0)
            front=si-1;
        else
            front--;
    }
    
    void deleteRear(){
        if(front==-1 && rear==-1){
            cout<<(-1)<<endl;
            return;
        }
        if(rear==front){
            rear=-1;
            front=-1;
            return;
        }
        rear=(rear+1)%si;
    }
    
    int getFront(){
        if(front==-1 && rear==-1){
            return -1;
        }
        return deq[front];
    }
    int getRear(){
        if(front==-1 && rear==-1){
            return -1;
        }
        return deq[rear];
    }    
    
};



