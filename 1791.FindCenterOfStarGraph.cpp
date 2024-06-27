#include <bits/stdc++.h>

using namespace std;

int findCenter(vector<vector<int>>& edges) {
    int sizeEdges = edges.size();
    if (sizeEdges == 1) return edges[0][0];
    int number1 = edges[0][0];
    int number2 = edges[0][1];
    int center = number1;
    vector<int> edge = edges[1];
    if (center == edge[0] || center == edge[1]) {
        return center;
    }
    return  number2;
}

int main () {
    vector<vector<int>> edges = {{1,2},{5,1},{1,3},{1,4}};
    int center = findCenter(edges);
    cout << "center: " << center << endl;
    return 0;
}