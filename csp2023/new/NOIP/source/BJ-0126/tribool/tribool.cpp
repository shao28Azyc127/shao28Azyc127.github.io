#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long LL;
int n,m,ans,cnt;
int a[100010][2];
int c[100010];
int t[100010];
int q[100010][3];
bool check(){
	for(int i=1;i<=n;i++) t[i]=c[i];
	for(int i=1;i<=m;i++){
		if(q[i][0]<3) t[q[i][1]]=q[i][0];
		if(q[i][0]==3) t[q[i][1]]=t[q[i][2]];
		if(q[i][0]==4){
			if(t[q[i][2]]==0) t[q[i][1]]=1;
			else if(t[q[i][2]]==1) t[q[i][1]]=0;
			else if(t[q[i][2]]==2) t[q[i][1]]=2;
		}
	}
	for(int i=1;i<=n;i++)
		if(c[i]!=t[i]) return 0;
	return 1;
}
void dfs(int x){
	if(x==n+1){
		if(check())	ans=min(ans,cnt);
		return;
	}
	c[x]=0;dfs(x+1);
	c[x]=1;dfs(x+1);
	c[x]=2;cnt++;
	dfs(x+1);cnt--;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int T1,T2;cin>>T1>>T2;
	while(T2--){
		cin>>n>>m;
		if(T1==1||T1==2){
			for(int i=1;i<=m;i++){
				char cc;int x,y;cin>>cc>>x;
				if(cc=='T') q[i][0]=1,q[i][1]=x;
				if(cc=='F') q[i][0]=0,q[i][1]=x;
				if(cc=='U') q[i][0]=2,q[i][1]=x;
				if(cc=='+') cin>>y,q[i][0]=3,q[i][1]=x,q[i][2]=y;
				if(cc=='-') cin>>y,q[i][0]=4,q[i][1]=x,q[i][2]=y;
			}
			ans=n;cnt=0;dfs(1);
		}
		if(T1==3||T1==4){
			for(int i=1;i<=n;i++) c[i]=0;
			for(int i=1;i<=m;i++){
				char cc;int x;cin>>cc>>x;
				if(cc=='T') c[x]=1;
				if(cc=='F') c[x]=0;
				if(cc=='U') c[x]=2;
			}
			for(int i=1;i<=n;i++)
				if(c[i]==2) ans++;
		}
		if(T1==7||T1==8){
			for(int i=1;i<=n;i++) a[i][0]=1,a[i][1]=i;
			for(int i=1;i<=m;i++){
				char cc;int x,y;cin>>cc>>x;
				if(cc=='+') cin>>y,a[x][0]=1,a[x][1]=y;
				if(cc=='-') cin>>y,a[x][0]=0,a[x][1]=y;
			}
			ans=0;
			for(int i=1;i<=n;i++) t[i]=0;
			for(int i=1;i<=n;i++){
				int j=a[i][1];a[i][1]=a[j][1];
				if(a[i][0]==0&&a[j][0]==0&&i!=j) a[i][0]=1;
				else if(a[i][0]==1&&a[j][0]==0) a[i][0]=0;
				t[a[i][1]]++;
			}
			for(int i=1;i<=n;i++)
				if(a[i][0]==0&&a[i][1]==i) ans+=t[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}