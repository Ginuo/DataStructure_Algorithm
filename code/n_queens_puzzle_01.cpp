#include<cstdio>
#include<cmath>

//���������n�ʺ����⣺
/*˼·�� 
1��ÿһ�еĻʺ����ڵ��к�����д��������1~n��һ������
2������ȫ����
3����Ϊÿ����һ�εݹ�߽磬��������һ�����У�
�����ڵݹ�߽�Ե�ǰ�����е�**����**�����ʺ��Ƿ���һ���Խ��߽����ж�
**�ؼ���������ж��Ƿ���ͳһ�Խ��� 
*/ 

const int maxn = 11;        //����һ���Ƚ�С�����ֶ��� 
int n;
int count = 0;       //����������¼�ж��ٸ��Ϸ����� 
int P[maxn];
bool hashTable[maxn] = {false};


void generateP(int index){
	if (index == n+1){
		bool flag = true;             //flag�����ж��Ƿ�Ϸ����Ǽ����������� 
		//***���Ĵ��룺�ж��Ƿ��лʺ���ͬһ���Խ���*** 
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				//***ֻҪ�����ʺ�֮������ߵ�б�ʵľ���ֵΪ1����˵����ͬһ�Խ����� 
				//***����˵��ֻҪ�����ʺ���о���о���ȣ�����ͬһ�Խ����� 
				if(abs(i-j) == abs(P[i] - P[j]))
					flag = false;        //�лʺ���ͬһ�Խ����ϣ����Ϸ��������� 
			}
		} 
		if(flag) count++;
		return;             //***һ��Ҫ�ǵ�return������ 
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
