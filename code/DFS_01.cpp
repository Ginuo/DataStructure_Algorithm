#include<cstdio>

const int maxn = 30;
int n;          //n����Ʒ 
int V;          //��������V 
int maxV = 0;        //����ֵ
int w[maxn]= {3,5,1,2,2};
int c[maxn]= {4,5,2,1,3};  //�洢ÿ����Ʒ�������ͼ�ֵ 

void DFS(int index, int sumW, int sumC){
	if(index == n){      //������Ʒ��ѡ���ˣ������ݹ� 
		if(sumW <= V && sumC > maxV){  //��ǰ�������ܼ�ֵ������ǰ����������ֵ����������ֵ 
			maxV = sumC;
		}
		return;
	}
	
	DFS(index+1,sumW,sumC);   //��ѡ���index����Ʒ������Ҫ�Ż�
	
	//��if����ֻ��һ���Ż�����������ʱ�俼�ǣ����Բ�д 
	if(sumW + w[index] <= V){ //��ѡ���index����Ʒ�����ˣ��Ͳ���Ҫ���˵ݹ��� 
		if(sumC + c[index] > maxV){
			maxV = sumC + c[index];
		}
		DFS(index+1,sumW+w[index],sumC+c[index]); 
		//��ѡ��index����Ʒ���ᳬ�أ���ѡ���index����Ʒ
	}
	
	
	 
}

int main(){
	n = 5;
	V = 8;
	DFS(0,0,0);
	printf("maxV=%d\n",maxV);
	return 0;
}
