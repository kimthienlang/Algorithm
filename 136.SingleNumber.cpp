#include <bits/stdc++.h>

using namespace std;

int singleNumber(vector<int>& nums) {
    if (nums.size() == 1) return nums.front();
    int res = -1;
    sort(nums.begin(), nums.end());
    int lenNums = nums.size();
    if (nums[0] != nums[1]) return nums[0];
    for (int i = 3; i < lenNums; i+= 2) {
        if (nums[i] != nums[i-1]) return nums[i-1];
    }
    if (res == -1) res = nums[lenNums - 1];
    return res;
}
int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    int singleNum = singleNumber(nums);
    cout << "single number is " << singleNum << endl;
    return 0;
}