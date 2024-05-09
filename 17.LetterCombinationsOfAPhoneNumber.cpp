#include <bits/stdc++.h>

using namespace std;

int convertStringToInt (string s) {
    int result = 0;
    int lenS = s.length();
    for (int i = 0; i < lenS; ++i) {
        result = result * 10 + (s[i] - '0');
    }
    return result;
}

void combinationLetters(vector<string> letters, int digits, vector<string> &resultStore, string result, int d, int lengthDigits) {
    
    int modNum = pow(10, (lengthDigits - d));
    int index = digits / modNum;
    int lenIndex = letters[index].length();
    digits = digits % modNum;

    for (int i = 0; i < lenIndex; ++i) {
        string s = result;
        result += letters[index][i];
        if (d < lengthDigits) {
            d++;
            combinationLetters(letters, digits, resultStore, result, d, lengthDigits);
            d--;
        } else {
            resultStore.push_back(result);
        }
        result = s;
    }

    d--;
}

vector<string> letterCombinations(string digits) {
    
    vector<string> result;
    if (digits.length() < 1) return result;
    vector<string> letters = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tvu",
        "wxyz"
    };

    int lengthDigits = digits.length();
    int digitsInt = convertStringToInt(digits);
    combinationLetters(letters, digitsInt, result, "", 1, lengthDigits);

    return result;
}

int main() {
    cout << pow(10, 0) << endl;
    vector<string> testcase = {"23", "234", "", "2435", "23"};
    for (auto s : testcase) {
        vector<string> res = letterCombinations(s);
        cout << "S : " << s << endl;
        for (string x : res) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}