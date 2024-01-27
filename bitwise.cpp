#include <iostream>;
using namespace std;
int main(){
    int a = 3;
    int b = 4;
    cout<<"a&b AND is  "<< (a&b) << endl;
    cout<<"a|b OR is  "<< (a|b) << endl;
    cout<<"~b NOT is  "<< ~b << endl;
    cout<<"a^b ZOR is  "<< (a^b) << endl;

// left shift
cout<<"left shift 9<<2 "<<(9<<2)<<endl;
cout<<"left shift 2<<1 "<<(2<<1)<<endl;
//right shift
cout<<"right shift 3>>1 "<<(3>>1)<<endl;
cout<<"right shift 4>>1 "<<(4>>1)<<endl;



}