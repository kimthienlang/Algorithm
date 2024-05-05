#include <bits/stdc++.h>

using namespace std;

int romanToInt(string s) {
    int result = 0;
    int lenS = s.length();
    unordered_map<char, int> romanInteger;
    
    romanInteger['I'] = 1;
    romanInteger['V'] = 5;
    romanInteger['X'] = 10;
    romanInteger['L'] = 50;
    romanInteger['C'] = 100;
    romanInteger['D'] = 500;
    romanInteger['M'] = 1000;

    for (int i = 0; i < lenS - 1; ++i) {
        if (romanInteger[s[i]] < romanInteger[s[i + 1]]) {
            result -= romanInteger[s[i]];
        } else {
            result += romanInteger[s[i]];
        }
    }
    result += romanInteger[s[lenS - 1]];

    return result;
}

int main() {
    string testcase[] = {"III", "LVIII", "MCMXCIV"};
    for (string test : testcase) {
        cout << setw(10) << test << " = " << romanToInt(test) << endl;
    }
    return 0;
}