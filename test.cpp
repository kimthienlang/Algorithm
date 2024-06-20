#include <bits/stdc++.h>

using namespace std;

int binary_search(int left, int right, vector<int>& arr, int target) {
    if (left > right) return -1;
    int mid = (left + right) / 2;
    if (target < arr[mid]) {
        right = mid - 1;
        return binary_search(left, right, arr, target);
    } else 
    if (target > arr[mid]) {
        left = mid + 1;
        return binary_search(left, right, arr, target);
    } else 
    if (target == arr[mid]) return mid;
    else return -1;
}

int isContainTargetInList(int target, vector<int> list) {
    vector<int> arr = list;
    int res = binary_search(0, arr.size()-1, arr, target);
    if (res != -1) return res;
    else return res; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> list = {0, 0, 0, 0, 3};
    vector<int> targets = {0, 6, 1, 5, 3, 7, -1}; 
    for (int target : targets) {
        int res = isContainTargetInList(target, list);
        string text = " is contain in list";
        if (res == -1) text = " is not contain in list";
        cout << target << text << endl;
    }
    return 0;
}