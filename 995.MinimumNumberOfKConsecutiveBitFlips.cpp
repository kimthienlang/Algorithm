//Difficulty: Hard.

#include <bits/stdc++.h>

using namespace std;

int minKBitFlips(vector<int>& nums, int k) {
    int res = 0;
    int sizeNums = nums.size();
    int i = 0;

    while (i < sizeNums) {
        if (nums[i] == 0) {
            res++;
            int j = 0;
            for (; j + i < sizeNums && j < k; ++j) {
                nums[j + i] = !nums[j + i];
            }
            if (j < k) {
                res = -1;
                return res;
            }
        }
        i++;
    }
    return res;       
}

int main() {
    vector<int> nums = {1,1,0};
    int k = 2;
    int res = minKBitFlips(nums, k);

    cout << "res = " << res << endl;
    return 0;
}
/*
3
   1 1 1 1 1 1 1 1 
1. 1 0 0 0 1 0 0 0
2. 1 0 1 1 0 0 0 0
3. 0 1 0 0 1 1 0 0
4. 0 1 0 0 0 0 1 0
---
1. 1 0 1 1 1 1 1 0
2. 1 1 0 0 1 1 1 0
3. 1 1 1 1 0 1 1 0
4. 1 1 1 1 1 0 0 0
5. 1 1 1 1 1 1 1 1
*/