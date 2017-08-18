#include<cstdio>
#include<queue>

using namespace std;

struct node{
	int x,y;
} Node;

int m = 6,n = 7;        //m�У�n�еľ��� 
const int maxn = 100;
int matrix[6][7] = {
					{0,1,1,1,0,0,1},
					{0,0,1,0,0,0,0},
					{0,0,0,0,1,0,0},
					{0,0,0,1,1,1,0},
					{1,1,1,0,1,0,0},
					{1,1,1,1,0,0,0}
					};
bool inq[maxn][maxn] = {false};      //in queue ��¼ÿ��λ���Ƿ������  
//�������飬����ö���ĸ����������Ԫ�� 
int X[4] = {0,0,-1,1};
int Y[4] = {1,-1,0,0};


//��x��y��������ӣ��򷵻�true 
bool judge(int x,int y){
	if(matrix[x][y] == 0)	return false;      //Ԫ��Ϊ0������� 
	else if(inq[x][y] == true)	return false;   //Ԫ������ӣ������ظ���� 
	else if(x >= n || x < 0 || y >= m || y < 0)	return false;//Ԫ��Խ�磬����� 
															//x>0,y>0����© 
	return true;
}
//ע�⣬������Ҫx��y 
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
			if(judge(newX,newY)){    //���������λ����Ҫ���� 
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
	printf("��%d����\n",count);
	return 0;
}



