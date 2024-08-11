#include <bits/stdc++.h>
using namespace std;
int id,t;
const int N=1e3+5;
typedef long long ll;
int n,m,k,d;
struct test{
    int r;
    int c;
    ll w;
}q[N];
bool cmp(test a,test b){
    if(a.r!=b.r) return a.r<b.r;
    return a.c<b.c;
}
ll f[1003][1003];
ll a[N],sum;
ll ans,pt;
void dfs(int cur,int len){
    if(cur>n){
        ans=max(ans,sum);
        return ;
    }
    ll lst=0;
    lst=sum;
    if(len<k){
        sum-=d;
        for(;pt<=m;pt++){
            if(q[pt].r>cur){
                pt--;
                break;
            }
            if(q[pt].r==cur&&len>=q[pt].c-1) sum+=q[pt].w;
        }
        dfs(cur+1,len+1);
        sum=lst;
    }
    dfs(cur+1,0);
}

signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>id>>t;
    if(id<=18&&id>=17){
        while(t--){
            cin>>n>>m>>k>>d;
            ll r,c,w,ans=0;
            for(int i=1;i<=m;i++){
                cin>>r>>c>>w;
                if(c<=k){
                    ans+=max(0ll,w-c*d);
                }
            }
            cout<<ans<<endl;
        }
        return 0;
    }
    if(id<=4){
        while(t--){
            cin>>n>>m>>k>>d;
            for(int i=1;i<=m;i++){
                cin>>q[i].r>>q[i].c>>q[i].w;
            }
            sort(q+1,q+m+1,cmp);
            ans=0,sum=0,pt=1;
            dfs(1,0);
            cout<<ans<<endl;
        }
    }
}

/*
3 1
5 3 4 1
6 4 3
6 3 3
6 2 11
*/