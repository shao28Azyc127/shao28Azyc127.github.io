#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#define int long long
#define ull unsigned long long
using namespace std;
int n;
struct node{
    int a,b,c;
    int d;
}land[100005];
vector<int>vec[100005],vec1[100005];
int ans;
int day;
void dfs(int x,int fa){
    for(int i=0;i<vec[x].size();i++){
        int v=vec[x][i];
        if(v!=fa){
            dfs(v,x);
            vec1[x].push_back(v);
        }
    }
}
struct nodeq{
    int to;
    int w;
    bool operator < (const nodeq &a)const{
        return w<a.w;
    }
};
priority_queue<nodeq>q;
void bfs(){
    q.push((nodeq){1,land[1].d});
    while(!q.empty()){
        int u=q.top().to,w=q.top().w;
        q.pop();
        ans=max(ans,w+day);
        day++;
        for(int i=0;i<vec1[u].size();i++){
            q.push((nodeq){vec1[u][i],land[vec1[u][i]].d});
        }
    }
}
int count(int x){
    if(land[x].c>=0){
        int l=1,r=1e9;
        while(l<r){
            int mid=(l+r)/2;
            int val=land[x].b*mid+(1+mid)*(mid)/2*land[x].c;
            if(val>land[x].a)r=mid-1;
            if(val==land[x].a){l=mid;break;}
            if(val<land[x].a)l=mid+1;
        }
        return l-1;
    }else{
        int tmp=land[x].b/land[x].c;
        int val=tmp*land[x].b+(1+tmp)*tmp/2*land[x].c;
        if(val<=land[x].a)return land[x].a-val+tmp-1;
        int l=0,r=val;
        while(l<r){
            int mid=(l+r)/2;
            val=land[x].b*mid+(1+mid)*(mid)/2*land[x].c;
            if(val>land[x].a)r=mid-1;
            if(val==land[x].a){l=mid;break;}
            if(val<land[x].a)l=mid+1;
        }
        return l-1;
    }
}
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%lld",&n);
    bool flag=false;
    bool flag1=false;
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&land[i].a,&land[i].b,&land[i].c);
        if(land[i].c)flag=true;
        land[i].d=land[i].a/land[i].b;
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%lld%lld",&u,&v);
        if(abs(u-v)!=1)flag1=true;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    if(flag){
        if(!flag1){
            for(int i=1;i<=n;i++){
                ans=max(ans,i+count(i));
            }
            printf("%lld\n",ans);
            return 0;
        }
        return 0;
    }
    dfs(1,0);
    bfs();
    printf("%lld\n",ans);
    return 0;
}
/*
8
1 1 0
2 2 0
29 3 0
3 2 0
4 1 0
35 6 0
6 7 0
5 1 0
1 2
1 3
2 4
2 5
4 6
4 7
4 8

*/
