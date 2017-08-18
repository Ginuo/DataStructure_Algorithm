#include<cstdio>
#include<vector>
using namespace std;

//�����Զ��ѡ��ͬһ������ֻ��Ҫ��ѡ��index����������֧�޸�һ�� 
int N,K,X;
int a[10];
int Kcnt = 0;
int maxSumSqu = -1;
vector<int> ans, temp;     //�洢���շ����͵�ǰ���� 

//�ĸ����� 
void DFS(int index, int Kcnt, int sum, int sumSqu){
	if(Kcnt == K){  //ȡ����K������Ȼ���ж� 
		if(sum == X && sumSqu > maxSumSqu){  //����ΪX �� ƽ���ʹ���֮ǰ�ķ��� 
			ans = temp;             //����answer���� 
			maxSumSqu = sumSqu;     //�������ƽ���� 
		}
		return;
	}
	//������һ�����Ҫ����ʱ������ö������֮��Kcnt���ܻ�С��K����������һ���ݹ����
	//���Ա���Ҫ����ĳ��ڣ�
	//Ԫ�غʹ���Xʱ��Ҳ����ֹͣ�ݹ飨��֦�� 
	if(index == N || sum > X)  return;
	//ѡ��index����,�����ȴ��������֧ 
	temp.push_back(a[index]);
	DFS(index, Kcnt+1, sum + a[index], sumSqu + a[index]*a[index]);
	//��ѡ��index���� 
	temp.pop_back();
	DFS(index+1, Kcnt, sum, sumSqu);
	
}

int main(){
	scanf("%d %d %d",&N,&K,&X);
	for(int i = 0; i < N; i++){
		scanf("%d",&a[i]);
	}
	DFS(0,0,0,0);
	for(int i = 0; i < ans.size(); i++){
		printf("%d\n",ans[i]);
	}
	printf("%d\n",maxSumSqu);
	return 0;
} 
