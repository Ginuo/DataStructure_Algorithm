#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm> 

using namespace std;

struct node{
	int V;
	int L;
	node(int _v, int _l){
		V = _v;
		L = _l;
	}
};

const int INF = 0x3fffffff;

const int maxn = 500;
int amount[maxn];
int m,n,start,end;
vector<node> map[maxn];
int d[maxn*3];
int pathCnt[maxn];
int maxTeam[maxn];
bool vis[maxn] = {false};


void Dijkstra(){
	fill(d,d+n,INF);
	memset(pathCnt,0,sizeof(pathCnt));
	memset(maxTeam,0,sizeof(maxTeam));
	d[start] = 0;
	pathCnt[start] = 1;
	maxTeam[start] = amount[start];
	for(int i = 0; i <n ; i++){
		int u = -1;
		int MIN = INF;
		for(int j = 0; j < n; j++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}	
		}
		//不要把下面所有的语句写到上面的for循环中去了
		//虽然错得离谱，但是真的很难找出来！！！ 
		if(u == -1)		return;
		vis[u] = true;
		for(int k = 0; k < map[u].size(); k++){
			int v = map[u][k].V;
			int l = map[u][k].L;
			if(vis[v] == false){
				if(d[u] + l < d[v]){
					d[v] = d[u] + l;
					pathCnt[v] = pathCnt[u];
					maxTeam[v] = maxTeam[u] + amount[v];
				}else if(d[u] + l == d[v]){
					pathCnt[v] = pathCnt[v] + pathCnt[u];
					if( maxTeam[u] + amount[v] > maxTeam[v]){
						maxTeam[v] = maxTeam[u] + amount[v];
					}
				}
				
			}
		}
	}
	
}

int main(){
	scanf("%d%d%d%d",&n,&m,&start,&end);
	for(int i = 0; i < n; i++){
		scanf("%d",&amount[i]);
	}
	for(int i = 0; i < m; i++){
		int c1,c2,l;
		scanf("%d%d%d",&c1,&c2,&l);
		map[c1].push_back(node(c2,l));
		map[c2].push_back(node(c1,l));
	}
	Dijkstra();
	
	printf("%d %d",pathCnt[end],maxTeam[end]);

	return 0;
} 
