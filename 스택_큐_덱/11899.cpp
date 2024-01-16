#include <bits/stdc++.h>
using namespace std;

string a;
stack<char> s;
int main(){
    cin >> a;
    for(int i = 0; i < a.length(); i++){
        if(!s.empty() && s.top() == '(' && a[i] == ')'){
            s.pop();
        }
        else{
            s.push(a[i]);
        }
    }
    cout << s.size();
}