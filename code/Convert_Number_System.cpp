#include<cstdio>

int q[20];
int cnt = 0;

//P����xת����ʮ���� 
int toTen(int x, int P){
	int product = 1;  //��ʼΪ1������0���� 
	int ans = 0;
	while(x != 0){    //ע������ x!=0 
		ans = ans + (x % 10) * product;
		x = x/10;
		product = product * P;       //*P���� 
	}
	return ans;
} 

//ʮ����xת����Q���� 
//��Qȡ�෨��do-whileѭ�� 
void toQ(int x, int Q){
	
	do{
		q[cnt++] = x % Q;
		x = x / Q;
	}while(x != 0);     //����Ҳ��x!=0 
}

int main(){
	int x = 16;
	int ans = toTen(x,8);
	toQ(ans,8);
	printf("%d��ʮ���ƣ�%d\n%d�İ˽��ƣ�",x,ans,ans);
	for(int i = cnt-1; i >= 0; i--){
		printf("%d",q[i]);
	}
	return 0 ;
}
