#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& prices) {
    int res = 0;
    int minval = prices[0];
    int lenPrices = prices.size();
    for (int i = 1; i < lenPrices; ++i) {
        minval = min(prices[i], minval);
        res = max(res, prices[i] - minval);
    }
    return res;       
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    int max = maxProfit(prices);
    cout << "Max profit = " << max << endl;
    return 0;
}