##最小生成树：针对无向图

* 生成树：加权**无向图**中含有所有顶点的无环连通子图

* 最小生成树：边权之和最小的生成树

* 最小生成树的性质：
  1. 是树，所以边数 = 顶点数 - 1
  2. 因为是树，所以没有环
  3. 对给定的无向图G，最小生成树可以不唯一，但边权之和一定是唯一的
  4. 任意结点都可以作为根节点，需要时具体用哪个一般题目会给定


##prim算法（贪婪算法）

* 数学描述：
  用集合S存放已访问的顶点，每次从未访问的顶点集V-S中找到离**集合S**的最短距离最小的顶点u，访问并加入S；
  令顶点u为中介点，判断并优化所有能从u到达的顶点到**集合S**的最短距离

* 与最短路径的Dijkstra算法非常类似，不同之处仅在于，Dijkstra算法中是“到**起点s**的最短距离”，而不是“到**集合S**的最短距离”


* **☆对考试题如何区分是要求最短路径还是最小生成树？☆**
  * 若要求经过**所有顶点**------>最小生成树
  * 若要求某一点到另一点，或所有点到另一点的最短距离（路径）------>最短路径


* 实现的关键点（尤其注意无向图的初始化）：
  1. 数组d用于存放各个顶点离集合S的最短距离，运行结束时，数组d中所有元素的和就是最小边权（一般在prim函数中一步步累加，最后直接返回最小边权）
  2. 因为前提是无向图，所以图在初始化时要**双向赋值！！！**，不然运行会出错
  3. if(u == -1) return -1； 不要像Dijkstra算法返回空值（当然，如果最终通过d数组计算最小边权和，也可以不需要返回值）
  4. 注意是否优化d[v]的判断条件


```C++
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
```

##同样可以增加边权，计算一个全局的最小成本

##复杂度

* O(V^2)
* 使用堆优化后：O(ElogV)
* 适合于稀疏图（顶点少、边多），效果较好