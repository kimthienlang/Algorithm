/*
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
*/
#include <bits/stdc++.h>

using namespace std;

int search(vector<int>& arr, int k) {
    ios_base::sync_with_stdio(false);
    
    int n = arr.size();
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == k){
            return mid;
        }

        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        else{
            if(arr[mid] <= k && k <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> testcase = {8, 9, 10, 0,1,2,4,5,6,7};
    cout << search(testcase, 9);
    return 0;
}