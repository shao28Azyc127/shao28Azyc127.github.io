#include <bits/stdc++.h>
using namespace std;
long long n,d,v[111111],a[111111],sumv[111111],ans;
vector<long long> stop;
void f(long long l,long long r){
    //cout<<l<<" "<<r<<endl;
    if(l==r){
        return ;
    }
    long long mn=long long_MAX,mnp;
    for(long long i=l;i<r;i++){
        if(a[i]<mn){
            mn=a[i];
            mnp=i;
        }
    }

    if(mnp==l){
        long long dis=sumv[r]-sumv[l];
        if(dis%d==0){
            ans+=dis/d*a[l];
            //cout<<"fuel"<<dis/d<<"@"<<l<<endl;
        }
        else{
            ans+=(dis/d+1)*a[l];
            //cout<<"fuel"<<dis/d+1<<"@"<<l<<endl;
        }
        //cout<<"ans="<<ans<<endl;
        return ;
    }
    stop.push_back(mnp);
    f(l,mnp);
    f(mnp,r);
    return ;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(long long i=1;i<=n-1;i++){
        cin>>v[i];
        sumv[i+1]=sumv[i]+v[i];
    }
    sumv[1]=0;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    long long p=1;
    f(1,n);
    //for(long long i=0;i<stop.size();i++)cout<<stop[i]<<endl;
    cout<<ans;
    return 0;
}
