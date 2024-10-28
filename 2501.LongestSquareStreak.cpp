#include <bits/stdc++.h>

using namespace std;

int longestSquareStreak(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int res = -1;
    map<int, int> mp;
    for (int num: nums) 
    {
        int _sqrt = sqrt(num);
        if (_sqrt*_sqrt == num && mp.find(_sqrt) != mp.end()) {
            mp[num] = mp[_sqrt]+1;
            res = max(mp[num], res);
        } else mp[num] = 1;
    }
    return res;
}

int main() {
    vector<int> nums = {4,3,6,16,8,2};
    
    int result = longestSquareStreak(nums);
    cout << "\nResult = " << result << endl;
    return 0;
}