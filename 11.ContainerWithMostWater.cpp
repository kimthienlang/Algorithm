#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int>& height) {
    int result = 0;
    int maxVol = 0;
    int left   = 0;
    int right  = height.size() - 1;
    
    while(left < right) {
        int verticalLine = min(height[left], height[right]);
        int vol = verticalLine * (right - left);
        if (vol > maxVol) maxVol = vol;

        if (height[left] < height[right]) left++;
        else right--;
    }

    result = maxVol;
    return result;
}

int main() {
    vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = maxArea(height);

    cout << result << endl;
    return 0;
}