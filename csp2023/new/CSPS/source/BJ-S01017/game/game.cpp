#include<bits/stdc++.h>
using namespace std;
string s;
int a[200004][26];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,i,j,k;
	scanf("%d",&n);
	cin>>s;
	for(i=0;i<n;++i){
		for(j=0;j<26;++j){
			a[i+1][j]=a[i][j];
			if((s[i]-'a')==j)
				a[i+1][j]++;
		}
	}
	long long ans=0;
	for(i=1;i<n;++i){
		for(j=i+1;j<=n;j+=2){
			int f=0;
			for(k=0;k<26;++k){
				if((a[j][k]-a[i-1][k])%2!=0){
					f=1;
					break;
				}
			}
			if(f==0){
				//cout<<i<<" "<<j<<endl;
				ans++;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
