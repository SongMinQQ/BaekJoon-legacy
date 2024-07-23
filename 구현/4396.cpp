#include <bits/stdc++.h>
using namespace std;

char n[12][12], open[12][12];
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int a;
bool isBoom = false;
bool check(){
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            if(n[i][j] == '*' && open[i][j] == 'x') {
                isBoom = true;
                return true;
            }
        }
    }
    return false;
}
int main(){
    cin >> a;
    for(int i = 0; i < a; i++){
        string line;
        cin >> line;
        for(int j = 0; j < line.size(); j++){
            n[i][j] = line[j];
        }
    }
    for(int i = 0; i < a; i++){
        string line;
        cin >> line;
        for(int j = 0; j < line.size(); j++){
            open[i][j] = line[j];
        }
    }
    check();
    for(int i = 0; i < a; i++){
        bool boom = false;
        for(int j = 0; j < a; j++){
            int cnt = 0;
            for(int k = 0; k < 8; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(n[nx][ny] == '*' && open[i][j] == 'x')cnt++;
            }
            if(isBoom == true) {
                if(n[i][j] == '*') cout << '*';
                else {
                    if(open[i][j] == 'x') cout << cnt;
                    else cout << '.';
                }
            }
            else{
                // if(open[i][j] == 'x' && n[i][j] == '*') cout << '*';
                if(open[i][j] == 'x') cout << cnt;
                else cout << '.';
            }
            
        }
        cout << '\n';
    }
    return 0;
}