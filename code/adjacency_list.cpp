#include<cstdio>
#include<string.h>
#include<algorithm>

using namespace std; 

int G[1000][1000];

int main(){
	for(int i = 0; i < 1000; i++){
		//ֻ��ʹ��0��-1 
		memset(G[i],0,sizeof(G[i]));   //��ʼ��,memset����string.hͷ�ļ�
		//fill(G[i],G[i]+1000,0);     //��fillҲ���� 
	}
	printf("%d\n",G[3][24]);
	return 0;
}
