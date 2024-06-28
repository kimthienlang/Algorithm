#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    res.push_back({1});
    if (numRows == 1) return res;
    res.push_back({1, 1});
    if (numRows == 2) return res;
    res.push_back({1, 2, 1});
    if (numRows == 3) return res;
    
    for (int i = 3; i < numRows; ++i) {
        vector<int> row;
        row.push_back(1);
        for (int j = 1; j < i; ++j) {
            int num = res[i-1][j-1] + res[i-1][j];
            row.push_back(num);
        } 
        row.push_back(1);
        res.push_back(row);
    }
    return res;
}

int main() {
    int numRows = 5;
    vector<vector<int>> res = generate(numRows);
    for (auto x : res) {
        for (auto i : x) cout << i << " ";
        cout << endl;
    }
    return 0;
}