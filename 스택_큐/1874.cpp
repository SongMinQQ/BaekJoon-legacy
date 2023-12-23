#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
    int n, num, num2 = 1, num3 = 1;
    stack<int> a;
    stack<int> check;
    queue<int> b;
    queue<int> checkQueue;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> num;
        b.push(num);
        checkQueue.push(num);
    }

    while(checkQueue.empty() == false){
        if(check.empty() || (num3 <= n && check.top() != checkQueue.front())){
            check.push(num3);
            num3++;

        }
        else if(check.top() == checkQueue.front()){
            check.pop();
            checkQueue.pop();
        }
        else if(checkQueue.front() < check.top()){
            cout << "NO" << endl;
            return 0;
        }
    }
    while(b.empty() == false){
        if(a.empty() || (num2 <= n && a.top() != b.front())){
            a.push(num2);
            num2++;
            cout << '+' << '\n';
        }
        else if(a.top() == b.front()){
            a.pop();
            b.pop();
            cout << '-' << '\n';
        }
        else if(b.front() < a.top()){
            cout << "NO" << endl;
            return 0;
        }
    }


    return 0;
}