#include<cstdio>
#include<vector>
#include<string.h>
using namespace std;
//ͬʱ�洢��ǰ����źͱ�Ȩ 
struct Node{
	int vertex;      //��ǰ���ı�ţ�Adj[u][i].vertex �൱���ڽӱ�G[u][v]�е�v 
	int w;      //��Ȩ,�ڱ�����δ�õ� 
	Node(int _v):vertex(_v){}
	Node(int _v, int _w):vertex(_v),w(_w){}	
}; 

vector<Node> Adj[100];
bool vis[100] = {false};  //visited����¼�����Ƿ��ѷ���

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
	//�����㷨�ʼǡ�P351��������ͼ 
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
