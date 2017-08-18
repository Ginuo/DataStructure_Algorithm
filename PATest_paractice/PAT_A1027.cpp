#include<cstdio>


void toRadix13(int num){
	int index = 0;
	int ans[10];
	char str[10];
	do{
		ans[index++] = num % 13;
		num /= 13;
	}while(num != 0);
	int res = 0;
	int t = 1;
	for(int i = 0; i < index; i++){
		if(ans[i] == 10){
			str[i] = 'A';
		}else if(ans[i] == 11){
			str[i] = 'B';
		}else if(ans[i] == 12){
			str[i] = 'C';
		}else{
			str[i] = '0' + ans[i];
		}
	}
	if(index == 1)	printf("0");       //答案只有一位时，需要补零 
	for(int i = index-1; i >= 0; i--){
		printf("%c",str[i]);
	}
}

int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("#");
	toRadix13(a);
	toRadix13(b);
	toRadix13(c);
	
	return 0;
}
