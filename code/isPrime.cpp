#include<cstdio>
#include<cmath>

//�������ж�

bool isPrime(int n){
	if(n <= 1) 	return false;
	int sqr = (int)sqrt(1.0*n);   //ע�����1.0����n��ɸ�����
	for(int i = 2; i<=sqr; i++){      //2 �� �����ڸ���n��������� 
		if(n % i == 0)	return false;
	} 
	return true;
}

int main(){
	printf("9 is a Prime? %d\n",isPrime(9));
	printf("17 is a Prime? %d\n",isPrime(17));
	return 0;
}
