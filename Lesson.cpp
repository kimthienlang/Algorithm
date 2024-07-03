/*Lesson 03*/

#include <bits/stdc++.h>

using namespace std;

vector<bool> lesson3(vector<int>& arr1, vector<int>& arr2, int num) {
    vector<bool> res;
    vector<long long> cumulativeTotal;

    long long sum = 0;
    for (auto x : arr1) {
        sum += x;
        cumulativeTotal.push_back(sum);
    }

    int lenA1 = arr1.size(), lenA2 = arr2.size();
    for (int i = 0; i < lenA2; ++i) {
        int l = 0, r = lenA1;
        while (l < r) {
            if ()
        }
    }

    return res;
}

int main() {
    vector<int> arr1 = {1, 3, 9, -2, 3, -19, -10}, 
                arr2 = {10, -18, -28, 7, 18}; 
    return 0;
}