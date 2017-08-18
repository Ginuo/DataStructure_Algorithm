#include<cstdio>

const int maxn = 30;
int n;          //n件物品 
int V;          //背包容量V 
int maxV = 0;        //最大价值
int w[maxn]= {3,5,1,2,2};
int c[maxn]= {4,5,2,1,3};  //存储每件物品的重量和价值 

void DFS(int index, int sumW, int sumC){
	if(index == n){      //所有物品都选完了，结束递归 
		if(sumW <= V && sumC > maxV){  //当前方案的总价值大于以前方案的最大价值，更新最大价值 
			maxV = sumC;
		}
		return;
	}
	
	DFS(index+1,sumW,sumC);   //不选择第index号物品，不需要优化
	
	//该if语句块只是一种优化，出于做题时间考虑，可以不写 
	if(sumW + w[index] <= V){ //若选择第index号物品超重了，就不需要该趟递归了 
		if(sumC + c[index] > maxV){
			maxV = sumC + c[index];
		}
		DFS(index+1,sumW+w[index],sumC+c[index]); 
		//若选择index号物品不会超重，则选择第index号物品
	}
	
	
	 
}

int main(){
	n = 5;
	V = 8;
	DFS(0,0,0);
	printf("maxV=%d\n",maxV);
	return 0;
}
