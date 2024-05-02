#include <bits/stdc++.h>

using namespace std;

bool isMatch (string text, string pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();
    bool board[textLength + 1][patternLength + 1];

    memset(board, false, sizeof(board));
    board[0][0] = true;
        
    for(int i = 0; i <= textLength; i++){
        for(int j = 1; j <= patternLength; j++){
            if(pattern[j-1] == '*'){
                board[i][j] = board[i][j-2] || (i > 0 && (text[i-1] == pattern[j-2] || pattern[j-2] == '.') && board[i-1][j]);
            }
            else{
                board[i][j] = i > 0 && board[i-1][j-1] && (text[i-1] == pattern[j-1] || pattern[j-1] == '.');
            }
        }
    }
    
    return board[textLength][patternLength];
}

int main() {
    string text = "aaaaaaa";
    string pattern = "a...";
    cout << isMatch(text, pattern);
    return 0;
}