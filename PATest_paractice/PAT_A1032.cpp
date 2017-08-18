#include<cstdio>

const int maxn = 100000;

struct node{
	char letter;
	int next;
	node(){
	}
	node(char l, int n){
		letter = l;
		next = n;
	}
} list[maxn];

bool hashTable[maxn] = {false};

int findCommon(int start1, int start2){
	int i = start1;
	int j = start2;
	if(j == i)	return i;
	hashTable[i] = true;
	while(list[i].next != -1){
		i = list[i].next;
		hashTable[i] = true;
	}
	
	while(list[j].next != -1){
		j = list[j].next;
		if(hashTable[j] == true){
			return j;
		}
	}
	return -1;
}

int main(){
	int start1, start2,N;
	scanf("%d%d%d",&start1,&start2,&N);
	for(int i = 0; i < N; i++){
		int index,next;
		char c;
		scanf("%d %c %d",&index, &c, &next);
		list[index] = node(c,next);
	}
	int ans = findCommon(start1,start2);
	printf("%05d\n",ans);
	return 0;
} 
