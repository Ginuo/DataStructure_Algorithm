#include<cstdio>
#include<algorithm>
using namespace std;

//0号位忽略，置为任何数都可以
//数组最好可以命名为heap 
int a[100] = {-1,85,55,82,57,68,92,99,98,66,56}; 
int n = 10;     //heap大小 

//low为要调整的结点下标，high通常是最后一个结点的下标 
void downAdjust(int low, int high){
	int Lnum = 2 * low;    //左孩子的下标 
	while(Lnum <= high){      //如果有左结点 
		if(Lnum + 1 <= high){  //如果也有右结点 
			if(a[low] < max(a[Lnum],a[Lnum+1]) && a[Lnum] > a[Lnum+1]){  //如果左孩子是三个中（根，左，右）最大的 
				swap(a[low],a[Lnum]);
				low = Lnum;
			}else if(a[low] < max(a[Lnum],a[Lnum+1]) && a[Lnum + 1] > a[Lnum]){//如果右孩子是三个中最大的 
				swap(a[low],a[Lnum+1]);
				low = Lnum + 1;
			}else{     //根节点比左右孩子都大时，不需要调整 ****** 
				break;
			}
		}else if(a[low] < a[Lnum]){   //只有左孩子，且左孩子大于它 
			swap(a[low],a[Lnum]);
			low = Lnum;
		}else{      //只有左孩子，且左孩子不大于它，不需要调整  **这个必须要有** 
			break;
		}
		//**只有low的值在上面的if语句块中被改变（增加）过，下一行才不会导致死循环** 
		Lnum = 2 * low;    //如果没有最后的else，这里可能导致死循环
		//（比如以教材的示例为例，当low=5时会死循环） 
	} 
}

//通过向下调整所有非叶子结点来建堆
//在[1,high]范围内建堆 
void createHeap(int high){
	for(int i = high/2; i >= 1; i--){
		downAdjust(i,high);
	}
}

//删除堆顶元素 
void delTop(){
	a[1] = a[n--];
	downAdjust(1,n);
}

//向上调整，high为要调整的结点 
void upAdjust(int low, int high){
	int father = high/2;
	while(father >= 1){//必须先判断father是否在[low,high]范围内 
		if(a[father] < a[high]){
			swap(a[father], a[high]);
			high = father;
			father = high/2;
		}else{
			break;
		}
	}
}

//添加结点 
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
		if(j-1 > 1){       //剩余两个及以上元素才有必要重新建堆(不加判断也行) 
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
