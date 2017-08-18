#include<cstdio>
#include<cmath>

//素数的判断

bool isPrime(int n){
	if(n <= 1) 	return false;
	int sqr = (int)sqrt(1.0*n);   //注意乘以1.0，把n变成浮点数
	for(int i = 2; i<=sqr; i++){      //2 到 不大于根号n的最大整数 
		if(n % i == 0)	return false;
	} 
	return true;
}

int main(){
	printf("9 is a Prime? %d\n",isPrime(9));
	printf("17 is a Prime? %d\n",isPrime(17));
	return 0;
}
