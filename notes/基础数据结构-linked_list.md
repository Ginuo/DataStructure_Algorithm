##动态内存分配

###一、C语言的malloc和free

* 需要`#include<stdlib.h>`

* 返回类型是申请的同变量类型的指针（其实是void*，需要强制转换成申请的类型的指针类型）

* 通常都会用到 `sizeof(typename)` 作为参数

```C
int* p = (int*)malloc(sizeof(int));
*p = 100;
node* np = (node*)malloc(sizeof(node));
np->data = 99;
printf("%d %d\n",*p, np->data);
free(p);
free(np);
```

###二、C++的new操作符和delete函数

* new是个关键字，`typename* p = new  typename`即可

```C++
int* p1 = new int;
*p1 = 21;
node* np2 = new node;
np2->data = 88;
printf("%d %d\n",*p1, np2->data); 
delete(p1);
delete(np2);
```

##链表

* 基本组成：指针域（指向下一个结点）和数据域

```C++
struct node{
	int data;
	node* next;
};
```

* 一般写带head结点的链表，head结点的数据域为空，指针域指向第一个结点

###一、链表的创建（从数组到链表的转换）

```C++
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
```

###查找元素，并记录出现次数

```C++
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
```

###插入元素到指定位置

```C++
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
```

###删除数据域为x的结点

```C++
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
```