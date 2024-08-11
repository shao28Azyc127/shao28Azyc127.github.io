#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
const int N=1000010,M=3000010;
int n;
int real[N],op[N],cnt;
int to[M],ne[M],h[N],idx;
int co[N];
bool st[N];
inline void add(int a,int b){
	to[++idx]=b,ne[idx]=h[a],h[a]=idx;
	to[++idx]=a,ne[idx]=h[b],h[b]=idx;
}
bool getc(int x){
	for(int i=h[x];i;i=ne[i]){
		int j=to[i];
		if(!~co[j]){
			co[j]=!co[x];
			if(!getc(j))
				return 0;
		}
		else if(co[j]==co[x])
			return 0;
	}
	return 1;
}
void fill(int x){
	st[x]=1;
	for(int i=h[x];i;i=ne[i])
		if(!st[to[i]])
			fill(to[i]);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		int m;
		scanf("%d%d",&n,&m);
		cnt=n*2+3,idx=0;
		memset(h,0,sizeof h);
		for(int i=1;i<=n;i++)
			op[i]=i+n,op[i+n]=i,add(i,i+n);
		for(int i=1;i<=n*2+3;i++)
			real[i]=i;
		while(m--){
			char type[2];
			int x,y;
			scanf("%s%d",type,&x);
			real[x]=++cnt;
			real[x+n]=++cnt;
			add(real[x],real[x+n]);
			op[real[x]]=real[x+n];
			op[real[x+n]]=real[x];
			if(type[0]=='T'){
				add(real[x],n*2+2);
				add(real[x+n],n*2+1);
			}
			else if(type[0]=='F'){
				add(real[x],n*2+1);
				add(real[x+n],n*2+2);
			}
			else if(type[0]=='U'){
				add(real[x],n*2+3);
				add(real[x+n],n*2+3);
			}
			else if(type[0]=='+'){
				scanf("%d",&y);
				add(real[x],real[y+n]);
				add(real[x+n],real[y]);
			}
			else{
				scanf("%d",&y);
				add(real[x],real[y]);
				add(real[x+n],real[y+n]);
			}
		}
		for(int i=1;i<=n*2;i++){
			add(real[i],++cnt);
			add(cnt,i);
		}
		int ans=0;
		memset(co,-1,sizeof co);
		memset(st,0,sizeof st);
		//for(int i=1;i<=n*2;i++)
		//	printf("%d ",fa[i]);
		//puts("");
		for(int i=1;i<=cnt;i++)
			if(!~co[i]){
				co[i]=0;
				if(!getc(i)){
					fill(i);
					//printf("%d*\n",i);
				}
			}
		for(int i=1;i<=n;i++)
			if(st[real[i]])
				ans++;
		printf("%d\n",ans);
		//for(int i=1;i<=cnt;i++)
		//	for(int j=h[i];j;j=ne[j])
		//		printf("%d %d\n",i,to[j]);
	}
	return 0;
}