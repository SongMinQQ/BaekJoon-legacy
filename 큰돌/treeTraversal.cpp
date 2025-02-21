#include <bits/stdc++.h>
using namespace std; 
vector<int> adj[1004]; 
int visited[1004];

void postOrder(int here){ 
    if(visited[here] == 0){ 
        if(adj[here].size() == 1)postOrder(adj[here][0]);
        if(adj[here].size() == 2){
            postOrder(adj[here][0]); 
            postOrder(adj[here][1]);
        }
        visited[here] = 1; 
        cout << here << ' ';
	} 
} 
void preOrder(int here){
    if(visited[here] == 0){
        visited[here] = 1; 
        cout << here << ' ';
        if(adj[here].size() == 1)preOrder(adj[here][0]);
        if(adj[here].size() == 2){
            preOrder(adj[here][0]); 
            preOrder(adj[here][1]);
		}
	}
}  
void inOrder(int here){   	
    if(visited[here] == 0){ 
        if(adj[here].size() == 1){ 
            inOrder(adj[here][0]); 
            visited[here] = 1; 
            cout << here << ' ';
        }else if(adj[here].size() == 2){
            inOrder(adj[here][0]); 
            
            visited[here] = 1; 
            cout << here << ' ';
            
            inOrder(adj[here][1]);
        }else{
            visited[here] = 1; 
            cout << here << ' '; 
		}
	}

} 
int main(){
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[2].push_back(4);
	adj[2].push_back(5); 
	int root = 1;
    cout << "\n Ʈ����ȸ : postOrder \n";
    postOrder(root); memset(visited, 0, sizeof(visited));
    cout << "\n Ʈ����ȸ : preOrder \n"; 
    preOrder(root); memset(visited, 0, sizeof(visited)); 
    cout << "\n Ʈ����ȸ : inOrder \n"; 
    inOrder(root); 
    return 0;
}
/*
 Ʈ����ȸ : postOrder
4 5 2 3 1
 Ʈ����ȸ : preOrder
1 2 4 5 3
 Ʈ����ȸ : inOrder
4 2 5 1 3
*/
//[��ó] [�˰��� ����] 2����. �׷����̷�, �������, ��������Ʈ, DFS, BFS, Ʈ����ȸ|�ۼ��� ū��