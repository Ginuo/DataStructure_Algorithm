#include<cstdio>
#include<vector>

using namespace std;

struct Node{
	int v;    //�յ���Vertex
	int w;    //��Ȩ 
	Node(int _v, int _w):v(_v),w(_w){}     //���캯�� 
}; 

vector<Node> Adj[100];

int main(){
	//�����ֻ��Ҫpush_backһ�Σ���0��3 
	Adj[0].push_back(Node(3,100));
	//���������ߣ���Ҫ����洢һ��,��3��0 
	Adj[3].push_back(Node(0,100)); 
	return 0;
}
