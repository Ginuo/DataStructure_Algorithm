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

//�����ҵ����root��ǰ����㣨�����������Ȩֵ��㣩 
node* findmax(node* root){
	if(root->lchild == NULL)	return NULL;  //���û�������� 
	root = root->lchild;
	while(root->rchild != NULL){
		root = root->rchild;
	}
	return root;
}

//�����ҵ����root�ĺ�̽�㣨����������СȨֵ��㣩 
node* findmin(node* root){
	if(root->rchild == NULL)	return NULL;
	root = root->rchild;
	while(root->lchild != NULL){
		root = root->lchild;
	} 
	return root;
}

//ɾ�����ڵ� 
void delRoot(node* &root){
	if(findmax(root) != NULL){   //1.��ǰ�����ʱ 
		node* max = findmax(root);
		node* temp = max;
		max = max->lchild;   //��ǰ����������������ǰ����� 
		root = temp;         //��ǰ����㸲�Ǹ��ڵ� 
	}else if(findmin(root) != NULL){//2.û��ǰ����㣬�����к�̽�� 
		node* min = findmin(root);
		node* temp = min;
		min = min->rchild;   //�ú�̽������������Ǻ�̽�� 
		root = min;         //�ú�̽�㸲�Ǹ��ڵ� 
	}else{        //2.ǰ����̶�û�У���������Ϊ�գ���ֱ��ɾ���ý�� 
		root = NULL;
	}
}

void del(node* &root, int x){
	if(root == NULL){         //�Ҳ���������Ϊx�Ľ�� 
		printf("��㲻����\n");
		return;
	}else if(x == root->data){//�����ڵ�������Ϊx��ɾ�����ڵ� 
		delRoot(root);
	}else if(x < root->data){//���������ݹ�ɾ�� 
		del(root->lchild, x);
	}else{                  //���������ݹ�ɾ�� 
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
