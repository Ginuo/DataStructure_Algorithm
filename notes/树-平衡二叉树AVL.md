##平衡二叉树

* 定义：左右子树的高度之差的绝对值不超过1的二叉树

* node结构体中需要一个成员变量height记录每棵树的高度，在newNode函数中初始化为1

* **平衡因子**：左子树高度 - 右子树高度


* `updateHeight(node* root)`函数更新树的高度:
  * **树的高度 = max(左子树高度， 右子树高度) + 1**
  * 不需要递归，因为高度是从叶子结点开始计数的；一个结点的位置变动不会影响**相对它未变的子树**的高度，但是会影响其祖先结点的高度


* 叶子结点（结点初始时都是叶子结点）的高度为1，空结点的高度为0

* **因为通过`root->height`无法获取空结点的高度（0），所以必须有一个函数getHeight来计算任何结点的高度，**否则对于没有子树的结点来说，就无法通过比较左右子树的高度来计算其高度

##查找、插入、删除：O(logn)

##旋转后的中序遍历序列是不变的，所以旋转前后的树是等价的。

##平衡的判断和实现（insert()函数）

* 左旋：将右子结点左移变成root
  * 步骤：画个图就好了，将root->rchild的左子树变成root的右子树；将root变成root-rchild的左子树


* 右旋：将左子结点右移变成root 
  * 步骤：将root->lchild的右子树变成root的左子树；将root变成root->lchild的右子树


* 只要getBalanceFactor(root)等于-2或2时，说明不平衡了

* **维持平衡的方法，在insert函数中实现**：
  1. 像普通的的BST一样插入元素，**插入之后切记先更新结点高度**
  2. 插入后判断：
    1. 如果root的平衡因子为2，说明左子树偏重
       1. 如果左子树的平衡因子为1，直接对root右旋即可
       2. 如果左子树平衡因子为-1，先对左子树左旋，变成上一种情况，再对root右旋
    2. 如果root平衡因子为-2，说明右子树偏重
       1. 如果右子树平衡因子为-1，直接对root左旋即可
       2. 如果右子树平衡因子为1，先对右子树右旋，变成上一种情况，再对root左旋

```C++
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

//平衡在insert中实现
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


int main(){
	int a[19] = {1,2,3,4,5,6,6,7,8,9,10,11,12,13,14,15,16,17,18};
	node* root = create(a,19);
	inorder(root);
	printf("\n");
	preorder(root);
	return 0;
} 
```