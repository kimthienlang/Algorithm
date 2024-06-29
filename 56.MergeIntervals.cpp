#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int lenIntervals = intervals.size();
    if (lenIntervals == 1) return intervals;

    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
        return a[0] < b[0];
    });
    
    res.push_back(intervals[0]);
    for (int i = 1; i < lenIntervals; ++i) {
        int lenRes = res.size();
        if (intervals[i][0] <= res[lenRes-1][1]) {
            res[lenRes-1][1] = max(res[lenRes-1][1], intervals[i][1]);
        } else {
            res.push_back(intervals[i]);
        }
    }
    return res;
}

int main() {
    vector<vector<int>> intervals = 
    {
        {1,3},{2,6},{8,10},{15,18}
    };
    vector<vector<int>> mergedIntervals = merge(intervals);

    cout << "RESULT: " << endl;
    for (auto inter : mergedIntervals) {
        cout << inter[0] << " -> " << inter[1] << endl;
    }
    return 0;
}