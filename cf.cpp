#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        string s = "";
        for (int i = 0; i < n; i++) {
            string left = a[i] + s;  
            string right = s + a[i];  
            if (left < right) s = left;
            else s = right;
        }
        cout << s << "\n";
    }
}