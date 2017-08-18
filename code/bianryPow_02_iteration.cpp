#include<cstdio>

typedef long long LL;

LL binaryPow(LL a, LL b){
	LL answer = 1;         //初始值为1
	while(b > 0){
		if(b & 1){ //如果指数b的二进制形式的最低位为1（或者理解为b是奇数） 
			answer = answer * a;
		}
		a *= a;        //对a平方
		b >>= 1;       //b右移1位，直到b=0 
	}
	return answer; 
} 

int main(){
	LL ans = binaryPow(3,3);
	printf("3^3=%lld",ans);
	return 0;
}
