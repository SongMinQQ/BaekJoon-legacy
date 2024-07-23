#include <bits/stdc++.h>
using namespace std;

char a[21][21];
int n;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string line;
        cin >> line;
        for(int j = 0; j < line.length(); j++){
            a[i][j] = line[j];
        }
    }
    
}