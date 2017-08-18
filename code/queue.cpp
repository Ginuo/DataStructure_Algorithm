#include<cstdio>

int q[100];
int front = -1;
int rear = -1;

void clear(){
	front = rear = -1;
}

int size(){
	return rear - front;
}

bool empty(){
	if(front == rear)	return true;    //front == rear时，表示没有元素了 
	else return false;
}

void push(int x){
	q[++rear] = x;
}

void pop(){
	front++;
}
//取队首元素 
int get_front(){
	return q[front+1];
}
//取队尾元素
int get_rear(){
	return q[rear];
}

int main(){
	push(89);
	push(24);
	push(242);
	push(53);
	while(!empty()){
		printf("front = %d  rear = %d\n",get_front(),get_rear());
		pop();
	}
	return 0;
}

