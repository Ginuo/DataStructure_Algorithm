#include<cstdio>
#include<cstdlib>
#include<ctime>

int randPartition(int a[], int left,int right);

//从无序序列中找出第K大元素 

//重点注意两个return，第K大元素可能从两个地方返回 
int randSelect(int a[], int left, int right, int K){
	if(left == right) 	return a[left];     //返回第K大元素 **最坏情况，容易漏写！！ 
	int p = randPartition(a,left,right);  //调用切分，返回切分元素的位置 
	int M = p - left + 1;             //切分元素是序列中第M大元素（p只是它的位置，不是第p大！！） 
	if(K == M)	return a[p];          //切分元素正好是第K大元素时返回  
	if(K > M)
		return randSelect(a, p+1, right, K-M);      //K>M时，查找右边的第K-M大元素 
	else
		return randSelect(a, left, p-1, K);        //K<M时，查找左边的第K大元素 
	
}

//这是随机快速排序中的切分算法 
int randPartition(int a[], int left, int right){
	srand((unsigned)time(NULL));
	int rnd_pos = left + rand() % (right - left + 1);
	
	int t = a[rnd_pos];
	a[rnd_pos] = a[left];
	a[left] = t;
	
	int x = a[left];
	while(left < right){
		while(left < right && a[right] > x)		right--;
		a[left] = a[right];
		while(left < right && a[left] <= x)		left++;
		a[right] = a[left];
	}
	a[left] = x;
	return left;
} 

int main(){
	int a[1] = {9};
	int index;
	scanf("%d",&index);            //输入K，查询第k大的元素 
	int ans = randSelect(a,0,9,index);
	printf("%d", ans);
	return 0;
}
