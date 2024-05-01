#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool isCorrectLetter(char c) {
        if (c >= '0' && c <= '9') return true;
        return false;
    }

    static int myAtoi (string str) {
        bool sign = false;
        long long result = 0;
        int i = 0;

        for (; i < str.length(); ++i) {
            if (str[i] != ' ') break;
        }

        if (str[i] == '-') {
            sign = true;
            i++;
        }
        else
        if (str[i] == '+') {
            sign = false;
            i++;
        }

        for (; i < str.length(); ++i) {
            if (isCorrectLetter(str[i])) {
                int num = str[i] - '0';
                result = result * 10 + num;
                
                if(result > INT_MAX && sign == true)
                    return INT_MIN;
                else if(result > INT_MAX && sign == false)
                    return INT_MAX;

            } else break;
        }

        if (sign) result *= -1;

        return result;
    } 
};

int main () {
    string input[] = {
        "42",
        "042",
        "-42",
        " 42",
        "nmap-43",
        "42 pacman",
        "4a2helloworldd",
        "-91283472332",
        "-23412354354645",
    };

    int longestInput = 0;

    for (string i : input) {
        if (longestInput < i.length()) {
            longestInput = i.length();
        }
    }

    for (string i : input) {
        cout << setw(longestInput) << i << " : " << Solution::myAtoi(i) << endl;
    }
    return 0;
}