#include<cstdio>

typedef long long LL;

LL binaryPow(LL a, LL b){
	LL answer = 1;         //��ʼֵΪ1
	while(b > 0){
		if(b & 1){ //���ָ��b�Ķ�������ʽ�����λΪ1���������Ϊb�������� 
			answer = answer * a;
		}
		a *= a;        //��aƽ��
		b >>= 1;       //b����1λ��ֱ��b=0 
	}
	return answer; 
} 

int main(){
	LL ans = binaryPow(3,3);
	printf("3^3=%lld",ans);
	return 0;
}
