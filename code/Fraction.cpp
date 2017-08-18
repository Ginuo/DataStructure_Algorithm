#include<cstdio>
#include<cmath>

struct Fraction{
	long long up,down;       //long long�ͣ���ΪΪ���������п������ 
	
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

//���� 
Fraction reduction(Fraction result){
	if(result.down < 0){         //��֤��ĸ����0 
		result.up = -result.up;
		result.down = -result.down;
	}
	if(result.up == 0){
		result.down = 1;     //����ֵΪ0ʱ������Ϊ0�����涨��ĸΪ1 
	}else{
		//Լȥ���Լ��������Ҫ���������ʹ�����ͻ��ʣ�Լһ��Ҳ����ı� 
		int d = gcd(abs(result.up),abs(result.down));      //**ע�⣺ȡ����ֵ����gcd�㷨�����������
		result.up /= d;
		result.down /= d; 
	}
	return result;
} 

//�����ļӷ�
Fraction add(Fraction f1, Fraction f2){
	Fraction result ;
	result.up = f1.up * f2.down + f2.up * f1.down;
	result.down = f1.down * f2.down;
	return result;
}

//����minus 
Fraction minu(Fraction f1, Fraction f2){
	Fraction result;
	result.up = f1.up * f2.down - f2.up * f1.down;
	result.down = f1.down * f2.down;
	return result; 
}

//�˷� ������

//���
void show(Fraction r){
	r = reduction(r);     //�ǵû���
	if(r.down == 1)
		printf("%lld\n",r.up);        //down==1���÷�����һ������ 
	else if(abs(r.up) > r.down)      //�Ǽٷ���ʱ 
		printf("%lld %lld/%lld\n",abs(r.up)/r.down, abs(r.up)%r.down,r.down);
	else{                 //�����ʱ 
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
