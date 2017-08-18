#include<cstdio>


typedef long long LL;
//快速幂的递归实现 
LL binaryPow(LL a, LL b){
	if(b==0) return 1;         //***递归边界 
	else if(b % 2 == 1){      //若b为奇数 
		return a * binaryPow(a,b-1);
	}else{                    //若b为偶数 
		LL mul = binaryPow(a,b/2);      //只写一个递归调用 
		return mul * mul;    
		//注意：不要写成return binaryPow(a,b/2) * binaryPow(a,b/2)，费时费栈
	}
}

int main(){
	LL result = binaryPow(10LL,10LL);
	printf("%ll
	d",result);     //***注意长整型输出使用%lld，不能使用%d，会出错的！！ 
	return 0;
}
