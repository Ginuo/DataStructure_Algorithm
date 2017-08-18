##两根指针

* 大致思想：
  对一个**有序序列**，用两根指针从两边往中间扫描(也可以同向扫描)，找出特定的元素（更多的是找出所有满足要求的两个数的组合）,相比暴力枚举，复杂度降低很多。

###典型实例

* 题目描述：给定一个递增的正整数序列{1，2，3，4，5，6，7}，求序列中的两个不同位置的数a和b，使得a+b=8

* 直观的想法是使用二重循环，依次枚举所有数，看它们和是否为8；但这样效率太低，很多枚举其实是没有必要的

* 使用指针i从左向右，指针j从右向左
  1. 若a[i]+a[j]==8,指针i向右移一位，j向左移一位
  2. 若a[i]+a[j] > 8,指针j向左移一位
  3. 若a[i]+a[j] < 8,指针i向右移一位

```C++
	int a[7] = {1,2,3,4,5,6,7};
	int i = 0, j = 6;          //两根指针 
	while(i < j){
		if(a[i] + a[j] == 8){
			printf("%d  %d\n",a[i],a[j]);

			i++;
			j--;
		}else if(a[i] + a[j] > 8){
			j--;
		}else{
			i++;
		}
	} 
```

###序列合并

* 将两个递增序列或两个递减序列a和b合并
* 
* 思路：
  1. 使用两个指针分别扫描a和b
  2. 引入第三个数组c，存放合并后的序列
  3. **只要有一个序列空了，就停止循环**，然后把另一个非空序列的剩余元素添加到c的末尾

```C++
int merge(int a[], int b[], int c[], int alen, int blen){
	int i = 0, j = 0;   //两根指针同向扫描两个数组
	int index = 0;
	while(i < alen && j < blen){   //只要有一个数组空了，就退出循环 
		if(a[i] < b[j]){
			c[index++] = a[i++];
		}else{
			c[index++] = b[j++];
		}
	}
	while(i < alen)		c[index++] = a[i++];
	while(j < blen)		c[index++] = b[j++];
	
	return index;  //返回合并后序列的长度 
} 
```

##归并排序（2路归并）

* 先将序列元素两两分组，组内排序；然后把这些组两两归并，组内再单独排序；以此类推，直至仅剩一个组

* 如{55，12，33，57，64，27，18}
  1. 两两分组{{55，12}，{33，57}，{64，27}，{18}}
  2. 组内排序{{12，55}，{33，57}，{27，64}，{18}}
  3. 每两组归并{{12，55，33，57}，{27，64，18}}
  4. 组内排序{{12，33，55，57}，{18，27，64}}
  5. 每两组归并{12，33，55，57，18，27，64}
  6. 组内排序{12，18，27，33，57，64，66}

* 递归实现：

```C++
//归并排序的递归实现 
 
void merge(int a[], int L1, int R1, int L2, int R2);

//***递归方法：逻辑很简单，左排序，右排序，左右归并 
void sort(int a[], int left, int right){
	if(left >= right)	return;       //**递归出口也很自然 
	int mid = (left + right)/2;
	sort(a, left, mid);             //对左边排序 
	sort(a, mid+1, right);          //对右边排序 
	merge(a,left, mid, mid+1, right);  //左右归并 
}

//将区间[L1,R1]和[L2,R2]归并，这里不需要递归！
//关键就在于使用两根指针合并两组，并把合并结果复制到原数组 
void merge(int a[], int L1, int R1, int L2, int R2){
	int i = L1, j = L2;           //两根指针
	int temp[R2 - L1 + 1];   
	int index = 0;
	while(i <= R1 && j <= R2){
		if(a[i] <= a[j]){
			temp[index++] = a[i++];
		}else{
			temp[index++] = a[j++];
		}
	} 
	while(i <= R1)		temp[index++] = a[i++];
	while(j <= R2)		temp[index++] = a[j++];
	//将临时数组的结果复制到数组a 
	for(int k = 0; k < index; k++){
		a[L1+k] = temp[k];
	}
}
```

* 还有非递归实现，暂略；

##快速排序

* 也用到了两根指针的思想

* 以某一元素（比如第一个元素）为标杆，移动元素，使得标杆元素左边的元素都不超过它，右边的元素都大于它

* 排序流程：
  1. 以首元素为切分元素进行切分，此时确定了一个元素的最终位置
  2. 对切分元素的左右两边递归切分（排序）

* 切分流程（假设数组下标从1开始，以A[1]为标杆）：
  1. 将A[1]存到临时变量temp，并令两个下标left，right分别指向序列首尾（left=1，right=n）
  2. 只要right所指向的元素A[right]大于temp，就将right**不断**左移**（使用内部循环）**；直到A[right]<=temp，将元素A[right]挪到left所指向的元素A[left]处
  3. 只要left所指向的元素A[left]小于等于temp，就将left不断右移；直到A[left]>temp，将A[left]挪到right所指向的元素A[right]处
  4. 重复2、3，直到left和right相遇，把temp放到相遇的位置

* 基本的快排

```C++
//切分，确定一个元素的最终位置 
int partition(int a[], int left, int right){
	int temp = a[left];
	while(left < right){
		//**一定要先从右边开始扫描，因为left指针初始指向的元素已保存到temp，
		//所以a[0]的位置可以先被覆盖
		// 
		while(left < right && a[right] > temp)       
			right--;
		a[left] = a[right];
		
		while(left < right && a[left] <= temp)
			left++;
		a[right] = a[left];
	} 
	a[left] = temp;
	return left;           //返回相遇的下标 ，必须！！！！！这是sort的依据 
} 

void sort(int a[], int left, int right){
	if(left >= right)	return;	
	int pos = partition(a,left,right);
	sort(a,left,pos-1);
	sort(a,right, pos+1);
	
	//***下面的写法是错误的！！ 乍一看没毛病*** 	
//	int mid = (left + right)/2; 
//因为并不是对半分的！！而是以切分元素的位置作为左右划分依据的，不能使用mid！！ 
//	partition(a,left,right); 
//	sort(a, left, mid);
//	sort(a,mid+1, right);
}

int main(){
	int a[7] = {33,53,64,1,64,5,88};
	sort(a,0,6);
	for(int k = 0; k < 7; k++){
		printf("%d ",a[k]);
	}
	return 0;
}
```

### 随机化的快排（略微修改即可）

* 首先看C语言如何生成随机数：**需要`<stdlib.h>`和`<time.h>`**
* 生成闭区间[a,b]范围内的随机数: **a + rand() % (b-a+1)**
*  

```C++
#include<cstdio>
#include<cstdlib>           //注意这两个头文件
#include<ctime>

int main(){
	srand((unsigned)time(NULL));     //生成随机数种子
	printf("%d %d\n", rand(), rand());    //需要随机数的地方调用rand即可 
	
	//生成闭区间[a,b]范围内的随机数: a + rand() % (b-a+1) 
	//例生成[2,10]范围内的随机数
	int r1 = 2 + rand()%9;
	int r2 = 2 + rand()%9;
	int r3 = 2 + rand()%9;
	printf("%d %d %d\n",r1,r2,r3); 
	return 0; 
} 
```