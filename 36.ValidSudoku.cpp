// Difficulty: Med
#include <bits/stdc++.h>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    const int num = 9;
    bool row[num][num] = {false};
    bool col[num][num] = {false};
    bool subGrid[num][num] = {false};
    
    for(int r = 0; r < num; ++r){
        for(int c = 0; c < num; ++c){
            if(board[r][c] == '.')
                continue; 
            
            int idx = board[r][c] - '0' - 1;
            int gridNum = (r/3) * 3 + (c/3);
            
            if(row[r][idx] || col[c][idx] || subGrid[gridNum][idx]){
                return false; 
            }
            
            row[r][idx] = true;
            col[c][idx] = true;
            subGrid[gridNum][idx] = true;
        }
    }
    return true; 
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<char>> testcase = {{'5','3','.','.','7','.','.','.','.'}
                                    ,{'6','.','.','1','9','5','.','.','.'}
                                    ,{'.','9','8','.','.','.','.','6','.'}
                                    ,{'8','.','.','.','6','.','.','.','3'}
                                    ,{'4','.','.','8','.','3','.','.','1'}
                                    ,{'7','.','.','.','2','.','.','.','6'}
                                    ,{'.','6','.','.','.','.','2','8','.'}
                                    ,{'.','.','.','4','1','9','.','.','5'}
                                    ,{'.','.','.','.','8','.','.','7','9'}};
    //Expect: True
    bool result = isValidSudoku(testcase);
    cout << "Result: " << result << endl;
    return 0;
}
