#include<cstdio>
#include<cstring>

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	int sum = a+b;
	char str[30];
	sprintf(str,"%d",sum);
	int len = strlen(str);
	for(int i = 0; i < len; i++){
		if(i == 0 && str[i] == '-'){
			printf("-");
			continue;
		}
		int t = len - 1 - i;
		printf("%c",str[i]);
		if(t%3 == 0 && t != 0){
			printf(",");
		}
	}
	return 0;
} 
