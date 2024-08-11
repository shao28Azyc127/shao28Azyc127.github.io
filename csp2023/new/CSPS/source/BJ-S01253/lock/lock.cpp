#include<bits/stdc++.h>
using namespace std;

struct qqq{
	int a[10];
	int num;
}p[10];

int n;
int b[10];
int cnt[100005];
int ans;

void check(){
	int s;
	for(int i=1;i<=5;++i){
		for(int j=0;j<=9;++j){
			++b[i];
			b[i]=(b[i]+10)%10;
			s=0;
			for(int k=1;k<=5;++k){
				s*=10;
				s+=b[k];
			}
			++cnt[s];
		}
	}
	for(int i=1;i<=4;++i){
		for(int j=0;j<=9;++j){
			++b[i];
			b[i]=(b[i]+10)%10;
			++b[i+1];
			b[i+1]=(b[i+1]+10)%10;
			s=0;
			for(int k=1;k<=5;++k){
				s*=10;
				s+=b[k];
			}
			++cnt[s];
		}
	}
	return;
}

int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		p[i].num=0;
		for(int j=1;j<=5;++j){
			scanf("%d",&p[i].a[j]);
			p[i].num*=10;
			p[i].num+=p[i].a[j];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=5;++j){
			b[j]=p[i].a[j];
		}
		check();
	}
	for(int i=1;i<=n;++i){
		cnt[p[i].num]=0;
	}
	for(int i=0;i<=99999;++i){
		if(cnt[i]==n){
			++ans;
		}
	}
	printf("%d",ans);
	return 0;
}
