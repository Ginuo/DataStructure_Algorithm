#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 502;
const int INF = 0x3fffffff;

int G[maxn][maxn];
int N,M,s,e;
int weight[maxn] = {0};

void init(){
	fill(G[0],G[0]+maxn*maxn, INF);
	cin >> N >> M >> s >> e;
	for(int i = 0; i < N; i++){
		cin >>weight[i];
	}
	int u,v;
	for(int i = 0; i < M; ++i){
		cin >> u >> v;
		cin >> G[u][v];
		G[v][u] = G[u][v];
	}
}

void Floyd(){
	for(int k = 0; k < N; ++k){
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j){
				//记得判断两点间是否可达 
				if(G[i][k] != INF && G[k][j] != INF && G[i][k] + G[k][j] < G[i][j]){
					G[i][j] = G[i][k] + G[k][j];
				}
			}
		}
	}
}

int main(){
	freopen("1003_data.txt", "r", stdin);
	init();
	Floyd();
	cout << G[s][e] << endl;      //s和e之间的最短路径距离 
	return 0;
}


