#include<bits/stdc++.h>
using namespace std;
long long n,d,ans,jl=1,cnt,lc,pd=0;
long long v[100005];
long long a[100005];
long long w[100005];
long long cz(long long zd){
    long long minn1=1e7,minn2=0;
    if(zd==1) return 0;
    for(int i=1;i<zd;i++){
        if(a[i]<minn1){
            minn1=a[i];
            minn2=i;
        }
    }
    w[minn2]=a[minn2];
    cz(minn2);
    return 0;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cz(n);
    w[n]=1;
    for(int i=1;i<=n;i++){
        if(w[i]!=0){
            jl=0;
            pd=0;
            for(int j=i+1;j<=n;j++){
                if(w[j]!=0&&pd!=1){
                    jl=j;
                    pd=1;
                }
            }
            for(int j=i;j<jl;j++){
                cnt+=v[i];
            }
            if(cnt%d==0){
                ans+=cnt/d*w[i];
            }else{
                lc+=cnt%d;
                if(lc>=d){
                    ans+=cnt/d*w[i];
                    lc-=d;
                }else{
                    ans+=cnt/d*w[i]+w[i];
                }
            }
            cnt=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}
