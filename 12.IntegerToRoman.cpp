#include <bits/stdc++.h>

using namespace std;

string intToRoman(int num) {
    string result = "";

    string units[]      = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string dozens[]     = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string hundreds[]   = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string Thousands[]  = {"", "M", "MM", "MMM"};

    result = units[num % 10] + result;
    result = dozens[(num % 100) / 10] + result;
    result = hundreds[(num % 1000) / 100] + result;
    result = Thousands[num / 10000] + result;

    return result;       
}

int main() {
    int arr[] = {123, 456, 789, 111, 222, 333, 3999, 58, 1994, 3749};

    for (int x: arr) {
        cout << setw(6) << x << " = " << intToRoman(x) << endl;
    }

    return 0;
}