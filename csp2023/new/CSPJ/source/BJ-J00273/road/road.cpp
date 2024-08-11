#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m,ans,all;
int a[100010];
int u[100010];
int main(){
	freopen("road.in","r",srdin);
	freopen("road.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n-1;i++){cin>>u[i],all+=u[i];}
	for(int i=1;i<=n;i++)cin>>a[i];
	int l=1;
	while(1){
		if(l*m>=all){
			ans=l*a[1];
                     break;
		}
	}
	cout<<ans;
    return 0;
}