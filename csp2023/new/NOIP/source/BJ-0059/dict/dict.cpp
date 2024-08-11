/*
突然发现明治巧克力的英文是 meiji，用中文读出来就是没急，所以 cxy 你先别急（错乱
发现 yth、wqy、ysz 和 xjs 都和我同考场，可爱
NOIp2023 RP++
解压密码是错的，难绷
考场键盘近乎于不能用，受不了一点
这几天情绪有点失控，希望考完了能好点吧
她说我还有一辈子，不可能一辈子都不释怀对吧（笑
她说要我好好地活下去，那即便是为了她，也不能继续想着自杀了对吧（笑

现在是 2023.11.18 08:14，愿接下来的一切顺利。
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