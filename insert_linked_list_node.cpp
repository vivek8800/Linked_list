#include<iostream>
using namespace std;

class Node
{  
    public:
    
    int data;
    Node* next;     // to store the address of next node
    
    Node()
    {
        this->data=0;
        this->next=nullptr;
    }
    
    Node(int data)
    {
        this->data=data;
        this->next=nullptr;
    }
};

// function to insert data in linked list at head
void insertAtHead(Node* &head, Node* &tail, int data)
{
    // if ll is empty then create 1 node and point head and tail at newNode
    if(head==nullptr)
    {        
        Node* newNode= new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    
    // if ll is not empty then create a newNode 
    Node* newNode= new Node(data);
    
    // Link newNode at head
    newNode->next=head;
    
    // update head with newNode
    head=newNode;
}

// function to insert elements at tail
void insertAtTail(Node* &head, Node* &tail, int data)
{
    // if ll is empty then create 1 node and point head and tail at newNode
    while(head==nullptr)
    {
        Node* newNode = new Node(data);
        tail=newNode;
        head=newNode;
        return;
    }
    
    // if ll is not empty then create a newNode 
    Node* newNode= new Node(data);
    
    // Link newNode at head
    tail->next= newNode;
    
    // update tail with newNode
    tail=newNode;
}

// This function is used to get the length of linked List
int getLength(Node* &head)
{
    // create temperory node
    Node* temp=head;
    int count=0;
    
    // iterate temp till next of temp not equal to null
    while(temp!=nullptr)
    {
        // move node and count that node
        temp=temp->next;
        count++;
    }
    
    return count;
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position)
{
    // if ll is empty then create 1 node and point head and tail at newNode
    while(head==nullptr)
    {
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    
    // insert element at 1st position
    if(position==0)
    {
        insertAtHead(head, tail, data);
        return;
    }
    
    int len=getLength(head);
    
    // insert element at last position
    if(position>=len)
    {
        insertAtTail(head, tail, data);
        return;
    }
    
    // insert element between 1st and last position
    int i=1;
    Node* prev=head;
    
    // find previous
    while(i<position)
    {
        prev=prev->next;
        i++;
    }
    
    // current will be next of previous
    Node* curr=prev->next;
    
    // create a new Node to insert at poistion
    Node* newNode= new Node(data);
    
    // link newNode with current
    newNode->next= curr;
    
    // link previous with newNode
    prev->next=newNode;
}

// function to print linked list
void print(Node* &head)
{
    // create temperory node
    Node* temp=head;
    
    while(temp!=nullptr)
    {
        // print data and move pointer to next node
        cout<<temp->data<<" ";
        temp=temp->next;;
    }
}

int main()
{
    // initially head and tail pointer pointing to null
    Node* head=nullptr;
    Node* tail=nullptr;
    
    // insert elements at head
    insertAtHead(head,tail, 32);
    insertAtHead(head,tail, 34);
    insertAtHead(head,tail, 39);
    insertAtHead(head,tail, 36);
    insertAtHead(head,tail, 38);
    
    // insert elements at tail    
    insertAtTail(head, tail, 40);
    
    // insert elements at any given position
    insertAtPosition(head, tail, 1000, 6);
    
    // print linked list data
    print(head);
 
    return 0;
}