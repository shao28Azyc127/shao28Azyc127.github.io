#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,v[10002],a[10002],mi,m,ans=0,flag,sg=0,l,last,ll=0,ll2=0,ll3;
    cin>>n>>d;
    n--;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    last=v[n];
    for(int i=1;i<=n+1;i++){
        cin>>a[i];
    }
    a[n+1]=0;
    v[0]=0;
    for(int i=1;i<=n;i++){
        v[i]+=v[i-1];
    }
    for(int i=1;i<=n;i++){
        mi=a[i];
        m=i;
        flag=0;
        for(int j=i+1;j<=n;j++){
            if(mi>a[j]&&flag==0){
                mi=a[j];
                m=j;
                flag=1;
            }
        }
        l=(v[m]-v[i]+d-1-sg)/d;
        ans+=l*a[i];
        sg=sg+(l*d)-(v[m]-v[i]);
        //ll2=ll;
        //ll=i;
        //cout<<ll<<" ";
        //cout<<i<<" "<<ans<<endl;
        if(flag==1){
            ll3=ll2;
            ll2=ll;
            ll=m;
            i=m-1;
        }
    }
    int ans2=(last-sg+d-1)/d;
    ans2*=a[m];
    cout<<ans+ans2;
    return 0;
}
