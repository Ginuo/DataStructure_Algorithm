#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

struct node{
	int u;
	int w;
	node(int _u, int _w):u(_u),w(_w){}
};

int indegree[500];
vector<node> Adj[500];
stack<int> topOrder;
int ve[500];
int vl[500];
int n;

bool toplogicalSort(){
	for(int i = 0; i < n; i++){
		if(indegree[i] == 0){
			topOrder.push(i);
		}
	}
	queue<int> q;
	int sum = 0;       //用于判断是否是有向无环图 
	q.push(0);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		sum++;
		topOrder.push(u);      //入栈的位置很重要，这句不能在for循环内 
		for(int i = 0; i < Adj[u].size(); i++){
			int v = Adj[u][i].u;
			int w = Adj[u][i].w;
			indegree[v]--;
			if(indegree[v] == 0)	q.push(v);
			if(ve[v] < ve[u] + w){    //注意符号，max{某前驱结点的最早开始时间+相应的活动持续时间} 
				ve[v] = ve[u] + w;
			}
			
		}
	}
	if(sum == n)	return true;
	else if(sum > n)	return false;
}

int criticalPath(){
	//初始化vl数组，先让vl每个元素都等于工程结束所需的时间
	//即，最后一个事件的开始时间（最早最晚相等） 
	fill(vl,vl+n,ve[n-1]);           
	while(!topOrder.empty()){
		int u = topOrder.top();
		topOrder.pop();
		for(int i = 0; i < Adj[u].size(); i++){
			int v  = Adj[u][i].u;
			int w = Adj[u][i].w;
			if(vl[u] > vl[v] - w){//vl[u] = min{后继结点v的最晚开始时间 - 相应的活动持续时间}
				vl[u] = vl[v] - w;
			} 
		}
	}
	
	for(int u = 0; u < n; u++){     //遍历所有边 
		for(int j = 0; j < Adj[u].size(); j++){
			int v = Adj[u][j].u;
			int w = Adj[u][j].w;
			int e = ve[u];     //活动最早开始时间=前驱事件最早开始时间 
			int l = vl[v] - w; //活动最晚开始时间=后继时间最晚开始时间 - 活动持续时间 
			if(e == l){      //判断并输出所有关键活动（可连成关键路径） 
				printf("%d-->%d\n",u,v);
			}
		} 
	}
	return ve[n-1];   //关键路径长度   =vl[n-1] 
}

int main(){
	int m;//m边数(**注意**顶点数n已经定义成了全局变量，不能重复定义，否则会覆盖)
	scanf("%d%d",&n,&m);
	for(int i = 0; i < m; i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		Adj[u].push_back(node(v,w));
		indegree[v]++;
	} 
	
	//方便测试 
//	indegree[0] = 0;
//	indegree[1] = 1;
//	indegree[2] = 1;
//	indegree[3] = 1;
//	indegree[4] = 2;
//	indegree[5] = 1;
//	Adj[0].push_back(node(1,30));
//	Adj[0].push_back(node(3,40));
//	Adj[1].push_back(node(2,40));
//	Adj[3].push_back(node(4,40));
//	Adj[2].push_back(node(4,50));
//	Adj[4].push_back(node(5,70));
	
	if(toplogicalSort()){
		int len = criticalPath();
		printf("length of the criticalPath is %d\n",len);
	}else{
		printf("false");
	}
	return 0;
}

