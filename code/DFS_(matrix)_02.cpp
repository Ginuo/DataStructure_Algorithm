#include<cstdio>
#include<vector>
#include<string.h>

using namespace std;

vector<int> Adj[100];
bool vis[100] = {false};


void DFS(int u){
	vis[u] = true;
	for(int i = 0; i < Adj[u].size(); i++){
		int v = Adj[u][i];
		if(vis[v] == false){
			printf("%d ",v);
			DFS(v);
		}
	}
}

void traveAll(){
	for(int i = 0; i < 5; i++){
		if(vis[i] == false){
			DFS(i);
		}
	}
}

int main(){
	//按《算法笔记》P351构造有向图 
	Adj[0].push_back(1);
	Adj[0].push_back(2);
	Adj[1].push_back(4);
	Adj[1].push_back(3);
	Adj[2].push_back(1);
	Adj[2].push_back(4);
	Adj[4].push_back(5);
	Adj[4].push_back(3);
	Adj[5].push_back(3);
	
	DFS(0);
	printf("\n");
	memset(vis,0,sizeof(vis));
	traveAll();
	return 0;
	
}
