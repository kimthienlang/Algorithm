#include <bits/stdc++.h>

using namespace std;

bool isNumber(string& s) {
    bool res = false;
    s = "123";
    return res;
}

int main() {
    string numString = "000-.123e-2314";
    bool isANumber = isNumber(numString);
    string res = "";
    if (isANumber) res = "is a number :))";
    else res = "is not a number NaN!";
    cout << numString << " " << res << endl;
}