#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    participant.insert(participant.end(), completion.begin(), completion.end());
    multiset<string> mset(participant.begin(), participant.end());
    
    for (const auto& name : mset) {
        if (mset.count(name) % 2 != 0) {
            return name;
        }
    }
    
    return "";
}

int main(){
    vector<string> v1;
    v1.push_back("leo");
    v1.push_back("kiki");
    v1.push_back("eden");
    vector<string> v2;
    v2.push_back("eden");
    v1.push_back("kiki");
    cout << solution(v1, v2);
}