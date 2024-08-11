#include<stdio.h>
int vis[100000],cnt[100001],a[5];
int get(){
	int k=0;
	for(int i=0;i<5;++i)k=k*10+a[i];
	return k;
}
void add(int&x,int y){x=10-x>y?x+y:y-(10-x);}
void dif(int&x,int y){x=x<y?10-(y-x):x-y;}
int main(){
	freopen("lock.in","r",stdin),freopen("lock.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		for(int i=0;i<5;++i)scanf("%d",a+i);
		vis[get()]=1;
		for(int k=1;k<10;++k)
			for(int i=0;i<5;++i){
				add(a[i],k),++cnt[get()];
				if(i>0)add(a[i-1],k),++cnt[get()],dif(a[i-1],k);
				dif(a[i],k);
			}
	}
	int res=0;
	for(int i=0;i<100000;++i)
		if(!vis[i]&&cnt[i]==n)
			++res;
	printf("%d",res);
	return 0;
}