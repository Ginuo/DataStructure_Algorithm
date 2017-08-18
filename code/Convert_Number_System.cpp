#include<cstdio>

int q[20];
int cnt = 0;

//P进制x转换成十进制 
int toTen(int x, int P){
	int product = 1;  //初始为1，不是0！！ 
	int ans = 0;
	while(x != 0){    //注意条件 x!=0 
		ans = ans + (x % 10) * product;
		x = x/10;
		product = product * P;       //*P进制 
	}
	return ans;
} 

//十进制x转换成Q进制 
//除Q取余法，do-while循环 
void toQ(int x, int Q){
	
	do{
		q[cnt++] = x % Q;
		x = x / Q;
	}while(x != 0);     //条件也是x!=0 
}

int main(){
	int x = 16;
	int ans = toTen(x,8);
	toQ(ans,8);
	printf("%d的十进制：%d\n%d的八进制：",x,ans,ans);
	for(int i = cnt-1; i >= 0; i--){
		printf("%d",q[i]);
	}
	return 0 ;
}
