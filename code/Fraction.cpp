#include<cstdio>
#include<cmath>

struct Fraction{
	long long up,down;       //long long型，因为为乘数过程中可能溢出 
	
	Fraction(){}
	Fraction(int u, int d){
		up = u;
		down = d;
	}
}; 

int gcd(long long a, long long b){
	if(b == 0) 	return a;
	return gcd(b,a%b);
}

//化简 
Fraction reduction(Fraction result){
	if(result.down < 0){         //保证分母大于0 
		result.up = -result.up;
		result.down = -result.down;
	}
	if(result.up == 0){
		result.down = 1;     //分数值为0时（分子为0），规定分母为1 
	}else{
		//约去最大公约数，不需要分情况，即使本来就互质，约一下也不会改变 
		int d = gcd(abs(result.up),abs(result.down));      //**注意：取绝对值！！gcd算法仅针对正整数
		result.up /= d;
		result.down /= d; 
	}
	return result;
} 

//分数的加法
Fraction add(Fraction f1, Fraction f2){
	Fraction result ;
	result.up = f1.up * f2.down + f2.up * f1.down;
	result.down = f1.down * f2.down;
	return result;
}

//减法minus 
Fraction minu(Fraction f1, Fraction f2){
	Fraction result;
	result.up = f1.up * f2.down - f2.up * f1.down;
	result.down = f1.down * f2.down;
	return result; 
}

//乘法 除法略

//输出
void show(Fraction r){
	r = reduction(r);     //记得化简
	if(r.down == 1)
		printf("%lld\n",r.up);        //down==1，该分数是一个整数 
	else if(abs(r.up) > r.down)      //是假分数时 
		printf("%lld %lld/%lld\n",abs(r.up)/r.down, abs(r.up)%r.down,r.down);
	else{                 //真分数时 
		printf("%lld/%lld\n",r.up,r.down);
	}
} 

int main(){
	Fraction r1 = Fraction(14,29);
	Fraction r2 = Fraction(29,14);
	Fraction r3 = Fraction(9,-9);
	show(r1);
	show(r2);
	show(r3);
	return 0;
}
