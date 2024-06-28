#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maximumImportance(int n, vector<vector<int>>& roads) {
    int lenRoads = roads.size();
    long long res = 0;

    vector<pair<int, int>> pairs;
    
    for (int i = 0; i < n; ++i) pairs.push_back(make_pair(i, 0));
    for (int i = 0; i < lenRoads; ++i) {
        pairs[roads[i][0]].second++;
        pairs[roads[i][1]].second++;
    }

    sort(pairs.begin(), pairs.end(), [](const auto& l, const auto& r) {
        return l.second > r.second;
    });

    for (int i = 0; i < pairs.size(); ++i) {
        res += ((long long)n * pairs[i].second);
        n--;
    }
    return res;
}

int main() {
    vector<vector<int>> roads = {{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}};
    int res = maximumImportance(5, roads);
    cout << "RES = " << res << endl;
    return 0;
}