#include <bits/stdc++.h>

using namespace std;

bool safeornot(int row,int col,vector<string> &bd,int n){
    int duprow=row;
    int dupcol=col;

    while(row>=0 && col>=0){
        if(bd[row][col]=='Q'){return false;}
        row--;
        col--;
    }
    
    col=dupcol;
    row=duprow;
    while(col>=0){
        if(bd[row][col]=='Q'){return false;}
        col--;
    }
    row=duprow;
    col=dupcol;
    while(row<n && col>=0){
        if(bd[row][col]=='Q'){return false;}
        row++;
        col--;
    }
    return true;
}

void solve(int col,vector<string>&bd,vector<vector<string>> &ans,int n){
    if (col==n){
        ans.push_back(bd);
        return ;
    }
    for (int row=0;row<n;row++){
        if(safeornot(row,col,bd,n)){
            bd[row][col]='Q';
            solve(col+1,bd,ans,n);
            bd[row][col]='.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>>ans;
    vector<string>bd(n);
    string s(n,'.');
    for( int i=0;i<n;i++){
        bd[i]=s;
    }
    solve(0,bd,ans,n);
    return ans;  
}

int main() {
    int n = 4;
    vector<vector<string>> res = solveNQueens(n);
    for (auto r : res) {
        for (auto e : r) cout << e << " ";
        cout << endl;
    }
    return 0;
}