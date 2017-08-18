#include<cstdio>

const int maxn = 10;
int n;         //�Դ�1��n���������� 
int P[maxn];    //��¼��ǰ��һ�����У���һλ���� 
bool hashTable[maxn] = {false};   //ɢ�����飬�ж������Ƿ����������� 

//û�з���ֵ�ĵݹ麯����ʹ��return���� 
/*
������ǣ�generateP�����Ĳ���index����ʼֵΪ1�� 
          index���ŵݹ�������Ӷ����ӣ���fabonacci���еĲ����ǵݼ��ģ� 
*/
void generateP(int index){
	if(index == n+1){       //***�ݹ�߽磬�Ѿ����������еĵ�1~nλ 
		for(int i = 1; i <= n; i++){
			printf("%d",P[i]);
		}
		printf("\n");
		return ;       //�յķ��� 
	} 
	/*
	���Ĵ���Ҳ�������⼸�У����ϵļ��ж��Ǵ���߽����������Ҫ�����
	*/ 
	for (int x = 1; x <= n; x++){      //ö��1~n��ÿ��forѭ��������x��ͷ���������� 
		if(hashTable[x] == false){
			P[index] = x;            //���x�������飨�����У��У������������ 
			hashTable[x] = true;
			generateP(index + 1);     //����ǰ���е���һλ
			hashTable[x] = false;       //�Ѵ�����P[index]Ϊx�������⣬��ԭ״̬  
			                            //**ͬ������**�ݹ���̻�Ҫʹ�ã���֤������Ķ����ԣ� 
		}
	} 
}

int main(){
	n = 3;    //�����1-3��ȫ����
	generateP(1);      //**ע�⣺��������n����1     ��ʾ��1��ʼ
	return 0; 
}
