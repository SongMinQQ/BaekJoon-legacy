#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    while(cin >> n){
        long long a = 1;
        int count = 1;
        while(1){
            if(a % n != 0){
                a = (a * 10) + 1; 
                a %= n;
                count++;
            }
            else{
                cout << count << '\n';
                break;
            }
        }
        
    }
    return 0;
}