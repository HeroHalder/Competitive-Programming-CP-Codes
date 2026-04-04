#include <bits/stdc++.h>
using namespace std;

int main() {
int n;
cin>>n;
int a1=n%10;
int a2=n/10;
if (a2>=a1)
    cout<<n*(a2+1);
else
 cout<<-1;
return 0;
}