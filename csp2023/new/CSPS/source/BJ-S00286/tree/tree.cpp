#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int n;
vector<int> ve[MAXN];
struct Node{
    int a,b,c;
    bool operator <(const Node &x)const{
        return a==x.a?c<x.c:a>x.a;
    }
}d[MAXN];
bool check(int i,int mid){
    int need=ceil((1.0-d[i].b)/d[i].c);
    if(i>need)
        return d[i].b*(mid-i+1)+d[i].c*(mid-i+1)*(mid+i)>=d[i].a;
    else{
        if(mid<=need) return mid-i+1>=d[i].a;
        int i0=need-i;
        i=need;
        return d[i].b*(mid-i+1)+d[i].c*(mid-i+1)*(mid+i)+i0>=d[i].a;
    }
}
bool tpb=1,tpd=1;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d%d",&d[i].a,&d[i].b,&d[i].c);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        ve[u].push_back(v);
        ve[v].push_back(u);
        if(u!=i||v!=i+1) tpb=0;
        if(u!=1) tpd=0;
    }
    if(tpb){
        int ans=0;
        for(int i=1;i<=n;i++){
            int l=1,r=d[i].a,mid;
            while(l<r){
                mid=(l+r)>>1;
                if(check(i,mid)) r=mid;
                else l=mid+1;
            }
            ans=max(ans,l);
        }
        printf("%d",ans);
        return 0;
    }
    if(tpd){
        sort(d+1,d+1+n);
        int ans=0;
        for(int i=1;i<=n;i++){
            int l=1,r=d[i].a,mid;
            while(l<r){
                mid=(l+r)>>1;
                if(check(i,mid)) r=mid;
                else l=mid+1;
            }
            ans=max(ans,l);
        }
        printf("%d",ans);
    }
    return 0;
}
