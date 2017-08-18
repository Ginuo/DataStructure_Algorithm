##最短路径

* 从起点到终点可能有很多条路径，其中边权之和最小的路径称为最短路径

##单源最短路径问题

* 给定图G和起点s，要求得到从s到达其他**每个顶点**的最短距离

##Dijkstra算法，由于是基于广度优先搜索，所以很容易用队列来优化，见《数据结构与算法》P245

##Dijkstra算法的原理：（一个贪婪算法）

* 基本思想（数学描述）：
  1. 对图G(V,E)设置集合S，存放已被访问过的顶点
  2. 然后每次从集合（V-S），即从未被访问过的顶点中选择与起点s的最短距离最小的顶点u，访问并加入集合S
  3. 以u为中介点，判断并**优化**起点s 与 从u能到达的所有顶点之间的最短距离
  4. **以上的操作执行n次（n=顶点个数）**，直到集合S包含了所有顶点（即所有顶点都被访问过了）


* 代码实现关键：
  1. 集合S用bool型的vis[n]表示；用数组d[n]记录从s到每个顶点的最短距离（最短路径的边权和），**d[起点]初始化为0，表示到起点的距离为0，其他元素初始化为INF（如0x3fffffff）**


* 算法伪代码框架：

```C++
Dijkstra(起点s){
	数组d中除d[s]之外的所有元素都初始化INF，d[s]初始化为0；
	for(循环n次){
		for(循环n次){
			找到未访问的顶点中与起点之间的最短距离最小的，记为顶点u
		}
		若找不到，则直接返回；
		记u已被访问；
		for(遍历从u能到达的所有顶点v){
			if(v未被访问过 && 以u为中介点（通过u访问v）能使s到v的最短距离d[v]更有){
				更新d[v];            //优化
			}
		}
	}
}
```

##局限性：边权不能为负，若有负边权，应使用SPFA算法

* 因为若有负边权，则可能形成一个无限的环路，使得含有负边权的路径越来越短

##一、邻接矩阵版

###一定要记得初始化图G[][]和最短距离数组d[]！！！！

###如何找出未访问的顶点中最短距离最小的顶点

* 定义变量MIN，初始为INF，然后遍历所有顶点，如果未访问**且其最短距离d[j]小于当前的最短距离MIN**，则更新MIN的值为d[j];

* 初始化二维数组`G[1000][1000]`的方法**（二维数组的地址也是连续的，初始地址是G[0]，也就是第一个一维数组的地址，总的有1000×1000个元素）**：
  `fill(a[0], a[0]+1000*1000， INF)`


```
int u = -1;      //u记录未访问的顶点中最短距离最小的那个顶点的下标
int MIN = INF;   //最小的最短距离
for(int j = 0; j < n; j++){ //遍历数组d，找出未访问的顶点中最短距离最小的 
	if(vis[j] == false && d[j] < MIN){//**注意这里使用MIN，而不能是INF**
		u = j;
		MIN = d[j];			
	}
}
```

```
int n;      //顶点个数 
int G[1000][1000];
const int INF = 0x3fffffff;
bool vis[1000] = {false};
int d[1000]; 

void Dijkstra(int s){
	fill(d,d+1000,INF);
	d[s] = 0;
	//这里假设顶点标号是按顺序的，如有n个顶点，则它们的编号为0~n-1
	//做题时读入顶点应注意遵循这条约定 
	for(int i = 0; i < n; i++){   //循环n次，而不是MAXV次 
		int u = -1;
		int MIN = INF; 
		for(int j = 0; j < n; j++){ //遍历数组d，找出未访问的顶点中最短距离最小的 
			if(vis[j] == false && d[j] < MIN){//**注意这里使用MIN，而不能是INF
				u = j;
				MIN = d[j];			
			}
		}
		if(u == -1) 	return;
		vis[u] = true;
		for(int v = 0; v < n; v++){
			//如果没有初始化图G中边权为INF，if条件在很多时候都成立 
			if(vis[v] == false && G[u][v] != INF && G[u][v]+d[u] < d[v]){
				d[v] = G[u][v] + d[u]; 
			}
		}
	}
}

int main(){
	n = 6;
	int s = 0;
	//将初始的边权全设为INF 
	fill(G[0],G[0]+1000*1000,INF); //***一定要初始化图！！！，不然错了很难调试 
	G[0][1] = 1;
	G[0][3] = 4;
	G[0][4] = 4;
	G[1][3] = 2;
	G[2][5] = 1;
	G[3][2] = 2;
	G[3][4] = 3;
	G[4][5] = 3;
	Dijkstra(s);
	for(int i = 0; i < n; i++){
		printf("%d ",d[i]);
	}
	return 0;
}
```

