#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> v;

struct cmp{
    bool operator()(int a, int b){
        if(abs(a) == abs(b))
            return a > b;
        return abs(a) > abs(b);
    }
};

priority_queue<int, vector<int>, cmp> q;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        
        if(x == 0){
            if(q.empty()) v.push_back(0);
            else{
                v.push_back(q.top());
                q.pop();
            }
        }
        else q.push(x);
    }
    for(int i : v){
        cout << i << '\n';
    }
    return 0;
}