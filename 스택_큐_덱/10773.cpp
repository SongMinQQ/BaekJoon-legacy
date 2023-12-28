#include <iostream>
#include <stack>

using namespace std;

int main(){
    int a, b, result = 0;
    stack<int> c;

    cin >> a;

    for(int i = 0; i < a; i++){
        cin >> b;
        if(b == 0 && !c.empty()){
            c.pop();
        }
        else{
            c.push(b);
        }
    }
    if(c.empty()){
        cout << "0";
        return 0;
    }
    else{
        while(!c.empty()){
            result += c.top();
            c.pop();
        }
        cout << result;
    }
}