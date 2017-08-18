##DFS：O(n+e)

###一、相关概念

* 无向图中
  * 两顶点连通：**无向图**中，两个顶点可以通过一定路径直接或间接到达
  * 连通图：无向图中任意两个顶点都连通，称为连通图
  * **连通分量：**非连通图中的极大连通子图（包含了小的连通子图），一个非连通图中会有多个连通分量


* 有向图中
  * 两顶点强连通：两顶点可以**各自**通过一条有向路径到达
  * 强连通图：任意两顶点都强连通
  * **强连通分量**：非强连通图中的极大连通子图


* 连通块：联通分量和强联通分量都称为连通块

###二、DFS思路(DFS(int start) 、 traveAll())

* 先考虑如何遍历一个连通块，再遍历所有连通块

* 关键：
  1. 使用一个vis[]一维数组记录**各个顶点**的访问状态，**要选择递归函数中合适的位置（第一行）设置访问状态：`vis[i] = true;`**
  2. 除了要判断顶点是否已访问外，**对于邻接矩阵实现的图还要判断两点之间是否有边（即`G[x][y]`是否为INF）**


* **遍历一个连通块的流程**，起点为u（DFS函数）：
  1. 设置vis[u] = true;
  2. 遍历从u出发能到达的所有顶点：
    1. 若该顶点未被访问过，则递归访问它
    2. 若已被访问过，则忽略


##三、邻接矩阵版实现

* 比邻接表要多考虑一些问题：
  * 需要初始化每个数组元素（如果不使用INF，而是用0表示没有边，也可以不初始化）
  * 需要判断两点之间是否有边（如可以设置常量INF，如果`G[u][v]==INF`，表示u、v之间没有边）


* 注意：多次调用DFS或traveAll时，要重置vis数组才行，邻接表实现也一样

```C++
const int INF = 0x3fffffff;
int G[100][100];     //图，存储边权，最多可以有100个顶点 
                     //G[u][v]为1表示有从u到v的边
					 //值为INF表示没有边 
bool vis[100] = {false}; //visited，记录是否访问过

//遍历一个连通块 ，参数u为起点 
void DFS(int u){
	vis[u] = true;     //必须先设置成已访问，再循环 
	for(int v = 0; v < 100; v++){
		if(G[u][v] != INF && vis[v] == false){
			printf("%d ",v);
			DFS(v); 
		}
	}
} 

//遍历整个图（所有连通块） 
void traveAll(){
	for(int u = 0 ; u < 100; u++){
		if(vis[u] == false){
			DFS(u);
		} 
	}
}
```

###四、（仅存储编号的）邻接表版

* 使用push_back添加连通关系：
  `Adj[0].push_back(1);`表示添加从0到1的有向边

* 第二维索引不是终点编号！！！，数组元素才是

```C++
#include<cstdio>
#include<vector>
#include<string.h>

using namespace std;

vector<int> Adj[100];    //起点编号=第一维索引；终点编号=数组元素（而不是第二维索引）
bool vis[100] = {false};

//遍历一个连通块
void DFS(int u){
	vis[u] = true;
	for(int i = 0; i < Adj[u].size(); i++){
		int v = Adj[u][i];
		if(vis[v] == false){
			printf("%d ",v);
			DFS(v);
		}
	}
}

//遍历整个图
void traveAll(){
	for(int i = 0; i < 5; i++){
		if(vis[i] == false){
			DFS(i);
		}
	}
}

int main(){
	//按《算法笔记》P351构造有向图 
	Adj[0].push_back(1);
	Adj[0].push_back(2);
	Adj[1].push_back(4);
	Adj[1].push_back(3);
	Adj[2].push_back(1);
	Adj[2].push_back(4);
	Adj[4].push_back(5);
	Adj[4].push_back(3);
	Adj[5].push_back(3);
	
	DFS(0);
	printf("\n");
	memset(vis,0,sizeof(vis));
	traveAll();
	return 0;
	
}
```

###五、（既存储结点编号又存储边权的）邻接表版

* 使用push_back添加连通关系：
  `Adj[0].push_back(Node(1));`表示添加从0到1的有向边

* 第二维索引不是终点编号！！！，数组元素的vertex成员才是

```
struct Node{
	int vertex;      //当前结点的编号，Adj[u][i].vertex 相当于邻接表G[u][v]中的v 
	int w;      //边权,在本例中未用到 
	Node(int _v):vertex(_v){}
	Node(int _v, int _w):vertex(_v),w(_w){}	
}; 

vector<Node> Adj[100];
bool vis[100] = {false};  //visited，记录顶点是否已访问

void DFS(int u){
	vis[u] = true;
	for(int i = 0; i < Adj[u].size(); i++){
		Node now = Adj[u][i];
		int t = now.vertex;
		if(vis[t] == false){
			printf("%d ",t);
			DFS(t);
		}
	}
}

void traveAll(){
	for(int i = 0; i < 5; i++){
		if(vis[i] == false){
			DFS(i);
		}
	}
}

int main(){
	//按《算法笔记》P351构造有向图 
	Adj[0].push_back(Node(1));
	Adj[0].push_back(Node(2));
	Adj[1].push_back(Node(4));
	Adj[1].push_back(Node(3));
	Adj[2].push_back(Node(1));
	Adj[2].push_back(Node(4));
	Adj[4].push_back(Node(5));
	Adj[4].push_back(Node(3));
	Adj[5].push_back(Node(3));
	
	
	DFS(0);
	printf("\n");
	memset(vis,0,sizeof(vis));
	traveAll();
	return 0;
}
```