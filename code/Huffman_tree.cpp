#include<cstdio> 
#include<queue>

using namespace std;

//С���� 
//ע��'>>'֮���ÿո����"> >" 
priority_queue<long long, vector<long long>, greater<long long> > pq;

int main(){
	pq.push(1);
	pq.push(2);
	pq.push(9);
	long long ans = 0;
	while(pq.size() > 1){
		long long a = pq.top();
		pq.pop();
		long long b = pq.top();
		pq.pop();
		pq.push(a+b);
		ans += a+b;//��һ�����Ҫ�����У��ѣ������һ��Ԫ�ؽ����������Ͷ���
	}
	printf("%lld\n",ans);
	return 0;
}
