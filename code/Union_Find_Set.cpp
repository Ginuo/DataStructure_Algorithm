#include<cstdio>

int father[100];

//Ѱ�Ҹ����ڵ�ĸ��ڵ� 
int findRoot(int x){
	int a = x; 
	printf("%d ",x);
	while(x != father[x]){
		x = father[x];
		printf("%d ",x);
	}
	printf("\n");
	//**ѹ��·�����Ż����ң���·���ϵ����н��ֱ��ָ����ڵ�** 
	while(a != father[a]){
		int t = a; 
		a = father[a];
		father[t] = x; 
	} 
	
	return x;
} 

//�ϲ�����������ڵļ��ϣ���������
void Union(int x, int y){
	int xr = findRoot(x);
	int yr = findRoot(y);
	if(xr == yr)	return; //����������ͬһ�����ϣ�����Ҫ�ϲ�
	father[xr] = y; //��x�ĸ��ڵ�ָ��y 
} 

int main(){
	//��ʼ�� 
	for(int i = 1; i < 100; i++){
		father[i] = i;
	}
	//һ�����ϣ�5->4->3->2->1 
	father[2] = 1;
	father[3] = 2;
	father[4] = 3;
	father[5] = 4;
	findRoot(5);
	//��һ�����ϣ�8->9->10->11->12 
	father[8] = 9;
	father[9] = 10;
	father[10] = 11;
	father[11] = 12;
	findRoot(8); 
	
	Union(5,8);
	findRoot(5); 
	return 0;
}
 
