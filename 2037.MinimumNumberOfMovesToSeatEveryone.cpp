#include <bits/stdc++.h>

using namespace std;

int setup = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());
    int res = 0;
    int length = seats.size();
    for (int i = 0;i < length; ++i) {
        res += abs(students[i] - seats[i]);
    }
    return res;
}

int main() {
    vector<int> seats = {4, 1, 5, 9};
    vector<int> students = {1, 3, 2, 6};
    int res = minMovesToSeat(seats, students);
    cout << "RES = " << res << endl;
    return 0;
}