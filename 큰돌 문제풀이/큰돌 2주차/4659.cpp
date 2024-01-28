#include <bits/stdc++.h>
using namespace std;

const char gather[] = {'a', 'e', 'i', 'o', 'u'};

string a;

bool check1(string a){
    int check = 0;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < 5; j++){
            if(a[i] == gather[j]) check++;
        }
    }
    if(check > 0) return true;
    else return false;
}

bool valCheck(char a){
    int check = 0;
    for(int j = 0; j < 5; j++){
            if(a == gather[j]) check++;
    }
    if(check > 0) return true;
    else return false;
}
bool check2(string a){
    if(a.size() <= 2) return true;
    int count = 0;
    int count2 = 0;
    for(int i = 0; i < a.size(); i++){
        if(valCheck(a[i])){
            count++;
            count2 = 0;
        }
        else{
            count2++;
            count = 0;
        }
        if(count == 3 || count2 == 3) return false;
    }
    return true;
}

bool check3(string a){
    if(a.size() == 1) return true;
    for(int i = 1; i < a.size(); i++){
        if(a[i-1] == a[i] && a[i] != 'e' && a[i] != 'o'){
            return false;
        }
        else continue;
    }
    return true;
}
int main(){
    while(1){
        cin >> a;
        if(a == "end") break;
        if(check1(a) && check2(a) && check3(a)){
            cout << '<' << a << "> " << "is acceptable.\n";
        }
        else 
            cout << '<' << a << "> " << "is not acceptable.\n";
    }
    return 0;
}