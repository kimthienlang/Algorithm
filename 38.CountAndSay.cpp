//Difficulty: MED

#include <bits/stdc++.h>

using namespace std;

string countAndSay(int n) {
    if (n == 1) return "1";
    string s = countAndSay(n - 1);
    s += "#";
    string res = "";
    int i = 0, num = 1;
    while (s[i] != '#') {
        if (s[i] == s[i+1]) {
            num++;
        }else {
            res += ('0' + num);
            res += s[i];
            num = 1;
        }
        i++;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s = countAndSay(4);
    cout << s << endl;
    return 0;
}