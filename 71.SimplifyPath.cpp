#include <bits/stdc++.h>

using namespace std;

string simplifyPath(string path) {
    vector<string> dir, ans_vec;
    string T;
    string ans = "";
    stringstream x(path);
    while(getline(x, T, '/')){
        dir.push_back(T);
    }
    for(int i = 0; i < dir.size(); i++){
        if(dir[i ]== ".."){
            if(ans_vec.size() > 0) 
                ans_vec.pop_back();
        }else if(dir[i] == "."){
        }else{
            if(dir[i] != "")
                ans_vec.push_back(dir[i]);
        }
    }
    for(int i = 0; i < ans_vec.size(); i++){
        ans += "/" + ans_vec[i];
    }
    if(ans == "") ans = "/";
    return ans;
}

int main() {
    cout << "Program is running..." << endl;
    string path = "/AABB/CCDD/..//.../_///CC/";
    string newPath = simplifyPath(path); 
    cout << newPath << endl;
    return 0;
}