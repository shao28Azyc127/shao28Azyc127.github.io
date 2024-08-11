#include<bits/stdc++.h>
using namespace std;
int vis[1000000]={0};
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int cnt,n1=n,j=0;
    while(n1){
		j++;int i;
	    for(i=1;i<=n;i++)if(!vis[i]){
			vis[i]=j;cnt=0;n1--;break;
		}
		for(i=i;i<=n;i++){
			if(!vis[i])cnt++;
		    if(cnt==3){
				vis[i]=j;cnt=0;n1--;
			}
	    }
	}
	cout<<j<<' '<<vis[n];
    return 0;
}
