#include <bits/stdc++.h>

using namespace std;

/*
input: 
3
"PAYPALISHIRING"
output: "PAHNAPLSIIGYIR"
ex:
P   A   H   N
A P L S I I G
Y   I   R
*/

class Solution {
public:
    string convert (string s, int numRows) {
        int lengthS = s.length();
        int index = 0;
        vector<string> boardEx (numRows, "");

        while (index < lengthS) {
            int i = 0;
            while (i < numRows && index < lengthS) 
            {
                boardEx[i++] += s[index++]; 
            }
            i = numRows - 2; 
            while (i > 0 && index < lengthS) 
            {
                boardEx[i--] += s[index++]; 
            }
        }
        string result = "";

        for (string &element : boardEx) 
        {
            result += element;
        }

        return result;
    }
};

int main () {
    Solution solution;
    int rows = 3;
    string input  = "PAYPALISHIRING";
    string result = solution.convert(input, rows);
    cout << result << endl;
    return 0;
}