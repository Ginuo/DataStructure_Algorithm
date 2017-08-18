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
