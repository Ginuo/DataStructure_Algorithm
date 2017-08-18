#include<cstdio>
#include<cstring>

const int MOD = 1000000007; 
const int maxn = 100001; 

struct A{        //每个元素表示一个A 
	int leftP;         //该A左边的P的个数 
	int rightT;        //右边的T的个数 
} a[maxn];


int main(){
  char str[maxn];
  gets(str);
  int len = strlen(str);

  int p = 0;      //记录P的个数 
  int t = 0;      //记录T的个数 
  int index = 0;      //结构体数组的索引 
  //从左往右扫描，对'P'计数 
  for(int i = 0; str[i] != '\0'; i++){
    if(str[i] == 'P'){       
      p++;
    }
    else if(str[i] == 'A'){ //遇到一个A，就把它左边的P的个数记录到结构体 
      a[index++].leftP = p;
    }
  }
  //从右往左扫描，对'T'计数 
  int x = index;
  for(int i = len - 1; i >= 0; i--){
    if(str[i] == 'T')
      t++;
    else if(str[i] == 'A') //遇到一个A，就把它右边的T的个数记录到结构体 
      a[--x].rightT = t;  
  
  }
  
  int ans = 0;
  for(int i = 0; i < index; i++){
    //****一定要在这里对每一步取余，而不是仅在输出前对最终结果取！！
	//****因为中间结果也可能溢出！！
    ans = (ans + a[i].leftP * a[i].rightT) % MOD;
  }
  printf("%d\n",ans);            //ans % MOD 不能写在这里 
  return 0;
} 
