#include<cstdio>
#include<string.h>
#include<queue>

using namespace std;

const int INF = 0x3fffffff;
int G[100][100];
bool inq[100] = {false};

void BFS(int start){
	inq[start] = true;
	queue<int> Q;
	Q.push(start);
	while(!Q.empty()){
		int now = Q.front();
		Q.pop(); 
		for(int i = 0; i < 100; i++){
			if(inq[i] == false && G[now][i] != INF){
				printf("%d ",i);//对元素的处理语句只能放在这个if语句块中 
				Q.push(i);
				inq[i] = true;
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
	//初始化边权（令G[100][100]每个元素为INF） 
	for(int i = 0; i < 100; i++){
		fill(G[i],G[i]+100,INF);
	}
	//按《算法笔记》P351构造有向图 
	G[0][1] = 1;
	G[1][4] = 1;
	G[4][5] = 1;
	G[5][3] = 1;
	G[0][2] = 1;
	G[2][4] = 1;
	G[2][1] = 1;
	G[1][3] = 1;
	G[4][3] = 1;
	
	BFS(0); 
	printf("\n");
	memset(inq, 0, sizeof(inq));
	traveAll();
	return 0;
} 

