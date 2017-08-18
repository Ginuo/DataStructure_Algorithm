#include<cstdio>


int gcd(int a, int b){
	if(b == 0)	return a;       //正整数和0的最大公约数为a 
	return gcd(b,a%b);
}

int main(){
	int ans1 = gcd(2,9);
	int ans2 = gcd(2,8);
	printf("2 and 9---%d;\n2 and 8---%d",ans1,ans2);
	return 0;
}
