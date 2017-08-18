#include<cstdio>

struct node{
	int data;
	node* lchild;
	node* rchild;
};

node* newNode(int x){
	node* root = new node;
	root->data = x;
	root->lchild = root->rchild = NULL;
	return root;
}

void search(node* root, int x){
	if(root == NULL){
		printf("search failed\n");
		return;
	}else if(x == root->data){
		printf("%d\n",root->data);
	}else if(x < root->data){
		search(root->lchild, x);
	}else{
		search(root->rchild, x);
	}
}

void insert(node* &root, int x){
	if(root == NULL){
		root = newNode(x);
		return;
	}
	if(x <= root->data){
		insert(root->lchild, x);
	}else{
		insert(root->rchild, x);
	}
}

node* create(int a[], int size){
	node* root = newNode(a[0]);
	for(int i = 1; i < size; i++){
		insert(root,a[i]);
	}
	return root;
}

//递推找到结点root的前驱结点（左子树的最大权值结点） 
node* findmax(node* root){
	if(root->lchild == NULL)	return NULL;  //如果没有左子树 
	root = root->lchild;
	while(root->rchild != NULL){
		root = root->rchild;
	}
	return root;
}

//递推找到结点root的后继结点（右子树的最小权值结点） 
node* findmin(node* root){
	if(root->rchild == NULL)	return NULL;
	root = root->rchild;
	while(root->lchild != NULL){
		root = root->lchild;
	} 
	return root;
}

//删除根节点 
void delRoot(node* &root){
	if(findmax(root) != NULL){   //1.有前驱结点时 
		node* max = findmax(root);
		node* temp = max;
		max = max->lchild;   //用前驱结点的左子树覆盖前驱结点 
		root = temp;         //用前驱结点覆盖根节点 
	}else if(findmin(root) != NULL){//2.没有前驱结点，但是有后继结点 
		node* min = findmin(root);
		node* temp = min;
		min = min->rchild;   //用后继结点的右子树覆盖后继结点 
		root = min;         //用后继结点覆盖根节点 
	}else{        //2.前驱后继都没有（左右子树为空），直接删除该结点 
		root = NULL;
	}
}

void del(node* &root, int x){
	if(root == NULL){         //找不到数据域为x的结点 
		printf("结点不存在\n");
		return;
	}else if(x == root->data){//若根节点数据域为x，删除根节点 
		delRoot(root);
	}else if(x < root->data){//在左子树递归删除 
		del(root->lchild, x);
	}else{                  //在右子树递归删除 
		del(root->rchild, x);
	}
}

void inorder(node* root){
	if(root == NULL)	return;
	inorder(root->lchild);
	printf("%d ",root->data);
	inorder(root->rchild);
}

int main(){
	int a[10] = {98,233,12,64,23,62,94,25,63,88};
	node* root = create(a,10);
	
	inorder(root);
	
	printf("\n");
	del(root,63);
	del(root,233);
	inorder(root);
	return 0;
} 
