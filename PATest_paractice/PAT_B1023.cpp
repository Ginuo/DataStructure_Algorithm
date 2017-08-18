#include<cstdio>

int main(){
	int count[10];
	for(int i = 0; i < 10; i++){
		scanf("%d",&count[i]);
	}
	
	for(int i = 1; i < 10; i++){    //从1~9选择一个count不为零的最小的数字作为最高位 
		if(count[i] > 0){
			printf("%d",i);
			count[i]--;         //用掉了一个1 
			break;             //输出了一位即可，必须马上中断，因为后面可能要填0 
		}
	}
	
	for(int i = 0 ; i < 10; i++){
		while(count[i]--){
			printf("%d",i);
		}
	}
	return 0;
}
