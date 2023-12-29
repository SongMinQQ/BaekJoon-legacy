#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, c;
    string a;
    queue<int> b;
    cin >> n;
    for(int i=0; i < n; i++){
        cin >> a;
        if(a == "push"){
            cin >> c;
            b.push(c);
        }
        else if(a == "pop"){
            if(b.empty()){
                cout << -1 << '\n';
            }
            else{
                cout << b.front() << '\n';
                b.pop();
            }
        }
        else if(a == "size"){
            cout << b.size() << '\n';
        }
        else if(a == "empty"){
            cout << (b.empty() ? 1 : 0) << '\n';
        }
        else if(a == "front"){
            cout << (b.empty() ? -1 : b.front()) << '\n';
        }
        else if(a == "back"){
            cout << (b.empty() ? -1 : b.back()) << '\n';
        }
    }
    return 0;
}