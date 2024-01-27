#include <iostream>
using namespace std;

void printArray(int arr[], int size){
    for(int i=0; i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"printing the array"<<endl;
}
int main(){
    int array[15] = {2,7};
    int n = 15;
    printArray(array, 15);
    cout<<endl;

    int array2[20] = {2,4,5,6,7,8,9,78,89,56};
    printArray(array2, 20);
}