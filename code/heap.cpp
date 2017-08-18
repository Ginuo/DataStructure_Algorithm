#include<cstdio>
#include<algorithm>
using namespace std;

//0��λ���ԣ���Ϊ�κ���������
//������ÿ�������Ϊheap 
int a[100] = {-1,85,55,82,57,68,92,99,98,66,56}; 
int n = 10;     //heap��С 

//lowΪҪ�����Ľ���±꣬highͨ�������һ�������±� 
void downAdjust(int low, int high){
	int Lnum = 2 * low;    //���ӵ��±� 
	while(Lnum <= high){      //��������� 
		if(Lnum + 1 <= high){  //���Ҳ���ҽ�� 
			if(a[low] < max(a[Lnum],a[Lnum+1]) && a[Lnum] > a[Lnum+1]){  //��������������У��������ң����� 
				swap(a[low],a[Lnum]);
				low = Lnum;
			}else if(a[low] < max(a[Lnum],a[Lnum+1]) && a[Lnum + 1] > a[Lnum]){//����Һ��������������� 
				swap(a[low],a[Lnum+1]);
				low = Lnum + 1;
			}else{     //���ڵ�����Һ��Ӷ���ʱ������Ҫ���� ****** 
				break;
			}
		}else if(a[low] < a[Lnum]){   //ֻ�����ӣ������Ӵ����� 
			swap(a[low],a[Lnum]);
			low = Lnum;
		}else{      //ֻ�����ӣ������Ӳ�������������Ҫ����  **�������Ҫ��** 
			break;
		}
		//**ֻ��low��ֵ�������if�����б��ı䣨���ӣ�������һ�вŲ��ᵼ����ѭ��** 
		Lnum = 2 * low;    //���û������else��������ܵ�����ѭ��
		//�������Խ̲ĵ�ʾ��Ϊ������low=5ʱ����ѭ���� 
	} 
}

//ͨ�����µ������з�Ҷ�ӽ��������
//��[1,high]��Χ�ڽ��� 
void createHeap(int high){
	for(int i = high/2; i >= 1; i--){
		downAdjust(i,high);
	}
}

//ɾ���Ѷ�Ԫ�� 
void delTop(){
	a[1] = a[n--];
	downAdjust(1,n);
}

//���ϵ�����highΪҪ�����Ľ�� 
void upAdjust(int low, int high){
	int father = high/2;
	while(father >= 1){//�������ж�father�Ƿ���[low,high]��Χ�� 
		if(a[father] < a[high]){
			swap(a[father], a[high]);
			high = father;
			father = high/2;
		}else{
			break;
		}
	}
}

//��ӽ�� 
void insert(int v){
	a[++n] = v;
	upAdjust(1,n);
}

void layerorder(){
	for(int i = 1; i <= n; i++){
		printf("%d ",a[i]);
	}
}

void heapSort(){
	for(int j = n; j > 1; j--){
		swap(a[j],a[1]);
		if(j-1 > 1){       //ʣ������������Ԫ�ز��б�Ҫ���½���(�����ж�Ҳ��) 
			createHeap(j-1);	
		}
	}
}

int main(){ 
	layerorder();
	printf("\n");
	downAdjust(5,n);
	layerorder();
	printf("\n");
	
	createHeap(n);
	layerorder();
	printf("\n");
	
	insert(120);
	layerorder();
	printf("\n");
	
	heapSort();
	layerorder();
	return 0;
	
}
