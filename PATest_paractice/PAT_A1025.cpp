#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Student{
	char id[15];
	int score;
	int final_r;
	int loc;
	int local_r;
} stu[100*300];

int index_counter = 0; 

bool cmp(Student a, Student b){
	if(a.score != b.score)
		return a.score > b.score;
	else
		return strcmp(a.id,b.id) < 0;
}

int main(){
	int nLists, nStu;   
	scanf("%d",&nLists);
	for(int i = 0; i < nLists; i++){
		scanf("%d",&nStu);
		int k;
		for(k = 0; k < nStu; k++){
			scanf("%s %d",stu[index_counter].id, &stu[index_counter].score);   //��¼׼��֤�źͷ��� 
			stu[index_counter].loc = i + 1;      //��¼������ 
			index_counter++;
		}
		//sort�����ǵ�ʹ��algorithmͷ�ļ���std�����ռ�
		//sort���Է�������ڶ������һ�������� 
		sort(&stu[index_counter - k], &stu[index_counter], cmp);    //��ÿ�������ֱ�����
		
		stu[index_counter - k].local_r = 1; 
		for(int ii = 1; ii < k; ii++){              //��¼�������������ṹ�� 
			if(stu[index_counter - k + ii].score == stu[index_counter - k + ii - 1].score){
				stu[index_counter - k + ii].local_r = stu[index_counter - k + ii - 1].local_r;
			}else{
				stu[index_counter - k + ii].local_r = ii + 1;
			}
		} 
	}
	
	sort(stu, stu + index_counter, cmp);
	stu[0].final_r = 1;
	for(int i = 1; i < index_counter; i++){          //��¼�������� 
		if(stu[i].score == stu[i-1].score)
			stu[i].final_r = stu[i-1].final_r;
		else
			stu[i].final_r = i+1;
	}
	
	printf("%d\n",index_counter);
	for(int i = 0; i < index_counter; i++){
		printf("%s %d %d %d\n", stu[i].id, stu[i].final_r, stu[i].loc, stu[i].local_r);
	}
	return 0;
}
