#include <bits/stdc++.h>

using namespace std;

int lengthOfLastWord(string s) {
    int n = s.size();
    int len = 0;
    int i = n-1;
    while(i>=0 && s[i]==' ') i--;
    while(i>=0 && s[i]!=' '){
        len ++;
        i--;
    }
    return len;
}

int main() {
    string s = "hello world";
    int lengthLW = lengthOfLastWord(s);
    cout << "length of last word \"" << s << "\" is " << lengthLW << endl; 
    return 0;
}