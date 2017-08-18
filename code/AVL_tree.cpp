#include<cstdio>
#include<algorithm>

using namespace std;

struct node{
	int data;
	int height;   //记录结点高度，初始为1，即为叶子结点的高度
	node* lchild;
	node* rchild;
};

void insert(node* &root, int x);      //insert函数原型 

//构造AVL树 
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

//之所以不直接使用root->height获取高度，而要实现getHight函数 
//是因为当root是空树时，高度获取将失败！ 
int getHeight(node* root){
	if(root == NULL) return 0;  //空结点的高度为0
	else return root->height;
}

//高度是从叶子结点算起的，不需要递归更新子树高度
//不过更新root高度之前，必须先更新其左右子树高度（如果有变化） 
void updateHeight(node* root){
	root->height = max(getHeight(root->lchild),getHeight(root->rchild)) + 1;
}

//计算结点root的平衡因子：左子树高度-右子树高度 
int getBalanceFactor(node* root){
	return getHeight(root->lchild)-getHeight(root->rchild);
}

//右旋，将左子结点变成根节点 
//引用参数！！ 
void rightRotation(node* &root){
	node* temp = root->lchild;
	root->lchild = temp->lchild;
	temp->rchild = root;
	//***特别注意以下几句的顺序*** 
	updateHeight(root); //因为root是left的右子树，所以要先更新它的高度
	updateHeight(temp); 
	root = temp;
}

//区分左右旋:左旋就是把右子树根节点左移，代替root
//右旋就是把左子树的根节点右移，代替root 
void leftRotation(node* &root){
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;	
}

//记得引用参数！！ 
void insert(node* &root, int x){
	//插入的方法与一般的BST一致 
	if(root == NULL){
		root = newNode(x);
		return; 
	}
	if(x <= root->data){
		insert(root->lchild,x);
	}else{
		insert(root->rchild,x);
	}
	
	//以下是比BST的插入多出来的部分 
	
	updateHeight(root); //**插入之后必须先更新高度，不然以下的平衡判断将出错** 
	
	//判断并控制平衡 
	if(getBalanceFactor(root) == 2){
		if(getBalanceFactor(root->lchild) == 1){
			rightRotation(root);
		}else if(getBalanceFactor(root->lchild) == -1){
			leftRotation(root->lchild);  //先对左子树左旋，就转化成了上一种情况 
			rightRotation(root);
		}
	}else if(getBalanceFactor(root) == -2){
		if(getBalanceFactor(root->rchild) == -1){
			leftRotation(root);
		}else if(getBalanceFactor(root->rchild) == 1){
			rightRotation(root->rchild);//转换成上一种情况 
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










