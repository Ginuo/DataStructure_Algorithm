#include<cstdio>

const int maxn = 100010;
int school[maxn] = {0};
int main(){
	int n;
	int sid,score;
	scanf("%d",&n);
	int m = n;      //����һ��n������whileѭ���ĵ���������ֱ�Ӷ�n�����Լ�������ֱ��д��forѭ��Ҳ�У������׳��� 
	while(m--){  
		scanf("%d%d",&sid,&score);
		school[sid] += score;
	}
	printf("fsdfsd\n");
	int maxID = 0, max = -1;
	for(int i = 1; i <= n; i++){
		if(school[i] > max){
			max = school[i];
			maxID = i;
		}
	} 
	printf("%d %d",maxID,max);
	return 0;	
} 
