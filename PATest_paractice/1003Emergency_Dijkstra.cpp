#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 510;
const int INF = 0x3fffffff;

vector<int> graph[MAXN];

int N;  //Vertex nums
int M;  //Edge nums
int s;  //starting point
int e;  //end point


int pathNums[MAXN] = {0};     //从start到任意城市的最短路径条数 
int dis[MAXN][MAXN] = {0};   //两个城市间的距离 
int team[MAXN] = {0};      //每个城市的队伍数 
int d[MAXN] = {0};     //到各点的最短路径
int maxAmount[MAXN] = {0};   //到各点的所有最短路径中，能集结的最大队伍数 
bool vis[MAXN];    

void Dijkstra(){
	//注意，此处还不能设置vis[start] = true;
	//否则将无法找出未访问顶点中最短距离最小的那个 
	for(int i = 0; i < N; ++i){
		int u = -1, mind = INF;
		//注意：内层循环变量不要又写成i，这样就和外层重复了，有可能出问题 
		for(int j = 0; j < N; ++j){
			if(vis[j] == false && d[j] < mind){
				u = j;
				mind = d[j]; 
			}
		}
		if(u == -1)		return;
		vis[u] = true;              //只需在这一个地方设置访问标记即可 
		for(int k = 0; k < graph[u].size(); ++k){
			int v = graph[u][k];
			if(vis[v] == false){
				if(d[u] + dis[u][v] < d[v]){
					d[v] = d[u] + dis[u][v];
					maxAmount[v] = maxAmount[u] + team[v];
					pathNums[v] = pathNums[u];	
				}else if(d[u] + dis[u][v] == d[v]){
					if(maxAmount[u] + team[v] > maxAmount[v])
						maxAmount[v] = maxAmount[u] + team[v];
					pathNums[v] += pathNums[u];
				}
			}
			
			
			//不能写成下面这样，因为只要找到一条相同长度的最短路径，就要增加pathNums
			//而与点权是否更大无关 
//			else if(d[u] + dis[u][v] == d[v] && maxAmount[u] + team[v] > maxAmount[v] && vis[v] == false){
//				maxAmount[v] = maxAmount[u] + team[v];
//				pathNums[v] += pathNums[u];
//			}
		}
	}
}

int main(){
	// ※切记：提交的时候绝对不能把freopen带进去！！ 注释掉 
	freopen("1003_data.txt","r",stdin);
	cin >> N >> M >> s >> e;
	for(int i = 0; i < N; ++i){
		cin >> team[i];
	}
	for(int i = 0; i < M; ++i){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
		cin >> dis[u][v];
	}
	//算法逻辑已经不是最大的问题了，要特别注意的是一系列的初始化
	//宁可多此一举，也不要漏掉任何一个需要初始化的变量或数组
	//（需要初始化的基本都是数组，以及数组在start处的元素） 
	fill(d, d+MAXN, INF);
	memset(maxAmount, 0, sizeof(maxAmount));
	memset(vis, 0, sizeof(maxAmount));
	memset(pathNums, 0, sizeof(pathNums));
	d[s] = 0;                //起点到自身的最短距离为0 
	maxAmount[s] = team[s];   //起点可集结的最大队伍等于其自身拥有的队伍 
	pathNums[s] = 1;     //起点到自身的路径必须设为1 
	Dijkstra();
	cout << pathNums[e] << " " << maxAmount[e] << endl;
	//cout << d[e] << endl;
	return 0;
}
