#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(int x) {
    if (x < 0) return false;
    long long x1 = x, x2 = 0;
    while(x > 0) {
        x2 = x2 * 10 + (x % 10);
        x /= 10;
    }
    if (x2 == x1) return true;
    return false;
}

int main() {
    int input = 11234211;
    cout << input << " isPalindrome : " << isPalindrome(input) << endl;
    return 0;
}