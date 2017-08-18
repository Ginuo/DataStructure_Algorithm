#include<cstdio> 
#include<queue>

using namespace std;

//小顶堆 
//注意'>>'之间用空格隔开"> >" 
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
		ans += a+b;//这一句必须要，队列（堆）中最后一个元素仅仅是质量和而已
	}
	printf("%lld\n",ans);
	return 0;
}
