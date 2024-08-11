#include <bits/stdc++.h>

using namespace std;

long long v[10005],a[10005];

long long d;

long long quzheng(long long x){
    if(x%d==0)return x/d;
    return x/d+1;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n;
	cin>>n>>d;
	v[1]=0;
	for(int i=2;i<=n;i++){
        cin>>v[i];
        v[i]=v[i-1]+v[i];
	}
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	long long frnt=1,i;
    long long nv=a[1];
	long long ans=0;
	long long lft=0;
	for(int i=2;i<n;i++){
        if(a[i]<nv){
            ans+=(quzheng(v[i]-v[frnt]-lft))*nv;
            nv=a[i];
            lft=quzheng(v[i]-v[frnt]-lft)*d-(v[i]-v[frnt]-lft);
            frnt=i;
        }
	}
	ans+=(quzheng(v[n]-v[frnt]-lft))*nv;
	cout<<ans<<endl;
	return 0;
}
