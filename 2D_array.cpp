#include <iostream>
using namespace std;

void row_wise_sum(int arr[3][3], int row, int col){
    
    for(int row=0; row<3; row++){
        int sum = 0;
        for(int col=0; col<3; col++){
            sum += arr[row][col];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
}
void col_wise_sum(int arr[3][3], int row, int col){
    
    for(int col=0; col<3; col++){
        int sum = 0;
        for(int row=0; row<3; row++){
            sum += arr[row][col];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[3][3];
    
    //input
    cout<<"enter the element: "<<endl;
    for (int row = 0; row<3; row++){
        for(int col = 0; col < 3; col++){
            cin>>arr[row][col];
        }
    }
    
    //print
    for (int row = 0; row<3; row++){
        for(int col = 0; col < 3; col++){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
    row_wise_sum(arr, 3, 3);
    col_wise_sum(arr, 3, 3);


    return 0;
}