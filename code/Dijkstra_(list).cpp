#include<cstdio>
#include<algorithm>

using namespace std;

int n;      //顶点个数 
int G[1000][1000];
const int INF = 0x3fffffff;
bool vis[1000] = {false};
int d[1000]; 

void Dijkstra(int s){
	fill(d,d+1000,INF);
	d[s] = 0;
	//这里假设顶点标号是按顺序的，如有n个顶点，则它们的编号为0~n-1
	//做题时读入顶点应注意遵循这条约定 
	for(int i = 0; i < n; i++){   //循环n次，而不是MAXV次 
		int u = -1, MIN = INF; 
		for(int j = 0; j < n; j++){ //遍历数组d，找出未访问的顶点中最短距离最小的 
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];			
			}
		}
		if(u == -1) 	return;
		vis[u] = true;
		for(int v = 0; v < n; v++){
			//如果没有初始化图G中边权为INF，if条件在很多时候都成立 
			if(vis[v] == false && G[u][v] != INF && G[u][v]+d[u] < d[v]){
				d[v] = G[u][v] + d[u]; 
			}
		}
	}
}

int main(){
	n = 6;
	int s = 0;
	//将初始的边权全设为INF 
	fill(G[0],G[0]+1000*1000,INF); //***一定要初始化图！！！，不然错了很难调试 
	G[0][1] = 1;
	G[0][3] = 4;
	G[0][4] = 4;
	G[1][3] = 2;
	G[2][5] = 1;
	G[3][2] = 2;
	G[3][4] = 3;
	G[4][5] = 3;
	Dijkstra(s);
	for(int i = 0; i < n; i++){
		printf("%d ",d[i]);
	}
	return 0;
}
