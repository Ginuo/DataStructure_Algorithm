#include<cstdio>

int main(){
	int count[10];
	for(int i = 0; i < 10; i++){
		scanf("%d",&count[i]);
	}
	
	for(int i = 1; i < 10; i++){    //��1~9ѡ��һ��count��Ϊ�����С��������Ϊ���λ 
		if(count[i] > 0){
			printf("%d",i);
			count[i]--;         //�õ���һ��1 
			break;             //�����һλ���ɣ����������жϣ���Ϊ�������Ҫ��0 
		}
	}
	
	for(int i = 0 ; i < 10; i++){
		while(count[i]--){
			printf("%d",i);
		}
	}
	return 0;
}
