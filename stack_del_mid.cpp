#include <iostream>
#include <stack>
using namespace std;
void solve(stack<int>&inputStack, int count, int size){
    if (count==size/2){
        inputStack.pop();
        return;
    }
    int num = inputStack.top();
    inputStack.pop();

    solve(inputStack, count+1, size);

    inputStack.push(num);
}
    void deleteMiddle(stack<int> &inputStack, int N){
    int count = 0;
    solve (inputStack, count, N);
}
int main(){
    // create a stack of integers
    stack<int> inputStack;
    // push some elements into the stack
    inputStack.push(10);
    inputStack.push(20);
    inputStack.push(30);
    inputStack.push(40);
    inputStack.push(50);
    // delete the middle element
    deleteMiddle(inputStack, inputStack.size());
    // print the remaining elements
    cout << "The elements after deleting the middle element are: \n";
    while(!inputStack.empty()){
        cout << inputStack.top() << " ";
        inputStack.pop();
    }
    cout << "\n";
    return 0;
}