#include<cstdio>

int a[100];      //������ʵ��ջ�Ļ�������
int TOP = -1;     //TOPΪ-1��ʾû��Ԫ��

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

//ֻ�зǿ�ʱ����ʹ�� 
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



