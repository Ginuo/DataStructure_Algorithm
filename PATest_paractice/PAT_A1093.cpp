#include<cstdio>
#include<cstring>

const int MOD = 1000000007; 
const int maxn = 100001; 

struct A{        //ÿ��Ԫ�ر�ʾһ��A 
	int leftP;         //��A��ߵ�P�ĸ��� 
	int rightT;        //�ұߵ�T�ĸ��� 
} a[maxn];


int main(){
  char str[maxn];
  gets(str);
  int len = strlen(str);

  int p = 0;      //��¼P�ĸ��� 
  int t = 0;      //��¼T�ĸ��� 
  int index = 0;      //�ṹ����������� 
  //��������ɨ�裬��'P'���� 
  for(int i = 0; str[i] != '\0'; i++){
    if(str[i] == 'P'){       
      p++;
    }
    else if(str[i] == 'A'){ //����һ��A���Ͱ�����ߵ�P�ĸ�����¼���ṹ�� 
      a[index++].leftP = p;
    }
  }
  //��������ɨ�裬��'T'���� 
  int x = index;
  for(int i = len - 1; i >= 0; i--){
    if(str[i] == 'T')
      t++;
    else if(str[i] == 'A') //����һ��A���Ͱ����ұߵ�T�ĸ�����¼���ṹ�� 
      a[--x].rightT = t;  
  
  }
  
  int ans = 0;
  for(int i = 0; i < index; i++){
    //****һ��Ҫ�������ÿһ��ȡ�࣬�����ǽ������ǰ�����ս��ȡ����
	//****��Ϊ�м���Ҳ�����������
    ans = (ans + a[i].leftP * a[i].rightT) % MOD;
  }
  printf("%d\n",ans);            //ans % MOD ����д������ 
  return 0;
} 
