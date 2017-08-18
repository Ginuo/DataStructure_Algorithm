##定义、特点

* BST可以是空树
* 左子树所有结点的数据域**小于等于**根节点的数据域，右子树的都**大于**根节点数据域

* 二叉查找树的中序遍历序列是有序的

##☆二叉查找树的删除☆

* 都可以递归地理解为对根节点的删除问题

* 删除root的大致思路：
  1. 找到左子树的最大权值结点max（即最右结点，也叫**前驱**），然后用它覆盖root，再删除max
  2. 若没有左子树，则找到右子树的最小权值min（最左，也叫**后继**），覆盖root，再删除min

###第一步：找到前驱和后继(findmax(root)  findmin(root))

* 书上的代码只是找到一棵树中的最小结点，而不是前驱后继

```C++
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

```


###第二步：删除根节点的方法（不需要递归），delRoot(node* &root)

* **重要性质：**前驱结点一定没有右子树，后继结点一定没有左子树
  所以**删除前驱结点时，只需要让它的左子树覆盖它；删除后继结点时，只需要让它的右子树覆盖它即可**

* 流程：
  1. 若有前驱结点，先用前驱结点的左子树覆盖前驱结点，再用前驱结点覆盖root
  2. 若没有前驱结点，但由后继结点，用后继结点得右子树覆盖后继结点，再用后继结点覆盖root
  3. 若前驱后继都没有，表示root是叶子结点，直接删除root（置为NULL）

```
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
```

###第三步：删除数据域为x的结点

* 注意:树中可能不存在数据域为x的结点

* 流程：
  1. 递归边界：root==NULL，找不到数据域为x的结点
  2. 若根节点数据域是x，**调用delRoot**删除根节点
  3. 若x小于根节点数据域，对左子树递归调用del(root->lchild)
  4. 若x大于根节点数据域，对右子树递归调用del(root->rchild)

```
void del(node* &root, int x){
	if(root == NULL){         //找不到数据域为x的结点 
		printf("结点不存在\n");
		return;
	}else if(x == root->data){//若根节点数据域为x，删除根节点 
		delRoot(root);//调用delRoot

	}else if(x < root->data){//在左子树递归删除 
		del(root->lchild, x);
	}else{                  //在右子树递归删除 
		del(root->rchild, x);
	}
}
```