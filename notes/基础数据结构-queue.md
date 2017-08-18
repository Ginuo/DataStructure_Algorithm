##队列的数组实现

* 基本规则：
  1. 队首指针front指向队首的**前一个位置**
  2. 队尾指针rear指向**队尾元素**
  3. 初始状态：front = rear = -1;
  4. front == rear时，表示队列为空，没有元素

```C++
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

//注意队列为空的情况
void pop(){
	if(!empty())
		front++;
}
//取队首元素 
int get_front(){
	if(!empty())     //注意队空的情况
		return q[front+1];
	else
		return;
}
//取队尾元素
int get_rear(){
	if(!empty())
		return q[rear];
	else
		return;
}

int main(){
	push(89);
	push(24);
	push(242);
	push(53);
	while(!empty()){
		printf("front = %d  rear = %d\n", get_front(), get_rear());
		pop();
	}
	return 0;
}
```

* STL也没有实现队列的清空，所以也要循环pop（），或者直接定义一个新的队列