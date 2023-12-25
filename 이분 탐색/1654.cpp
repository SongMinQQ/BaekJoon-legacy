#include <iostream>

using namespace std;

int calculate(int a[], int b, int c){
    
}
int main(){
    int k, n, count, lanNum, max = 0, result;

    int *lan = new int[k];
    cin >> k >> n;

    for(int i = 0; i < k; i++){
        cin >> lanNum;
        lan[i] = lanNum;
        max = (lan[i] > max) ? lan[i] : max;
    }
    for(int i = 0; i < k; i++){
        if((lan[i] / max) < 1){
            max = max * 0.5;
        }
    }
}