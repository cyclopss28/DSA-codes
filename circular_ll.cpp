#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }
    //destructor
    ~Node(){
        int value = this -> data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory free for node with data "<< value<<endl;
    }
};

// in circular LL head pointer is not needed
void insertNode(Node* &tail, int element, int d){
    //asssuming that the element is present in the list
    //empty list
    if(tail == NULL){
       Node* newNode = new Node(d);
       tail = newNode;
       newNode->next = newNode;
    }
    else{
      //non empty list
        Node* curr = tail;
        while(curr -> data != element){
            curr = curr -> next;
        }
        //element found -> curr is repre.. element wala node
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}

void print(Node* tail){
    Node* temp = tail;
    if (tail == NULL){
        cout<<"list is empty "<<endl;
        return;
    }
    
    do{
        cout<< tail -> data <<" ";
        tail = tail -> next;
    }while(tail != temp);
    cout<<endl;
}

void deleteNode(Node* &tail, int value){
    //for empty list
    if( tail == NULL){
      cout<<"list is empty pls check again "<<endl;  
    }
    else{
    //for non empty list

    Node* prev = tail;
    Node* curr = prev -> next;
    while (curr->data != value){
        prev = curr;
        curr = curr -> next;
    }
    prev -> next = curr -> next;
    
    //1 node LL
    if(curr == prev){
        tail = NULL;
    }
    // >=2 node LL
    else if(tail == curr){
        tail = prev;
    }
    curr -> next = NULL;
    delete curr;
    }

}

int main(){
    
    Node* tail = NULL;
    //inserting in empty list
    insertNode(tail, 5, 3);
    print(tail);
    insertNode(tail, 3, 5);
    print(tail);
    /* insertNode(tail, 5, 7);
    print(tail);
    insertNode(tail, 7, 9);
    print(tail);
    insertNode(tail, 5, 6);
    print(tail);
    insertNode(tail, 9, 10);
    print(tail);

    deleteNode(tail, 3);
    print(tail);
    deleteNode(tail, 10);
    print(tail); */
    deleteNode(tail, 3);
    print(tail);
    
    return 0;
}