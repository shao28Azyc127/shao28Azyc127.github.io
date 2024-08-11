#include <bits/stdc++.h>
#define ll long long
using namespace std;

char c[2000005];
ll n,ans;
int y[2000005],s[2000005],d[2000005],x[2000005];

int main(){
	ios::sync_with_stdio(false);
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	cin>>c;
	for(ll i=1;i<n;i++){
		d[i]=0;
		if(c[i]==c[i-1]){
			ans++;
			s[i]=s[i-1]=1;
			y[i]=i-1;
			x[i]=y[i];
			d[i]=d[y[i]-1]+1;
			if(s[y[i]-1]==1){
				ans+=d[i]-1;
				x[i]=x[y[i]-1];
			}
		}else if(s[i-1]==1){
			if(c[y[i-1]-1]==c[i]){
				ans++;
				s[i]=s[y[i-1]-1]=1;
				y[i]=y[i-1]-1;
				x[i]=y[i];
				d[i]=d[y[i]-1]+1;
				if(s[y[i]-1]==1){
					ans+=d[i]-1;
					x[i]=x[y[i]-1];
				}
			}else if(c[x[i-1]-1]==c[i]){
				ans++;
				s[i]=s[x[i-1]-1]=1;
				y[i]=y[x[i-1]-1]-1;
				x[i]=y[i];
				d[i]=d[y[i]-1]+1;
				if(s[y[i]-1]==1){
					ans+=d[i]-1;
					x[i]=x[y[i]-1];
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
