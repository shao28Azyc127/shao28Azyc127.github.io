#include <bits/stdc++.h>
using namespace std;
bool flag=true;
int n,t=4,sum=0,ans;
short a[1000005]
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(flag){
	for(int i=1;i<=n;i++){
        if(t==4){
            t=1;
            a[i]=1;
       }
        if(a[i]==0) t++;
        sum++;
        if(i==n) ans=sum;
    }
    for(int i=0;i<n;i++){
		if(a[i]==0) break;
		if(i+1==n) flag=false;
    }
}
	cout<<sum<<" "<<ans;
    return 0;
}
