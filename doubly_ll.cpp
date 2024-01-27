#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }
    //destructor
    ~Node(){
        int value =  this-> data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
         
    }
};

//traversal
void print(Node* head, Node* tail){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data<<endl;
        temp = temp -> next;
    }
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<< tail->data<<endl;
    cout<<endl;
}

//func for LL length
int getLength(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++ ;
        temp = temp -> next;
    }
    return len;
}

void insertAtHead(Node* &tail, Node* &head, int d){
    //empty list
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
    cout<< endl;
}
   
void insertAtTail(Node* &tail,Node* &head, int d){
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d){
    if(position==1){
        insertAtHead(tail, head, d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp -> next;
        cnt++ ;
    }

    if(temp -> next == NULL){
        insertAtTail(tail,head, d);
        return;
    }
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;

}
void deleteNode(int position, Node* &head ){
    if(position == 1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt<position){
            prev = curr;
            curr = curr -> next;
            cnt++ ;
        }
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(tail, head, 11);
    print(head, tail);
    insertAtHead(tail, head, 12);
    print(head, tail);
    insertAtHead(tail, head, 13);
    print(head, tail);
    insertAtTail(tail,head, 9);
    print(head, tail);
    insertAtPosition(tail, head, 1, 100);
    print(head, tail);
    insertAtPosition(tail, head, 5, 102);
    print(head, tail);
    
    deleteNode(2, head);
    print(head, tail);
    deleteNode(4, head);
    print(head, tail);
    deleteNode(1, head);
    print(head, tail);
    return 0;
}