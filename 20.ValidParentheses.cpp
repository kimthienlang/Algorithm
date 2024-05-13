#include <bits/stdc++.h>

using namespace std;

bool isValid(string s) {
    stack<char> stack;
    unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};

    for (char c : s) {
        if (mapping.find(c) == mapping.end()) {
            stack.push(c);
        } else if (!stack.empty() && mapping[c] == stack.top()) {
            stack.pop();
        } else {
            return false;
        }
    }

    return stack.empty();
}

int main() {
    string s = "(){}}{";
    bool result = isValid(s);
    cout << "string   : " << s << endl;
    cout << "Is valid : " << result << endl;
    return 0;
}