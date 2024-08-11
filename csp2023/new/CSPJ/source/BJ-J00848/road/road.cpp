#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n,d;
int v[100010];
int a[100010];
int maxyou[100010];
int qjh[100010];
int ans=2000000000;
int mina=2000000000;
int minai;
int vsum=0;

void dfs(int x,int you,int cost){
//	cout<<cost<<' '<<x<<endl;
    if(x==n){
//		cout<<cost<<endl;
		if(cost<ans){
			ans=cost;
		}
        return;
    }
    int needyou=v[x];
    if(needyou<0) needyou=0;
//   	cout<<needyou<<' '<<you<<endl;
	int nowneedyou=needyou-you;
	if(nowneedyou<0) nowneedyou=0;
	int needyou2=(nowneedyou-1)/d+1;
	if(nowneedyou==0) needyou2=0;
//	cout<<needyou2<<' '<<you<<' '<<needyou<<' '<<nowneedyou<<endl;
    for(int i=needyou2;i<=maxyou[x]/d+1;i++){
//		cout<<cost+a[i]*i<<' '<<a[x]<<' '<<i<<endl;
        dfs(x+1,i*d-needyou+you,cost+a[x]*i);
    }
}

int main(){

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
        vsum+=v[i];
        qjh[i]=qjh[i-1]+v[i];
    }
    for(int i=1;i<n;i++){
        maxyou[i]=qjh[n-1]-qjh[i-1];
    }
   
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<mina){
			mina=a[i];
			minai=i;
		}
    }
    if(minai==1){
		cout<<((vsum-1)/d+1)*a[1]<<endl;
		return 0;
	}
		
    dfs(1,0,0);
    cout<<ans<<endl;
   	for(int i=1;i<=10;i++){
//		cout<<minjl[i]<<endl;
	}

    return 0;
}
