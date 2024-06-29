//Difficulty: Med.
#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int len = nums.size();
    if (len == 1) return nums[0];

    int res = nums[0];
    vector<int> save;

    save.push_back(nums[0]);

    for (int i = 1; i  < len; ++i) {
        int temp = save[i-1] + nums[i]; 
        if (temp > nums[i]) {
            save.push_back(temp);
            res = max(res, temp);
        } else {
            save.push_back(nums[i]);
            res = max(res, nums[i]);
        }
    }

    return res;
}

int main() {
    vector<int> nums = {5,4,-1,7,8};
    int maxSubTotal = maxSubArray(nums);
    cout << "max is : " << maxSubTotal << endl;
    return 0;
}