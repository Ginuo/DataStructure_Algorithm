#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

const int maxn = 500;

struct node{
	int u;
	int w;
	node(int _u, int _w){
		u = _u;
		w = _w;
	}
};
vector<node> Adj[maxn];

stack<int> topOrder;      //存放拓扑序列
int indegree[500];  //入度数组 
int ve[maxn];
int vl[maxn];
int n;

void generateVe(){
	queue<int> q;
	for(int i = 0; i < n; i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int now = q.front();
		q.pop();
		st.push(now);
		for(int i = 0; i < Adj[now].size(); i++){
			int t = Adj[now][i].u;
			indegree[t]--;
			if(indegree[t] == 0){
				q.push(t);
			}
			if(ve[now] + Adj[now][i].w > ve[t]){
				ve[t] = ve[now] + Adj[now][i].w;	
			}
		}
	}
}

void generateVl(){
	fill(vl,vl+n,ve[n-1]);

	while(!st.empty()){
		int now = st.top();
		st.pop();
		for(int i = 0; i < Adj[now].size(); i++){
			int v = Adj[now][i].u;
			int w = Adj[now][i].w;
			if(vl[i] - w < vl[now]){
				vl[now] = vl[i]-w;
			}
		}
		
	}
}

int criticalPath(){

	for(int u = 0; u < n; u++){
		for(int j = 0; j < Adj[u].size(); j++){
			int v = Adj[u][j].u;
			int w = Adj[u][j].w;
			if(ve[u] == vl[v] - w){
				printf("%d %d\n",u,v);
			}
		}
	}
	return ve[n-1];
	
}


int main(){
	n = 6; 
	indegree[0] = 0;
	indegree[1] = 1;
	indegree[2] = 1;
	indegree[3] = 1;
	indegree[4] = 2;
	indegree[5] = 1;
	Adj[0].push_back(node(1,30));
	Adj[0].push_back(node(3,40));
	Adj[1].push_back(node(2,40));
	Adj[3].push_back(node(4,40));
	Adj[2].push_back(node(4,50));
	Adj[4].push_back(node(5,70));
	generateVe();
	generateVl();
	criticalPath();
	return 0;
}










