#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,op,ads[100010],now,cnt,tmp;
struct node{
	char name[110];
	int fa,son[110],sz;
	int num,st,ed;
	bool lf;
};
char s[10],s2[110],s3[110];
node point[100010];
char in[10]="int",by[10]="by",sh[10]="short",lo[10]="long";
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&op);
		if(op==2){
			scanf("%s",s);
			scanf("%s",point[++cnt].name);
			if(s[0]=='b'){
				point[cnt].num=1;
				point[cnt].st=now;
				point[cnt].ed=now;
				ads[now]=cnt;
				now=now+1;
			}
			if(s[0]=='s'){
				point[cnt].num=2;
				point[cnt].st=(now%2==0?now:now+1);
				now=point[cnt].st;
				point[cnt].ed=now+1;
				now=now+2;
				for(int i=point[cnt].st;i<=point[cnt].ed;i++) ads[i]=cnt;
			}
			if(s[0]=='i'){
				point[cnt].num=4;
				point[cnt].st=(now%4==0?now:((now/4)+1)*4);
				now=point[cnt].st;
				point[cnt].ed=now+2;
				now=now+4;
				for(int i=point[cnt].st;i<=point[cnt].ed;i++) ads[i]=cnt;
			}
			if(s[0]=='l'){
				point[cnt].num=8;
				point[cnt].st=(now%8==0?now:((now/8)+1)*8);
				now=point[cnt].st;
				point[cnt].ed=now+7;
				now=now+8;
				for(int i=point[cnt].st;i<=point[cnt].ed;i++) ads[i]=cnt;
			}
			printf("%d %d\n",point[cnt].st,point[cnt].ed);
		}
		if(op==3){
			scanf("%s",s2);
			for(int i=1;i<=cnt;i++){
				int q=strlen(point[i].name),p=strlen(s2);
				if(q!=p) continue;
				bool flag=0;
				for(int j=0;j<q;j++) if(point[i].name[j]!=s2[j]) flag=1;
				if(!flag){
					printf("%d\n",point[i].st);
					break;
				}
			}
		}
		if(op==4){
			scanf("%d",&tmp);
			printf("%s",point[ads[tmp]].name);
		}
	}
	return 0;
}
