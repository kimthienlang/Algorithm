#include <iostream>

using namespace std;

int main() {
    string s = "0123456789";
    string b = s.substr(2, 4);
    string c = s.substr(8, 9);
    cout << b << endl << c << endl;
    cout << s << endl;
    s = s.erase(3, (9 - 3 + 1));
    cout << s << endl;
    return 0;
}