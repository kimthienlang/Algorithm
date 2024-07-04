/*Lesson 03*/

#include <bits/stdc++.h>

using namespace std;

vector<bool> lesson3(vector<int>& arr1, vector<int>& arr2) {
    vector<bool> res;
   
    int lenA1 = arr1.size(), lenA2 = arr2.size();
    for (int i = 0; i < lenA2; ++i) {
        int target = arr2[i];
        bool check = false;
        for (int j = 0; j < lenA1; ++j) {
            int sum = 0;
            for (int k = j; k > -1; --k) {
                sum += arr1[k];
                if (sum == target) {
                    check = true;
                    break;
                }
            }
            if (check) {
                break;
            }
        }
        res.push_back(check);
    }

    return res;
}

int main() {
    vector<int> arr1 = {1, 3, 9, -2, 3, -19, -10}, 
                arr2 = {10, -18, -28, 7, 18, 8}; 
    
    vector<bool> res = lesson3(arr1, arr2);
    for (auto x : res) cout << x << " ";
    return 0;
}