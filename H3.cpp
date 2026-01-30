 #include<iostream>
 #include<map>
    using namespace std;
int main() {
    map<string,int> m;
    string key;
    int value;
    cout << "Enter key-value pairs (key value), type 'exit' to stop:\n";
    for(int i=0; i<3; i++){
        cin>>key>>value;
        m[key]=value;
    }
    cout << "The Output is:\n";
    for(auto i:m){
        cout << i.first << " : " << i.second << "\n";

    }

    return 0;




}