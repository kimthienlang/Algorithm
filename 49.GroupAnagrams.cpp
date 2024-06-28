#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> store;
    for (auto x : strs) {
        string saver = x;
        sort(saver.begin(), saver.end());
        store[saver].push_back(x);
    }
    vector<vector<string>> res;
    for (auto item : store) {
        res.push_back(item.second);
    }
    return res;
}

int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> res = groupAnagrams(strs);
    for (auto x : res) {
        for (auto item : x) cout << item << " ";
        cout << endl;
    }
    return 0;
}