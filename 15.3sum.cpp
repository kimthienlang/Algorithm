#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {

    int twoSum = 0;
    set<vector<int>> s;
    vector<vector<int>> result;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i){
        int j = i + 1;
        int k = nums.size() - 1;

        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == twoSum) {
                s.insert({nums[i], nums[j], nums[k]});
                j++;
                k--;
            } else if (sum < twoSum) {
                j++;
            } else {
                k--;
            }
        }
    }
    for(auto triplets : s)
        result.push_back(triplets);
    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}