#include<cstdio>

//质因子分解  prime factorization
//例如180 = 2^2 ×3^2 ×5    （2个质因子2,2个质因子3，1个质因子5）

//打表列出前10个素数（考试时可以先用另一个程序生成，然后抄入） 
int prime[10] = {2,3,5,7,11,13,17,19,23,29}; 

struct factor{
	int x;      //质因子 
	int cnt;      //该质因子的个数 
} fac[10];        //不需要大数组，2×3×5×...×29就已经超过int范围了 

int num = 0;

void resolution(int n){
	for(int i = 0; i < 10; i++){
		if(n % prime[i] == 0){       //可以整除，说明prime[i]是n的质因子 
			fac[num].x = prime[i];
			fac[num].cnt = 0;
			while(n % prime[i] == 0){   //计算质因子prime[i]的个数 
				fac[num].cnt++;
				n /= prime[i];
			}
			num++;
		}
	}
	if(n != 1){
		fac[num].x = n;
		fac[num].cnt = 1;
		num++;
	}
}

int main(){
	resolution(180);       //记得调用！！ 
	for(int i = 0; i < num; i++){
		printf("x=%d  cnt=%d\n",fac[i].x, fac[i].cnt);
	}
	return 0;
}
