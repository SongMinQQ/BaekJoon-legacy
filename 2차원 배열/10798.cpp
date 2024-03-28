#include <bits/stdc++.h>
using namespace std;

char a[17][17];
int maxNum = 0;
int main(){
    for(int i = 0; i < 5; i++){
        string line;
        cin >> line;
        for(int j = 0; j < line.size(); j++){
            a[i][j] = (char)line[j];
            maxNum = line.size() > maxNum ? line.size() : maxNum;
        }
    }
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            if(a[j][i]){
                cout << a[j][i];
            }
            else continue;
        }
    }
    return 0;
}