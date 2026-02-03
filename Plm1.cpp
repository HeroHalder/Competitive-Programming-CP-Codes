#include <iostream>
#include<cmath>
using namespace std;
int main() {
    int n,x;
    cin>>n>>x;
    double f=double(n)/(90+x);
    int c=ceil(f);
    cout<<c;

    return 0;
}