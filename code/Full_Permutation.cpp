#include<cstdio>

const int maxn = 10;
int n;         //对从1到n的数字排列 
int P[maxn];    //记录当前这一个排列，第一位闲置 
bool hashTable[maxn] = {false};   //散列数组，判断数字是否已在排列中 

//没有返回值的递归函数！使用return返回 
/*
特殊的是：generateP函数的参数index，初始值为1， 
          index随着递归深度增加而增加（而fabonacci数列的参数是递减的） 
*/
void generateP(int index){
	if(index == n+1){       //***递归边界，已经处理完排列的第1~n位 
		for(int i = 1; i <= n; i++){
			printf("%d",P[i]);
		}
		printf("\n");
		return ;       //空的返回 
	} 
	/*
	核心代码也就下面这几行，以上的几行都是处理边界情况，不需要刻意记
	*/ 
	for (int x = 1; x <= n; x++){      //枚举1~n，每个for循环生成以x开头的所有排列 
		if(hashTable[x] == false){
			P[index] = x;            //如果x不在数组（即排列）中，将其加入数组 
			hashTable[x] = true;
			generateP(index + 1);     //处理当前排列的下一位
			hashTable[x] = false;       //已处理完P[index]为x的子问题，还原状态  
			                            //**同层其他**递归过程还要使用（保证子问题的独立性） 
		}
	} 
}

int main(){
	n = 3;    //输出从1-3的全排列
	generateP(1);      //**注意：参数不是n，是1     表示从1开始
	return 0; 
}
