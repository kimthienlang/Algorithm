#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
    if (n == 1) return 1;
    if (n == 2) return 5;
    return solve(n-1) + solve(n-2);
}

int main() {
    int n = 4;
    cout << solve(n) << endl;
}