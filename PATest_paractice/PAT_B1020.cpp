#include<cstdio>
#include<algorithm>
using namespace std;

struct Mooncake{
	//注意：应使用浮点型 
	double store;     //库存量
	double sell;       //总售价
	double price;      //单价
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
	//按单价从大到小排序 
	sort(cake,cake+n,cmp);
	
	//***关键的贪心实现，总是先把单价最高的卖掉*** 
	double ans = 0;   //收益 
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

 
