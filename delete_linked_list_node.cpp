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
    
    ~Node()
    {
        cout<<"deleted element is: "<<data<<endl;
    }
};

// function to insert data in linked list at head
void insertAtHead(Node* &head, Node* &tail, int data)
{
    if(head==nullptr)
    {
        // if ll is empty then create 1 node and point head and tail at newNode
        Node* newNode= new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    
    // if ll is not empty then create a newNode 
    Node* newNode= new Node(data);
    
    // Attach newNode at head
    newNode->next=head;
    
    // update head with newNode
    head=newNode;
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

// function to delete a node at any position
void deleteNode(Node* &head, Node* &tail, int position)
{
    if(head==nullptr)
    {
        cout<<"LL is empty, Can't delete node"<<endl;
        return;
    }
    
    // delete element at 1st position
    if(position==1)
    {
        // create temperory node
        Node* temp=head;
        
        // move head to next of head so that head can be deleted
        head=head->next;
        
        // now temp or previously head point to null
        temp->next=nullptr;
        
        // temp is isolated, can be deleted
        delete temp;
        
        return;
    }
    
    // length of linked list
    int len=getLength(head);
    
    // delete element at last position
    if(position==len)
    {
        // find previous
        int i=1;
        
        Node*prev=head;
        
        while(i<position-1)
        {
            prev=prev->next;
            i++;
        }
        
        // previous will be our tail so it should point to null
        prev->next= nullptr;
        
        // create temperory node
        Node* temp=tail;
        
        // move/update tail to previous
        tail=prev;
        
        // now temp(previously tail) is isolated, you can delete
        delete temp;
        
        return;
    }
    
    // delete element between 1st node and last node
    int i=1;
    Node* prev=head;
        
    // find previous
    while(i<position-1)
    {
        prev=prev->next;
        i++;
    }
        
    // current will be next of previous
    Node* curr= prev->next;
    
    // link next of previous to next of current
    prev->next= curr->next;
        
    // need to delete current, now current is isolated
    curr->next=nullptr;
    
    // delete current  
    delete curr;
        
    return;
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

    // insert data at head of linked list
    insertAtHead(head,tail, 32);
    insertAtHead(head,tail, 34);
    insertAtHead(head,tail, 39);
    insertAtHead(head,tail, 36);
    insertAtHead(head,tail, 38);
    
    // delete a node
    deleteNode(head, tail, 5);
    
    // print linked list
    print(head);
    
    return 0;
}


