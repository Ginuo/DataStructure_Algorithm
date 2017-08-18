#include<cstdio>
#include<algorithm>
#include<string.h> 
using namespace std;

const int INF = 0x3fffffff;
int G[100][100];     //ͼ���洢��Ȩ����������100������ 
                     //G[u][v]Ϊ1��ʾ�д�u��v�ı�
					 //ֵΪINF��ʾû�б� 
bool vis[100] = {false}; //visited����¼�Ƿ���ʹ�

//����һ����ͨ�� ������uΪ��� 
void DFS(int u){
	vis[u] = true;     //���������ó��ѷ��ʣ���ѭ�� 
	for(int v = 0; v < 100; v++){
		if(G[u][v] != INF && vis[v] == false){
			printf("%d ",v);
			DFS(v); 
		}
	}
} 

//��������ͼ��������ͨ�飩 
void traveAll(){
	for(int u = 0 ; u < 100; u++){
		if(vis[u] == false){
			DFS(u);
		} 
	}
}

int main(){
	//��ʼ����Ȩ 
	for(int i = 0; i < 100; i++){
		fill(G[i],G[i]+100,INF);
	}
	//�����㷨�ʼǡ�P351��������ͼ 
	G[0][1] = 1;
	G[1][4] = 1;
	G[4][5] = 1;
	G[5][3] = 1;
	G[0][2] = 1;
	G[2][4] = 1;
	G[2][1] = 1;
	G[1][3] = 1;
	G[4][3] = 1; 
	
	DFS(0);  //��ΪͼG����ͨ�ģ�����DFS(0)�Ѿ�����������ͼ
	         //�Ҹ������Ӧ��visԪ���ѱ���Ϊtrue
			 //���Լ�������traveAll֮ǰ����������vis����
			 //����ʲô������������� 
	printf("\n");
	memset(vis,0,sizeof(vis)); 
	traveAll();
	return 0;
}
