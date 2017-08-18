#include<cstdio>

//根据先序遍历序列和中序遍历序列，重建二叉树

struct node{
	int data;
	node *lchild, *rchild;
};


int pre[10] = {32,2,3,12,54,42,64,75,66,99};
int in[10] = {2,3,12,32,42,54,64,66,75,99};

node* newNode(int x){
	node* root = new node;
	root->data = x;
	root->rchild = root->lchild = NULL;
	return root;
}

//四个参数是两个遍历序列数组的端点：[preL,preR]、[inL,inR] 
node* create(int preL, int preR, int inL, int inR){
	if(preL >= preR){       //递归边界（不能写>=，会出错！！所有的叶子结点都会被忽略！！） 
		return NULL;      //记得返回NULL，而不能只写return 
	}
	
	node* root = newNode(pre[preL]);       //给root赋值 
		
	int rootindex;
	//如果中序序列中有多个相同元素pre[preL]，应该取最后的那个，
	//这样才严格符合BST的定义（左子树都小于等于root），不过此处未考虑重复元素的情况 
	for(rootindex = inL; rootindex <= inR; rootindex++){  //关键：在中序序列中查找根节点的位置rootindex 
		if(in[rootindex] == pre[preL])	break;
	}
	int lchildsize = rootindex - inL;     //根据中序序列计算左子树的大小 
	root->lchild = create(preL+1, preL + lchildsize, inL, rootindex - 1);   //递归地给左结点赋值 
	root->rchild = create(preL + lchildsize +1, preR, rootindex+1, inR);     //递归地给右结点赋值
	return root;
}

void inorder(node* root){
	if(root == NULL)	return;
	inorder(root->lchild);
	printf("%d ",root->data);
	inorder(root->rchild);
}

int main(){
	node* root = create(0,9,0,9);
	inorder(root);
	return 0;
}
