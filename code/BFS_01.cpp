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
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++) {
			if(matrix[i][j] == 1 && inq[i][j] == false){
				count++;
				BFS(i,j);
			}
		}
	}
	printf("有%d个块\n",count);
	return 0;
}



