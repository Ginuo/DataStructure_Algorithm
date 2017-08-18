#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

struct node{
	int u;
	int w;
	node(int _u, int _w):u(_u),w(_w){}
};

int indegree[500];
vector<node> Adj[500];
stack<int> topOrder;
int ve[500];
int vl[500];
int n;

bool toplogicalSort(){
	for(int i = 0; i < n; i++){
		if(indegree[i] == 0){
			topOrder.push(i);
		}
	}
	queue<int> q;
	int sum = 0;       //�����ж��Ƿ��������޻�ͼ 
	q.push(0);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		sum++;
		topOrder.push(u);      //��ջ��λ�ú���Ҫ����䲻����forѭ���� 
		for(int i = 0; i < Adj[u].size(); i++){
			int v = Adj[u][i].u;
			int w = Adj[u][i].w;
			indegree[v]--;
			if(indegree[v] == 0)	q.push(v);
			if(ve[v] < ve[u] + w){    //ע����ţ�max{ĳǰ���������翪ʼʱ��+��Ӧ�Ļ����ʱ��} 
				ve[v] = ve[u] + w;
			}
			
		}
	}
	if(sum == n)	return true;
	else if(sum > n)	return false;
}

int criticalPath(){
	//��ʼ��vl���飬����vlÿ��Ԫ�ض����ڹ��̽��������ʱ��
	//�������һ���¼��Ŀ�ʼʱ�䣨����������ȣ� 
	fill(vl,vl+n,ve[n-1]);           
	while(!topOrder.empty()){
		int u = topOrder.top();
		topOrder.pop();
		for(int i = 0; i < Adj[u].size(); i++){
			int v  = Adj[u][i].u;
			int w = Adj[u][i].w;
			if(vl[u] > vl[v] - w){//vl[u] = min{��̽��v������ʼʱ�� - ��Ӧ�Ļ����ʱ��}
				vl[u] = vl[v] - w;
			} 
		}
	}
	
	for(int u = 0; u < n; u++){     //�������б� 
		for(int j = 0; j < Adj[u].size(); j++){
			int v = Adj[u][j].u;
			int w = Adj[u][j].w;
			int e = ve[u];     //����翪ʼʱ��=ǰ���¼����翪ʼʱ�� 
			int l = vl[v] - w; //�����ʼʱ��=���ʱ������ʼʱ�� - �����ʱ�� 
			if(e == l){      //�жϲ�������йؼ���������ɹؼ�·���� 
				printf("%d-->%d\n",u,v);
			}
		} 
	}
	return ve[n-1];   //�ؼ�·������   =vl[n-1] 
}

int main(){
	int m;//m����(**ע��**������n�Ѿ��������ȫ�ֱ����������ظ����壬����Ḳ��)
	scanf("%d%d",&n,&m);
	for(int i = 0; i < m; i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		Adj[u].push_back(node(v,w));
		indegree[v]++;
	} 
	
	//������� 
//	indegree[0] = 0;
//	indegree[1] = 1;
//	indegree[2] = 1;
//	indegree[3] = 1;
//	indegree[4] = 2;
//	indegree[5] = 1;
//	Adj[0].push_back(node(1,30));
//	Adj[0].push_back(node(3,40));
//	Adj[1].push_back(node(2,40));
//	Adj[3].push_back(node(4,40));
//	Adj[2].push_back(node(4,50));
//	Adj[4].push_back(node(5,70));
	
	if(toplogicalSort()){
		int len = criticalPath();
		printf("length of the criticalPath is %d\n",len);
	}else{
		printf("false");
	}
	return 0;
}

