#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct node{
	int v;
	int w;
	node(int _v, int _w){
		v = _v;
		w = _w;
	}
}; 

vector<node> Adj[500];
int d[500];  //顶点i离集合S的最短距离
bool vis[500] = {false};
const int INF = 0x3fffffff;
int n ; //顶点数 

int prim(int s){
	int minW = 0;     //最小边权
	fill(d, d+500, INF);
	d[s] = 0;
	for(int i = 0; i < n; i++){
		int u = -1;
		int min = INF;
		for(int j = 0; j < n; j++){ //找出未访问的顶点中离集合S距离最小的 
			if(vis[j] == false && d[j] < min){
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return -1;//找不到小于INF的d[j],剩下顶点都与集合S不连通，返回-1 
		vis[u] = true;
		
		//*************************************************************
		//以上代码都和Dijkstra算法相同（除了return -1） 
		 
		minW += d[u];
		for(int k = 0; k < Adj[u].size(); k++){
			int v = Adj[u][k].v;
			int w = Adj[u][k].w;
			if(vis[v] == false && w < d[v]){  //注意第二个判断条件******* 
				d[v] = w;       //优化d[v] 
			}
		} 
	}
	return minW; 
}

int main(){
	n = 6;
	//按P402构造图，无向图双向赋值！！！！ 
	Adj[0].push_back(node(1,4));
	Adj[0].push_back(node(5,2));
	Adj[0].push_back(node(4,1));
	Adj[1].push_back(node(0,4));
	Adj[1].push_back(node(5,3));
	Adj[1].push_back(node(2,6));
	Adj[2].push_back(node(1,6));
	Adj[2].push_back(node(5,5));
	Adj[2].push_back(node(3,6));
	Adj[3].push_back(node(2,6));
	Adj[3].push_back(node(5,5));
	Adj[3].push_back(node(4,4));
	Adj[4].push_back(node(3,4));
	Adj[3].push_back(node(5,3));
	Adj[4].push_back(node(0,1));
	Adj[5].push_back(node(0,2));
	Adj[5].push_back(node(1,3));
	Adj[5].push_back(node(2,5));
	Adj[5].push_back(node(3,5));
	Adj[5].push_back(node(4,3));
	
	int ans = prim(0);   //可以通过prim函数返回最小边权和 
	printf("%d\n",ans);
	
	int ans1 = 0;
	for(int i = 0; i < n; i++){//也可以通过累加数组d[]，计算最小边权和 
		ans1 += d[i];
	}
	printf("%d\n",ans1);
	return 0;
}
