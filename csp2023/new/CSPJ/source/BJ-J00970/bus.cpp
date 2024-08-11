#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
vector<int>v[10004];
struct stu{
    int u,v,a;
}p[20004];
bool cmp(stu x,stu y){
    return x.a<y.a;
}
int work(int x){
    vector<int>vv,g;
    int head=0;
    vv.push_back(1);
    int fr=0,ffr=1e18,tt=x;
    while(tt-x<=n+k&&ffr){
        map<int,bool>mp;
        while(fr+1<=m&&p[fr+1].a<=tt){
            fr++;
            v[p[fr].u].push_back(p[fr].v);
        }
        for(int i=0;i<vv.size();i++){
            for(int j=0;j<v[vv[i]].size();j++){
                if(!mp[v[vv[i]][j]])g.push_back(v[vv[i]][j]),mp[v[vv[i]][j]]=1;
            }
        }
        tt++;
        ffr--;
        while(vv.size())vv.pop_back();
        for(int i=0;i<g.size();i++){
            vv.push_back(g[i]);
            if(g[i]==n){
                ffr=k+3;
                if(tt%k==0){
                    return tt;
                }
            }
        }
        while(g.size())g.pop_back();
    }
    return 1e18;
}
signed main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>p[i].u>>p[i].v>>p[i].a;
    }
    sort(p+1,p+m+1,cmp);
    int l=0,r=1500000,ans=1e18;
    while(l<=r){
        int mid=(l+r)/2;//start on mid*k.
        int ffff=work(mid*k);
        ans=min(ffff,ans);
        if(ffff==1e18){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
        //cerr<<l<<' '<<r<<endl;
        for(int i=1;i<=n;i++)while(!v[i].empty())v[i].pop_back();
    }
    if(ans==1e18){
        cout<<-1;
        return 0;
    }
    cout<<ans;
    return 0;
}
/*
5 5 3
1 2 0
2 5 1
1 3 0
3 4 3
4 5 1
*/
