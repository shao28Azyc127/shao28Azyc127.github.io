#include<iostream>
#include<cstdio>
using namespace std;
int v[100005],a[100005];
long long sum[100005];
long long df(long long x,long long y){
    if(x%y==0) return x/y;
    else return x/y+1;
}
int main(){
    freopen("road.in","r",stdin);//---------------------------------------
    freopen("road.out","w",stdout);
    long long n,w,d,ans=0,x=0,cnt=0;
    long long s=0;
    bool ed=0;
    cin>>n>>d;
    w=d,v[1]=0;
    for(int i=2; i<=n; i++){
        cin>>v[i];
        s+=v[i];
        sum[i]=sum[i-1]+v[i];
    }
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    w=d;
    for(int i=1; i<=n; ){
        for(int j=i+1; j!=i; j++){
            if(a[j]<a[i]){
                    if(j>=n){
                        ans+=df(sum[n]-sum[i]-x,d)*a[i];
                        //cout<<"\n"<<a[i]<<'*'<<sum[n]<<'-'<<sum[i]<<' '<<x<<"\n";
                        ed=1;
                        break;
                    }
                    //cout<<"\n"<<i<<' '<<j<<' '<<df(sum[j]-sum[i]-x,d)*a[i];//-----------------------------------------------------------------------
                    ans+=df(sum[j]-sum[i]-x,d)*a[i];
                    x=(sum[j]-sum[i]-x)%d;
                    i=j;
                    //cout<<"\n"<<ans<<"\n";//--------------------------------------------------------------------------------------------------
                    break;
            }
            else continue;
            if(j>=n){
                ans+=df(sum[n]-sum[i]-x,d)*a[i];
                ed=1;
                break;
            }
        }
        if(ed) break;
        if(i>=n) break;
    }
    cout<<ans;
    return 0;
}

