#include<cstdio>
 
//归并排序的递归实现 
 
void merge(int a[], int L1, int R1, int L2, int R2);

//***逻辑很简单，左排序，右排序，左右归并 
void sort(int a[], int left, int right){
	if(left >= right)	return;       //递归出口也很自然 
	int mid = (left + right)/2;
	sort(a, left, mid);             //对左边排序 
	sort(a, mid+1, right);          //对右边排序 
	merge(a,left, mid, mid+1, right);  //左右归并 
}

//将区间[L1,R1]和[L2,R2]归并
//关键就在于使用两根指针合并两组，并把合并结果复制到原数组 
void merge(int a[], int L1, int R1, int L2, int R2){
	int i = L1, j = L2;           //两根指针
	int temp[R2 - L1 + 1];       //需要临时数组用于存放合并后的序列   
	int index = 0;
	while(i <= R1 && j <= R2){
		if(a[i] <= a[j]){
			temp[index++] = a[i++];
		}else{
			temp[index++] = a[j++];
		}
	} 
	while(i <= R1)		temp[index++] = a[i++];
	while(j <= R2)		temp[index++] = a[j++];
	//将临时数组的结果复制到数组a 
	for(int k = 0; k < index; k++){
		a[L1+k] = temp[k];
	}
}

int main(){
	int n;
	while(scanf("%d",&n) != EOF){         //Ctrl+Z表示文件尾 
		int b[n];
		for(int i = 0; i < n; i++){
			scanf("%d",&b[i]);
		}
		sort(b,0,n-1);
		for(int i = 0; i < n; i++){
			printf("%d\n",b[i]);
		} 
	}
	return 0;
}
//
//int main(){
//	int a[7] = {66,12,33,57,64,27,18};
//	sort(a,0,6);
//	for(int i = 0; i < 7; i++){
//		printf("%d ", a[i]);
//	}
//	return 0;
//}


