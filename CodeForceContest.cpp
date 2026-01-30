#include<iostream>
using namespace std;
int main(){
int tastes;
cin>> tastes;
while(tastes--){

    string word;
    cin>> word;
    string root=word.substr(0,word.size()-2);
    cout<<root +"i"<<"\n";
}

return 0;

}