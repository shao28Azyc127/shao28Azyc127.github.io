#include<bits/stdc++.h>
using namespace std;

long long n,m,ans;
bool a[1000001000];

int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	while(1){
		++m;
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(a[i]==0){
				if(cnt%3==0){
					if(i==n){
						ans=m;
					}
					a[i]=1;
				}
				++cnt;
			}
		}
		if(cnt==0){
			break;
		}
	}
	cout<<m-1<<" "<<ans;
	
	
	return 0;
}
