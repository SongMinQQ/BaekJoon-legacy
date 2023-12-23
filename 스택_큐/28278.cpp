#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a;
    int num, b;
    stack<int> stack;
    cin >> num;

    for(int i = 0; i < num; i++){
        cin >> a;
        switch (a)
        {
        case 1:
            cin >> b;
            stack.push(b);
            break;
        case 2:
            if(stack.size() == 0){
                cout << "-1" << '\n';
            }
            else{
                cout << stack.top() << '\n';
                stack.pop();
            }
            break;
        case 3:
            cout << stack.size() << '\n';
            break;
        case 4:
            cout << stack.empty() << '\n';
            break;
        case 5:
            if(stack.size() == 0){
                cout << "-1" << '\n';
            }
            else {
                cout << stack.top() << '\n';
            }
            break;
        default:
            break;
        }
    }
    return 0;
}