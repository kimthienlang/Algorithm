// Difficulty: Hard

#include <bits/stdc++.h>

using namespace std;

int setup = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

int minPatches(vector<int>& nums, int n) {
    long long miss = 1;
    int res = 0, i = 0;
    int len = nums.size();
    while (miss <= n) {
        if (i < len && nums[i] <= miss){
            miss += nums[i];
            i++;
        }else {
            miss += miss;
            res++;
        }
    }
    return res;
}

int main() {
    vector<vector<int>> testcase;
    int target = 10;
    testcase.push_back({0});
    testcase.push_back({1});
    testcase.push_back({1,2});
    testcase.push_back({1,2,2});
    testcase.push_back({1,2,3,4,5});
    
    for (vector<int> e : testcase){ 
        cout << "testcase: ";
        for (int val : e) {
            cout << val << " ";
        }
        int res = minPatches(e, target);
        cout << "= " << res << endl;
    }
    
    return 0;
}