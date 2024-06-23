#include <bits/stdc++.h>

using namespace std;

int longestSubarray(vector<int>& nums, int limit) {
    int res = 1;
    int sizeNums = nums.size();

    if (sizeNums == 1) return 1;
    if (sizeNums == 0) return 0;
    
    vector<int> subArray;
    int count = 1;
    int maxValue = nums[0], minValue = nums[0]; 
    subArray.push_back(nums[0]);

    for (int idx = 1; idx < sizeNums; ++idx) {
        subArray.push_back(nums[idx]);
        count++;

        minValue = min(minValue, nums[idx]);
        maxValue = max(maxValue, nums[idx]);

        bool outLimit = abs(minValue - maxValue); 
        if (outLimit) {
            res = max(count-1, res);
            int sizeSubArray = subArray.size();
            int jdx = sizeSubArray - 2;
            for (; jdx > -1; --jdx) {
                if (abs(subArray[jdx] - subArray[sizeSubArray - 1]) > limit) break;
            }
            subArray.erase(subArray.begin(), subArray.begin() + jdx + 1);
            count -= (jdx + 1);
        }
    }
    res = max(count, res);

    return res;       
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums = {10,1,2,4,7,2};
    int limit = 5;
    int longestSub = longestSubarray(nums, limit);
    cout << "Longest sub array is : " 
    << longestSub << endl;
    return 0;
}