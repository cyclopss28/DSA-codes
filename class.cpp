#include <iostream>
using namespace std;
class Hero{
    public:
    int Health;
    char Level;

    //constructor
    Hero(){
        cout<<"Constructor Called"<<endl;
    }

    void print(){
        cout<< Level <<endl;
    }

    int getHealth(){
        return Health;
    }

    int getLevel(){
        return Level;
    }

    void setHealth(int h){
        Health = h;
    }

    void setLevel(char ch){
        Level = ch;
    }
};
    
int main(){
    //static
    Hero a;
    a.setHealth(70);
    a.setLevel('A');
    cout<<"level is "<< a.Level<<endl;
    cout<<"Health is "<< a.getHealth()<<endl;
    
    //dynamically
    Hero *b = new Hero;
    (*b).setHealth(100);
    (*b).setLevel('B');
    cout<<"level is "<< (*b).Level<<endl;
    cout<<"Health is "<< (*b).getHealth()<<endl;


    return 0;
}