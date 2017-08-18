#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

vector<int> Adj[100];

bool inq[100] = {false};

void BFS(int start){
	inq[start] = true;
	queue<int> Q;
	Q.push(start);
	while(!Q.empty()){
		int now = Q.front();
		Q.pop();
		for(int i = 0; i < Adj[now].size(); i++){
			int t = Adj[now][i];
			if(inq[t] == false){
				printf("%d ",t);
				Q.push(t);
				inq[t] = true;
			}
		}
	}
}

void traveAll(){
	for(int i = 0; i < 100; i++){
		if(inq[i] == false){
			BFS(i);
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
	BFS(0);
	printf("\n");
	memset(inq, 0, sizeof(inq));
	traveAll();
	return 0;
}
