/*
ͻȻ���������ɿ�����Ӣ���� meiji�������Ķ���������û�������� cxy ���ȱ𼱣�����
���� yth��wqy��ysz �� xjs ������ͬ�������ɰ�
NOIp2023 RP++
��ѹ�����Ǵ�ģ��ѱ�
�������̽����ڲ����ã��ܲ���һ��
�⼸�������е�ʧ�أ�ϣ���������ܺõ��
��˵�һ���һ���ӣ�������һ���Ӷ����ͻ��԰ɣ�Ц
��˵Ҫ�Һúõػ���ȥ���Ǽ�����Ϊ������Ҳ���ܼ���������ɱ�˶԰ɣ�Ц

������ 2023.11.18 08:14��Ը��������һ��˳����
*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
char s[3000][3001],mn[3001],sm[3001];
int main(){
	freopen("dict.in","r",stdin),freopen("dict.out","w",stdout);
	int n,m,p;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i)mn[i]=sm[i]=127;
	mn[m]=sm[m]='\0';
	for(int i=0;i<n;++i){
		scanf(" %s",s[i]);
		std::sort(s[i],s[i]+m,[](const char&a,const char&b){return a>b;});
		if(strcmp(s[i],mn)<0){
			p=i;
			for(int j=0;j<m;++j)mn[j]=s[i][j];
		}else if(strcmp(s[i],sm)<0){
			for(int j=0;j<m;++j)sm[j]=s[i][j];
		}
		for(int j=0;j<m-1-j;++j){
			char t=s[i][j];
			s[i][j]=s[i][m-1-j];
			s[i][m-1-j]=t;
		}
	}
	for(int i=0;i<n;++i){
		if(i!=p){
			putchar(strcmp(s[i],mn)<0?'1':'0');
		}
		else putchar(strcmp(s[i],sm)<0?'1':'0');
	}
	return 0;
}