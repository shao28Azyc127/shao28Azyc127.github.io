#include<bits/stdc++.h>
using namespace std;

long long n,a[1000005];
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	scanf("%lld",&n);
		bool flag=1;long long ans=-1,k;
	for(k=1;flag;k++){
			flag=0;
			long long cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i])continue;
				cnt++;
				if(cnt%3==1){
					if(i==n)ans=k;
					a[i]=1;
				}
			}
			for(long long i=1;i<=n;i++)if(!a[i])flag=1;
		}
		cout<<--k<<' '<<ans<<endl;
	return 0;
}
