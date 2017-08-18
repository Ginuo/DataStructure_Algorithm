#include<cstdio>
#include<vector>
#include<string.h>
using namespace std;
//同时存储当前结点编号和边权 
struct Node{
	int vertex;      //当前结点的编号，Adj[u][i].vertex 相当于邻接表G[u][v]中的v 
	int w;      //边权,在本例中未用到 
	Node(int _v):vertex(_v){}
	Node(int _v, int _w):vertex(_v),w(_w){}	
}; 

vector<Node> Adj[100];
bool vis[100] = {false};  //visited，记录顶点是否已访问

void DFS(int u){
	vis[u] = true;
	for(int i = 0; i < Adj[u].size(); i++){
		Node now = Adj[u][i];
		int t = now.vertex;
		if(vis[t] == false){
			printf("%d ",t);
			DFS(t);
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
	Adj[0].push_back(Node(1));
	Adj[0].push_back(Node(2));
	Adj[1].push_back(Node(4));
	Adj[1].push_back(Node(3));
	Adj[2].push_back(Node(1));
	Adj[2].push_back(Node(4));
	Adj[4].push_back(Node(5));
	Adj[4].push_back(Node(3));
	Adj[5].push_back(Node(3));
	
	
	DFS(0);
	printf("\n");
	memset(vis,0,sizeof(vis));
	traveAll();
	return 0;
}
