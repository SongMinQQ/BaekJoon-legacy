#include <iostream>
#include <deque>

using namespace std;

deque<pair<int,int>> deq;

int main(){
    int a, b, c, d;

    cin >> a;

    for(int i = 0; i < a; i++){
        cin >> b;
        deq.push_back(make_pair(i+1,b));
    }

    while(!deq.empty()){
        c = deq.front().second;
        d = deq.front().first;
        deq.pop_front();
        cout << d << ' ';
        if(deq.empty()) break;
        if(c > 0){
            for(int i = 0; i < c - 1; i++){
                deq.push_back(deq.front());
                deq.pop_front();
            }
        }
        else{
            for(int i = c; i < 0; i++){
                deq.push_front(deq.back());
                deq.pop_back();
            }
        }
    }
    return 0;
}