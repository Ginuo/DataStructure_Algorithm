##用数组实现栈

* 栈顶指针TOP始终指向栈的最上方元素

```C++
#include<cstdio>

int a[100];      //用数组实现栈的基本操作
int TOP = -1;     //栈顶指针，TOP为-1表示没有元素

//清空
void clear(){
	TOP = -1;
} 

//返回大小
int size(){
	return TOP + 1;
}

//判空
bool empty(){
	if(TOP == -1)	return true;
	else 	return false;
}

//将x入栈
void push(int x){
	a[++TOP] = x;
}

//出栈，只有非空时才能使用 
void pop(){
	if(!empty())
		TOP--;
}

//取栈顶元素
int top(){
	if(!empty()){
		return a[TOP];
	}
	return NULL;
}

int main(){
	push(4);
	push(8);
	push(5);
	while(!empty()){
		printf("%d ",top());
		pop();
	}
	return 0;
}
```

* **STL中没有实现栈的清空**，需要清空时，可以循环pop()，或者定义一个新的stack即可

###待做习题：后缀表达式的算法训练：codeup 1918