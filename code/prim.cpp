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
int d[500];  //����i�뼯��S����̾���
bool vis[500] = {false};
const int INF = 0x3fffffff;
int n ; //������ 

int prim(int s){
	int minW = 0;     //��С��Ȩ
	fill(d, d+500, INF);
	d[s] = 0;
	for(int i = 0; i < n; i++){
		int u = -1;
		int min = INF;
		for(int j = 0; j < n; j++){ //�ҳ�δ���ʵĶ������뼯��S������С�� 
			if(vis[j] == false && d[j] < min){
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return -1;//�Ҳ���С��INF��d[j],ʣ�¶��㶼�뼯��S����ͨ������-1 
		vis[u] = true;
		
		//*************************************************************
		//���ϴ��붼��Dijkstra�㷨��ͬ������return -1�� 
		 
		minW += d[u];
		for(int k = 0; k < Adj[u].size(); k++){
			int v = Adj[u][k].v;
			int w = Adj[u][k].w;
			if(vis[v] == false && w < d[v]){  //ע��ڶ����ж�����******* 
				d[v] = w;       //�Ż�d[v] 
			}
		} 
	}
	return minW; 
}

int main(){
	n = 6;
	//��P402����ͼ������ͼ˫��ֵ�������� 
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
	
	int ans = prim(0);   //����ͨ��prim����������С��Ȩ�� 
	printf("%d\n",ans);
	
	int ans1 = 0;
	for(int i = 0; i < n; i++){//Ҳ����ͨ���ۼ�����d[]��������С��Ȩ�� 
		ans1 += d[i];
	}
	printf("%d\n",ans1);
	return 0;
}
