#include <bits/stdc++.h>
using namespace std;

set<int> a;
set<int> b;
int q, w, num;
int main(){
    cin >> q >> w;
    for(int i = 0; i < q; i++){
        cin >> num;
        a.insert(num);
    }
    for(int i = 0; i < w; i++){
        cin >> num;
        b.insert(num);
    }
    for (auto it = a.begin(); it != a.end(); ++it){
        if(b.find(*it) != b.end()) w--;
    }
    for (auto it = b.begin(); it != b.end(); ++it){
        if(a.find(*it) != a.end()) q--;
    }
    cout << q + w;
    return 0;
}