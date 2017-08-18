#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 510;
const int INF = 0x3effffff;

int G[maxn][maxn];
vector<int> pre[maxn];
vector<int> minPath;
bool vis[maxn] = {false};

int weight[maxn];
int d[maxn];
int w[maxn] = {0};
int paths[maxn] = {0};

int N,M;
int s,e;

void init(){
	//切记：用fill对二维数组进行初始化时，第一个参数应该是G[0]，而不能写成G 
	//同样的，第二个参数也应该是G[0]+xxx 
	fill(G[0], G[0]+maxn*maxn, INF);
	fill(d, d+maxn, INF);
	cin >> N >> M >> s >> e;
	for(int i = 0; i < N; i++)	cin >> weight[i];
	int u,v;
	for(int i = 0; i < M; i++){
		cin >> u >> v;
		cin >> G[u][v];
		G[v][u] = G[u][v];
	}
	d[s] = 0;
	w[s] = weight[s];
	paths[s] = 1;
}

void Dijkstra(){
	for(int i = 0; i < N; i++){
		int u = -1, MIN=INF;
		for(int j= 0; j < N; j++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
			//一个难以发现的失误：把下面的所有语句写在了这个循环内
		}
		
		if(u == -1)	return;
		vis[u] = true;
		for(int v = 0; v < N; v++){
			if(G[u][v] != INF && vis[v] ==false){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					paths[v] = paths[u];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u] + G[u][v] == d[v]){
					paths[v] += paths[u];
					pre[v].push_back(u);
				}
			}
		}
	}
}

//最短路径的长度已经由Dijkstra负责记录
//DFS主要用于处理第二第三标尺
void DFS(int endp){
	if(endp == s){
		minPath.push_back(s);
		int tmpW = 0;
		for(int i = 0; i < minPath.size(); i++){
			tmpW += weight[ minPath[i] ];
		}
		if(tmpW > w[e])	w[e] = tmpW;
		//打印最短路径 
//		for(int i = minPath.size()-1; i > 0; i--){
//			cout << minPath[i] << "-->";
//		}
//		cout << minPath[0] << endl;
		minPath.pop_back();
		return;
	}
	minPath.push_back(endp);                //先加入 
	for(int i = 0; i < pre[endp].size(); i++){
		DFS(pre[endp][i]);       //递归调用 
	}
	minPath.pop_back();                      //再移除 
}

int main(){
	freopen("1003_data.txt", "r", stdin);
	init();
	Dijkstra();
	DFS(e);
	cout << paths[e] << " " << w[e] << endl;
	return 0;
}







