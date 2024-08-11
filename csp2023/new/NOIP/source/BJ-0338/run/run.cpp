#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c,t,n,m,x[N],y[N],sum[N];
long long k,d,ans,z[N];
inline long long check(long long spt){
    long long feb=0;
    for(int i=1;i<=m;i++)
        if(sum[x[i]]>=y[i]) feb+=z[i];
    feb-=spt;
    return feb;
}
void find(int p,int k1,long long spt){
    if(k1>k)    return ;
    if(p==n){
        ans=max(check(spt),ans);
        return ;
    }
    for(int i=0;i<=1;i++){
        spt+=i*d;
        if(i==0){
            sum[p+1]=0;
            find(p+1,0,spt);
        }
        else{
            sum[p+1]=k1+1;
            find(p+1,k1+1,spt);
        }
        spt-=i*d;
    }
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    if((c!=17)&&(c!=18)){
        while(t--){
            ans=0;
            cin>>n>>m>>k>>d;
            for(int i=1;i<=m;i++)   cin>>x[i]>>y[i]>>z[i];
            find(0,0,(long long)0);
            cout<<ans<<endl;
        }
    }
    if(c==17||c==18){
        while(t--){
            ans=0;
            cin>>n>>m>>k>>d;
            for(int i=1;i<=m;i++)   cin>>x[i]>>y[i]>>z[i];
            for(int i=1;i<=m;i++){
                if(y[i]*d>z[i]) continue;
                if(y[i]>k)  continue;
                ans+=z[i]-y[i]*d;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
