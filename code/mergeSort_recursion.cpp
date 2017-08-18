#include<cstdio>
 
//�鲢����ĵݹ�ʵ�� 
 
void merge(int a[], int L1, int R1, int L2, int R2);

//***�߼��ܼ򵥣����������������ҹ鲢 
void sort(int a[], int left, int right){
	if(left >= right)	return;       //�ݹ����Ҳ����Ȼ 
	int mid = (left + right)/2;
	sort(a, left, mid);             //��������� 
	sort(a, mid+1, right);          //���ұ����� 
	merge(a,left, mid, mid+1, right);  //���ҹ鲢 
}

//������[L1,R1]��[L2,R2]�鲢
//�ؼ�������ʹ������ָ��ϲ����飬���Ѻϲ�������Ƶ�ԭ���� 
void merge(int a[], int L1, int R1, int L2, int R2){
	int i = L1, j = L2;           //����ָ��
	int temp[R2 - L1 + 1];       //��Ҫ��ʱ�������ڴ�źϲ��������   
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
	//����ʱ����Ľ�����Ƶ�����a 
	for(int k = 0; k < index; k++){
		a[L1+k] = temp[k];
	}
}

int main(){
	int n;
	while(scanf("%d",&n) != EOF){         //Ctrl+Z��ʾ�ļ�β 
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


