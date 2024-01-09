#include <bits/stdc++.h>
using namespace std;

string a;
int n;
stack<char> s;

int main(){
    int count = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        while(!s.empty()) s.pop();
        cin >> a;
        if(a.length() & 1) continue;
        else{
            for(int j = 0; j < a.length(); j++){
                if(s.empty()||s.top()!=a[j]) s.push(a[j]);
                else s.pop();
            }
        }
        if(s.empty()) count++;
    }
    cout << count;
    return 0;
}