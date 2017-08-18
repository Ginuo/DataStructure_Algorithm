#include<cstdio>

//��������������к�����������У��ؽ�������

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

//�ĸ�����������������������Ķ˵㣺[preL,preR]��[inL,inR] 
node* create(int preL, int preR, int inL, int inR){
	if(preL >= preR){       //�ݹ�߽磨����д>=������������е�Ҷ�ӽ�㶼�ᱻ���ԣ����� 
		return NULL;      //�ǵ÷���NULL��������ֻдreturn 
	}
	
	node* root = newNode(pre[preL]);       //��root��ֵ 
		
	int rootindex;
	//��������������ж����ͬԪ��pre[preL]��Ӧ��ȡ�����Ǹ���
	//�������ϸ����BST�Ķ��壨��������С�ڵ���root���������˴�δ�����ظ�Ԫ�ص���� 
	for(rootindex = inL; rootindex <= inR; rootindex++){  //�ؼ��������������в��Ҹ��ڵ��λ��rootindex 
		if(in[rootindex] == pre[preL])	break;
	}
	int lchildsize = rootindex - inL;     //�����������м����������Ĵ�С 
	root->lchild = create(preL+1, preL + lchildsize, inL, rootindex - 1);   //�ݹ�ظ����㸳ֵ 
	root->rchild = create(preL + lchildsize +1, preR, rootindex+1, inR);     //�ݹ�ظ��ҽ�㸳ֵ
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
