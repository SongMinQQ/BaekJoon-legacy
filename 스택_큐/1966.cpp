#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> q;

    int a, m, n, max, important, count, store;

    cin >> a;

    for(int i = 0; i < a; i++){
        count = 1;
        max = 0;
        cin >> m >> n;
        for(int j = 0; j < m; j++){
            cin >> important;
            max = important > max ? important : max;//가장 큰 중요도를 저장
            q.push(important);
        }
        for(int k = 0; k < m; k++){
            if(q.front() < max){//맨 앞 문서가 문서의 최대 중요도보다 낮다면
                store = q.front();//맨 앞 문서의 중요도 저장
                q.pop();
                count++;//인쇄 카운트 증가
                q.push(store);//다시 push
            }
            else{
                cout << count << '\n';
            }
        }
    }
}