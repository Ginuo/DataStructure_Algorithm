#include<cstdio>
#include<string>
#include<map>
#include<iostream>

using namespace std;

int main(){
	int M,N,S;
	scanf("%d%d%d",&M,&N,&S);
	map<string,bool> mp;
	string name[1010];
	for(int i = 1; i <= M; i++){
		cin >> name[i];
		mp[name[i]] = false;
	}
	if(S > M){
		printf("Keep going...");
	}else{
		for(int i = S; i <= M;){
			if(mp[name[i]] == false){
				cout << name[i] << endl;
				mp[name[i]] = true;
				i += N;
			}else{
				i += 1;
			}
		}
	}
	return 0;
}
