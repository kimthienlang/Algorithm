#include <bits/stdc++.h>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    if (target > nums[n - 1]) {
        return n;
    }
    if (target <= nums[0]) {
        return 0;
    }
    int r = 0;
    int l = n - 1;
    int mid = 0;
    while (r < l) {
        mid = (r + l) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] < target) {
            r = mid + 1;
        } else {
            l = mid - 1;
        }
    }
    if (target <= nums[l]) {
        return l;
    } else {
        return l + 1;
    }
}

int main() {
    vector<int> testcase = {2, 4, 5, 9, 10, 11, 23};
    int target = 10;
    int result = searchInsert(testcase, target);
    cout << "List nums: ";
    for (auto x : testcase) cout << x << " ";
    cout << endl;
    cout << "Target: " << target << endl;
    cout << "Position of target: " << result << endl;
    return 0;
}