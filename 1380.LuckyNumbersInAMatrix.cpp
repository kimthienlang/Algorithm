#include <bits/stdc++.h>

using namespace std;

vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    vector<int> res;
    vector<pair<int, int>> minRows;
    vector<pair<int,int>> maxCols;
    int rows = matrix.size(), cols = matrix[0].size();

    for (int j = 0; j < cols; ++j)
        maxCols.push_back(make_pair(j, 0));
    for (int i = 0; i < rows; ++i) {
        minRows.push_back(make_pair(i, matrix[i][0]));
        for (int j = 0; j < cols; ++j) {
            minRows[i].second = min(minRows[i].second, matrix[i][j]);
            maxCols[j].second = max(maxCols[j].second, matrix[i][j]);
        }
    }
    for (pair<int, int> x : minRows) cout << x.first << " : " << x.second << endl;
    cout << endl;
    for (pair<int, int> x : maxCols) cout << x.first << " : " << x.second << endl;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (minRows[i].second == maxCols[j].second) 
                res.push_back(minRows[i].second);
    return res;
}

int main() {
    cout << "Program is running..." << endl;
    vector<vector<int>> matrix = {{1,10,4,2},{9,3,8,7},{15,13,17,12}};
    vector<int> res = luckyNumbers(matrix);
    cout << "lucky number: ";
    for (auto num : res) 
        cout << num << " "; 
    cout << "\nProgram closed!" << endl;
    return 0;
}
