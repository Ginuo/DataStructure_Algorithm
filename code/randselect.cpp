#include<cstdio>
#include<cstdlib>
#include<ctime>

int randPartition(int a[], int left,int right);

//�������������ҳ���K��Ԫ�� 

//�ص�ע������return����K��Ԫ�ؿ��ܴ������ط����� 
int randSelect(int a[], int left, int right, int K){
	if(left == right) 	return a[left];     //���ص�K��Ԫ�� **����������©д���� 
	int p = randPartition(a,left,right);  //�����з֣������з�Ԫ�ص�λ�� 
	int M = p - left + 1;             //�з�Ԫ���������е�M��Ԫ�أ�pֻ������λ�ã����ǵ�p�󣡣��� 
	if(K == M)	return a[p];          //�з�Ԫ�������ǵ�K��Ԫ��ʱ����  
	if(K > M)
		return randSelect(a, p+1, right, K-M);      //K>Mʱ�������ұߵĵ�K-M��Ԫ�� 
	else
		return randSelect(a, left, p-1, K);        //K<Mʱ��������ߵĵ�K��Ԫ�� 
	
}

//����������������е��з��㷨 
int randPartition(int a[], int left, int right){
	srand((unsigned)time(NULL));
	int rnd_pos = left + rand() % (right - left + 1);
	
	int t = a[rnd_pos];
	a[rnd_pos] = a[left];
	a[left] = t;
	
	int x = a[left];
	while(left < right){
		while(left < right && a[right] > x)		right--;
		a[left] = a[right];
		while(left < right && a[left] <= x)		left++;
		a[right] = a[left];
	}
	a[left] = x;
	return left;
} 

int main(){
	int a[1] = {9};
	int index;
	scanf("%d",&index);            //����K����ѯ��k���Ԫ�� 
	int ans = randSelect(a,0,9,index);
	printf("%d", ans);
	return 0;
}
