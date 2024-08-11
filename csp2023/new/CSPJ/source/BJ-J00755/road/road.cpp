#include<bits/stdc++.h>
using namespace std;
int n,d;
long long ans=0,cur=1,oil=0,key;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d",&n,&d);
	vector<long long> pri(n+2,0),dis(n+2,0);
	for(int i=1;i<n;i++) cin>>dis[i];
	for(int i=1;i<=n;i++) cin>>pri[i];
	while(cur<n) {
		long long minp,tar=0;
		bool flag=0;
		for(int i=cur+1;i<n;i++) {
			tar+=dis[i-1];
			if(pri[i]<pri[cur]) {
				flag=1;
				minp=i;
				break;
		}	}
		tar-=oil;
		if(!flag) {
			tar+=dis[n-1];
			key=tar/d;
			if(key*d<tar) key++;
			if(key<0) key=0;
			ans+=pri[cur]*key;
			cur=n;
			oil=key*d-tar;
		}
		else {
			key=tar/d;
			if(key*d<tar) key++;
			if(key<0) key=0;
			ans+=pri[cur]*key;
			cur=minp;
			oil=key*d-tar;
	}	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}