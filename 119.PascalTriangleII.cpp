#include <bits/stdc++.h>

using namespace std;

vector<int> getRow(int numRows) {
    vector<vector<int>> res;

    res.push_back({1});
    if (numRows == 0) return res[0];

    res.push_back({1, 1});
    if (numRows == 1) return res[1];

    res.push_back({1, 2, 1});
    if (numRows == 2) return res[2];
    
    for (int i = 3; i <= numRows; ++i) {
        vector<int> row;
        row.push_back(1);
        for (int j = 1; j < i; ++j) {
            int num = res[i-1][j-1] + res[i-1][j];
            row.push_back(num);
        } 
        row.push_back(1);
        res.push_back(row);
    }
    return res[res.size()-1];
}

int main() {
    int numRows = 3;
    vector<int> res = getRow(numRows);
    for (auto i : res) {
        cout << i << " ";
    }
    return 0;
}