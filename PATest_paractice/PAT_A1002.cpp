#include<cstdio>
#include<set>
#include<vector>

using namespace std; 

vector<double> poly[1010];


int main(){
	int maxIndex = 0;
	set<int> st;       //记录单项式个数（指数相同的算作一个） 
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		int exp;
		double coe;
		scanf("%d %lf",&exp,&coe);
		poly[exp].push_back(coe);
		if(exp > maxIndex)	maxIndex = exp;
		st.insert(exp);
	}
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		int exp;
		double coe;
		scanf("%d %lf",&exp,&coe);
		poly[exp].push_back(coe);
		if(exp > maxIndex)	maxIndex = exp;
		st.insert(exp);
	}
	
	printf("%d",st.size());
	for(int i = maxIndex; i >= 0; i--){
		if(!poly[i].empty()){
			double sum = 0.0;
			for(int j = 0; j < poly[i].size(); j++){
				sum += poly[i][j];
			}
			printf(" %d %.1f",i,sum);
		}
	}
	return 0;
}
