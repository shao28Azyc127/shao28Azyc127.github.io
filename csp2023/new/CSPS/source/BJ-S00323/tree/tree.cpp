#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=2e6+10;

int n,a[N],b[N],c[N],t[N],u,v,ans;

int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<n;i++){
        cin>>u>>v;
    }
    for(int i=1;i<=n;i++){
            cout<<ans<<"\n";
        if(c[i]==0){
            int k;
            if(a[i]%b[i]==0) k=a[i]/b[i];
            else
                k=a[i]/b[i]+1;
                ans=max(ans,i+a[i]/b[i]-1);
            continue;
        }
        int day=0,k=b[i];
        while(a[i]>0){
                if(k==1){
                    day+=a[i];
                    break;
                }
            day++;
            k+=c[i];
            k=max(k,1);
            a[i]-=k;
        }
        ans=max(ans,i-1+day);
    }
    cout<<ans;
    return 0;
}
/*
4
15 2 3
10 2 0
14 1 1
15 10 -9
*/
