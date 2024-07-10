#include <bits/stdc++.h>

using namespace std;

const int _ = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return 1;
}();

int minPathSum(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    for (int i = 1; i < cols; ++i)
        grid[0][i] += grid[0][i-1];
    for (int i = 1; i < rows; ++i) 
        grid[i][0] += grid[i-1][0];
    
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j)
        {
            grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
        }
    }

    return grid[rows-1][cols-1];
}

int main() {
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    int minimumPathSum = minPathSum(grid);
    cout << "Minimum path sum = " << minimumPathSum << endl;
    return 0;
}