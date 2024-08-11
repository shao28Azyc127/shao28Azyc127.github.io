#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct line{
    long long t,val;
};
vector<int>link[1000050];
long long n;
struct stu{
    long long a,b,c;
    long long fa;
}x[100050];
bool cmp(stu x,stu y){
    if(x.c!=y.c)return x.c<y.c;
    else return x.a*1.0/x.b<y.a*1.0/y.b;
}
long long f[100050];
bool vis[100050];
long long use=0,anser=0;
long long ask;
long long work(long long p,long long day){
    long long l=0,r=1000000000;
    while(l<r){
        long long mid=(l+r)>>1;
        if(l+1==r){
            mid=r;
        }
        if(x[p].b+(day+mid)*x[p].c<=0)r=mid-1;
        else l=mid;
    }
    long long mx=(day+l)*(day+l+1)/2*x[p].c+l*x[p].b-day*(day+1)/2*x[p].c;

    if(mx<x[p].a){
        return day+l+x[p].a-max(0ll,mx);
    }else{
        long long ll=day,rr=day+l;
        while(ll<rr){
            long long mid=(ll+rr)>>1;
            if((mid)*(mid+1)/2*x[p].c+(mid-day)*x[p].b-day*(day+1)/2*x[p].c>x[p].a)rr=mid;
            else ll=mid+1;
        }
        return ll-1;
    }
}
bool dfs(long long p,long long fa,long long day){
    if(p==ask){
        anser=max(anser,work(p,use+day));
        use+=day;
        return true;
    }
    for(long long u:link[p]){
        if(u==fa)continue;
        if(vis[p]){
            if(dfs(u,p,day)){
                vis[p]=true;
            }
        }else{
            if(dfs(u,p,day+1)){
                vis[p]=true;
            }
        }
    }
    return false;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    bool op=1;
    for(long long i=1;i<=n;i++){
        scanf("%lld%lld%lld",&x[i].a,&x[i].b,&x[i].c);
    }
    //sort(x+1,x+n+1,cmp);
    for(long long i=1;i<n;i++){
        long long u,v;
        scanf("%lld%lld",&u,&v);
        link[u].push_back(v);
        link[v].push_back(u);
    }
    long long a=1;
    for(long long i=1;i<=n;i++){
        if(cmp(x[i],x[a]))a=i;
    }
    ask=a;
    dfs(1,0,0);
    x[a].c=214748;
    for(long long i=1;i<=n;i++){
        if(cmp(x[i],x[a]))a=i;
    }
    ask=a;
    dfs(1,0,0);

    cout<<anser;
    return 0;
}
