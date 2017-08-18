#include<cstdio>
#include<math.h>
#include<algorithm>
using namespace std;

const double eps = 1e-8;

int cmp(double a, double b){
	if( (a-b) > eps || fabs(a-b) <= eps){
		return 1;
	}else if( (b-a) > eps ){
		return -1;
	}
}

int main(){
	long long N;
	scanf("%lld",&N);
	bool ans[20] = {false};
	for(int i = 1; i <= N; i++){
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		long long sum = a + b;
		if(sum > c){
			ans[i]=true;
		}
	}
	for(int i = 1; i <= N; i++){
		if(ans[i]){
			printf("Case #%d: true\n",i);
		}else{
			printf("Case #%d: false\n",i);
		}
	}
}
