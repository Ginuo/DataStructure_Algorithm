#include<iostream>
#include<cstring> 
#include<string>
using namespace std;

/*�ֵ�����Trie���� 
����Ӧ��������ͳ�ƣ�����ͱ���������ַ����������������ַ�������
���Ծ�������������ϵͳ�����ı���Ƶͳ�ơ�
�����ŵ��ǣ������ַ����Ĺ���ǰ׺����Լ�洢�ռ䣬
����޶ȵؼ�����ν���ַ����Ƚϣ���ѯЧ�ʱȹ�ϣ��ߡ� 

ע�⣺����+��ѯ��trie���ǿ���ͬʱִ�еģ������Ĺ���Ҳ�Ϳ��Գ�Ϊ��ѯ�Ĺ���
���磺��n�����ʣ��������Ƿ����ĳ�������� ����������һ������һ����ǰ׺
      �Ϳ��Ա߽����߲�ѯ�� 
*/



const int CHILD_NUM = 26;

struct Trie{
	//ÿ�����26���ӽ�㣨26����ĸ������Ҫ��ʾ��Сд�ĵ��ʣ���CHILD_NUMӦΪ52
	//������֧��26��Сд��ĸ 
	Trie* next[CHILD_NUM];    //��������ʾ��ĸ 
	bool isEndOfSomeStr;        //�ַ�����β��ǣ�����һ����Ҷ�ӽ�㣩 
	//int v;  //v���Ա�ʾһ���ֵ��������ж��ٸ���ͬǰ׺�ĵ��ʣ������京��ɸ�����Ҫ���ɱ仯��
	Trie(){
		isEndOfSomeStr = false;
		for(int i = 0; i < CHILD_NUM; ++i){
			next[i] = NULL;
		}
	}
}; 


//�����ַ����������ֵ��� 
//���а������ֵ����Ĳ������insert���������Զ������� 
Trie* createTrie(char* str){
	int len = strlen(str);
	Trie* root = new Trie();   //���ڵ�vֵ���ó�0�ɣ�Ӧ�ö�����ν 
	Trie* p = root;   //��Ҫ��root�ĸ���ȥ������root���ڷ��� 
	
	//���ǴӸ��ڵ㿪ʼ����ģ����ڵ㱾��û����ĸ���壩 
	for(int i = 0; i < len; ++i){   //����ÿ���ַ� ���ܹ�len�� 
		int childIndex = str[i] - 'a';   //����ĸת����26���Ƶ����֣���Ϊ���� 
		
		if(p->next[childIndex] == NULL){  //�����л�û�������ĸ 
			//���ӽڵ㽨��ʱ��ǰ׺���������ӽڵ㱾����ȫ��ͬ�ĵ���ֻ��һ�� 
			Trie* newChild = new Trie(); 
			p->next[childIndex] = newChild;
		}
		
		p = p->next[childIndex];    //ÿ����һ���ַ���Ҫ����һ�� 
	}
	
	p->isEndOfSomeStr = true;  //˵���Ӹ��ڵ㵽�ýڵ������Ϊһ���������ַ��� 
	
	return root;
}

//��Trie���ϲ����ַ���
bool find(Trie* root, char* str){
	int len = strlen(str);
	Trie* p = root;
	for(int i = 0; i < len; ++i){
		int childIndex = str[i] - 'a';
		p = p->next[childIndex];
		if(p == NULL)	return false;
	}
	return true;
}

int main(){
	char str[] = "wanglingxiao";
	Trie* root = createTrie(str);
	
	char tofind[5] = "wang";
	char tofind2[] = "wanglingxi";
	char tofind3[] = "wangxxxxx";
	char tofind4[] = "wanglingxiaowanglingxiao"; 
	cout << tofind << "�Ƿ������У�\t\t\t" << find(root, tofind) << endl;
	cout << tofind2 << "�Ƿ������У�\t\t\t"<< find(root, tofind2) << endl;
	cout << tofind3 << "�Ƿ������У�\t\t\t" << find(root, tofind3) << endl;
	cout << tofind4 << "�Ƿ������У�\t" << find(root, tofind4) << endl;
	return 0;	
}






















