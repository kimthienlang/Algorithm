#include <bits/stdc++.h>

using namespace std;
// 
// 1 2 3 4 -> 
// 1 2 4 3 -> 
// 1 3 2 4 ->
// 1 3 4 2 ->
// 1 4 2 3 ->
// 1 4 3 2 ->
// 

void nextPermutation(vector<int>& nums) {
    next_permutation(nums.begin(),nums.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> testcase = {1, 2, 4, 3};
    for (int e : testcase) 
        cout << e << " ";
    cout << endl;

    nextPermutation(testcase);

    for (int e : testcase) 
        cout << e << " ";
    return 0;
}