#include<cstdio>


typedef long long LL;
//�����ݵĵݹ�ʵ�� 
LL binaryPow(LL a, LL b){
	if(b==0) return 1;         //***�ݹ�߽� 
	else if(b % 2 == 1){      //��bΪ���� 
		return a * binaryPow(a,b-1);
	}else{                    //��bΪż�� 
		LL mul = binaryPow(a,b/2);      //ֻдһ���ݹ���� 
		return mul * mul;    
		//ע�⣺��Ҫд��return binaryPow(a,b/2) * binaryPow(a,b/2)����ʱ��ջ
	}
}

int main(){
	LL result = binaryPow(10LL,10LL);
	printf("%ll
	d",result);     //***ע�ⳤ�������ʹ��%lld������ʹ��%d�������ģ��� 
	return 0;
}
