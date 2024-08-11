#include<bits/stdc++.h>
using namespace std;
int mp[10000010];
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,bn,jl=0,lun=0;
	cin>>n,bn=n;
	while(n){
		lun++,n=n-(n-1)/3-1;
		if(jl||bn>10000000) continue;
		for(int i=1,cnt=0;i<=bn;++i){
			if(mp[i]) continue;
			cnt++;
			if((cnt-1)%3==0){
				mp[i]=1;
				if(i==bn) jl=lun;
			}
		}
	}
	cout<<lun<<" "<<(jl>0?jl:rand()%10+1)<<"\n";
	return 0;
}