#include<iostream>
#include<set>
using namespace std;
int main(){
set<int> s;
int x, y, z;
cout << "Enter three input: ";
cin >> x >> y >> z;
s.insert(x);
s.insert(y);
s.insert(z);
cout << "The Output is: ";
for(int i : s)
    cout << i << "\n";
    s.erase(s.find(x));
cout << "After erasing the first element, the output is: ";
for(int i : s)
    cout << i << "\n";
    cout<< "The count : "<<s.count(x)<<"\n";
    return 0;



}