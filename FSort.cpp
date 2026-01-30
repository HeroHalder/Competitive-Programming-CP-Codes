#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    srand(time(0));
    string name1, name2;
    cout<<"Enter Your Name: ";
    cin>> name1;
    cout<<"Enter Your Crush name: ";
    cin>> name2;

    cout<<"Calculating Love Percentage......\n";
    int Love = rand() % 101;
    cout<<name2 << " Loves " << name1 << " = " << Love << "%\n";
    if(Love < 50){
        cout << "Oof... Friendzone Alert!\n"; 
    }
    else{
        cout<<"Congrats! Wedding Bells Soon!!\n";
    }
    return 0;
}