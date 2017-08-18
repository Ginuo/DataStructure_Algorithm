##深度优先搜索（迷宫问题）

* 每次碰到岔道口时，总是以“深度”作为前进的关键词，只有碰到死胡同才回到岔道口，每次走到死胡同就是一条**完整路径**的形成

* 深度优先搜索是一种枚举所有完整路径以遍历所有情况的搜索方法

* **DFS通常以递归方式实现**（也可以用栈实现，但难度较大，递归本质也是栈），递归式就是岔道口，递归边界就是死胡同

##背包问题

* 问题描述：
  有n件物品，每件物品的重量是w[i]，价值为c[i]。现在需要选出若干件物品放入一个容量为V的背包中，使得在选入背包的物品重量和不超过容量V的前提下，让背包中物品的价值之和最大，求最大价值。(1<= n <= 20)

* 基本算法：复杂度较高O(2^n)

* 三个参数：
  * index用于对n个物品计数，从0开始（因为要作为数组下标）
  * sumW当前已选物品的总重量
  * sumC当前已选物品的总价值

```C++
const int maxn = 30;
int n;          //n件物品 
int V;          //背包容量V 
int maxV = 0;        //最大价值
int w[maxn]= {3,5,1,2,2};
int c[maxn]= {4,5,2,1,3};  //存储每件物品的重量和价值 

void DFS(int index, int sumW, int sumC){
	if(index == n){      //所有物品都选完了，结束递归 
		if(sumW <= V && sumC > maxV){  //当前方案的总价值大于以前方案的最大价值，更新最大价值 
			maxV = sumC;
		}
		return;
	}
	
	DFS(index+1,sumW,sumC);   //不选择第index号物品，不需要优化
	DFS(index+1,sumW+w[index],sumC+c[index]); //若选择index号物品不会超重，则选择第index号物品
	 
}

int main(){
	n = 5;
	V = 8;
	DFS(0,0,0);
	printf("maxV=%d\n",maxV);
	return 0;
}
```

* **剪枝优化**：当取该件物品会超过重量时，可以不继续递归选择下去而直接判断并更新最大价值，然后return

* 只有当`sumW<=V`时才进入第二个岔道（选择当前物品）

```C++
void DFS(int index, int sumW, int sumC){
	if(index == n){      //所有物品都选完了，结束递归 
		if(sumW <= V && sumC > maxV){  //当前方案的总价值大于以前方案的最大价值，更新最大价值 
			maxV = sumC;
		}
		return;
	}
	
	DFS(index+1,sumW,sumC);   //不选择第index号物品，不需要优化
	 
	//该if语句块只是一种优化，出于做题时间考虑，可以不写
	if(sumW + w[index] <= V){ //若选择第index号物品超重了，就不需要该趟递归了 
		if(sumC + c[index] > maxV){
			maxV = sumC + c[index];
		}
		DFS(index+1,sumW+w[index],sumC+c[index]); 
		//若选择index号物品不会超重，则选择第index号物品	
	}
	 
}
```

##问题的一般化

* 问题描述：给定一个序列，枚举这个序列的所有子序列（可以不连续）
  比如：对于{1，2，3}来说，所有子序列为{1}，{2}，{3}，{1，2}，{1，3}，{2，3}，{1，2，3}

* **全排列算法**与此有区别，全排列是关心顺序的，同一个序列会以不同的排列顺序多次出现

* 例题：
  给定N个整数，从中选择K个数，使得这K个数之和恰好等于一个给定的整数X；
  如果有多种方案，选择它们中元素平方和最大的一个。（数据保证这样的方案唯一）

* 要先处理“**选择**第index个元素”的分支，再处理“**不选择**第index个元素”的分支

```C++
#include<cstdio>
#include<vector>

using namespace std;

int N,K,X;
int a[10];
int Kcnt = 0;
int maxSumSqu = -1;
vector<int> ans, temp;     //存储最终方案和当前方案 

//四个参数
//index对N计数
//Kcnt对已选数字计数
//sum和sumSqu表示当前的元素和、平方和，
void DFS(int index, int Kcnt, int sum, int sumSqu){
	if(Kcnt == K){  //取足了K个数，然后判断 
		if(sum == X && sumSqu > maxSumSqu){  //若和为X 且 平方和大于之前的方案 
			ans = temp;             //更新answer向量 
			maxSumSqu = sumSqu;     //更新最大平方和 
		}
		return;
	}
	//下面这一句必须要，有时所有数枚举完了之后，Kcnt可能还小于K，到不了上一个递归出口
	//所以必须要下面的出口；
	//元素和大于X时，也可以停止递归（剪枝） 
	if(index == N || sum > X)  return;
	//选第index号数 （必须先处理这个分支）
	temp.push_back(a[index]);
	DFS(index+1, Kcnt+1, sum + a[index], sumSqu + a[index]*a[index]);
	//不选第index号数 
	temp.pop_back();
	DFS(index+1, Kcnt, sum, sumSqu);
	
}

int main(){
	scanf("%d %d %d",&N,&K,&X);
	for(int i = 0; i < N; i++){
		scanf("%d",&a[i]);
	}
	DFS(0,0,0,0);
	for(int i = 0; i < ans.size(); i++){
		printf("%d\n",ans[i]);
	}
	printf("%d\n",maxSumSqu);
	return 0;
}
```

* 若一个元素可以被多次选择：只要修改“选index号数”这条分支
  改为：（把index+1改为index即可）
  `DFS(index, Kcnt+1, sum+a[index], sumSqu+a[index]*a[index]);`