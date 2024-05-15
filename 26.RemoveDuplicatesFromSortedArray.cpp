#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int res = 0;
    int lenNums = nums.size();
    vector<int> newNums = {-101};
    for (int i = 0; i < lenNums; ++i) {
        if (nums[i] != newNums.back()) {
            newNums.push_back(nums[i]);
        }
    }
    newNums.erase(newNums.begin());
    res = newNums.size();
    nums = newNums;
    return res;
}

int main () {
    vector<int> testcase = {1, 1, 2, 2, 2, 3, 4,6};
    int result = removeDuplicates(testcase);
    for (auto x : testcase) {
        cout << x << " ";
    }
    cout << endl;
    cout << "length expected: " << result << endl;
    return 0;
}