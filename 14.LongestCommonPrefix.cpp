#include <bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string result = "";
    int lenStrs = strs.size();
    bool run = true;
    int index = 0;

    while(index < strs[0].length() && run) {
        bool checkLetter = true;
        char c = strs[0][index];
        for (int i = 0; i < lenStrs; ++i) {
            int a = strs[i].length();
            
            if (a < index - 1){
                return result;
            }
            if (strs[i][index] != c) {
                checkLetter = false;
                break;
            }
        }
        if (checkLetter == false) {
            run = false;
            break;
        } else {
            result += c;
            index++;
        }
    }
    return result;
}

int main() {
    vector<string> testcase = {"git./lower","git./flow","git./flight","git./fdog","git./fracecar","git./fcar"};
    string result = longestCommonPrefix(testcase);
    cout << result << endl;
    return 0;
}