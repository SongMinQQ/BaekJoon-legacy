#include <bits/stdc++.h>
using namespace std;

int a[26];

int main(){
    fill(a, a + 26, 0);
    string b;
    cin >> b;
    for(int i = 0; i < b.length(); i++){
        a[(int)b[i] - 97]++;
    }
    for(int i : a) cout << i << ' ';
    return 0;
}