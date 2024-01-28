#include <iostream>
#include <map>
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
};

void InsertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp -> data << endl << " ";
        temp = temp -> next;
    }
    cout << endl;
}

//cycle detection in LL
bool detectLoop(Node* head){
    if(head == NULL){
        return false;
    }
    map<Node*,bool> visited;
    Node* temp = head;
    while(temp != NULL){
        if(visited[temp] == true){
            return true;
        }
        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
}
int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    
    InsertAtHead(head, 20);
    InsertAtHead(head, 30);
    InsertAtHead(head, 40);
    InsertAtHead(head, 50);
    
    tail -> next = head -> next; 

    cout<< "head "<< head -> data <<endl;
    cout<< "tail "<< tail -> data <<endl;

    if(detectLoop(head)){
        cout<< "cycle is present "<<endl;
    }
    else{
        cout<<"cycle is not present "<< endl;
    }
     return 0;
}



