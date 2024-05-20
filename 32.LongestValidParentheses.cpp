#include <bits/stdc++.h>

using namespace std;
// (()))
// ((())
// ()(()
// ())()

int longestValidParentheses(string s) {
    int n = s.size();
    if(n == 0)
        return 0;
    vector<int> longestLen(n + 1, 0);
    longestLen[1] = 0;
    int maxLen = 0;
    for(int i = 2; i < n + 1; ++i) {
        if(s[i - 1] == ')' && s[i - 2] == '(') {
            longestLen[i] = longestLen[i - 2] + 2;
        }
        else if(s[i - 1] == ')' && s[i - 2] == ')') {
            int j = i - 2 - longestLen[i - 1];
            if(j >= 0 && s[j] == '(') {
                longestLen[i] = longestLen[j] + longestLen[i - 1] + 2;
            }
            else {
                longestLen[i] = 0;
            }
        }
        maxLen = max(maxLen, longestLen[i]);
    }
    return maxLen;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string testcase = "(()";
    int result = longestValidParentheses(testcase);
    cout << result;
    return 0;
}