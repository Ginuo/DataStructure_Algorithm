#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

const int maxn = 210;
vector<int> Adj[maxn];
int N,M;
bool vis[1000000] = {false};

bool judge(int path[]){
	
	bool flag = false;
	for(int i = 1; i <= N; i++){
		int t = path[i];
		vis[t] = true;
		for(int j = 0; j < Adj[t].size(); j++){
			int v = Adj[t][j];
			if((vis[v] == false && v == path[i+1]) || (j == Adj[t].size() -1 && v == path[i+1])) {
				flag = true;
				break;
			}else{
				flag = false;
			}
		}
		if(flag == false)	return flag;
	}
	return flag;
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i = 0; i < M; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		Adj[u].push_back(v);
		Adj[v].push_back(u);     //编号是从1开始的 
	}
	int K;
	scanf("%d",&K);
	string ans[maxn];
	int index = 0;
	for(int i = 0; i < K; i++){
		int n ;
		scanf("%d",&n);
		int tpath[maxn];
		int cnt = 1;
		for(int j = 0; j < n; j++){
			int now ;
			scanf("%d",&now);
			tpath[cnt++] = now;
		}
		
		if(n != N+1 || tpath[1] != tpath[n]){
			ans[index++] = "NO";
		}else{
			bool flag = judge(tpath);
			if(flag == true)
				ans[index++] = "YES";
			else
				ans[index++] = "NO";
		}
	}
	for(int i = 0; i < index ; i++){
		cout << ans[i] << endl;
	}
	return 0;
}
