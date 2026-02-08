#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, w;
        cin >> n >> w;

        // maximum boards that can be removed
        long long ans = n - (n / w);
        cout << ans << '\n';
    }

    return 0;
}
