#include<cstdio>

//从a层到b层的时间 
int move(int a, int b){
	int time = 0;
	if(a >= b){    //down 
		time = 4 * (a-b) + 5;
	}else if(a < b){
		time = 6 * (b - a) + 5;
	}
	return time;
}

int main(){
	int N;
	int list[110];
	list[0] = 0;    //起始位置 
	scanf("%d",&N);
	for(int i = 1; i <= N; i++){
		scanf("%d",&list[i]);
	}
	int sum = 0;
	for(int i = 0; i < N; i++){
		sum = sum + move(list[i],list[i+1]); 
	}
	printf("%d",sum);
	return 0;
}
