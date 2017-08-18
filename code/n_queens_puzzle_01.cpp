#include<cstdio>
#include<cmath>

//暴力法解决n皇后问题：
/*思路： 
1、每一行的皇后所在的列号依次写出，会是1~n的一个排列
2、生成全排列
3、因为每到达一次递归边界，就生成了一个排列，
所以在递归边界对当前排列中的**任意**两个皇后是否在一条对角线进行判断
**关键在于如何判断是否在统一对角线 
*/ 

const int maxn = 11;        //任意一个比较小的数字都行 
int n;
int count = 0;       //计数器，记录有多少个合法排列 
int P[maxn];
bool hashTable[maxn] = {false};


void generateP(int index){
	if (index == n+1){
		bool flag = true;             //flag用于判断是否合法，是计数器的依据 
		//***核心代码：判断是否有皇后在同一条对角线*** 
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				//***只要两个皇后之间的连线的斜率的绝对值为1，就说明在同一对角线上 
				//***或者说，只要两个皇后的行距和列距相等，就在同一对角线上 
				if(abs(i-j) == abs(P[i] - P[j]))
					flag = false;        //有皇后在同一对角线上，不合法，不计入 
			}
		} 
		if(flag) count++;
		return;             //***一定要记得return！！！ 
	}
	
	for(int x = 1; x <= n; x++){
		if(hashTable[x] == false){
			P[index] = x;
			hashTable[x] = true;
			generateP(index+1);
			hashTable[x] = false;
		}
	}
}

int main(){
	n = 5;
	generateP(1);
	return 0;
} 
