#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d,v[100005],a[100005],minn,sum,maxx;
void dfs(ll x,ll ans,double y){
    ll summ=0;
    if(x==n){
        minn=min(minn,ans);
        return;
    }
    for(int i=x+1;i<=n;i++){
        summ+=v[i];
        if(a[x]<=a[i]){
            continue;
        }
        else{
            //if(summ%d==0){
            dfs(i,ans+(summ/d*a[x]),y);
            //}
            /*else{
                double xxc=0,ccc=0;
                ll tt=0,ttt=0;
                xxc=1.0*v[i]/d;
                tt=xxc;
                ttt=xxc-y;
                ccc=xxc-ttt;
                if(tt>ttt){//剩下的油有用
                    if(ccc>=0.0000000001){//

                    }
                }
            }*/
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    //提交前请删除！！！！！！！
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    minn=1145141919810;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        minn=min(minn,a[i]);
    }
    if(minn==a[1]){
        if(sum%d==0){
            cout<<sum/d*a[1];
            return 0;
        }
        else{
            cout<<sum/d+1;
            return 0;
        }
    }
    minn=1145141919810;
    dfs(1,0,0);
    cout<<minn;
    return 0;
}
//为什么我的眼里常含泪水？
//因为我对信息学爱的深沉！
