#include <bits/stdc++.h>
using namespace std;

const int N = 50;
vector<int> v[N];
int a, num, del, result = 0, rootNum = 0;

void erase(int index){
    if(!v[index].empty()){
        for(int j : v[index]){
            if(v[j].size() > 0){
                erase(j);
            }
        }
        while(!v[index].empty()){
            v[index].pop_back();
        }
    }
}
void calculate(int index){
    if(v[index].size() > 0){
        for(int k : v[index]){
            if(v[k].size() > 0){
                calculate(k);
            }
            else if(v[k].size() == 0){
                result++;
            }
        }
    }
}
int main(){
    cin >> a;
    int node = 0;
    for(int i = 0; i < a; i++){
        cin >> num;
        if(num == -1){
            rootNum = i;
            node++;
            // v[0].push_back(node);
            continue;
        }
        else{
            v[num].push_back(node);
            node++;
        }
    }
    cin >> del;
    if(del == rootNum){
        cout << 0;
        return 0;
    }
    int indexNum = 0;
    for(int i = 0; i < 50; i++){
        if(!v[i].empty()){
            for(int j : v[i]){
                if(j == del){
                    indexNum = i;
                    break;
                }
            }
        }
    }
    v[indexNum].erase(remove(v[indexNum].begin(),v[indexNum].end(),del),v[indexNum].end());

    erase(del);
    if(v[rootNum].empty()) {
        cout << 1;
        return 0;
    }
    else calculate(rootNum);
    cout << result;
    return 0;
}