#include<cstdio>
#include<cstring>



int main(){
	char num[110];
	gets(num);
	int len = strlen(num);
	int sum = 0;
	for(int i = 0; i < len; i++){
		sum = sum + (num[i] - '0'); 
	}
	int ans[100];
	int index = 0;
	do{
		ans[index++] = sum % 10;
		sum = sum / 10;
	}while(sum != 0);
	for(int i = index-1 ; i >= 0; i--){
		switch(ans[i]){
			case 0:
				printf("zero");
				break;
			case 1:
				printf("one");
				break;
			case 2:
				printf("two");
				break;
			case 3:
				printf("three");
				break;
			case 4:
				printf("four");
				break;
			case 5:
				printf("five");
				break;
			case 6:
				printf("six");
				break;
			case 7:
				printf("seven");
				break;
			case 8:
				printf("eight");
				break;
			case 9:
				printf("nine");
				break;
		}
		if(i > 0)	printf(" ");
	}
	return 0;
}
