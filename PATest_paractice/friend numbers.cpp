#include<cstdio>
#include<set>

using namespace std;

int digsum(int x){
	int sum = 0;
	while(x != 0){
		sum = sum + x%10;
		x /= 10;
	}
	return sum;
} 

int main(){
	int N; 
	scanf("%d",&N);
	set<int> st;
	for(int i = 0; i < N; i++){
		int t;
		scanf("%d",&t);
		int dsum = digsum(t);
		st.insert(dsum);
	}
	printf("%d\n",st.size());
	int cnt = 0;
	for(set<int>::iterator it = st.begin(); it != st.end(); it++){
		printf("%d",*it);
		if(cnt < st.size()-1){
			printf(" ");
		}
		cnt++;
	}
	return 0;
}
