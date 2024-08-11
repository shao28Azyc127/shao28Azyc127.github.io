#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,ans,t,u=1;
struct dit{
	int x;
	int f;
};
dit e[1000010];
dit a[1000010];
int r[1000010];
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		a[i].x=i;
	}
	for(int i=1;i<=n;i++){
		if(!r[i]){
			t++;
			for(int j=1;j<=n;j++){
				e[j]=a[j];
			}
			for(int j=1;j<=n;j+=3){
				e[j].f=1;
				r[e[j].x]=1;
				if(e[j].x==n&&ans==0)ans=t;
			}
			int u=1;
			for(int j=1;j<=n;j++){
				if(!e[j].f){
					a[u]=e[j];
					u++;
				}
			}
			for(int j=1;j<=n;j++){
				e[j].f=0;
				e[j].x=0;
			}
		}
	}
    cout<<t<<" "<<ans<<"\n";
    return 0;
}
