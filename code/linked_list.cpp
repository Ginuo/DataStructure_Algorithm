#include<cstdio>

struct node{
	int data;
	node* next;
};

//重点看，容易出错，pre结点必需 
//2.使用函数创建，把数组转换成链表
node* create(int arr[]){
	node *p, *head, *pre;
	head = new node;   //head是不能变的，所以还需要一个pre结点 
	head->next = NULL;     //记得每个结点创建时，都要把指针域初始化为NULL，否则可能指向一个莫名的地址吧  
	pre = head;
	for(int i = 0; i < 10; i++){
		p = new node;
		p->data = arr[i];
		p->next = NULL;
		pre->next = p;
		pre = p;
	}
	return head;     //返回head即可，元素已经链上了 
} 

//查找x元素出现的次数 
int search(node* head, int x){
	int cnt = 0;       //记录x出现次数 
	node* p = head->next;
	while(p != NULL){
		if(p->data == x){
			cnt++;
		}
		p = p->next;
	}
	return cnt;
}

//把x插入第pos个位置上 ,pos是从1开始计数的，而不是0（仅此处，具体因情况而定） 
void insert(node* head, int pos , int x){
	node* p = head;
	for(int i = 1; i < pos; i++){ //循环pos-1次，先找到pos的前一个位置 
		p = p->next;
	}
	node* newNode = new node;
	newNode->data = x;
	newNode->next = p->next;
	p->next = newNode; 
}

//删除数据域为x的所有结点，需要多练习，不然写起来挺慢的 
void del(node* head, int x){
	node* p = head->next;
	node* pre = head;
	while(p != NULL){
		if(p->data == x){       //数据域是x，则删除 
			pre->next = p->next;
			delete(p);         //记得释放，当然了，数据量小没关系，不过最好释放！ 
			p = pre->next;
		}else{                //数据域不是x，把pre和p后移一位 
			pre = p;
			p = p->next;
		}
		
	}
}

void print(node* head){
	node* temp = head->next;
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	} 
} 

int main(){
	//1.手动创建 
	node* node1 = new node;
	node1->data = 9;
	node* node2 = new node;
	node2->data = 10;
	node1->next = node2;

	int a[10] = {0,1,2,3,3,3,6,7,8,9};
	node* head = create(a);
	print(head);
	
	printf("\n%d\n",search(head,3));
	
	insert(head,3,99);
	del(head,9); 
	print(head);
	return 0;
}
