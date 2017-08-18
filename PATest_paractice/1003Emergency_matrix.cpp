#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 510;
const int INF = 0x3fffffff;

int G[maxn][maxn];

int N,M,S,E;     //顶点数，边数，起点，终点 

int pathNum[maxn] = {0};        //到达每个顶点的最短路径条数
int d[maxn];             //到达每个顶点的最短路径长度
//int dis[maxn][maxn];      //u到v的距离 
int team[maxn];          //每个顶点的救援队数
int maxt[maxn] = {0};          //到达每个顶点的所有最短路径中，最大的队数和

bool vis[maxn];       //访问标记

void init(){
	fill(G[0], G[0]+(maxn*maxn), INF);
	fill(d, d+maxn, INF);
	memset(vis, 0, sizeof(vis));
	pathNum[S] = 1;
	d[S] = 0;
	maxt[S] = team[S];	
}

void Dijkstra(){
	for(int i = 0; i < N; i++){
		int u = -1, MIN = INF;
		for(int j= 0; j < N; j++){
			if(d[j] < MIN && vis[j] == false){
				MIN = d[j];
				u = j;
			}
		}
		if(u == -1)		return;
		vis[u] = true;
		for(int v = 0; v < N; v++){
			if(G[u][v] != INF && vis[v] == false){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					maxt[v] = maxt[u] + team[v];
					pathNum[v] = pathNum[u];
				}else if(d[u] + G[u][v] == d[v]){
					pathNum[v] += pathNum[u];
					if(maxt[u] + team[v] > maxt[v]){
						maxt[v] = maxt[u] + team[v];
					}
				}
			}
		}
	}
}


int main(){
	//freopen()记得注释掉 
	//freopen("1003_data.txt", "r", stdin);
	
	cin >> N >> M >> S >> E;
	for(int i = 0; i < N; i++)	cin >> team[i];
	
	init();  //初始化数组等 
	
	int u,v;
	for(int i = 0; i < M; i++){
		cin >> u >> v;
		cin >> G[u][v];
		G[v][u] = G[u][v];
	}
	
	Dijkstra();
	cout << pathNum[E] << " " << maxt[E] << endl;
	return 0;
} 
