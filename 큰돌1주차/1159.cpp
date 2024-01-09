#include <bits/stdc++.h>
using namespace std;

int arr[26], n;
string name, result="";

int main(){
    fill(arr,arr + 26, 0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> name;
        arr[(int)name[0] - 97]++;
    }
    for(int i = 0; i < 26; i++){
        if(arr[i] > 4){
            result+=(i+97);
        }
    }
    if(result.length() > 0) cout << result;
    else cout << "PREDAJA";

}