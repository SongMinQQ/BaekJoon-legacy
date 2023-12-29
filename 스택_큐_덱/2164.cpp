#include <iostream>
#include <queue>

using namespace std;

int main(){
    int a, c;
    queue<int> b;
    cin >> a;
    for(int i = 0; i < a; i++){
        b.push(i+1);
    }
    while(b.size() > 1){
        b.pop();
        if(b.size() > 1){
            b.push(b.front());
            b.pop();
        }
    }
    cout << b.front();
}