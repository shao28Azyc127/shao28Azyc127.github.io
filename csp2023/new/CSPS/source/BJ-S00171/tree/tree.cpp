#include<algorithm>
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#define int long long
using namespace std;
int n,a[112345],b[112345],c[112345],mx[112345],ans[112345],st,ans3,h[2123456];
bool vis[112345];
vector<int> v1[112345];
bool cmp(int x,int y){
    return mx[x]>mx[y];
}
void dfs1(int x){
    int now=0;
    vis[x]=1;
    for(int i=0;i<v1[x].size();i++)
        if(!vis[v1[x][i]]) {dfs1(v1[x][i]);mx[x]=max(mx[x],mx[v1[x][i]]);}
    if(a[x]%b[x]!=0)
        mx[x]=max(mx[x],a[x]/b[x]+1);
    else    mx[x]=max(mx[x],a[x]/b[x]);
}
void dfs2(int x){
    vis[x]=1;
    if(a[x]%b[x]!=0)
        ans[x]=max(ans[x],a[x]/b[x]+1+st);
    else    ans[x]=max(ans[x],a[x]/b[x]+st);
    st++;
    for(int i=0;i<v1[x].size();i++)
        if(!vis[v1[x][i]])   dfs2(v1[x][i]),st++,ans[x]=max(ans[x],ans[v1[x][i]]);
}
void dfs3(int x,int d){
    vis[x]=1;
    int mm=0;
    if(c[x]>=0){
        int l=0,r=1e9;
        while(l<r){
            int mid=(l+r)>>1;
            if(b[x]*mid+c[x]*(h[d+mid]-h[d-1])>=a[x])    l=mid;
            else    r=mid-1;
        }
        mm=l;
    }
    else{
        c[x]*=-1;
        int ydy=b[x]/c[x];
        if(b[x]*ydy-c[x]*(h[x+ydy]-h[x-1])>=a[x]){
//        cout<<1<<endl;
            int l=0,r=1e9;
            while(l<r){
                int mid=(l+r+1)>>1;
                if(b[x]*mid-c[x]*(h[d+mid]-h[d-1])>=a[x])    l=mid;
                else    r=mid-1;
            }
            mm=l;
        }
        else    {mm=ydy+(a[x]-b[x]*ydy-c[x]*(h[x+ydy]-h[x-1]));}
    }
    ans3=max(ans3,d+mm);
    for(int i=0;i<v1[x].size();i++)
       if(!vis[v1[x][i]])     dfs3(v1[x][i],d+1);
}
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<n;i++)
    {
        int x1,y;
        cin>>y>>x1;
        v1[x1].push_back(y);
//        cout<<1<<" "<<x1<<" "<<y<<endl;
        v1[y].push_back(x1);
    }
    bool o=0;
    for(int i=1;i<=n;i++)
        if(c[i]!=0){o=1;break;}
    if(!o){
        dfs1(1);
        for(int i=1;i<=n;i++)
            sort(v1[i].begin(),v1[i].end(),cmp);
        for(int i=1;i<=n;i++)   vis[i]=0;
        dfs2(1);
        cout<<ans[1]<<endl;
    }
    int ydy=0;
    for(int i=1;i<=n;i++){
        if(v1[i].size()!=2&&(!(v1[i][0]==i-1&&v1[i][1]==i+1||v1[i][0]==i+1&&v1[i][1]==i-1))) ydy++;
        if(ydy>2){
            o=0;
            break;
        }
    }
    if(o){
        for(int i=1;i<=10000;i++){
//            if(h[i]>1e9)   break;
            h[i]=h[i-1]+i*i;
//            cout<<i<<endl;
        }
//        cout<<h[10000]<<endl;
        dfs3(1,0);
        cout<<ans3<<endl;
    }
//    if(n<=20){
//        cout<<dfs(1,0,0)<<endl;
//        return 0;
//    }
    return 0;
}
