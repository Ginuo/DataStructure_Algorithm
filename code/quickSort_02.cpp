 #include<cstdio>
 #include<cstdlib>
 #include<ctime>
 
 //������Ŀ������� 
 
 int partition(int a[], int left, int right){
 	srand((unsigned)time(NULL));        //������������� 
 	int rnd = left + rand() % (right-left+1);    //����[left,right]֮���������� 
	//�Ȱ������Ԫ������Ԫ�ؽ�����Ȼ��Ϳ����ճ�ʹ�û����Ŀ����㷨 
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
