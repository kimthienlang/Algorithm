//Difficulty: Med.

#include <bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int rowsMatrix = matrix.size();
    int colsMatrix = matrix[0].size();
    int lenRes = rowsMatrix * colsMatrix;
    if (lenRes == 0) return {};
    vector<int> res;
    int startCol = 0, endCol = colsMatrix - 1;
    int startRow = 0, endRow = rowsMatrix - 1;
    while (true) {
        for (int k = startCol; k <= endCol; ++k) res.push_back(matrix[startRow][k]);
        if (res.size() == lenRes) break;
        startRow++;
        for (int k = startRow; k <= endRow; ++k) res.push_back(matrix[k][endCol]);
        if (res.size() == lenRes) break;
        endCol--;
        for (int k = endCol; k >= startCol; --k) res.push_back(matrix[endRow][k]);
        if (res.size() == lenRes) break;
        endRow--;
        for (int k = endRow; k >= startRow; --k) res.push_back(matrix[k][startCol]);
        startCol++;
        if (res.size() == lenRes) break;
    }
    return res;       
}

int main() {
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> spiralMatrix = spiralOrder(matrix);

    cout << "Spiral matrix: ";
    for (auto& x : spiralMatrix) {
        cout << x << " ";
    }

    return 0;
}