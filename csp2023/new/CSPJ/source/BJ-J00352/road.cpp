#include<bits/stdc++.h>
using namespace std;
//cout<<"Thanks god.Please help me AK CSP-J!";
int w[100005],v[100005],vis[100005];
int n,d,minn=1000000000,mi,ans,ls;
void tj(){
    int cnt=1;
    for(int i=2;i<=n;i++){
        if(vis[i]){
            long long sum=0;
            for(int j=cnt;j<i;j++){
                sum+=v[j];
            }
            sum-=ls;
            //cout<<ls<<endl;
            if(sum%d==0){
                ans+=(sum/d)*w[cnt];
                ls=sum%d;
                //cout<<sum<<" "<<i<<" "<<ls<<" "<<sum/d<<" "<<w[cnt]<<" "<<ans<<endl;
            }else{
                ans+=(sum/d+1)*w[cnt];
                ls=sum%d+1;
                //cout<<sum<<" "<<i<<" "<<ls<<" "<<sum/d+1<<" "<<w[cnt]<<" "<<ans<<endl;
            }
            if(ls<0)ls=0;
            //cout<<ls<<endl;
            cnt=i;
        }
    }
    cout<<ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long sum=0;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>w[i];
        if(w[i]<minn){
            minn=w[i];
            mi=i;
        }
    }
    if(mi==1){
        if(sum%d==0)cout<<sum/d;
        else cout<<sum/d+1;
        return 0;
    }
    vis[mi]=1;
    while(1){
        int mi1;
        minn=1000000000;
        for(int i=1;i<mi;i++){
            if(w[i]<minn){
                minn=w[i];
                mi1=i;
            }
        }
        vis[mi1]=1;
        if(mi1==1){
            tj();
            return 0;
        }
        minn=1000000000;
        for(int i=1;i<mi1;i++){
            if(w[i]<minn){
                minn=w[i];
                mi=i;
            }
        }
        vis[mi]=1;
        if(mi==1){
            tj();
            return 0;
        }
    }
    return 0;
}
