##Kruskal算法

* 思路：
  1. 设置结构体数组edge存储**各条边（每条边包含两个顶点和一个边权）**（将边而不是顶点抽象成一个对象），并按边权从小到大排序
  2. （只需要一层循环）从小到大测试所有边，如果当前测试边所连接的两个顶点不在同一个连通块，则把这条测试边加入当前最小生成树；否则，跳过
  3. 直到最小生成树的`边数=总顶点数-1`（可以用if-break提前结束循环）或者测试完所有边时结束
  4. 如果边数<总顶点数-1，说明该图不连通，可以返回-1


###关键点一、判断一条边的两个顶点是否在同一个连通块（集合）中

* 可以当做并查集的查找操作，增加一个father数组和findFather函数，以顶点号为索引

* **记得初始化father数组，**`father[i] = i`，即首先是n（顶点数n）个连通块，每两个顶点都不连通

```
int father[500];

int findFather(int x){
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x; 
	} 
	return x;
}
```

###关键点二、将测试边加入生成树中

* 转化成，将测试边的两个顶点所在的集合合并（并查集的合并操作）

* **注意:**必须让一个顶点的根节点指向另一个顶点的根节点（`father[fau] = fav;`），只是让一个顶点指向另一个顶点(`father[u] = v`)是合并不了的！！

* 不确定就画个图吧！！
![](http://i.imgur.com/oGcLHix.png)
![](http://i.imgur.com/YtwMFvN.png)

###全部代码

```
#include<cstdio>
#include<algorithm>

using namespace std;

struct Edge{
	int u,v;
	int w;
	Edge(){}//空的构造函数必须要，否则无法初始化数组e！（虽然后面用不到这个构造函数） 
	Edge(int _u, int _v, int _w):u(_u),v(_v),w(_w){}
}e[500];

bool cmp(Edge a, Edge b){
	return a.w < b.w;
}

int father[500];
int n,m;   //n--->顶点数  m------>边数 

int findFather(int x){
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x; 
	} 
	return x;
}

int kruskal(){
	int sum = 0;          //边权和 
	int edgeCnt = 0;      //已加入的边数 
	for(int i = 0; i < n; i++){
		father[i] = i;
	}
	sort(e,e+m,cmp);
	for(int i = 0; i < m; i++){
		int u = e[i].u;
		int v = e[i].v;
		int w = e[i].w;
		int fau = findFather(u);
		int fav = findFather(v);
		if(fau != fav){
			sum += w;
			father[fau] = fav;
			//father[u] = v;  //***非常容易错，一个结点直接改为指向另一个结点并不能合并两个集合**
			                 //必须让一个结点的根节点指向另一个结点的根节点！！************* 
			                 //并查集合并的时候，最好画个图！！以防出现难找的bug 
			edgeCnt++;
			//边数=顶点数-1（树的性质）时，就可以退出循环了 
			if(edgeCnt==n-1)	break;   //加了这句会稍微快点，不加也不影响结果 
		}
	}
	if(edgeCnt == n-1)	return sum;
	if(edgeCnt < n-1)   return -1;   //该图不连通，返回-1 
	
}

int main(){
	n = 6;
	m = 10;
	//按409页构造图 
	e[0] = Edge(0,4,1);
	e[1] = Edge(0,1,4);
	e[2] = Edge(0,5,2);
	e[3] = Edge(5,1,3);
	e[4] = Edge(5,4,3);
	e[5] = Edge(5,3,4);
	e[6] = Edge(5,2,5);
	e[7] = Edge(1,2,1);
	e[8] = Edge(2,3,6);
	e[9] = Edge(3,4,5);
	int ans = kruskal();
	printf("%d\n",ans);
	return 0;
}
```