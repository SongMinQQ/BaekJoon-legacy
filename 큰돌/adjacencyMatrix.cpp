#include <bits/stdc++.h>
using namespace std;

bool a[10][10], visited[10];

// int search(int c, int d){
//     if(a[c][d - 1] == 0 && a[c + 1][d] == 0 && a[c][d + 1] ==0 && a[c - 1][d] == 0){
//         return 0;
//     }
//     if(a[c][d - 1]) search(c, d - 1);
//     if(a[c + 1][d]) search(c + 1, d);
//     if(a[c][d + 1]) search(c, d + 1);
//     if(a[c - 1][d]) search(c - 1, d);
// }
void go(int from){
    visited[from] = 1;
    cout << from << '\n';
    for(int i = 0; i < 10; i++){
        if(visited[i]) continue;
        if(a[from][i]){
            go(i);
        }
    }
    return;
}
int main(){
    a[1][2] = 1; a[2][1] = 1;
    a[1][3] = 1; a[3][1] = 1;
    a[3][4] = 1; a[4][3] = 1;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(a[i][j] && visited[i] == 0){
                go(i);
            }
        }
    }
}