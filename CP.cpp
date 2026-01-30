#include <bits/stdc++.h>
using namespace std;

int main() {

    double x, y, d;
    cin >> x >> y >> d;

    long long ans = (long long)((y - x) / d) - 1;
    if (ans < 0) ans = 0; 
    cout << ans << "\n";

    return 0;
}