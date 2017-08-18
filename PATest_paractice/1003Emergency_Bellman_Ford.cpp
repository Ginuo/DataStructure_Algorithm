#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

const int INF = 0x3effffff;
const int maxn = 510;


vector<int> Adj[maxn];
set<int> pre[maxn];

vector<int> path;
int pathCnt = 0;

int d[maxn];
int w[maxn] = {0};
int num[maxn] = {0};
int dis[maxn][maxn] = {{0}};
int weight[maxn] = {0};

int N,M,s,e;

void init(){
	fill(d, d+maxn, INF);
	cin >> N >> M >> s >> e;
	d[s] = 0;
	for(int i= 0; i < N; i++){
		cin >> weight[i];
	}
	int u,v,t;
	for(int i = 0; i < M; i++){
		cin >> u >> v >> t;
		Adj[u].push_back(v);
		Adj[v].push_back(u);
		dis[u][v] = t;
		dis[v][u] = t;     //˫��ֵ���мǣ��� 
	}
	num[s] = 1;
    w[s] = weight[s]; 
} 

bool BellmanFord(){
	//ִ��N-1�� 
	for(int i = 0; i < N-1; i++){
		//��һ������ѭ���������б� 
		for(int u = 0; u < N; u++){
			for(int j = 0; j < Adj[u].size(); j++){
				int v = Adj[u][j];
				if(d[u] + dis[u][v] < d[v]){
					d[v] = d[u] + dis[u][v];
					w[v] = w[u] + weight[v];
					num[v] = num[u];       //�ҵ��˸��̵�·��ʱ���ò��ֵ�·������������Dijkstra��ͬ 
					pre[v].clear();
					pre[v].insert(u);
				}else if(d[u] + dis[u][v] == d[v]){
					if(w[u] + weight[v] > w[v]){  //��Ȩ����Ȩ�ĵڶ���ߣ���Dijkstra��ͬ 
						w[v] = w[u] + weight[v];
					}
					pre[v].insert(u);
					num[v] = 0;  //�ҵ�����ͬ���ȵ����·��ʱ������������Dijkstra��ͬ 
					set<int>::iterator it; //�������¼������·������ 
					for(it = pre[v].begin(); it != pre[v].end(); it++){
						num[v] += num[*it];
					}
					 
				}
			}
		}
	}
	//�������� 
	for(int u = 0; u < N; u++){
		for(int j = 0; j < Adj[u].size(); j++){
			int v = Adj[u][j];
			if(d[u] + dis[u][v] < d[v]){
				return false;
			}
		}
	}
	
	return true;
}




int main(){
	freopen("1003_data.txt","r",stdin);
	init();
	bool success = BellmanFord();
	if(success)
		cout << num[e] << " " << w[e] << endl;
	else
		cout << "Failed, a negative Circle exists in the Graph!" << endl; 
	return 0;
}








