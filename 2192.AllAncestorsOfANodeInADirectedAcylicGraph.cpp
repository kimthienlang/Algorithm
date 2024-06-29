#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& adj, vector<vector<int>>& ans, int& parent, int& child) {
    for (auto& ch: adj[child]) {
        if (ans[ch].size() == 0 || ans[ch].back() != parent) {
            ans[ch].push_back(parent);
            dfs(adj,ans,parent,ch);
        }
        
    }
}

vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n), ans(n);

    for (auto& edge: edges) {
        adj[edge[0]].push_back(edge[1]);
    }

    for (int i = 0; i < n; i++) {
        dfs(adj,ans,i,i);
    }
    
    return ans;
}

int main() {
    int n = 8;
    vector<vector<int>> edgeList = {
        {0,7},{7,6},{0,3},{6,3},{5,4},{1,5},{2,7},{3,5},{3,1},{0,5},{7,5},{2,1},{1,4},{6,1}
    };
    vector<vector<int>> ancestorOfAllNode = getAncestors(n, edgeList);
    int sizeAON = ancestorOfAllNode.size();
    for (int i = 0; i < sizeAON; ++i) {
        cout << i << ": ";
        for (auto j : ancestorOfAllNode[i]) cout << j << " ";
        cout << endl;
    }
    return 0;
}