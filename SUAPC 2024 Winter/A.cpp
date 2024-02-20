#include <bits/stdc++.h>
using namespace std;

int q, ta, tb, va, vb;

int main(){
    cin >> q;

    for(int i = 0; i < q; i++){
        int resultA = 0, resultB = 0, minResult, cnt = 0;
        cin >> ta >> tb >> va >> vb;
        if(ta == tb){
            if(va > vb){
                resultB = tb * vb;
                for(int i = 0; i < (va - vb) / 2; i++){
                    resultB += ta;
                }
            }
            else resultB = tb * vb;
        }
        else if(va < vb){
            resultB = tb * vb;
        }
        else if(ta > tb && va > vb){
            resultB = tb * vb;
            for(int i = 0; i < va; i++){
                resultA += ta;
                if(resultA < resultB) cnt++;
                else break;
            }
            resultB = resultB + (cnt * tb);
        }
        else if(va == vb){
            resultB = tb * vb;
            resultA = ta * va;
            resultB = max(resultB, resultA);
        }
        cout << resultB << '\n';
    }
    return 0;
}