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
		dis[v][u] = t;     //双向赋值，切记！！ 
	}
	num[s] = 1;
    w[s] = weight[s]; 
} 

bool BellmanFord(){
	//执行N-1轮 
	for(int i = 0; i < N-1; i++){
		//用一个二层循环遍历所有边 
		for(int u = 0; u < N; u++){
			for(int j = 0; j < Adj[u].size(); j++){
				int v = Adj[u][j];
				if(d[u] + dis[u][v] < d[v]){
					d[v] = d[u] + dis[u][v];
					w[v] = w[u] + weight[v];
					num[v] = num[u];       //找到了更短的路径时，该部分的路径条数计算与Dijkstra相同 
					pre[v].clear();
					pre[v].insert(u);
				}else if(d[u] + dis[u][v] == d[v]){
					if(w[u] + weight[v] > w[v]){  //点权、边权的第二标尺，与Dijkstra相同 
						w[v] = w[u] + weight[v];
					}
					pre[v].insert(u);
					num[v] = 0;  //找到了相同长度的最短路径时，条数计算与Dijkstra不同 
					set<int>::iterator it; //必须重新计算最短路径条数 
					for(it = pre[v].begin(); it != pre[v].end(); it++){
						num[v] += num[*it];
					}
					 
				}
			}
		}
	}
	//负环测试 
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








