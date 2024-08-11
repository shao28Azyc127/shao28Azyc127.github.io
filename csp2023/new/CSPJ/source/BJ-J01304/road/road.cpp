#include<bits/stdc++.h>
using namespace std;
int s[100005];
int n,d,km=0;;
int a[100005];
int v[100005];
long long ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
        if(i==1) s[i]=0;
        else s[i]=s[i-1]+v[i-1];
    }
    s[n]=s[n-1]+v[n-1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;){
        int t=i;
        for(int k=i+1;k<n;k++){
            if(a[k]<a[i]){
                i=k;
                break;
            }
        }
        if(t==i){
            int you=(s[n]-s[i]-km)/d;
            //cout<<km<<' ';
            if((s[n]-s[i]-km)%d!=0) ++you;
            //int kile=you*d;
            //cout<<you<<' ';
            ans+=you*a[i];
            //km=kile-(s[n]-s[i]-km);
            break;
        }else{
            int you=(s[i]-s[t]-km)/d;
            if((s[i]-s[t]-km)%d!=0) ++you;
            int kile=you*d;
            ans+=you*a[t];
            //cout<<ans<<' ';
            km=kile-(s[i]-s[t]-km);
        }
    }
    cout<<ans;
    return 0;
}