#include<cstdio>

//产生1000以内的素数 

const int maxn = 1000;
int prime[maxn];    //存放产生的素数
int pNum = 0;        //prime数组的索引
bool p[maxn] = {false};   //哈希表，如果i是素数，则p[i]==false（初始化全为false） 

void find_Prime(){
	for(int i = 2; i < maxn; i++){
		if(p[i] == false){
			prime[pNum++] = i;
			for(int j = i+i; j < maxn; j+=i){    //步长设置为j，筛去i的倍数
				p[j] = true;
			}
		}
	}
}

int main(){
	find_Prime();
	for(int i = 0; i < pNum; i++){
		printf("%3d ",prime[i]);
		if((i+1) % 10 == 0)	printf("\n");      //打印技巧**** 
	}
	return 0;
}
