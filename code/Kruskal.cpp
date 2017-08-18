#include<cstdio>
#include<algorithm>

using namespace std;

struct Edge{
	int u,v;
	int w;
	Edge(){}//�յĹ��캯������Ҫ�������޷���ʼ������e������Ȼ�����ò���������캯���� 
	Edge(int _u, int _v, int _w):u(_u),v(_v),w(_w){}
}e[500];

bool cmp(Edge a, Edge b){
	return a.w < b.w;
}

int father[500];
int n,m;   //n--->������  m------>���� 

int findFather(int x){
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x; 
	} 
	return x;
}

int kruskal(){
	int sum = 0;          //��Ȩ�� 
	int edgeCnt = 0;      //�Ѽ���ı��� 
	for(int i = 0; i < n; i++){
		father[i] = i;
	}
	sort(e,e+m,cmp);
	for(int i = 0; i < m; i++){
		int u = e[i].u;
		int v = e[i].v;
		int w = e[i].w;
		int fau = findFather(u);
		int fav = findFather(v);
		if(fau != fav){
			sum += w;
			father[fau] = fav;
			//father[u] = v;  //***�ǳ����״�һ�����ֱ�Ӹ�Ϊָ����һ����㲢���ܺϲ���������**
			                 //������һ�����ĸ��ڵ�ָ����һ�����ĸ��ڵ㣡��************* 
			                 //���鼯�ϲ���ʱ����û���ͼ�����Է��������ҵ�bug 
			edgeCnt++;
			//����=������-1���������ʣ�ʱ���Ϳ����˳�ѭ���� 
			if(edgeCnt==n-1)	break;   //����������΢��㣬����Ҳ��Ӱ���� 
		}
	}
	if(edgeCnt == n-1)	return sum;
	if(edgeCnt < n-1)   return -1;   //��ͼ����ͨ������-1 
	
}

int main(){
	n = 6;
	m = 10;
	//��409ҳ����ͼ 
	e[0] = Edge(0,4,1);
	e[1] = Edge(0,1,4);
	e[2] = Edge(0,5,2);
	e[3] = Edge(5,1,3);
	e[4] = Edge(5,4,3);
	e[5] = Edge(5,3,4);
	e[6] = Edge(5,2,5);
	e[7] = Edge(1,2,1);
	e[8] = Edge(2,3,6);
	e[9] = Edge(3,4,5);
	int ans = kruskal();
	printf("%d\n",ans);
	return 0;
}








