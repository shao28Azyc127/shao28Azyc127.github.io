#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    int v[100005],pr[100005];
    int us[100005];
    cin>>n>>d;
    int mn=1e9;
    for(int i=1;i<n;i++){
        cin>>v[i];
        v[i]+=v[i-1];
        us[i]=1e9;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>pr[i];
        mn=min(mn,pr[i]);
    }
    if(pr[1]==mn){
        cout<<v[n-1]/d*mn;
    }else{
        int l,mon;
        for(int i=1;i<n;i++){
            for(int j=i;j<=n;j++){
                mon=ceil((v[j]-v[i])/d);
                us[j]=min(us[j],us[i]+mon*pr[i]);
            }
        }
        cout<<us[n];
    }

    return 0;
}
