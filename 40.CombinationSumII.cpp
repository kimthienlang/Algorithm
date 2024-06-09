#include <bits/stdc++.h>

using namespace std;

void comb(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp, int idx,int target) {
    if(target<0){
        return;
    }
    if(target==0){
        res.push_back(temp);
        return;
    }
    int l=nums.size();
    if(idx==l){
        return;
    }
    // 1 2 2 3
    temp.push_back(nums[idx]);
    comb(nums, res, temp,idx+1,target-nums[idx]);
    temp.pop_back();
    while(idx<nums.size()-1 && nums[idx]==nums[idx+1]) idx++;
    comb(nums, res, temp,idx+1,target);
    
    return;
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int> temp;
    vector<vector<int>> res;
    sort(candidates.begin(),candidates.end());
    comb(candidates, res, temp, 0,target);
    return res;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    
    vector<vector<int>> combinations = combinationSum2(candidates, target);
    for (auto comb : combinations) {
        for (auto e : comb) cout << e << " ";
        cout << endl;
    }
    return 0;
}