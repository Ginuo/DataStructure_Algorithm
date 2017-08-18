#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

//***������̾�����ͬ�����·��ʱ��ȡ�������ٵ�·�� ����Ҫ������������ 

struct node{
	int v;
	int w;
	node(int _v, int _w){
		v = _v;
		w = _w;
	}
};

vector<node> Adj[500];
int n;    //���׸���
int d[500]; 
const int INF = 0x3fffffff;
bool vis[500] = {false};
int cost[500][500];    //��������Ļ���(��Ȩ)
int c[500];  //�����С���� 

void Dijkstra(int s){
	fill(d,d+500,INF);
	fill(c,c+500,INF); 
	d[s] = 0;
	c[s] = 0;
	for(int i = 0; i < n; i++){
		int u = -1;
		int min = INF;
		for(int j = 0; j < n; j++){   //�ҳ�δ���ʵĶ�������̾�����С�� 
			if(vis[j]==false && d[j] < min){
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int k = 0; k < Adj[u].size(); k++){
			int v = Adj[u][k].v;
			int w = Adj[u][k].w;
			if(vis[v] == false && d[u] + w < d[v]){
				d[v] = d[u] + w;
				c[v] = c[u] + cost[u][v];
			}else if(vis[v] == false && d[u] + w == d[v] && c[u] + cost[u][v] < c[v]){
				c[v] = c[u] + cost[u][v];
			}
		}
	}
} 

int main(){
	n = 6;
	//��P368����ͼ , V1-->V3�ľ���ĳ���3�������ͻ���������0��2�����·���� 
	Adj[0].push_back(node(1,1));
	Adj[0].push_back(node(3,4));
	Adj[0].push_back(node(4,4));
	Adj[1].push_back(node(3,3));
	Adj[2].push_back(node(5,1));
	Adj[3].push_back(node(2,2));
	Adj[3].push_back(node(4,3));
	Adj[4].push_back(node(5,3));
	//�������Լ���㶨�� 
	cost[0][1] = 3;
	cost[0][3] = 5;
	cost[0][4] = 2;
	cost[1][3] = 4;
	cost[2][5] = 1;
	cost[3][2] = 6;
	cost[3][4] = 2;
	cost[4][5] = 8;
	
	Dijkstra(0);
	for(int i = 0 ; i < n; i++){
		printf("%d ",d[i]);
	}
	printf("\n");
	for(int i = 0; i < n; i++){
		printf("%d ",c[i]);
	}
	return 0;
}
