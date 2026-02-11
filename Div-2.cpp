#include <bits/stdc++.h>
using namespace std;
 
long long digitSum(long long n) {
    long long sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
 
int main() {
    int t;
    cin >> t;
    
    while(t--) {
        long long x;
        cin >> x;
        
        int count = 0;
        
        for(long long y = x; y <= x + 90; y++) {
            if(y - digitSum(y) == x) {
                count++;
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}
