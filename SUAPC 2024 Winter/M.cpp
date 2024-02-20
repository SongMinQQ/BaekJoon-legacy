#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
char hellobit, friends[10004];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> friends[i];
    }
    cin >> hellobit;
    for(int i = 0; i < n; i++){
        if(friends[i] == hellobit){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
