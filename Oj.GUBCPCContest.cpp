#include <iostream>
#include <vector>
using namespace std;

string addStrings(string A, string B) {
    while (A.size() < B.size()) A = "0" + A;
    while (B.size() < A.size()) B = "0" + B;

    int carry = 0;
    string result = "";

    for (int i = A.size() - 1; i >= 0; i--) {
        int sum = (A[i] - '0') + (B[i] - '0') + carry;
        carry = sum / 10;
        result = char((sum % 10) + '0') + result; 
    }

    if (carry) result = char(carry + '0') + result;

    return result;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string A, B;
        cin >> A >> B;
        cout << addStrings(A, B) << "\n";
    }
    return 0;
}
