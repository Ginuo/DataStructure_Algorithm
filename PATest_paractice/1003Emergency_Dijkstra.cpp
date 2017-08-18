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


int pathNums[MAXN] = {0};     //��start��������е����·������ 
int dis[MAXN][MAXN] = {0};   //�������м�ľ��� 
int team[MAXN] = {0};      //ÿ�����еĶ����� 
int d[MAXN] = {0};     //����������·��
int maxAmount[MAXN] = {0};   //��������������·���У��ܼ������������ 
bool vis[MAXN];    

void Dijkstra(){
	//ע�⣬�˴�����������vis[start] = true;
	//�����޷��ҳ�δ���ʶ�������̾�����С���Ǹ� 
	for(int i = 0; i < N; ++i){
		int u = -1, mind = INF;
		//ע�⣺�ڲ�ѭ��������Ҫ��д��i�������ͺ�����ظ��ˣ��п��ܳ����� 
		for(int j = 0; j < N; ++j){
			if(vis[j] == false && d[j] < mind){
				u = j;
				mind = d[j]; 
			}
		}
		if(u == -1)		return;
		vis[u] = true;              //ֻ������һ���ط����÷��ʱ�Ǽ��� 
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
			
			
			//����д��������������ΪֻҪ�ҵ�һ����ͬ���ȵ����·������Ҫ����pathNums
			//�����Ȩ�Ƿ�����޹� 
//			else if(d[u] + dis[u][v] == d[v] && maxAmount[u] + team[v] > maxAmount[v] && vis[v] == false){
//				maxAmount[v] = maxAmount[u] + team[v];
//				pathNums[v] += pathNums[u];
//			}
		}
	}
}

int main(){
	// ���мǣ��ύ��ʱ����Բ��ܰ�freopen����ȥ���� ע�͵� 
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
	//�㷨�߼��Ѿ��������������ˣ�Ҫ�ر�ע�����һϵ�еĳ�ʼ��
	//���ɶ��һ�٣�Ҳ��Ҫ©���κ�һ����Ҫ��ʼ���ı���������
	//����Ҫ��ʼ���Ļ����������飬�Լ�������start����Ԫ�أ� 
	fill(d, d+MAXN, INF);
	memset(maxAmount, 0, sizeof(maxAmount));
	memset(vis, 0, sizeof(maxAmount));
	memset(pathNums, 0, sizeof(pathNums));
	d[s] = 0;                //��㵽�������̾���Ϊ0 
	maxAmount[s] = team[s];   //���ɼ�������������������ӵ�еĶ��� 
	pathNums[s] = 1;     //��㵽�����·��������Ϊ1 
	Dijkstra();
	cout << pathNums[e] << " " << maxAmount[e] << endl;
	//cout << d[e] << endl;
	return 0;
}
