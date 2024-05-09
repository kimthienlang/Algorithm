#include <bits/stdc++.h>

using namespace std;

bool check(vector<vector<int>> &resultA, vector<int> b) {
    bool checkAll = true;
    for(auto x : resultA) {
        bool checkX = true;
        for (int i = 0; i < 4; ++i) {
            if (b[i] == x[i]) {
                checkX = false;
            }else {
                checkX = true; 
                break;
            }
        }

        if (checkX == false) {
            return false;
        }
    }
    return checkAll;
}

void threeSum(vector<vector<int>> &resultA, int index, vector<int> nums, int target) {
    int twoSum = target - nums[index];
    vector<int> result;
    if (nums.size() < 4) return;
    result.push_back(nums[index]);
    sort(nums.begin(), nums.end());

    int lenN = nums.size();
    for (int i = index + 1; i < lenN; ++i){
        int j = i + 1;
        int k = lenN - 1;

        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == twoSum) {
                vector<int> resultT = result;
                resultT.push_back(nums[i]);
                resultT.push_back(nums[j]);
                resultT.push_back(nums[k]);
                j++;
                k--;
                if(check(resultA, resultT))
                    resultA.push_back(resultT);
            } else if (sum < twoSum) {
                j++;
            } else {
                k--;
            }
        }
    }
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int lenNums = nums.size();
    for (int i = 0; i < lenNums; ++i) {
        threeSum(result, i, nums, target);
    }
    return result;       
}

int main() {
    vector<int> testcase = {2, 2, 2, 2, 2}; //sort: -2, -1, 0, 0, 1, 2
    cout << "run 4 sum" << endl;
    vector<vector<int>> result = fourSum(testcase, 8);
    for (auto i : result) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}