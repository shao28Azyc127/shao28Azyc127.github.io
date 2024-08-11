#include<bits/stdc++.h>
using namespace std;
const int N=8e3+10;
long long n,f[N][N];
char s[N];
long long ans;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=2;i<=n;i++){
        f[i][i-1]=1;
	}
	for(int j=1;j<=n;j+=2){
		for(int i=1;i<=n-j;i++){
			if((s[i]==s[i+j])&&f[i+1][i+j-1]){
				f[i][i+j]=1;
			}
			for(int k=i;k<=i+j;k++){
				if(f[i][k]&&f[k+1][i+j])f[i][i+j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
            //cout<<f[i][j]<<' ';
			ans+=f[i][j];
		}
		//cout<<endl;
	}
	cout<<ans-n+1<<endl;
	return 0;
}
