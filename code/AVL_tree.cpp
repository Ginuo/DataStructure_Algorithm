#include<cstdio>
#include<algorithm>

using namespace std;

struct node{
	int data;
	int height;   //��¼���߶ȣ���ʼΪ1����ΪҶ�ӽ��ĸ߶�
	node* lchild;
	node* rchild;
};

void insert(node* &root, int x);      //insert����ԭ�� 

//����AVL�� 
node* newNode(int x){
	node* root = new node;
	root->data = x;
	root->height = 1;
	root->lchild = root->rchild = NULL;
	return root;
}

node* create(int a[], int size){
	node* root = newNode(a[0]);
	for(int i = 1; i < size; i++){
		insert(root,a[i]);
	}
	return root;
}

//֮���Բ�ֱ��ʹ��root->height��ȡ�߶ȣ���Ҫʵ��getHight���� 
//����Ϊ��root�ǿ���ʱ���߶Ȼ�ȡ��ʧ�ܣ� 
int getHeight(node* root){
	if(root == NULL) return 0;  //�ս��ĸ߶�Ϊ0
	else return root->height;
}

//�߶��Ǵ�Ҷ�ӽ������ģ�����Ҫ�ݹ���������߶�
//��������root�߶�֮ǰ�������ȸ��������������߶ȣ�����б仯�� 
void updateHeight(node* root){
	root->height = max(getHeight(root->lchild),getHeight(root->rchild)) + 1;
}

//������root��ƽ�����ӣ��������߶�-�������߶� 
int getBalanceFactor(node* root){
	return getHeight(root->lchild)-getHeight(root->rchild);
}

//�����������ӽ���ɸ��ڵ� 
//���ò������� 
void rightRotation(node* &root){
	node* temp = root->lchild;
	root->lchild = temp->lchild;
	temp->rchild = root;
	//***�ر�ע�����¼����˳��*** 
	updateHeight(root); //��Ϊroot��left��������������Ҫ�ȸ������ĸ߶�
	updateHeight(temp); 
	root = temp;
}

//����������:�������ǰ����������ڵ����ƣ�����root
//�������ǰ��������ĸ��ڵ����ƣ�����root 
void leftRotation(node* &root){
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;	
}

//�ǵ����ò������� 
void insert(node* &root, int x){
	//����ķ�����һ���BSTһ�� 
	if(root == NULL){
		root = newNode(x);
		return; 
	}
	if(x <= root->data){
		insert(root->lchild,x);
	}else{
		insert(root->rchild,x);
	}
	
	//�����Ǳ�BST�Ĳ��������Ĳ��� 
	
	updateHeight(root); //**����֮������ȸ��¸߶ȣ���Ȼ���µ�ƽ���жϽ�����** 
	
	//�жϲ�����ƽ�� 
	if(getBalanceFactor(root) == 2){
		if(getBalanceFactor(root->lchild) == 1){
			rightRotation(root);
		}else if(getBalanceFactor(root->lchild) == -1){
			leftRotation(root->lchild);  //�ȶ���������������ת��������һ����� 
			rightRotation(root);
		}
	}else if(getBalanceFactor(root) == -2){
		if(getBalanceFactor(root->rchild) == -1){
			leftRotation(root);
		}else if(getBalanceFactor(root->rchild) == 1){
			rightRotation(root->rchild);//ת������һ����� 
			leftRotation(root);
		}
	}
	
}

void inorder(node* root){
	if(root == NULL)	return;
	inorder(root->lchild);
	printf("%d ",root->data);
	inorder(root->rchild);
}

void preorder(node* root){
	if(root == NULL)	return;
	printf("%d ",root->data);
	preorder(root->lchild);
	preorder(root->rchild);
} 

int main(){
	int a[19] = {1,2,3,4,5,6,6,7,8,9,10,11,12,13,14,15,16,17,18};
	node* root = create(a,19);
	inorder(root);
	printf("\n");
	preorder(root);
	return 0;
} 










