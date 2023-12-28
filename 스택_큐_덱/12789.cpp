#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int main(){
    int num, num2, count = 1;
    stack<int> a;
    queue<int> b;
    string result = "Nice";

    cin >> num;

    for(int i = 0; i < num; i++){
        cin >> num2;
        b.push(num2);
    }

    for(int i = 0; i < num; i++){
        if(b.front() == count){
            b.pop();
            count++;
        }
        else{
            if(!a.empty() && (a.top() < b.front())){
                if(a.top() == count){
                    a.pop();
                    count++;
                }
                else{
                    result = "Sad";
                    break;
                }
            }
            else{
                a.push(b.front());
                b.pop();
            }
        }
    }
    cout << result;

    return 0;
}