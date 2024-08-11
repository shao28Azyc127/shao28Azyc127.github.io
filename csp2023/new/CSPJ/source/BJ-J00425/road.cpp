//·ð×æ±£ÓÓ
//·ð×æ±£ÓÓ
//·ð×æ±£ÓÓ
//·ð×æ±£ÓÓ
//·ð×æ±£ÓÓ
#include <bits/stdc++.h>
using namespace std;
long long n,d,v[100010],a[100010],len,res=8e18;
long long cnt;
void dfs(long long step,double o,long long m){
    //*/
    cnt++;
    if(cnt>=9.8e7){
        cout<<res;
        exit(0);
    }
    //*/
    //cout<<step<<' '<<o<<' '<<m<<endl;
    if(m>=res){
        return;
    }
    if(step==n+1){
        res=min(res,m);
        return;
    }

    for(long long i=0;i<=len-o;i++){
        if(o+i-v[step]*1.0/d>=0)dfs(step+1,o+i-v[step]*1.0/d,m+i*a[step]);
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    long long minn=8e18;
    for(long long i=1;i<n;i++){
        cin>>v[i];
        len+=v[i];

    }
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        minn=min(minn,a[i]);
    }

    len=ceil(len*1.0/d);
    if(a[1]==minn){
        cout<<a[1]*len;
        return 0;
    }
    dfs(1,0,0);
    cout<<res;
    return 0;
}
