#include <bits/stdc++.h>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int index = 0;
    for(int i = 0; i< nums.size(); i++){
        if(nums[i] != val){
            nums[index] = nums[i];
            index++;
        }
    }
    return index;
}

int main () {
    vector<int> testcase = {1, 1, 2, 2, 2, 3, 4,6};
    int result = removeElement(testcase, 2);
    for (auto x : testcase) {
        cout << x << " ";
    }
    cout << endl;
    cout << "length expected: " << result << endl;
    return 0;
}