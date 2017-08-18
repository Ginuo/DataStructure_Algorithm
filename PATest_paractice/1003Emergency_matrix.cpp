#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 510;
const int INF = 0x3fffffff;

int G[maxn][maxn];

int N,M,S,E;     //����������������㣬�յ� 

int pathNum[maxn] = {0};        //����ÿ����������·������
int d[maxn];             //����ÿ����������·������
//int dis[maxn][maxn];      //u��v�ľ��� 
int team[maxn];          //ÿ������ľ�Ԯ����
int maxt[maxn] = {0};          //����ÿ��������������·���У����Ķ�����

bool vis[maxn];       //���ʱ��

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
	//freopen()�ǵ�ע�͵� 
	//freopen("1003_data.txt", "r", stdin);
	
	cin >> N >> M >> S >> E;
	for(int i = 0; i < N; i++)	cin >> team[i];
	
	init();  //��ʼ������� 
	
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
