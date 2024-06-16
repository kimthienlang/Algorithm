//Difficulty: Med.

#include <bits/stdc++.h>

using namespace std;
int speedUp = []
{std::ios::sync_with_stdio(0); std::cin.tie(0); return 0; }();
bool has[100002];

int firstMissingPositive(vector<int>& nums) {
    int n= size(nums);
    
    for(int i=0;i<n;i++){
        int x=nums[i];
        
        while(x>=1 && x<=n && x!=i+1 && nums[x-1]!=x){
            swap(nums[x-1],nums[i]);
            x=nums[i];
        }
    }


    for(int i=0;i<n;i++){
        if(nums[i] == i+1)continue;
            return i+1;       
        
    }
    
    return n+1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums = {1, 2, 0};
    int res = firstMissingPositive(nums);
    cout << res << endl;
    return 0;
}