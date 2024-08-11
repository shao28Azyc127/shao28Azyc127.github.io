#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll mod=0;
int n;
int a[15][7];
int b[7];
int tmp[7];
int ans=0;
bool ok(){
	for(int i=1;i<=n;i++){
		int cnt=(a[i][1]!=b[1])+
				(a[i][2]!=b[2])+
				(a[i][3]!=b[3])+
				(a[i][4]!=b[4])+
				(a[i][5]!=b[5]);
		if(cnt==0||cnt>2)return 0;
		if(cnt==2){
			for(int j=1;j<=5;j++)tmp[j]=(a[i][j]-b[j]+10)%10;
			if(tmp[1]&&tmp[2]&&tmp[1]==tmp[2])continue;
			if(tmp[2]&&tmp[3]&&tmp[2]==tmp[3])continue;
			if(tmp[3]&&tmp[4]&&tmp[3]==tmp[4])continue;
			if(tmp[4]&&tmp[5]&&tmp[4]==tmp[5])continue;
			return 0;
		}
	}
	return 1;
}
void dfs(int now){
	if(now>5){
		ans+=ok();
		return;
	}
	for(int i=0;i<=9;i++){
		b[now]=i;
		dfs(now+1);
	}
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5];
	dfs(1);
	cout<<ans<<endl;
	return 0;
}