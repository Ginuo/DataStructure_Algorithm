#include<cstdio>

int father[100];

//寻找给定节点的根节点 
int findRoot(int x){
	int a = x; 
	printf("%d ",x);
	while(x != father[x]){
		x = father[x];
		printf("%d ",x);
	}
	printf("\n");
	//**压缩路径，优化查找，让路径上的所有结点直接指向根节点** 
	while(a != father[a]){
		int t = a; 
		a = father[a];
		father[t] = x; 
	} 
	
	return x;
} 

//合并两个结点所在的集合（两棵树）
void Union(int x, int y){
	int xr = findRoot(x);
	int yr = findRoot(y);
	if(xr == yr)	return; //本来就属于同一个集合，不需要合并
	father[xr] = y; //让x的根节点指向y 
} 

int main(){
	//初始化 
	for(int i = 1; i < 100; i++){
		father[i] = i;
	}
	//一个集合，5->4->3->2->1 
	father[2] = 1;
	father[3] = 2;
	father[4] = 3;
	father[5] = 4;
	findRoot(5);
	//另一个集合，8->9->10->11->12 
	father[8] = 9;
	father[9] = 10;
	father[10] = 11;
	father[11] = 12;
	findRoot(8); 
	
	Union(5,8);
	findRoot(5); 
	return 0;
}
 
