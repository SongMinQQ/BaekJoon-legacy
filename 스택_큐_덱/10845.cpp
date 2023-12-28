#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
    string a;
    int num, b;
    queue<int> queue;
    cin >> num;

    for(int i = 0; i < num; i++){
        cin >> a;
        
        if(a == "push"){
            cin >> b;
            queue.push(b);
        }
        else if(a == "pop"){
            if(queue.size() == 0){
                cout << "-1" << '\n';
            }
            else{
                cout << queue.front() << '\n';
                queue.pop();
            }
        }
        else if(a == "size"){
            cout << queue.size() << '\n';
        }
        else if(a == "empty"){
            cout << queue.empty() << '\n';
        }
        else if(a == "front"){
            if(queue.size() == 0){
                cout << "-1" << '\n';
            }
            else {
                cout << queue.front() << '\n';
            }
        }
        else if(a == "back"){
            if(queue.size() == 0){
                cout << "-1" << '\n';
            }
            else {
                cout << queue.back() << '\n';
            }
        }
    }
    return 0;
}