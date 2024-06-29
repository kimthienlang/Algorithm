#include <bits/stdc++.h>

using namespace std;

bool canJump(vector<int>& nums) {
    bool res = false;
    int lenNums = nums.size();
    if (lenNums == 1) return true;
    int save = 0;
    for (int i = 0; i < lenNums; ++i) {
        if (nums[i] == 0) break;
        if (i + nums[i] >= lenNums - 1) return true;

        int lenIJ = nums[i] + i + 1;
        int maxJump = nums[i] + i;
        int saveJ = i + 1;
        for (int j = i + 1; j < lenIJ; ++j) 
            if(maxJump < j + nums[j]){
                maxJump = j + nums[j];
                saveJ = j;
            }

        i = saveJ - 1;
        save = i;
    }

    if (save >= lenNums - 1) res = true;
    return res; 
}

int main() {
    vector<int> nums = {3,2,2,0,4};
    bool canCrossTheBridge = canJump(nums);
    if (canCrossTheBridge) cout << "We can pass the bridge !" << endl;
    else cout << "We can NOT pass the bridge !" << endl;
    return 0;
}