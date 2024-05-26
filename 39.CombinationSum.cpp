//Difficulty: MED

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> res;

void backtrack (vector<int>& candidates, int target, int idx, int sum, vector<int> temp) {
    int len = candidates.size();
    for (int i = idx; i < len; ++i) {
        temp.push_back(candidates[i]);

        if ((sum + candidates[i]) < target) {
            backtrack(candidates, target, i, sum + candidates[i], temp);
        } else 
        if ((sum + candidates[i]) > target) {
            break;
        } else {
            res.push_back(temp);
        }

        temp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    backtrack(candidates, target, 0, 0, {});
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> testcase = {2,3,6,7};
    int target = 7;
    vector<vector<int>> res = combinationSum(testcase, target);
    for (auto x : res) {
        for (auto y : x) cout << y << " ";
        cout << endl;
    }
    return 0;
}