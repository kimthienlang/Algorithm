#include <bits/stdc++.h>

using namespace std;

/*
Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 2,147,483,648
Output: 21

Example 4:
Input: x = 120
Output: 21

*/

class Solution 
{    
public:
    int reverse(int x) {
        int result = 0;    
         
        while (x){
            if (result > INT_MAX/10 || 
            result < INT_MIN/10) return 0;
            result = result * 10 + x % 10;  
            x = x /10;     
        } 

        return result;  
    }
}; 

int main() {
    Solution s;
    int number = 2147483641;
    cout << s.reverse(number);
    return 0;
}