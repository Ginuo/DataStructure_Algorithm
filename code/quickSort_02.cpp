 #include<cstdio>
 #include<cstdlib>
 #include<ctime>
 
 //随机化的快速排序 
 
 int partition(int a[], int left, int right){
 	srand((unsigned)time(NULL));        //生成随机数种子 
 	int rnd = left + rand() % (right-left+1);    //生成[left,right]之间的随机整数 
	//先把随机的元素与首元素交换，然后就可以照常使用基本的快排算法 
	int temp = a[rnd];
	a[rnd] = a[left];
	a[left] = temp;
	
	while(left < right){
 		while(left < right && a[right] > temp)	right--;
		a[left] = a[right];
		while(left < right && a[left] <= temp)	left++;
		a[right] = a[left];	
	}
	a[left] = temp;
	return left;
 }
 
 void sort(int a[], int left, int right){
 	if(left >= right)	return;
 	int pos = partition(a,left,right);
 	sort(a, left, pos-1);
 	sort(a, pos+1, right);
 }
 
 int main(){
 	int a[10] = {53,123,4,653,326,23,634,524,1,34};
 	sort(a,0,9);
 	for(int i = 0; i < 10; i++){
 		printf("%d ",a[i]);	
	}
 	return 0;
 }
