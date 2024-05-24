#include <bits/stdc++.h>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int first = lower_bound(nums.begin(), nums.end(), target)
                        - nums.begin();
    int last = upper_bound(nums.begin(), nums.end(), target)
                        - nums.begin()-1;
    if (first <= last)
        return {first, last};
    return {-1,-1};
}

int main () {
    ios::sync_with_stdio(false);
    vector<int> testcase = {0, 1, 2, 3, 3, 3, 4, 4, 7, 7, 8, 8};
    int target = 7;
    vector<int> result = searchRange(testcase, target);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}