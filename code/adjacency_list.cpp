#include<cstdio>
#include<string.h>
#include<algorithm>

using namespace std; 

int G[1000][1000];

int main(){
	for(int i = 0; i < 1000; i++){
		//只能使用0和-1 
		memset(G[i],0,sizeof(G[i]));   //初始化,memset属于string.h头文件
		//fill(G[i],G[i]+1000,0);     //用fill也可以 
	}
	printf("%d\n",G[3][24]);
	return 0;
}
