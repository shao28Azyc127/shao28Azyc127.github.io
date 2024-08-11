#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int a,b,c;
}a[100010];
struct nodee{
    int x,y;
};
bool operator <(nodee a,nodee b){
    return a.y<b.y;
}
int n,ans,t;
bool book[100010];
vector<int> v[100010];
priority_queue<nodee> pq;
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
    for(int i=1;i<=n;i++) a[i].b=max(a[i].b,1ll);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    pq.push(nodee{1,(a[1].a+a[1].b-1)/a[1].b});
    book[1]=1;
    ans=(a[1].a+a[1].b-1)/a[1].b;
    while(pq.size()){
        nodee x=pq.top();
        pq.pop();
        ans=max(ans,t+x.y);
        t++;
        for(int i=0;i<v[x.x].size();i++){
            int y=v[x.x][i];
            if(book[y]) break;
            pq.push(nodee{y,(a[y].a+a[y].b-1)/a[y].b});
            book[y]=1;
        }
    }
    printf("%lld",ans);
    return 0;
}
