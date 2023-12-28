#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(){
    int a;
    deque<int> deque;
    string b;

    cin >> a;

    for(int i = 0; i < a; i++){
        cin >> b;
        if(b == "push_front"){
            int c;
            cin >> c;
            deque.push_front(c);
        }
        else if(b == "push_back"){
            int c;
            cin >> c;
            deque.push_back(c);
        }
        else if(b == "pop_front"){
            if(deque.empty()){
                cout << "-1" << '\n';
            }
            else{
                cout << deque.front() << '\n';
                deque.pop_front();
            }
        }
        else if(b == "pop_back"){
            if(deque.empty()){
                cout << "-1" << '\n';
            }
            else{
                cout << deque.back() << '\n';
                deque.pop_back();
            }
        }
        else if(b == "size"){
            cout << deque.size() << '\n';
        }
        else if(b == "empty"){
            cout << deque.empty() << '\n';
        }
        else if(b == "front"){
            if(deque.empty()){
                cout << "-1" << '\n';
            }
            else{
                cout << deque.front() << '\n';
            }
        }
        else if(b == "back"){
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