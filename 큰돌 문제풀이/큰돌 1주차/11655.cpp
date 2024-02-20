#include <bits/stdc++.h>
using namespace std;
string a, b;

bool check(char a){
    if((a + 13) < 91 || ((a+13) > 96 && (a + 13) < 122)){
        return true;
    }
    else return false;
}
bool check2(char a){
    if((a > 65 && a < 90 )||(96 < a && a < 122)){
        return true;
    }
    else return false;
}
int main(){
    getline(cin, a);
    for(int i = 0; i < a.length(); i++){
        if(check2(a[i])){
            if(check(a[i])){
                b += a[i] + 13;
            }
            else b += a[i] + 13 - 26;
        }
        else b+= a[i];
    }

    cout << b;
}