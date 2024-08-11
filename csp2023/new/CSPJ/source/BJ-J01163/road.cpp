#include<bits/stdc++.h>
using namespace std;
int n,d,tmp=1,a[100010],pr[100010],s[100010],ans=0,oil;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){cin>>a[i];s[i]=s[i-1]+a[i];}
    for(int i=1;i<=n;i++) cin>>pr[i];
    for(int i=2;i<=n;i++){
        if(pr[i]<=pr[tmp]){
            int x=s[i-1]-s[tmp-1]-oil;
            if(x%d==0){ans+=(x/d)*pr[tmp];oil=0;}
            else{
                ans+=(x/d+1)*pr[tmp];
                oil=(x/d+1)*d-x;
            }
            tmp=i;
        }
    }
    cout<<ans<<'\n';
    return 0;
}