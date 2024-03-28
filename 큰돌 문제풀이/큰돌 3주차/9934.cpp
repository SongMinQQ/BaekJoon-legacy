#include <bits/stdc++.h>
using namespace std;

int k, nodes[1026];
vector<int> v[13];
bool visited[1026];
void makeBinaryTree(int s, int e, int level){
    if(s > e) return;
    if(s == e){
        v[level].push_back(nodes[s]);
        return;
    }
    int mid = (s + e) / 2;
    v[level].push_back(nodes[mid]);
    makeBinaryTree(s, mid - 1, level + 1);
    makeBinaryTree(mid + 1, e, level + 1);
    return;
}
int main(){
    cin >> k;
    //2^n - 1개의 노드를 가짐
    int nodeNum = (int)pow(2,k) - 1;
    for(int i = 0; i < nodeNum; i++){
        cin >> nodes[i];
    }
    makeBinaryTree(0, nodeNum, 1);
    for(int i = 1; i <= k; i++){
        for(int j : v[i]){
            cout << j << ' ';
        }
        cout << '\n';
    }
    return 0;
}