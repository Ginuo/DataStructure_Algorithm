#include<cstdio>

//����1000���ڵ����� 

const int maxn = 1000;
int prime[maxn];    //��Ų���������
int pNum = 0;        //prime���������
bool p[maxn] = {false};   //��ϣ�����i����������p[i]==false����ʼ��ȫΪfalse�� 

void find_Prime(){
	for(int i = 2; i < maxn; i++){
		if(p[i] == false){
			prime[pNum++] = i;
			for(int j = i+i; j < maxn; j+=i){    //��������Ϊj��ɸȥi�ı���
				p[j] = true;
			}
		}
	}
}

int main(){
	find_Prime();
	for(int i = 0; i < pNum; i++){
		printf("%3d ",prime[i]);
		if((i+1) % 10 == 0)	printf("\n");      //��ӡ����**** 
	}
	return 0;
}
