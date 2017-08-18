#include<cstdio>

//�����ӷֽ�  prime factorization
//����180 = 2^2 ��3^2 ��5    ��2��������2,2��������3��1��������5��

//����г�ǰ10������������ʱ����������һ���������ɣ�Ȼ���룩 
int prime[10] = {2,3,5,7,11,13,17,19,23,29}; 

struct factor{
	int x;      //������ 
	int cnt;      //�������ӵĸ��� 
} fac[10];        //����Ҫ�����飬2��3��5��...��29���Ѿ�����int��Χ�� 

int num = 0;

void resolution(int n){
	for(int i = 0; i < 10; i++){
		if(n % prime[i] == 0){       //����������˵��prime[i]��n�������� 
			fac[num].x = prime[i];
			fac[num].cnt = 0;
			while(n % prime[i] == 0){   //����������prime[i]�ĸ��� 
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
	resolution(180);       //�ǵõ��ã��� 
	for(int i = 0; i < num; i++){
		printf("x=%d  cnt=%d\n",fac[i].x, fac[i].cnt);
	}
	return 0;
}
