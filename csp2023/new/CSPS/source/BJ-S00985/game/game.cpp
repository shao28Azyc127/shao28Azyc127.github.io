#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(int i=1;i<=n;i++)
#define rep0(i,n) for(int i=0;i<n;i++)

const int N = 2e6+5;

int n;
string a;
struct joint{
	int center;
	int radius;
	int junk;
	//st=c-r+1
	//end=c+r
}p[N];
int cnt=0;
ll ans=0;

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);

	cin>>n;
	cin>>a;
	rep0(i,n){
		if(a[i]==a[i+1]){
			p[++cnt].center = i;
			p[cnt].junk = 1;
			int r = 1;
			r++;
			while(true){
				if(a[i-r+1] == a[i-r+2] && a[i-r+1] == a[i+r]) p[cnt].junk++;
				if(a[i-r+1] != a[i+r] || !(i-r+1>=0 && i+r<n)){
					break;
				}
				r++;
			}
			p[cnt].radius = r-1;
			i = i+r;
		}
	}
	int tmp=1;
	rep(i, cnt){
		ans+=p[i].radius;
		if(p[i].junk>1) ans+=(((p[i].junk+1)*p[i].junk)/2-1);
		if(p[i].center+p[i].radius == p[i+1].center-p[i+1].radius){
			ans+=tmp;
			tmp++;
		}
		else tmp=1;
	}
	cout<<ans<<endl;
    return 0;
}
