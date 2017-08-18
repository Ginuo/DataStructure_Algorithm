#include<cstdio>
#include<algorithm>
using namespace std;

struct Mooncake{
	//ע�⣺Ӧʹ�ø����� 
	double store;     //�����
	double sell;       //���ۼ�
	double price;      //����
} cake[1010];

bool cmp(Mooncake a, Mooncake b){
	return a.price > b.price;
}

int main(){
	int n;
	double D;
	scanf("%d%lf",&n,&D);
	for(int i = 0; i < n; i++){
		scanf("%lf",&cake[i].store);
	}
	for(int i = 0; i < n; i++){
		scanf("%lf",&cake[i].sell);
		cake[i].price = cake[i].sell / cake[i].store;
	}
	//�����۴Ӵ�С���� 
	sort(cake,cake+n,cmp);
	
	//***�ؼ���̰��ʵ�֣������Ȱѵ�����ߵ�����*** 
	double ans = 0;   //���� 
	for(int i = 0; i < n; i++){
		if(cake[i].store >= D){
			ans = ans + cake[i].price * D;
			break;
		}else{
			ans = ans + cake[i].sell;
			D -= cake[i].store;
		}
	}
	printf("%.2f",ans);
	
	return 0;
}

 