##二、邻接表版（推荐）

###1.记得初始化数组d元素为INF，邻接矩阵还需要初始化图G的所有边权为INF，邻接表不需要

```
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct node{
	int vertex;
	int weight;
	node(int v, int w):vertex(v),weight(w){}
};

vector<node> Adj[1000];
const int INF = 0x3fffffff;
int vis[1000] = {false};
int d[1000];
int n;  //顶点个数，默认添加顶点总是依次的，n个顶点下标为0~n-1 

void Dijkstra(int s){
	fill(d,d+1000,INF);    //切记初始化数组d 
	d[s] = 0;
	for(int i = 0; i < n; i++){  //循环n轮 
		int u = -1;
		int min = INF;
		for(int j = 0; j < n; j++){
			if(vis[j] == false && d[j] < min){  //注意是变化的min，不是常数INF 
				u = j;
				min = d[j];
			}
		}
		//剩余顶点中找不到最短距离小于INF的，说明余下的都与s不连通
		if(u == -1) 	return;  
		vis[u] = true;   //设置已访问 
		
		//***只有下面的for循环不同于邻接矩阵版*** 
		for(int k = 0; k < Adj[u].size(); k++){
			int v = Adj[u][k].vertex;
			int w = Adj[u][k].weight;
			if(vis[v] == false && w+d[u] < d[v]){
				d[v] = w + d[u];
			}
		}
	}
}

int main(){
	n = 6;
	//邻接表不能也不需要初始化图中所有边权为INF，但是邻接矩阵必须要！！ 
	Adj[0].push_back(node(1,1));
	Adj[0].push_back(node(3,4));
	Adj[0].push_back(node(4,4));
	Adj[1].push_back(node(3,2));
	Adj[2].push_back(node(5,1));
	Adj[3].push_back(node(2,2));
	Adj[3].push_back(node(4,3));
	Adj[4].push_back(node(5,3));
	Dijkstra(0);
	for(int i = 0; i < n ; i++){
		printf("%d ",d[i]);
	}
	return 0;
}
```

##以上程序仅仅求解出每个顶点到s的最短距离，而没有记录每条最短路径
##最短路径的记录

* 增加一个一维pre[]数组记录顶点的前驱,v的前驱是u，只要在上面的实现中增加两行代码即可

* **pre数组可以记录所有顶点到其他任一顶点的最短路径（如果连通）**

* 邻接矩阵：

```
int pre[1000];
·····
·····
for(int v = 0; v < n; v++){
	//如果没有初始化图G中边权为INF，if条件在很多时候都成立 
	if(vis[v] == false && G[u][v] != INF && G[u][v]+d[u] < d[v]){
		d[v] = G[u][v] + d[u]; 
		pre[v] = u;                    //增加的**，v的前驱结点是u
	}
}
```

* 邻接表：

```
int pre[1000];
······
······
//***只有下面的for循环不同于邻接矩阵版*** 
for(int k = 0; k < Adj[u].size(); k++){
	int v = Adj[u][k].vertex;
	int w = Adj[u][k].weight;
	if(vis[v] == false && w+d[u] < d[v]){
		d[v] = w + d[u];
		pre[v] = u;                   //增加的**，v的前驱结点是u 
	}
}
```

###最短路径的输出

* 利用pre[]数组从目标点e开始只能不断寻找前驱，直到起点s；要输出从起点s开始到终点e的最短路径需要递归
* 递归边界：s==e，说明已经追溯到了起点，此时需要输出起点


```C++
//对pre数组递归，得到指定起点到指定终点的最短路径
//按顺序打印出从起点s到e的最短路径上的结点 
void DFS(int s, int e){
	if(e == s){
		printf("%d ",s);   //递归边界，到达起点，打印出起点s并返回
		return; 
	}
	DFS(s,pre[e]);
	printf("%d ",e);     //输出每一层的顶点 
}
```


##有多条最短路径时，有些题目以第二标尺进行取舍

