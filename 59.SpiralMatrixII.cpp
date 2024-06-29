#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 1));
    if (n == 1) return res;
    int count = 0, maxCount = n * n;
    int startRow = 0, endRow = n - 1;
    int startCol = 0, endCol = n - 1;
    while (count < maxCount) {
        for (int k = startCol; k <= endCol; k++) res[startRow][k] = ++count;
        startRow++;
        if (count == maxCount) break;

        for (int k = startRow; k <= endRow; k++) res[k][endRow] = ++count;
        endCol--;
        if (count == maxCount) break;

        for (int k = endCol; k >= startCol; k--) res[endRow][k] = ++count;
        endRow--;
        if (count == maxCount) break;

        for (int k = endRow; k >= startRow; k--) res[k][startCol] = ++count;
        startCol++;
    }
    return res;
}

int main() {
    int n = 5;
    vector<vector<int>> spiralMatrix = generateMatrix(n);
    for (auto spi : spiralMatrix) {
        for (auto v : spi) cout << v << " ";
        cout << endl;
    }
    return 0;
}