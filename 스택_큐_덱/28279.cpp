#include <iostream>
#include <deque>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a;
    deque<int> deque;
    int b;

    cin >> a;

    for(int i = 0; i < a; i++){
        cin >> b;
        if(b == 1){
            int c;
            cin >> c;
            deque.push_front(c);
        }
        else if(b == 2){
            int c;
            cin >> c;
            deque.push_back(c);
        }
        else if(b == 3){
            if(deque.empty()){
                cout << "-1" << '\n';
            }
            else{
                cout << deque.front() << '\n';
                deque.pop_front();
            }
        }
        else if(b == 4){
            if(deque.empty()){
                cout << "-1" << '\n';
            }
            else{
                cout << deque.back() << '\n';
                deque.pop_back();
            }
        }
        else if(b == 5){
            cout << deque.size() << '\n';
        }
        else if(b == 6){
            cout << deque.empty() << '\n';
        }
        else if(b == 7){
            if(deque.empty()){
                cout << "-1" << '\n';
            }
            else{
                cout << deque.front() << '\n';
            }
        }
        else if(b == 8){
            if(deque.empty()){
                cout << "-1" << '\n';
            }
            else{
                cout << deque.back() << '\n';
            }
        }
    }
    return 0;
}