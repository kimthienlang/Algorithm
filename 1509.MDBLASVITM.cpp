#include <bits/stdc++.h>

using namespace std;

const char _ = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'y';
}();

int minDifference(vector<int>& nums) {
    int len = nums.size();
    if (len < 5) return 0;
    sort(nums.begin(), nums.end());
    int diff1 = nums[len - 4] - nums[0];
    int diff2 = nums[len - 3] - nums[1];
    int diff3 = nums[len - 2] - nums[2];
    int diff4 = nums[len - 1] - nums[3];
    int min1 = min(diff1, diff2), min2 = min(diff3, diff4);
    int minDiff = min(min1, min2);
    return minDiff;
}

int main() {
    vector<int> nums = {1, 5, 0, 10, 14};
    int minDiff = minDifference(nums);
    cout << "min diff = " << minDiff << endl;
    return 0;
}