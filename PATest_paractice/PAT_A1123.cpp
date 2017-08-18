#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

struct node{
	int data;
	int height;
	node* lchild;
	node* rchild;
};

node* newNode(int x){
	node* root = new node;
	root->data = x;
	root->height = 1;
	root->lchild = root->rchild = NULL;
	return root;
}

int getHeight(node* root){
	if(root == NULL)	return 0;
	else	return root->height;
}

int getBalanceFactor(node* root){
	return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(node* &root){
	root->height = max(getHeight(root->lchild),getHeight(root->rchild)) + 1;
}

void rightRotation(node* &root){
	node* left = root->lchild;
	root->lchild = left->rchild;
	left->rchild = root;
	updateHeight(root);
	updateHeight(left);
	root = left;
}

void leftRotation(node* &root){
	node* right = root->rchild;
	root->rchild = right->lchild;
	right->lchild = root;
	updateHeight(root);
	updateHeight(right);
	root = right;
}

void insert(node* &root, int x){
	if(root == NULL){
		root = newNode(x);
		return;
	}
	if(x <= root->data){
		insert(root->lchild,x);
	}else{
		insert(root->rchild,x);
	}
	updateHeight(root);
	if(getBalanceFactor(root) == 2){
		if(getBalanceFactor(root->lchild) == 1){
			rightRotation(root);
		}else if(getBalanceFactor(root->lchild) == -1){
			leftRotation(root->lchild);
			rightRotation(root);
		}
	}else if(getBalanceFactor(root) == -2){
		if(getBalanceFactor(root->rchild) == -1){
			leftRotation(root);
		}else if(getBalanceFactor(root->rchild) == 1){
			rightRotation(root->rchild);
			leftRotation(root);
		}
	}
}

node* create(int a[], int len){
	node* root = NULL;
	for(int i = 0; i<len; i++){
		insert(root,a[i]);
	}
	return root;
}

bool judge_BFS(node* root, int layerseq[]){
	queue<node*> q;
	queue<node*> last;
	q.push(root);
	bool flag1 = false;
	bool toqueue = false;
	int index = 0;
	while(!q.empty()){
		node* now = q.front();
		q.pop();
		layerseq[index++] = now->data;
		if(toqueue == true){
			last.push(now);
		}
		if(now->rchild == NULL && flag1 == false){
			flag1 = true;
			toqueue = true;
		}
		if(now->lchild != NULL){
			q.push(now->lchild);
		}
		if(now->rchild != NULL){
			q.push(now->rchild);
		}
	}
	while(!last.empty()){
		node* t = last.front();
		last.pop();
		if(t->lchild != NULL || t->rchild != NULL){
			return false;
		}
	}
	return true;
}

int main(){
	int N;
	scanf("%d",&N);
	int arr[21];
	for(int i = 0; i < N; i++){
		scanf("%d",&arr[i]);
	}
	node* root = create(arr, N);
	int layer[21];
	bool ifcom_tree = judge_BFS(root, layer);
	for(int i = 0; i < N -1; i++){
		printf("%d ",layer[i]);
	}
	printf("%d\n",layer[N-1]);
	if(ifcom_tree == true){
		printf("YES");
	}else{
		printf("NO");
	}
}









