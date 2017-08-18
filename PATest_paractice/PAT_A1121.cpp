#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 100000;
int couple[maxn];
bool hashTable[maxn] = {false};

int main(){
	int N;
	fill(couple,couple+maxn,-1);
	scanf("%d",&N);
	for(int i = 0; i < N; i++){
		int a,b;
		scanf("%d%d",&a,&b);
		couple[a] = b;
		couple[b] = a;
	} 
	int M;
	scanf("%d",&M);
	int t[maxn];
	int index = 0;
	for(int i = 0; i < M; i++){
		int x;
		scanf("%d",&x);
		hashTable[x] = true;
		t[index++] = x;
	}
	int single[maxn];
	int cnt = 0;
	for(int i = 0; i < index; i++){
		int y = t[i];
		if(hashTable[y] = true){
			int cop = couple[y];
			if(cop == -1 || hashTable[cop] == false){
				single[cnt++] = y;
			}
		}
	}
	sort(single,single+cnt);
	printf("%d\n",cnt);
	for(int i = 0; i < cnt ; i++){
		printf("%05d",single[i]);
		if(i < cnt-1){
			printf(" ");
		}
	} 
	return 0;
}
