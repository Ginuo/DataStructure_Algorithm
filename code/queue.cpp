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
	if(front == rear)	return true;    //front == rearʱ����ʾû��Ԫ���� 
	else return false;
}

void push(int x){
	q[++rear] = x;
}

void pop(){
	front++;
}
//ȡ����Ԫ�� 
int get_front(){
	return q[front+1];
}
//ȡ��βԪ��
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

