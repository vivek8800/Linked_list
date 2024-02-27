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

// function to get middle of linked list
Node* middleNodeusingPointer(Node* &head)
{
    // if either ll is empty or only single node is present
    if(head == nullptr || head->next == nullptr) 
    {
        return head;
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
    }
    
    // Now both fast and slow pointer will point at middle of linked list so return either fast or slow
    return slow;
}

int main()
{
    // initially head and tail pointer pointing to null
    Node* head = nullptr;
    Node* tail = nullptr;
    
    // Create or insert data in linked list
    insertAtHead(head, tail, 60);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    //insertAtHead(head, tail, 100);
    
    cout << "Linked list data is: ";
    print(head);
    cout << endl;
    
    Node* middle = middleNodeusingPointer(head);
    
    if(middle != nullptr) 
    {
        cout << "Middle element of the linked list: " << middle->data << endl;
    }
    
    else 
    {
        cout << "The linked list is empty." << endl;
    }
    
    // cout<<"Middle Node: "<<middleNodeusingPointer(head)->data<<endl;
   
    return 0;
}