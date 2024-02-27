#include <bits/stdc++.h>
using namespace std;

int y, m, d;
int monthDay[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool leapYear(int y){
    if(y % 4 == 0){
        if(y % 100 == 0) return false;
        else return true;
    }
    else return false;
}

int main(){
    cin >> y >> m >> d;
    
}