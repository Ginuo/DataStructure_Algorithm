#include<cstdio>

//切分，确定一个元素的最终位置 
int partition(int a[], int left, int right){
	int temp = a[left];
	while(left < right){
		//**一定要先从右边开始扫描，因为left指针初始指向的元素已保存到temp，
		//所以a[0]的位置可以先被覆盖
		while(left < right && a[right] > temp)     right--;
		a[left] = a[right];
		while(left < right && a[left] <= temp)     left++;
		a[right] = a[left];
	} 
	a[left] = temp;
	return left;           //返回相遇的下标 ，必须！！！！！这是sort的依据 
} 

void sort(int a[], int left, int right){
	if(left >= right) return;         //递归出口 
	int pos = partition(a,left,right);
	sort(a,left,pos-1);
	sort(a,pos+1,right);
	
	//***下面的写法是错误的！！ 乍一看没毛病*** 
//	int mid = (left + right)/2; //因为并不是对半分的！！
//  而是以切分元素的位置作为左右划分依据的 
//	partition(a,left,right); 
//	sort(a, left, mid);
//	sort(a,mid+1, right);
}

int main(){
	int a[7] = {33,53,64,1,64,5,88};
	sort(a,0,6);
	for(int k = 0; k < 7; k++){
		printf("%d ",a[k]);
	}
	return 0;
}
