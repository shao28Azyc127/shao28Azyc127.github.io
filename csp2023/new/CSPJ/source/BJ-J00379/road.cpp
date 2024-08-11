#include<bits/stdc++.h>
using namespace std;

const int maxn=100005;
int n,d,v[maxn],a[maxn],sta,pri,ans;

int dis(int a,int b){
	int x=0;
	for(int i=a+1;i<=b;i++){
		x+=v[i];
	}
	return x;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++)cin>>v[i];
	for(int i=0;i<n;i++)cin>>a[i];
	pri=a[0];
	for(int i=0;i<n;i++){
		if(a[i]<pri){
			if(dis(sta,i)%d==0){
				ans+=dis(sta,i)/d*pri;
			}
			else{
				ans+=(dis(sta,i)/d+1)*pri;
			}
			sta=i;
			pri=a[i];
		}
	}
	cout<<ans;
	//cout<<dis(0,n-1);
	
}
