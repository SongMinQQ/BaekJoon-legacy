#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    stack<int> a;
    int num;
    cin >> num;

    string c;
    string result;

    for(int i = 0; i < num; i++){
        while(!a.empty()){
            a.pop();
        }

        cin >> c;
        for(int i = 0; i < c.length(); i++){
            if(c[i] == '('){
                a.push(c[i]);
            }
            else {
                if(!a.empty()){
                    a.pop();
                    result = "YES";
                }
                else{
                    result = "NO";
                    break;
                }
            }
        }
        if(!a.empty()){
            result = "NO";
        }
        cout << result << '\n';
    }

}