#include<iostream>
#include<cstring> 
#include<string>
using namespace std;

/*字典树（Trie树） 
典型应用是用于统计，排序和保存大量的字符串（但不仅限于字符串），
所以经常被搜索引擎系统用于文本词频统计。
它的优点是：利用字符串的公共前缀来节约存储空间，
最大限度地减少无谓的字符串比较，查询效率比哈希表高。 

注意：建立+查询在trie中是可以同时执行的，建立的过程也就可以成为查询的过程
例如：有n个单词，问其中是否存在某两个单词 ，满足其中一个是另一个的前缀
      就可以边建立边查询。 
*/



const int CHILD_NUM = 26;

struct Trie{
	//每层可有26个子结点（26个字母），若要表示大小写的单词，则CHILD_NUM应为52
	//本例仅支持26个小写字母 
	Trie* next[CHILD_NUM];    //用索引表示字母 
	bool isEndOfSomeStr;        //字符串结尾标记（并不一定是叶子结点） 
	//int v;  //v可以表示一个字典树到此有多少个相同前缀的单词，不过其含义可根据需要自由变化。
	Trie(){
		isEndOfSomeStr = false;
		for(int i = 0; i < CHILD_NUM; ++i){
			next[i] = NULL;
		}
	}
}; 


//输入字符串，生成字典树 
//其中包含了字典树的插入操作insert，不过可以独立出来 
Trie* createTrie(char* str){
	int len = strlen(str);
	Trie* root = new Trie();   //根节点v值设置成0吧，应该都无所谓 
	Trie* p = root;   //需要用root的副本去操作，root用于返回 
	
	//总是从根节点开始插入的（根节点本身没有字母含义） 
	for(int i = 0; i < len; ++i){   //插入每个字符 ，总共len个 
		int childIndex = str[i] - 'a';   //将字母转换成26进制的数字，作为索引 
		
		if(p->next[childIndex] == NULL){  //子树中还没有这个字母 
			//新子节点建立时，前缀（包括该子节点本身）完全相同的单词只有一个 
			Trie* newChild = new Trie(); 
			p->next[childIndex] = newChild;
		}
		
		p = p->next[childIndex];    //每插入一个字符就要深入一层 
	}
	
	p->isEndOfSomeStr = true;  //说明从根节点到该节点可以作为一个完整的字符串 
	
	return root;
}

//在Trie树上查找字符串
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
	cout << tofind << "是否在树中：\t\t\t" << find(root, tofind) << endl;
	cout << tofind2 << "是否在树中：\t\t\t"<< find(root, tofind2) << endl;
	cout << tofind3 << "是否在树中：\t\t\t" << find(root, tofind3) << endl;
	cout << tofind4 << "是否在树中：\t" << find(root, tofind4) << endl;
	return 0;	
}






















