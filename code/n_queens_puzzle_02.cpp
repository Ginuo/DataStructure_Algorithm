#include<cstdio>
#include<cmath>

//����ִ�д��󣡣��� 

//���ݷ����n�ʺ�����
/*
�ڱ����������ϣ�
��������һ���ֻʺ�֮�����������е�һ���֣���ʣ��Ļʺ��������
�������ö�����֮ǰ���ѷ��ã���ĳ���ʺ���һ���Խ����ϣ�
�����磬��3���ʺ�������ô���ã��������1���ʺ���һ���Խ���ʱ�� 
��ʱû��Ҫ���µݹ飬ֱ�ӷ����ϲ㼴��
**ֻ�кϷ������ܵ���ݹ�߽�  
*/ 

const int maxn = 11;
int n;      //1~n������
int P[maxn];       //��ŵ�ǰ���� 
int hashTable[maxn] = {false};
int count = 0;     //�Ϸ����������� 

void generateP(int index){
	if(index == n+1){
		for(int i = 1; i <= n; i++){
			printf("%d",P[i]);
		}
		printf("\n");
		count++;        //��ִ�е���ģ����ǺϷ����� 
		return;
	}
	for(int x = 1; x <= n; x++){
		if(hashTable[x] == false){     //����x�л�û�лʺ� 
			bool flag = true;        //flagΪtrue��ʾ��ǰ�ʺ󲻻��֮ǰ���κλʺ��ͻ
			//�жϽ����õĻʺ��к�Ϊx�����Ƿ���֮ǰ�Ļʺ��ͻ 
			for(int pre = 1; pre < index; pre++){  //����֮ǰ�Ļʺ� 
				//��index�лʺ���к�Ϊx����pre�лʺ���к�ΪP[pre] 
				if(abs(index-pre) == abs(x-P[pre])){
					flag = false;
					break;  
				}
			} 
			//**ע�⣡����Ҫ��������ifд��ǰ���forѭ������ 
			if(flag){
				P[index] = x; 
				hashTable[x] = true;
				generateP(index + 1);
				hashTable[x] = false;
			}
		} 
	}
	
} 

int main(){
	n = 8;
	generateP(1);
	printf("n=%dʱ���Ϸ�������Ϊ%d��",n,count);
	return 0;
} 
