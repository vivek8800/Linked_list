#include<iostream>
using namespace std;

class Node
{
    public:
    
    int data;
    Node* next;
    
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

// function to check whether given linked list is circular or not using two  pointer approach
bool isCircular(Node* &head)
{
    // if no node is present then return false
    if(head==nullptr)
    {
        cout<<"LL is empty"<<endl;
        return false;
    }
    
    // Create fast and slow pointer
    Node* slow = head;
    Node* fast = head->next;

    // Move fast pointer two steps and slow pointer one step at a time
    // When fast reaches the end of the list, slow will be at the middle
    
    // check that fast should not be null
    while(fast != nullptr ) 
    {
        // move fast to 1 step and again check for null
        fast = fast->next;
        
        // if fast not null then move fast 1 step and slow 1 step
        if(fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        // slow meets with fast if true then loop present
        if(slow==fast)
        {
            return true;
        }
    }
    
    // fast null ho gaya, means loop nahi hai
    return false;
}

// function to check whether given linked list is circular or not using iterative approach
bool isLoopPresent(struct Node *head)
{
    // create a temperory node which points to head of linked list
     Node* temp=head;
     
    // if no node is present then return false
     if(head==nullptr)
     {
         return false;
     }
     
    while(temp!=NULL)
    { 
        //if temp points to head then it has completed a circle,thus a circular linked list.
        if(temp->next==head)
        {
            return true;
        }
        
        // increase the position of temp till temp not equal to null.
        temp=temp->next;
    }
    
    return false;
}

int main()
{
    
    Node* head= new Node(10);
    Node* second= new Node(20);
    Node* third= new Node(30);
    Node* fourth= new Node(40);
    Node* fifth= new Node(50);
    Node* sixth= new Node(60);
    
    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=head;
    second->next=head;

    
    // print(head);
    // Note: as loop is present so if you call print function, then printing will be infinite.
    
    bool ans1= isCircular(head);
    
    if(ans1)
    {
        cout<<endl<<"LL is circular"<<endl;
    }
    
    else
    {
        cout<<endl<<"LL is not circular"<<endl;
    }
    
    // ************Another approach***********
    
    bool ans2= isLoopPresent(head);
    
    if(ans2)
    {
        cout<<endl<<"LL is circular"<<endl;
    }
    
    else
    {
        cout<<endl<<"LL is not circular"<<endl;
    }
    
    return 0;
}


