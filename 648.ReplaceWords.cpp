#include <bits/stdc++.h>

using namespace std;

const char _ = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 'c';
}();

struct Trie{
    array<Trie*, 26> alphabet{};
    const string* str = nullptr;
    bool endOfWord = false;

    optional<const string*> findWord(const string& word) const noexcept {
        const auto* curr = this;
        for(auto& c : word){
            if(curr->endOfWord) return curr->str;
            if(curr->alphabet[c - 'a']) curr = curr->alphabet[c - 'a'];
            else break;
        }
        return nullopt;
    }

    static Trie* buildTrie(const vector<string>& dictionary) noexcept {
        Trie* root = new Trie();
        for(const auto& dic : dictionary){
            Trie* curr = root;
            for(int i = 0; i < dic.size(); ++i){
                auto& asci = curr->alphabet[dic[i] - 'a'];
                if(!asci) asci = new Trie();
                curr = asci;
            }
            curr->str = &dic;
            curr->endOfWord = true;
            curr = root;
        }
        return root;
    }
};

string replaceWords(const vector<string>& dictionary, const string& sentence){
    auto* root = Trie::buildTrie(dictionary);

    string replacedSentence;
    replacedSentence.reserve(sentence.size());

    istringstream iss(sentence);
    string word;
    while(iss >> word) {
        const auto w = root->findWord(word);
        replacedSentence += (w.has_value() ? *w.value() : word) + ' ';
    }

    replacedSentence.pop_back();
    return replacedSentence;
}

int main() {
    vector<string> dictionary = {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery";
    string replacedSentence = replaceWords(dictionary, sentence);
    cout << sentence << "\nafter replace\n" << replacedSentence << endl;
    return 0;
}