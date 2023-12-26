#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    string word, result;
    stack<char> a;
    int count;

    while(1){
        getline(cin,word);
        if(word == "."){
            return 0;
        }
        count = 0;
        for(int i = 0; i < word.length(); i++){
            if(word[i] == '(' || word[i] == '['){
                a.push(word[i]);
            }
            if(word[i] == ')'){
                if(a.empty() || a.top() != '('){
                    result = "no";
                    count++;
                    break;
                }
                else
                    a.pop();
            }
            if(word[i] == ']'){
                if(a.empty() || a.top() !='['){
                    // result = "no";
                    count++;
                    break;
                }
                else
                    a.pop();
            }
        }
        if(a.empty() && count == 0){
            result = "yes";
        }
        else    result = "no";
        cout << result << '\n';
        while(!a.empty()){
            a.pop();
        }
        
    }

}