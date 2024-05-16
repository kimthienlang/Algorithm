//LOD: Hard

#include <bits/stdc++.h>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    int lenS = s.length();
    int lenW = words.size();
    int lenW0 = words[0].size();

    for (int i = 0; i < lenS; ++i) {
        vector<int> indexW;
        bool isExistJ[lenW];
        memset(isExistJ, 0, sizeof(isExistJ));
        int ii = i;

        for (int k = 0; k < lenW; ++k)
        for (int j = 0; j < lenW; ++j) {
            bool checkJ = true;
            if (isExistJ[j]) continue;
            for (int l = 0; l < lenW0; ++l) {
                if (words[j][l] != s[ii]) {
                    checkJ = false;
                    ii -= l;
                    break;
                } else ii++;
            }
            if (checkJ) {
                indexW.push_back(j);
                cout << i << "-" << j << endl;
                isExistJ[j] = true;
            }
        }
        if (indexW.size() == lenW) res.push_back(i);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string testcase1 = "barfoofoobarthefoobarman";
    vector<string> word = {"bar","foo","the"};

    vector<int> result = findSubstring(testcase1, word);

    for (auto x : result) cout << x << " ";
    cout << endl;

    return 0;
}