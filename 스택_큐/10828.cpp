#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    string a;
    int num, b;
    stack<int> stack;
    cin >> num;

    for(int i = 0; i < num; i++){
        cin >> a;
        
        if(a == "push"){
            cin >> b;
            stack.push(b);
        }
        else if(a == "pop"){
            if(stack.size() == 0){
                cout << "-1" << '\n';
            }
            else{
                cout << stack.top() << '\n';
                stack.pop();
            }
        }
        else if(a == "size"){
            cout << stack.size() << '\n';
        }
        else if(a == "empty"){
            cout << stack.empty() << '\n';
        }
        else if(a == "top"){
            if(stack.size() == 0){
                cout << "-1" << '\n';
            }
            else {
                cout << stack.top() << '\n';
            }
        }
    }
    return 0;
}