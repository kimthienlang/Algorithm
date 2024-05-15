#include <bits/stdc++.h>

using namespace std;

int strStr(string haystack, string needle) {
    int res = -1;
    int lenH = haystack.length();
    int lenN = needle.length();
    int i = 0, j = 0;
    while (i < lenH) {
        if (haystack[i] == needle[j]) {
            i++;
            j++;
            if (j == lenN) {
                res = i - lenN;
                return res;
            }
        }else {
            i = i - j + 1;
            j = 0;
        }
    }
    return res;
}

int main () {
    int index = strStr("leetcode", "leeto");
    cout << index << endl;
    return 0;
}