#include<cstdio>
#include<cmath>

//死活执行错误！！！ 

//回溯法解决n皇后问题
/*
在暴力法基础上；
当放置了一部分皇后之后（生成了排列的一部分），剩余的皇后可能无论
怎样放置都会与之前（已放置）的某个皇后在一条对角线上，
（比如，第3个皇后无论怎么放置，都会与第1个皇后在一条对角线时） 
此时没必要往下递归，直接返回上层即可
**只有合法方案能到达递归边界  
*/ 

const int maxn = 11;
int n;      //1~n的排列
int P[maxn];       //存放当前排列 
int hashTable[maxn] = {false};
int count = 0;     //合法方案计数器 

void generateP(int index){
	if(index == n+1){
		for(int i = 1; i <= n; i++){
			printf("%d",P[i]);
		}
		printf("\n");
		count++;        //等执行到这的，都是合法方案 
		return;
	}
	for(int x = 1; x <= n; x++){
		if(hashTable[x] == false){     //若第x行还没有皇后 
			bool flag = true;        //flag为true表示当前皇后不会和之前的任何皇后冲突
			//判断将放置的皇后（行号为x），是否会和之前的皇后冲突 
			for(int pre = 1; pre < index; pre++){  //遍历之前的皇后 
				//第index列皇后的行号为x，第pre列皇后的行号为P[pre] 
				if(abs(index-pre) == abs(x-P[pre])){
					flag = false;
					break;  
				}
			} 
			//**注意！！不要误把下面的if写到前面的for循环中了 
			if(flag){
				P[index] = x; 
				hashTable[x] = true;
				generateP(index + 1);
				hashTable[x] = false;
			}
		} 
	}
	
} 

int main(){
	n = 8;
	generateP(1);
	printf("n=%d时，合法方案数为%d个",n,count);
	return 0;
} 
