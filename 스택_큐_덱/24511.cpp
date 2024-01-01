#include <iostream>
#include <stack>
#include <deque>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, num, count = 0;
    deque<int> b;

    cin >> n;

    int *arr = new int[n];

    for(int i = 0; i < n; i++){
        cin >> num;
        arr[i] = num;
    }
    for(int i = 0; i < n; i++){
        cin >> num;
        if(arr[i] == 0){
            b.push_back(num);
            count++;
        }
    }

    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> num;
        if(count > 0){
            b.push_front(num);
            cout << b.back() << ' ';
            b.pop_back();
        }
        else{
            cout << num << ' ';
        }
    }
    
    return 0;
}