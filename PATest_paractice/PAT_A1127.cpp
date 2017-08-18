#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

struct node{
	int data;
	int layer; 
	node* lchild;
	node* rchild;
}; 

const int maxn = 40;
int in[maxn];
int post[maxn];

node* newNode(int x){
	node* root = new node;
	root->data = x;
	root->layer = 1;
	root->lchild = root->rchild = NULL;
	return root;
}

node* create(int inL, int inR, int pL, int pR){
	if(inL > inR){
		return NULL;
	}
	int dat = post[pR];
	node* root = newNode(dat);
	int rindex = inL;
	while(in[rindex] != dat){
		rindex++;
	}
	int lsize = rindex - inL;   //左子树大小 
	root->lchild = create(inL, rindex-1, pL, pL + lsize -1);
	root->rchild = create(rindex+1, inR, pL+lsize, pR - 1);
	return root;
}

void zigorder(node* root){
	queue<node*> q;
	int layersequ[maxn];     //记录一般的层序序列 
	int layers[maxn];        //记录layersqu对应的各个元素的层号 
	int index = 0; 
	int maxLayer = 1;
	q.push(root);
	while(!q.empty()){
		node* now = q.front();
		q.pop();
		layersequ[index] = now->data;
		layers[index++] = now->layer;
		if(now->lchild != NULL){
			q.push(now->lchild);
			maxLayer = now->lchild->layer = now->layer + 1;
		}
		if(now->rchild != NULL){
			q.push(now->rchild);
			maxLayer = now->rchild->layer = now->layer + 1;
		}
	}
	int l = 1;
	while(l <= maxLayer){
		if(l % 2 == 1){
			int* lower = lower_bound(layers,layers+index,l);
			int* upper = upper_bound(layers,layers+index,l);
			int lindex = lower - layers;
			int uindex = upper - layers;
			reverse(layersequ+lindex, layersequ+uindex);
		}
		l++;
	}
	for(int  i =0; i < index; i++){
		printf("%d",layersequ[i]);
		if(i < index -1){
			printf(" ");
		}
	}
}


int main(){
	int N; 
	scanf("%d",&N);
	for(int i = 1; i <= N; i++){
		scanf("%d",in+i);
	}
	for(int i = 1; i <= N; i++){
		scanf("%d",post+i);
	}
	node* root = create(1,N,1,N);
	zigorder(root);
	return 0;
} 
