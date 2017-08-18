#include<cstdio>

const int maxn = 100010;
int school[maxn] = {0};
int main(){
	int n;
	int sid,score;
	scanf("%d",&n);
	int m = n;      //复制一个n，用于while循环的迭代（不能直接对n进行自减！），直接写成for循环也行，不容易出错 
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
