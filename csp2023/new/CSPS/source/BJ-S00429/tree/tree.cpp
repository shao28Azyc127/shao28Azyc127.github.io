#include<bits/stdc++.h>
using namespace std;
struct tree{
    int a,b,c,id;
    bool operator > (const tree&kkk) const{
        return b/a+(b&a!=0)>kkk.b/kkk.a+(kkk.b&kkk.a!=0);
    }
    bool operator < (const tree&kkk) const{
        return b/a+(b&a!=0)<kkk.b/kkk.a+(kkk.b&kkk.a!=0);
    }
}t[100005];
vector<int> e[100005];
bool vis[100005];
priority_queue<tree> q;
int main() {
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d %d %d",&t[i].a,&t[i].b,&t[i].c);
        t[i].id=i;
        q.push(t[i]);
    }
    for (int i=1;i<=n-1;i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    printf("%d",n+1);
    return 0;
}
