#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005, M=200005;
int n;
struct field{
    int a, b, c;
};
field f[N];
struct edge{
    int to, next;
};
edge e[M];
bool mark[N];
int tall[N];
int te, first[N];
int day;
struct node{
    int p, id;
    bool operator < (const node &x) const{
        return p<x.p;
    }
};
priority_queue<node> pq;
void addedge(int a, int b)
{
    te++;
    e[te].to=b;
    e[te].next=first[a];
    first[a]=te;
}
void add()
{
    day++;
    for(int i=1; i<=n; i++) 
        if(mark[i]) 
            tall[i]+=f[i].b;
}
bool A()
{
    bool flag=1;
        for(int i=1; i<=n; i++){
            if(tall[i]<f[i].a) flag=0;
        }
        return flag;
}
void bfs()
{
    pq.push((node){f[1].a/f[1].b, 1});
    while(!pq.empty()){
        int h=pq.top().id;
        mark[h]=1;
        pq.pop();
        add();
        for(int i=first[h]; i; i=e[i].next){
            int to=e[i].to;
            if(!mark[to]) pq.push((node){f[to].a/f[to].b, to});
        }
    }
    if(A()) return;
    else{
        while(!A()){
            add();
        }
    }
}
signed main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%lld", &n);
    for(int i=1,a,b,c; i<=n; i++){
        scanf("%lld%lld%lld", &a, &b, &c);
        f[i].a=a;
        f[i].b=b;
        f[i].c=c;
    }
    for(int i=1, u, v; i<=n-1; i++){
        scanf("%lld%lld", &u, &v);
        addedge(u, v);
        addedge(v, u);
        //printf("1")
    }
    memset(tall, 0, sizeof tall);
    bfs();
    //for(int i=1; i<=n; i++) printf("%d ", tall[i]);
    printf("%lld", day);
    puts("");
    return 0;
}