#include <bits/stdc++.h>

using namespace std;

int divide(int dividend, int divisor) {
    int result = 0;
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    result = dividend / divisor;
    return result;
}
/*
2
10 3
7 -3
*/
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dividend = -2147483648, divisor = -1;
    int result = divide(dividend, divisor);
    cout << result << endl;

    return 0;
}