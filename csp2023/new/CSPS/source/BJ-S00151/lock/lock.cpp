#include <iostream>
#include <stdio.h>
using std::cin;
using std::cout;
using std::endl;
#define MAXN 100003
int in[10],n,ans=0;
bool a[MAXN];
void dfs(int x,int step){
	if(step==5){
		int flags=0;
		for(int i=1;i<=n;i++){
			int cnt[6]={0,0,0,0,0,0},cntc=0;
			for(int j=1;j<=10000;j*=10)if(x/j%10!=in[i]/j%10){cnt[++cntc]=j;}
			if(cntc==1){flags++;continue;}
			if(cntc>2)break;
			if(cnt[1]*1.0/cnt[2]!=10&&cnt[1]*1.0/cnt[2]!=0.1)break;
			int t1=x/cnt[1]%10,t2=in[i]/cnt[1]%10,t3=x/cnt[2]%10,t4=in[i]/cnt[2]%10;
			if(t1-t2==t3-t4)	flags++;
			else if(10-t2+t1==t3-t4||10-t4+t3==t1-t2)	flags++;
			else if(t2+10-t1==t4-t3||t4+10-t3==t2-t1)	flags++;
		}
		if(flags==n)	ans++;
		return ;
	}
	for(int i=0;i<10;i++)	dfs(x*10+i,step+1);
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x=0;
		for(int i=1;i<=5;i++){int y;cin>>y;x=x*10+y;}
		in[i]=x;
	}
	dfs(0,0);
	cout<<ans<<endl;
	return 0;
}
