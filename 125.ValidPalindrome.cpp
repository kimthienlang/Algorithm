#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s) {
    bool res = true;
    string newS = "";
    for (int i = 0; i < s.length(); ++i) {
        char c = tolower(s[i]);
        if ((int(c) > 96 && int(c) < 123) || (c >= '0' && c <= '9')) newS += c;
    }
    int lenNewS = newS.length();
    int len = lenNewS / 2;
    for (int i = 0; i < len; ++i) {
        if (newS[i] != newS[lenNewS - i - 1]) return false;
    }
    return res;
}

int main() {
    string s = "0P";
    bool palindrome = isPalindrome(s);
    cout << "palindrom : " << palindrome  << endl;
    return 0;
}