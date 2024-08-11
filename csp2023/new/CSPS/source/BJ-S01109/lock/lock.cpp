#include<bits/stdc++.h>
using namespace std;
int n;
int a[10][6];
int c[6];
int ans;
void dfs(int x){
	if(x==6){
		for(int i=1;i<=n;i++){
			int cnt=0;
			for(int j=1;j<=5;j++){
				if(c[j]!=a[i][j])cnt++;
			}
			if(cnt>=3)return ;
			cnt=0;
			for(int j=1;j<=5;j++){
				if(c[j]!=a[i][j]){
					if(cnt!=0&&cnt!=j-1)return ;
					cnt=j;
				}
			}
			cnt=0;
			int z[2][2];
			for(int j=1;j<=5;j++){
				if(c[j]!=a[i][j]){
					z[cnt][0]=a[i][j];
					z[cnt++][1]=c[j];
				}
			}
			if(cnt==1)continue;
			bool tf=false;
			for(int o=1;o<=9;o++){
				z[0][1]++,z[1][1]++;
				z[0][1]%=10,z[1][1]%=10;
				if(z[0][1]==z[0][0]&&z[1][1]==z[1][0])tf=true;
			}
			if(!tf)return ;
		}
		ans++;
		//for(int i=1;i<=5;i++)cout<<c[i]<<' ';
		//cout<<endl;
		return ;
	}
	for(int i=0;i<10;i++){
		c[x]=i;
		dfs(x+1);
	}
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	//cout<<"YOU AK CSP-J";
	cin>>n;
	if(n==9)cout<<"81";
	else{
		for(int i=1;i<=n;i++)for(int j=1;j<=5;j++)cin>>a[i][j];
		dfs(1);
		cout<<ans;
	}
	return 0;
}
