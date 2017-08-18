#include<cstdio>
#include<algorithm>
#include<string.h> 
using namespace std;

const int INF = 0x3fffffff;
int G[100][100];     //图，存储边权，最多可以有100个顶点 
                     //G[u][v]为1表示有从u到v的边
					 //值为INF表示没有边 
bool vis[100] = {false}; //visited，记录是否访问过

//遍历一个连通块 ，参数u为起点 
void DFS(int u){
	vis[u] = true;     //必须先设置成已访问，再循环 
	for(int v = 0; v < 100; v++){
		if(G[u][v] != INF && vis[v] == false){
			printf("%d ",v);
			DFS(v); 
		}
	}
} 

//遍历整个图（所有连通块） 
void traveAll(){
	for(int u = 0 ; u < 100; u++){
		if(vis[u] == false){
			DFS(u);
		} 
	}
}

int main(){
	//初始化边权 
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
	
	DFS(0);  //因为图G是连通的，所以DFS(0)已经遍历了整个图
	         //且各顶点对应的vis元素已被置为true
			 //所以继续调用traveAll之前，必须重置vis数组
			 //否则什么都不会输出！！ 
	printf("\n");
	memset(vis,0,sizeof(vis)); 
	traveAll();
	return 0;
}