* 在最后一个for循环中调整判断条件，增加`d[u] + G[u][v] == d[v]`的情况（具体如何调整，视第二标尺要求而定）

* 如果仅需要求最短距离，不需要考虑最短路径的条数，不需要根据第二标尺取舍

* 第二标尺分类：
  * 边权：比如花费，最短路径有多条时，取花费最少的那条
  * 点权：比如可以收集到的物资，取多条最短路径中可收集物资最多的那条
  * 直接问**最短路径条数**


* 对于邻接矩阵实现的图：
  1. 若第二标尺是边权（以花费为例）：则需要增加一个**二维数组cost[][]**存放从u到v的花费，再增加一个一维数组c[]存放从起点到各个顶点的最少花费
  2. 若增加的是点权（以物资为例）：需要增加两个一维数组，一个用于存放每个顶点的物资数量，另一个存放从起点到各个顶点能收集的最大物资
  3. 若要求最短路径条数：增加一个一维数组num即可，存放各个顶点到起点的最短路径条数

* 对于邻接表实现的图：
  1. 边权：在结构中增加一个成员变量cost，存放从u到v的花费，令设一维数组c存放起点到各顶点的最少花费
  2. 点权：同邻接矩阵
  3. 路径条数：同邻接矩阵


* **特别注意路径条数的计算方法（P377）**，并不是简单的累加1：
  * d[v]可以优化时（即找到了更短的路径时），让num[v] = num[u]
  * 若又找到一条最短距离相同的路径，让num[v] += num[u]


###以增加了一个边权（花费）为例

* 源代码：`Dijkstra_+edge_weight.cpp`

* 求各点到起点的最短路径，如果存在相等的最短路径，取花费最少的那条，即**求到各点的最少花费的最短路径**

```
//***出现最短距离相同的最短路径时，取花费最少的路径 ；需要增加两个数组 

struct node{
	int v;
	int w;
	node(int _v, int _w){
		v = _v;
		w = _w;
	}
};

vector<node> Adj[500];
int n;    //顶底个数
int d[500]; 
const int INF = 0x3fffffff;
bool vis[500] = {false};
int cost[500][500];    //存放两点间的花费(边权)
int c[500];  //存放最小花费 

void Dijkstra(int s){
	fill(d,d+500,INF);
	fill(c,c+500,INF); 
	d[s] = 0;
	c[s] = 0;
	for(int i = 0; i < n; i++){
		int u = -1;
		int min = INF;
		for(int j = 0; j < n; j++){   //找出未访问的顶点中最短距离最小的 
			if(vis[j]==false && d[j] < min){
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int k = 0; k < Adj[u].size(); k++){
			int v = Adj[u][k].v;
			int w = Adj[u][k].w;
			if(vis[v] == false && d[u] + w < d[v]){
				d[v] = d[u] + w;
				c[v] = c[u] + cost[u][v];
			}else if(vis[v] == false && d[u] + w == d[v] && c[u] + cost[u][v] < c[v]){
				c[v] = c[u] + cost[u][v];
			}
		}
	}
} 

int main(){
	n = 6;
	//按P368构造图 , V1-->V3的距离改成了3（这样就会有两条从0到2的最短路径） 
	Adj[0].push_back(node(1,1));
	Adj[0].push_back(node(3,4));
	Adj[0].push_back(node(4,4));
	Adj[1].push_back(node(3,3));
	Adj[2].push_back(node(5,1));
	Adj[3].push_back(node(2,2));
	Adj[3].push_back(node(4,3));
	Adj[4].push_back(node(5,3));
	//花费是自己随便定的 
	cost[0][1] = 3;
	cost[0][3] = 5;
	cost[0][4] = 2;
	cost[1][3] = 4;
	cost[2][5] = 1;
	cost[3][2] = 6;
	cost[3][4] = 2;
	cost[4][5] = 8;
	
	Dijkstra(0);
	for(int i = 0 ; i < n; i++){
		printf("%d ",d[i]);
	}
	printf("\n");
	for(int i = 0; i < n; i++){
		printf("%d ",c[i]);
	}
	return 0;
}
```


##学会如何保存最短路径（P382）

* 使用一个名为pre的vector数组，存放每个顶点的所有前驱：`vector<int> pre[500];`

* `pre[v].push_back(u)`