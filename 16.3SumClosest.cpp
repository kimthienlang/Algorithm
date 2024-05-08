#include <bits/stdc++.h>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int result = INT_MAX;
    int minDiff = INT_MAX;
    int lenNums = nums.size();

    sort(nums.begin(), nums.end()); // -4, -1, 1, 2
    for (int i = 0; i < lenNums; ++i) {
        int anchor = i;
        int left = i + 1;
        int right = lenNums - 1;
        while (left < right) {
            int sum = nums[anchor] + nums[left] + nums[right];
            int diffSumTarget = abs(target - sum);
            if (diffSumTarget < minDiff) {
                minDiff = diffSumTarget;
                result = sum;
            }
            if (sum < target) left++;
            if (sum > target) right--;
            else {
                return sum;
                left++;
                right--;
            }
        }
    }

    return result;
}

int main() {
    vector<int> testcase = {-1, 2, 1, -4};
    int target = 1;
    int result = threeSumClosest(testcase, target);    
    cout << result << endl;
    return 0;
}