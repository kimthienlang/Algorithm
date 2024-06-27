#include <bits/stdc++.h>

using namespace std;


void printMatrix(vector<vector<int>> matrix) {
    for (auto mat : matrix) {
        for (auto e : mat) cout << e << " ";
        cout << endl;
    }
    cout << endl;
}

void rotateNotAllocate(vector<vector<int>> matrix) {
    int row = matrix.size();
        for(int i=0;i<row; i++){
            for(int j=0; j<=i;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0;i<row;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
}

void rotate(vector<vector<int>>& matrix) {
    vector<vector<int>> rtMatrix;
    int lenMatrix = matrix.size();
    int rowIdx = 0;
    while (rowIdx < lenMatrix) {
        vector<int> row;
        for (int i = lenMatrix-1; i > -1; --i) {
            row.push_back(matrix[i][rowIdx]);
        }
        rtMatrix.push_back(row);
        rowIdx++;
    }
    matrix = rtMatrix;
}

int main() {
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    printMatrix(matrix);
    rotate(matrix);
    printMatrix(matrix);
    return 0;
}