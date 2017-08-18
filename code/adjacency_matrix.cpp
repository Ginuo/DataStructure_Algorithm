#include<cstdio>
#include<vector>

using namespace std;

struct Node{
	int v;    //终点编号Vertex
	int w;    //边权 
	Node(int _v, int _w):v(_v),w(_w){}     //构造函数 
}; 

vector<Node> Adj[100];

int main(){
	//有向边只需要push_back一次，从0到3 
	Adj[0].push_back(Node(3,100));
	//如果是无向边，还要反向存储一次,从3到0 
	Adj[3].push_back(Node(0,100)); 
	return 0;
}
