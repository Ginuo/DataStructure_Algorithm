#include<cstdio>
#include<algorithm>

using namespace std;

int n;      //������� 
int G[1000][1000];
const int INF = 0x3fffffff;
bool vis[1000] = {false};
int d[1000]; 

void Dijkstra(int s){
	fill(d,d+1000,INF);
	d[s] = 0;
	//������趥�����ǰ�˳��ģ�����n�����㣬�����ǵı��Ϊ0~n-1
	//����ʱ���붥��Ӧע����ѭ����Լ�� 
	for(int i = 0; i < n; i++){   //ѭ��n�Σ�������MAXV�� 
		int u = -1, MIN = INF; 
		for(int j = 0; j < n; j++){ //��������d���ҳ�δ���ʵĶ�������̾�����С�� 
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];			
			}
		}
		if(u == -1) 	return;
		vis[u] = true;
		for(int v = 0; v < n; v++){
			//���û�г�ʼ��ͼG�б�ȨΪINF��if�����ںܶ�ʱ�򶼳��� 
			if(vis[v] == false && G[u][v] != INF && G[u][v]+d[u] < d[v]){
				d[v] = G[u][v] + d[u]; 
			}
		}
	}
}

int main(){
	n = 6;
	int s = 0;
	//����ʼ�ı�Ȩȫ��ΪINF 
	fill(G[0],G[0]+1000*1000,INF); //***һ��Ҫ��ʼ��ͼ����������Ȼ���˺��ѵ��� 
	G[0][1] = 1;
	G[0][3] = 4;
	G[0][4] = 4;
	G[1][3] = 2;
	G[2][5] = 1;
	G[3][2] = 2;
	G[3][4] = 3;
	G[4][5] = 3;
	Dijkstra(s);
	for(int i = 0; i < n; i++){
		printf("%d ",d[i]);
	}
	return 0;
}
