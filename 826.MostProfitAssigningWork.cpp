/*
    Difficulty: Med.
*/
#include <bits/stdc++.h>

using namespace std;

void sortDiffAndProf(vector<int>& difficulty, vector<int>& profit) {
    int len = profit.size();
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (difficulty[j] < difficulty[i]) {
                swap(difficulty[j], difficulty[i]);
                swap(profit[j], profit[i]);
            }
        }
    }
}

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    int res = 0;
    sortDiffAndProf(difficulty, profit);
    int i = 0, len_worker = worker.size(), len_diff = difficulty.size();
    while (i < len_worker) {
        int j = 0;
        int max = 0;
        while (j < len_diff) {
            if (worker[i] >= difficulty[j]) {
                if (profit[j] > max)
                max = profit[j];
            } else break;
            j++;
        }
        res += max;
        i++;
    }
    return res;       
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> difficulty = {2,4,6,8,10,1};
    vector<int> profit = {10,20,30,40,50,40};
    vector<int> worker = {4,5,6,7};
    int max = maxProfitAssignment(difficulty, profit, worker);
    cout << "max = " << max << endl;
    return 0;
}