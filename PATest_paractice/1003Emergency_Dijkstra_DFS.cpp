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
	//�мǣ���fill�Զ�ά������г�ʼ��ʱ����һ������Ӧ����G[0]��������д��G 
	//ͬ���ģ��ڶ�������ҲӦ����G[0]+xxx 
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
			//һ�����Է��ֵ�ʧ�󣺰�������������д�������ѭ����
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

//���·���ĳ����Ѿ���Dijkstra�����¼
//DFS��Ҫ���ڴ���ڶ��������
void DFS(int endp){
	if(endp == s){
		minPath.push_back(s);
		int tmpW = 0;
		for(int i = 0; i < minPath.size(); i++){
			tmpW += weight[ minPath[i] ];
		}
		if(tmpW > w[e])	w[e] = tmpW;
		//��ӡ���·�� 
//		for(int i = minPath.size()-1; i > 0; i--){
//			cout << minPath[i] << "-->";
//		}
//		cout << minPath[0] << endl;
		minPath.pop_back();
		return;
	}
	minPath.push_back(endp);                //�ȼ��� 
	for(int i = 0; i < pre[endp].size(); i++){
		DFS(pre[endp][i]);       //�ݹ���� 
	}
	minPath.pop_back();                      //���Ƴ� 
}

int main(){
	freopen("1003_data.txt", "r", stdin);
	init();
	Dijkstra();
	DFS(e);
	cout << paths[e] << " " << w[e] << endl;
	return 0;
}







