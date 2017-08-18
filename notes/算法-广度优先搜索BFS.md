##广度优先搜索

* 队列实现

* 当碰到岔道口时，总是先依次访问从该岔道口能直接到达的所有结点，然后再**按这些结点被访问的顺序**依次访问它们能直接到达的所有结点，以此类推

* 基本写法（模板）：

```C++
void BFS(int s){
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		取出队首元素top；
		访问队首元素；
		将队首元素出队pop；
		将与top直接相连的的下一层结点入队，并设置为已入队;
	}
}
```

##求矩阵中“块”的个数

* 问题描述：
  给出一个m×n的矩阵，矩阵中的元素为0或1.称位置(x,y)与其上下左右四个位置(x,y+1)、(x,y-1)、(x-1,y)、(x+1,y)是相邻的。如果矩阵中有若干个1**（可以是1个，也可以多于5个）**是相邻的，那么称这些1构成了一个“块”，求给定矩阵中块的个数。

* 求解思路：
  1. 枚举每个位置的元素，如果是0则跳过；
  2. 如果是1，则使用BFS查询与该位置相邻的四个位置（在不出界的前提下），判断它们是否也为1，如果相邻位置也是1，继续查询它的相邻位置，直到整个“块”访问完毕
  3. 如果某个位置已经**入队过**，则跳过
  4. 如果某个位置越界了，不在矩阵内，也跳过


* 技巧及注意点：
  1. 设置bool型二维数组inq记录每个位置是否入过队
  2. 最好单独设置一个judge函数判断某个位置（坐标）是否需要入队
    * **不需要入队的三种情况：**
      1. 该位置是0
      2. 该位置已经入队了
      3. 该位置不属于矩阵内，越界了
  3. 设置两个增量数组X={0,0,1,-1}，Y={1,-1,0,0}，便于枚举四个方向的元素
  4. 调用一次BFS函数，只能访问参数（x,y）所在的块，**并把该块中的元素1设置为已入队过**，所以还需要在main函数中**对每个位置判断是否要调用BFS()**

```C++
#include<cstdio>
#include<queue>

using namespace std;

struct node{
	int x,y;
} Node;

int m = 6,n = 7;        //m行，n列的矩阵 
const int maxn = 100;
int matrix[6][7] = {
					{0,1,1,1,0,0,1},
					{0,0,1,0,0,0,0},
					{0,0,0,0,1,0,0},
					{0,0,0,1,1,1,0},
					{1,1,1,0,1,0,0},
					{1,1,1,1,0,0,0}
					};
bool inq[maxn][maxn] = {false};      //in queue 记录每个位置是否已入队  
//增量数组，方便枚举四个方向的相邻元素 
int X[4] = {0,0,-1,1};
int Y[4] = {1,-1,0,0};


//（x，y）可以入队，则返回true 
bool judge(int x,int y){
	if(matrix[x][y] == 0)	return false;      //元素为0，不入队 
	else if(inq[x][y] == true)	return false;   //元素已入队，不可重复入队 
	else if(x >= n || x < 0 || y >= m || y < 0)	return false;//元素越界，不入队 
															//x>0,y>0易遗漏 
	return true;
}
//注意，参数需要x和y 
void BFS(int x, int y){
	Node.x = x;
	Node.y = y;
	queue<node> Q;
	Q.push(Node);
	while(!Q.empty()){
		node temp = Q.front();
		Q.pop();
		if(matrix[temp.x][temp.y] == 1)
			inq[temp.x][temp.y] = true;
		for(int i = 0; i < 4; i++){
			int newX = temp.x + X[i];
			int newY = temp.y + Y[i];
			if(judge(newX,newY)){    //如果该相邻位置需要访问 
				Node.x = newX;
				Node.y = newY;
				Q.push(Node);
				inq[newX][newY] = true;
			}
		} 
	}
}

int main(){
	int count = 0;
	for(int i = 0; i < m; i++){      //枚举每个位置
		for(int j = 0; j < n; j++) {
			//如果元素为1，且未入过队，则访问它所在的块，并将块数加一
			if(matrix[i][j] == 1 && inq[i][j] == false){
				count++;
				BFS(i,j);
			}
		}
	}
	printf("有%d个块\n",count);
	return 0;
}

```


##求从起点到达终点的最少步数（有墙壁）

* 类似上面的问题，在一个m行，n列的（字符）矩阵中，从指定的起点start到达终点end，字符'*'代表墙壁，不可通过，字符点号'.'表示可以通过，求最少步数。

* 思路：BFS访问start所在的点号'.'块，并记录每个点相对于start的层次（记录在node机构体中，start.layer = 0，以此类推），直到遇到end即返回end的层次，end.layer也就是最少的步数

```C++
#include<cstdio>
#include<queue>

using namespace std;

struct node{
	int x,y;
	int layer;        //layer记录结点相对于起点start的层数 
}start, end, Node;

const int maxn = 100;
int m = 5, n = 5;
char matrix[5][5] = {
					{'.','.','.','.','.'},
					{'.','*','.','*','.'},
					{'.','*','.','*','.'},
					{'.','*','*','*','.'},
					{'.','.','.','.','*'}};
bool inq[maxn][maxn] = {false};
int X[4] = {0,0,-1,1};
int Y[4] = {1,-1,0,0};


bool judge(int x, int y){
	if(matrix[x][y] == '*')	return false;
	else if(x >= m || x < 0 || y >= n || y < 0) return false;
	else if(inq[x][y] == true)	return false;
	return true;
} 

int BFS(){
	int layer = 0;
	queue<node> Q;
	Q.push(start);
	while(!Q.empty()){
		node temp = Q.front();
		Q.pop();
		if(temp.x == end.x && temp.y == end.y){
			return temp.layer;
		}
		for(int i = 0; i < 4; i++){ 
			int newX = temp.x + X[i];
			int newY = temp.y + Y[i];
			if(judge(newX,newY)){
				Node.x = newX;
				Node.y = newY;
				Node.layer = temp.layer+1;     //层数增加 
				Q.push(Node);
				inq[newX][newY] = true;	
			}
		}
	}
}

int main(){
	start.x = 2;
	start.y = 2;
	start.layer = 0;
	end.x = 4;
	end.y = 3;
	int minStep = BFS();
	printf("%d\n",minStep);
	return 0;
}
```

* **注意：（在以上例子中不需要考虑这一点，因为仅仅是对队列元素的访问，而没有修改）**
  * 使用STL的queue时，元素入队的push操作，只是传入了一个**副本**
  * 如果需要对STL的queue中的元素进行修改而不仅仅是访问时，队列中存放的元素最好不要是元素本身，而是他们的编号（如数组下标）