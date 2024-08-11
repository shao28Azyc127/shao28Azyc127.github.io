#include<bits/stdc++.h>
using namespace std;
int anxt[10000005],n,ans2,cnt;
bool a[10000005];
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++){
		anxt[i]=i+1;
		a[i]=1;
	}
	for(int i=1;;i++){
		for(int j=1;j<=n;j++){
			if((j-1)%3==0){
				anxt[cnt]=anxt[cnt+1];
				a[cnt]=0;
				if(j==n) ans2=j;
			}
			cnt=anxt[cnt+1];
		}
		bool f=0;
		for(int j=1;j<=n;j++){
			if(a[j]==1){
				f=1;
				break;
			}
		}
		if(f==0){
			cout<<i<<' '<<ans2;
			return 0;
		}
	}
	return 0;
}
