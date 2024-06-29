// Difficulty: Hard
#include <bits/stdc++.h>

using namespace std;

void backtracking(int n, int& count, int k, bool check[], string text, string& res) {
    
    for (int i = 1; i <= n; ++i) {
        if (check[i]) {
            check[i] = false;
            string temps = text + to_string(i);
            if (temps.size() == n) {
                count++;
                if (count == k) {
                    res = temps;
                    return;
                }
            } else {
                backtracking(n, count, k, check, temps, res);
            }
            check[i] = true;
        }
    }
}

string getPermutation(int n, int k) {
    string res = "";
    bool check[n + 1];
    int count = 0;
    memset(check, true, sizeof(check)/sizeof(check[0]));
    backtracking(n, count, k, check, "", res);
    
    return res;       
}

int main() {
    int n = 9, k = 362879;
    string permutationKOfN = getPermutation(n, k);
    cout << "permutation in k : " << permutationKOfN << endl;
    return 0;
}