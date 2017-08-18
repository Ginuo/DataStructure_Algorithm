#仍然是BFS（遍历一个连通块）搭配traveAll（遍历所有连通块）

##复杂度：O(n+e)

##邻接矩阵实现

* 流程：
  1. 将inq[start]设置为true，并将start入队
  2. 去除队首元素，记为now
  3. 然后遍历所有能从now到达的**且未入过队的**顶点，并依次入队
  4. 重复2、3，直到队列为空

* 关键仍是：在合适的位置设置inq数组元素的状态
* 注意对遍历过程中各顶点的其他处理语句（比如printf，根据需要编写）的位置

```
//遍历一个连通块
void BFS(int start){
	inq[start] = true;     //设置已访问
	queue<int> Q;
	Q.push(start);
	while(!Q.empty()){
		int now = Q.front();
		Q.pop(); 
		for(int i = 0; i < 100; i++){
			if(inq[i] == false && G[now][i] != INF){
				printf("%d ",i);//对元素的处理语句只能放在这个if语句块中 
				Q.push(i);
				inq[i] = true;       //设置已访问
			}
		}
	}
}

//遍历整个图，所有连通块
void traveAll(){
	for(int i = 0; i < 100; i++){
		if(inq[i] == false){
			BFS(i);
		}
	}
} 
```

##邻接表实现

```
//遍历一个连通块
void BFS(int start){
	inq[start] = true;
	queue<int> Q;
	Q.push(start);
	while(!Q.empty()){
		int now = Q.front();
		Q.pop();
		for(int i = 0; i < Adj[now].size(); i++){
			int t = Adj[now][i];
			if(inq[t] == false){
				printf("%d ",t);
				Q.push(t);
				inq[t] = true;
			}
		}
	}
}

//遍历整个图
void traveAll(){
	for(int i = 0; i < 100; i++){
		if(inq[i] == false){
			BFS(i);
		}
	}
}

```

##