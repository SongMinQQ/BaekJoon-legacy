#include <bits/stdc++.h>
using namespace std;

int r, c, result = 0;
char a[22][22];

int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        string line;
        cin >> line;
        for(int j = 0; j < line.size(); j++){
            a[i][j] = line[j];
        }
    }
    
}