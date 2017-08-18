#include<cstdio>
//插入排序的一种写法，但访问数组次数较多 
void sort(int a[], int len){
	for(int i = 1; i < len; i++){
		for(int j = i; j > 0; j--){
			if(a[j] < a[j-1]){
				int t = a[j];
				a[j] = a[j-1];
				a[j-1] = t;
			}
		}
	}	
} 

int main(){
	int a[6] = {5,2,6,1,7,3};
	sort(a,6);
	for(int i = 0; i < 6; i++){
		printf("%d ", a[i]);
	}
	return 0;
}
