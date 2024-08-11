#include<bits/stdc++.h>
using namespace std;
int n,day,temp,ans,f,t;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    long long a[n+3];
    memset(a,0,sizeof(a));
    while(t<n){
        day++;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                f=i;
                break;
            }
        }
        int tot=0;
        a[f]=1;
        t++;
        temp=f;
        if(temp==n)ans=day;
        for(int i=f;i<=n;i++){
            if(a[i]==0)tot++;
            if(tot==3){
                tot=0;
                t++;
                a[i]=1;
                temp=i;
                if(temp==n)ans=day;
            }
        }
    }
    cout<<day<<" "<<ans;
    return 0;
}