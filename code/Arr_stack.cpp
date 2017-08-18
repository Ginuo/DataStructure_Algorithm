#include<cstdio>

int a[100];      //用数组实现栈的基本操作
int TOP = -1;     //TOP为-1表示没有元素

void clear(){
	TOP = -1;
} 

int size(){
	return TOP + 1;
}

bool empty(){
	if(TOP == -1)	return true;
	else 	return false;
}

void push(int x){
	a[++TOP] = x;
}

//只有非空时才能使用 
void pop(){
	if(!empty())
		TOP--;
}

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



