#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    //destructor
    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout<<"memory is free for node with data "<<value <<endl;
    }
};

void InsertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void InsertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;

}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp -> data << endl << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void InsertAtPosition(Node* &head , int position, int d){
    
if(position == 1){
    InsertAtHead(head, d);
    return;
}
    Node* temp = head;
    int cnt = 1;
    while(cnt < position - 1){
        temp = temp -> next;
        cnt++;
    }
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void deleteNode(int position, Node* &head){
    //start node
    if(position==1){
        Node* temp = head;
        head = head -> next;
        
        //memoryfree
        temp -> next = NULL;
        delete temp;
    }

    //dleteing any middle or last node
    else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while (cnt < position){
        prev = curr;
        curr = curr -> next;
        cnt++;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;

    } 

         
}

int main(){
    
    Node* node1 = new Node(10);
    // cout<<node1->data<<endl << " ";
    // cout<<node1->next<<endl;
    
    Node* head = node1;
    Node* tail = node1;

    InsertAtTail(head, 20);
    
    InsertAtTail(head, 30);

    InsertAtPosition(head, 1, 40);

    cout<< "head "<< head -> data <<endl;
    cout<< "tail "<< tail -> data <<endl;

    deleteNode(1, head);
    cout<<"new head is "<< head -> data<<endl;

    
    return 0;
}
