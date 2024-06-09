#include <bits/stdc++.h>

using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    int res = 0, mp[k];
    memset(mp, 0, sizeof(mp));
    mp[0] = 1;
    int sum = 0;
    for(auto& num : nums)
    {
        sum += num;
        int rem = (sum % k + k) % k;
        res += mp[rem]++;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k = 5;
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int result = subarraysDivByK(nums, k);
    cout << "RESULT: " << result << endl;
    return 0;
}