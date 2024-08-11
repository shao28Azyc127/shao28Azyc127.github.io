#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+11;
long long a[7][1000];
long long n,m,f0=0,t[N];
long long g[7][1000],f[1000];
void f1(long long xb){
	long long i,j,h;
	for(h=1;h<=5;h++){
		for(i=1;i<=9;i++){
			g[h][++f0]=a[h][xb]+i;
			g[h][f0]%=10;
			for(j=1;j<=5;j++){
				if(j!=h){
					g[j][f0]=a[j][xb];
				}
			}
			
		}
	}
}
int main(){
	map<long long,long long> m0;
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	long long i,j,k,ans=0;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[1][i]>>a[2][i]>>a[3][i]>>a[4][i]>>a[5][i];
	}
	if(n==1){
		cout<<"81";
		return 0;
	}
	else{
		for(i=1;i<=n;i++){
			f1(i);
		}
		for(j=1;j<=f0;j++){
			long long a1,a2,a3,a4,a5;
			a1=g[1][j];
			a2=g[2][j];
			a3=g[3][j];
			a4=g[4][j];
			a5=g[5][j];
			long long u=10000*a1+1000*a2+100*a3+10*a4+a5;
			m0[u]++;
		}
		for(auto x:m0){
			if(x.second>=n){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
