//Daily challenge
//Difficulty: Med.

#include <bits/stdc++.h>

using namespace std;

int equalSubstring (string s, string t, int maxCost) {
    int res = 0;
    int len_s = s.length();
    int max_length = 0;
    vector<int> store;

    store.push_back(0);
    for (int i = 0; i < len_s; ++i) {
        int val = abs(s[i] - t[i]);
        store.push_back(val);
    }
    store.push_back(999999);

    int len_store = store.size();
    for (int i = 1; i < len_store; ++i) {
        int sum = 0;
        int j = i;
        int length = 0;
        while (j < len_store && sum <= maxCost) {
            sum += store[j];
            j++;
            length++;
        }
        length--;
        max_length = max(length, max_length);
    }
    res = max_length;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string testcase_s[] = {
        "abcd",
        "abcd",
        "abcd",
        "krpgjbjjznpzdfy"
    };
    string testcase_t[] = {
        "bcdf",
        "cdef",
        "acde",
        "nxargkbydxmsgby"
    };
    int maxCosts [] = {3, 3, 0, 14};
    int len = sizeof(testcase_s) / sizeof(testcase_s[0]);
    for (int i = 0; i < len;++i)  {
        int result = equalSubstring(testcase_s[i], testcase_t[i], maxCosts[i]);
        cout << result << endl;
    }
    return 0;
}