#include<cstdio>
#include<vector>
using namespace std;

//若可以多次选择同一个数，只需要把选择index号数这条分支修改一下 
int N,K,X;
int a[10];
int Kcnt = 0;
int maxSumSqu = -1;
vector<int> ans, temp;     //存储最终方案和当前方案 

//四个参数 
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
	//选第index号数,必须先处理这个分支 
	temp.push_back(a[index]);
	DFS(index, Kcnt+1, sum + a[index], sumSqu + a[index]*a[index]);
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
