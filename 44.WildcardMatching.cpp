/*
    Difficulty: Hard
    testcase 1: 
    input: s="aa" p="a"
    otput: false
*/

#include <bits/stdc++.h>

using namespace std;

bool isMatch(string s, string p) {
    int m = s.length(), n = p.length();
    int i = 0, j = 0, asterick = -1, match;
    while (i < m) {
        if (j < n && p[j] == '*') {
            match = i;  
            asterick = j++; 
            cout << "match = " << match 
                 << "\tasterick = "<< asterick 
                 << " j = " << j << endl;
        }
        else if (j < n && (s[i] == p[j] || p[j] == '?')) {
            i++;
            j++;
        }
        else if (asterick >= 0) {
            i = ++match;
            j = asterick + 1;
        }
        else return false;
    }
    while (j < n && p[j] == '*') j++;
    return j == n;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s = "abcdef";
    string p = "*?c*f";
    bool res = isMatch(s, p);
    cout << "res = " << res << endl;
    return 0;
}