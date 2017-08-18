#include<cstdio>

struct node{
	int data;
	node* next;
};

//�ص㿴�����׳���pre������ 
//2.ʹ�ú���������������ת��������
node* create(int arr[]){
	node *p, *head, *pre;
	head = new node;   //head�ǲ��ܱ�ģ����Ի���Ҫһ��pre��� 
	head->next = NULL;     //�ǵ�ÿ����㴴��ʱ����Ҫ��ָ�����ʼ��ΪNULL���������ָ��һ��Ī���ĵ�ַ��  
	pre = head;
	for(int i = 0; i < 10; i++){
		p = new node;
		p->data = arr[i];
		p->next = NULL;
		pre->next = p;
		pre = p;
	}
	return head;     //����head���ɣ�Ԫ���Ѿ������� 
} 

//����xԪ�س��ֵĴ��� 
int search(node* head, int x){
	int cnt = 0;       //��¼x���ִ��� 
	node* p = head->next;
	while(p != NULL){
		if(p->data == x){
			cnt++;
		}
		p = p->next;
	}
	return cnt;
}

//��x�����pos��λ���� ,pos�Ǵ�1��ʼ�����ģ�������0�����˴������������������ 
void insert(node* head, int pos , int x){
	node* p = head;
	for(int i = 1; i < pos; i++){ //ѭ��pos-1�Σ����ҵ�pos��ǰһ��λ�� 
		p = p->next;
	}
	node* newNode = new node;
	newNode->data = x;
	newNode->next = p->next;
	p->next = newNode; 
}

//ɾ��������Ϊx�����н�㣬��Ҫ����ϰ����Ȼд����ͦ���� 
void del(node* head, int x){
	node* p = head->next;
	node* pre = head;
	while(p != NULL){
		if(p->data == x){       //��������x����ɾ�� 
			pre->next = p->next;
			delete(p);         //�ǵ��ͷţ���Ȼ�ˣ�������Сû��ϵ����������ͷţ� 
			p = pre->next;
		}else{                //��������x����pre��p����һλ 
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
	//1.�ֶ����� 
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
