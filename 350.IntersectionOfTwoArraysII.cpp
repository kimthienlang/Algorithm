#include <bits/stdc++.h>

using namespace std;

const int _ = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 'c';
}();

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> res;
    int idxN1 = 0, idxN2 = 0;
    int lenN1 = nums1.size(), lenN2 = nums2.size();
    while(idxN1 < lenN1 && idxN2 < lenN2) {
        while (idxN1 < lenN1 && nums1[idxN1] < nums2[idxN2]) ++idxN1;     
        while (idxN2 < lenN2 && nums2[idxN2] < nums1[idxN1]) ++idxN2;  
        if (idxN1 == lenN1 || idxN2 == lenN2) break;
        if (nums1[idxN1] == nums2[idxN2]) {
            res.push_back(nums1[idxN1]);
            idxN1++;
            idxN2++;
        }
    }
    return res;
}

int main() {
    vector<int> nums1 = {4 , 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    vector<int> res = intersect(nums1, nums2);
    cout << "Intersection --> ";
    for (auto e : res) cout << e << " ";
    return 0;
}