//LOD: Super Hard if 20ms

#include <bits/stdc++.h>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    unordered_map<string, int> freq, curr;
    for (string& word : words) 
        freq[word]++;
    
    int len = s.size();
    int n = words.size();
    int wordSize = words[0].size();
    int windowSize = wordSize * n;

    vector<int> ans;
    for (int startPos = 0; startPos < wordSize; ++startPos) {
        int start = startPos;
        while (start + windowSize - 1 < len) {
            curr = freq;
            string currWord;
            bool match = true;
            for (int j = 0; j < n; ++j) {
                currWord = s.substr(start + j * wordSize, wordSize);
                if (!curr.count(currWord) or curr[currWord] == 0){
                    match = false;
                    break;
                }
                curr[currWord]--;
            }
            if (match == true) {
                ans.push_back(start);
            }
            start += wordSize;
        } 
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string testcase1 = "b";
    vector<string> word = {"bbb","bbb"};

    vector<int> result = findSubstring(testcase1, word);

    for (auto x : result) cout << x << " ";
    cout << endl;

    return 0;
}