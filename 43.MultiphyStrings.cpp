//Difficulty: Med.

#include <bits/stdc++.h>

using namespace std;

string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    string result = "";
    int len_num1 = num1.length();
    int len_num2 = num2.length();
    vector<int> num_2, res(len_num1 + len_num2, 0);
    
    for (int i = len_num2 - 1; i > -1; --i) 
        num_2.push_back((num2[i] - '0'));

    int start = 0;
    for (int i = len_num1 - 1; i > -1; --i) {
        int x = num1[i] - '0';
        int mod = 0;
        vector<int> store;
        for (int j = 0; j < len_num2; ++j) {
            int mul = (x * num_2[j]) + mod;
            int num = mul % 10;
            mod = mul / 10;
            store.push_back(num);
        }

        if (mod != 0) store.push_back(mod);
        mod = 0;

        if (i != len_num1 - 1) {
            start++;
            int k = start;
            int len_res = res.size();
            int i_store = 0;
            while (k < len_res) {
                int num = res[k] + store[i_store] + mod;
                res[k] = num % 10;
                mod = num / 10;
                k++;
                i_store++;
            }
            
            int len_store = store.size();
            while (i_store < len_store) {
                int num = store[i_store] + mod;
                res.push_back(num % 10);
                mod = num / 10;
                i_store++;
            }

            if (mod != 0) {
                res.push_back(mod);
                mod = 0;
            }
        }else {
            res = store;
        }
    }

    int len_res = res.size();
    for (int i = len_res - 1; i > -1; --i) {
        result += (res[i] + '0');
    }
    
    return result;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string num1 = "265";
    string num2 = "1000";
    cout << "Num1 = " << num1 << endl;
    cout << "Num2 = " << num2 << endl;
    string res = multiply(num1, num2);
    cout << num1 << " x " << num2 << " = " << res << endl;
    return 0;
}