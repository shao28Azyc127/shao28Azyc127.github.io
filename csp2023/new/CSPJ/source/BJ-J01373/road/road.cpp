#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,x,ans=0,minthan,c,mintag,sum=0,i=0;
    double needplus,ful=0;
    bool f;
    cin>>n>>x;
    int v[n]={},price[n+1]={},d[n+1]={};
    for(i=1;i<n;i++){
        cin>>v[i];
        d[i+1]=d[i]+v[i];
    }
    for(i=1;i<=n;i++) cin>>price[i];
    i=1;
    while(i<n){
        minthan=price[i],c=i,mintag=i,f=1;
        while(f){
            if(price[c]<minthan) mintag=c,minthan=price[c],f=0;
            c++;
        }
        sum=(d[mintag]-d[i]-ful)/x;
        needplus=double((d[mintag]-d[i])*1.0/(x*1.0))-ful;
        if(sum!=needplus){
            sum++;
        }
        ans+=sum*price[i],ful+=sum-(d[mintag]-d[i])*1.0/x;
        i=mintag;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}