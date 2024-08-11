//O(sigma(dis[i])/d)+A+B, 80pts

#include<iostream>
using namespace std;

#define N 100005
#define int long long

int n,d,dis[N],a[N];

void solve1(){
    int minc=1, nd=0,nc=0;
    
    while(nd<dis[n]){
		for(int i=1;dis[i]<nd;i++){
            if(a[i]<a[minc]) minc=i;
        }
        nd+=d,nc+=a[minc];
    }
    cout<<nc;
}

void solve2(){
	int minc=1,nc=0;
    for(int i=1;i<=n-1;i++){
		if(a[i]<a[minc]) minc=i;
		nc+=(dis[i+1]-dis[i])/d*a[minc];
	}
	cout<<nc;
}

signed main(){
	
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    
    cin>>n>>d;
    for(int i=2,v;i<=n;i++) cin>>v,dis[i]=dis[i-1]+v;
    for(int i=1;i<=n;i++) cin>>a[i];
    
    int Min=0x3f3f3f3f;
    for(int i=1;i<=n-1;i++) Min=min(Min,a[i]);
    
    if(n<=1005) solve1();
    else if(Min==a[1]){
		int oil=(dis[n]%d==0)?(dis[n]/d):(dis[n]/d+1);
		cout<<oil*a[1];
	}
	else solve2();
	return 0;
}
