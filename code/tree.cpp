#include<cstdio>
#include<queue>
using namespace std;

struct node{
	int data;
	int layer; 
	vector<int> child;
} Node[100]; 

int index = 0;

int newNode(int x){
	Node[index].data = x;
	Node[index].child.clear();     //清空子节点，初始化 
	return index++;
}

void preorder(int root){
	//不需要另外写递归边界，因为for循环结束就是边界
	//写了反而易错 
	printf("%d ",Node[root].data);
	for(int i = 0; i < Node[root].child.size(); i++){
		preorder(Node[root].child[i]);
	}
} 

void layerorder(int root){
	queue<int> Q;
	Q.push(root);
	Node[root].layer = 0;
	while(!Q.empty()){
		int now = Q.front();
		Q.pop();
		printf("%d ",Node[now].data);
		for(int i = 0; i < Node[now].child.size(); i++){
			int t = Node[now].child[i];
			Node[t].layer = Node[now].layer + 1; 
			Q.push(t);
		}
	}
}

	

int main(){
	int root = newNode(9);
	int child1 = newNode(8);
	int child2 = newNode(7);
	int child3 = newNode(6);
	int child4 = newNode(5);
	vector<int> vt;
	vt.push_back(child1);
	vt.push_back(child2);
	vt.push_back(child3);
	vt.push_back(child4);
	Node[root].child = vt;
	preorder(0);
	return 0;
}









