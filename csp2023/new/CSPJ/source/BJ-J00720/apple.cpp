#include<bits/stdc++.h>
using namespace std;
long long a[100000005];
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	long long n,cnt=0;
	int ans,ansn,f;
	cin>>n;
	ans=0;
	ansn=0;
	for(long long i=1;i<=n;i++){
		f=2;
		for(long long j=i;j<=n;j++){
			if(a[j]==0 && f==2){
				a[j]=1;
				if(j==n)
					ansn=ans+1;;
				f=0;
				cnt++;
			}
			else if(a[j]==0)
				f++;
		}
		ans++;
		if(cnt==n)
			break;		
		}
	cout<<ans<<" "<<ansn;
	return 0;
}
