#include<cstdio>

//�з֣�ȷ��һ��Ԫ�ص�����λ�� 
int partition(int a[], int left, int right){
	int temp = a[left];
	while(left < right){
		//**һ��Ҫ�ȴ��ұ߿�ʼɨ�裬��Ϊleftָ���ʼָ���Ԫ���ѱ��浽temp��
		//����a[0]��λ�ÿ����ȱ�����
		while(left < right && a[right] > temp)     right--;
		a[left] = a[right];
		while(left < right && a[left] <= temp)     left++;
		a[right] = a[left];
	} 
	a[left] = temp;
	return left;           //�����������±� �����룡������������sort������ 
} 

void sort(int a[], int left, int right){
	if(left >= right) return;         //�ݹ���� 
	int pos = partition(a,left,right);
	sort(a,left,pos-1);
	sort(a,pos+1,right);
	
	//***�����д���Ǵ���ģ��� էһ��ûë��*** 
//	int mid = (left + right)/2; //��Ϊ�����Ƕ԰�ֵģ���
//  �������з�Ԫ�ص�λ����Ϊ���һ������ݵ� 
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
