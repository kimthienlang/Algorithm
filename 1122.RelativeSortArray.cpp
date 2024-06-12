#include <bits/stdc++.h>

using namespace std;

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    vector<int> result;
    
    for (int i = 0; i < arr2.size(); i++) {
        for (int j = 0; j < arr1.size(); j++) {   
            if (arr1[j] == arr2[i]) {
                result.push_back(arr1[j]);
                arr1[j] = -1;
            }
        }
    }
    sort(arr1.begin(), arr1.end());

    for (int i = 0; i < arr1.size(); i++) {
        if (arr1[i] != -1) {
            result.push_back(arr1[i]);
        }
    }
    return result;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr1 = {28,6,22,8,44,17};
    vector<int> arr2 = {22,28,8,6};
    vector<int> resu = relativeSortArray(arr1, arr2);
    for (auto x : resu) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}