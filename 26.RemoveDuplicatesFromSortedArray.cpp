#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int res = 0;
    int lenNums = nums.size();
    int temp = -101;
    for (int i = 0; i < lenNums; ++i) {
        if (nums[i] != temp) {
            temp = nums[i];
            res++;
        }
    }
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