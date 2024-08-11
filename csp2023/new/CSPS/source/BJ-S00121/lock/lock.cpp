#include<bits/stdc++.h>
using namespace std;
int n;
int l(int a){
int s=0,i=1;
while(s<a){
    s+=i,i++;
}
return i;}
struct P{
int a,b,c,x;
int id;
bool operator>(const P&q)const {
    return l((double)(a-b)/c)>l((double)(q.a-q.b)/q.c);
}
}p[100010];
int vis[100010];
vector<pair<int,int> >h;
vector<int>v[100010];
priority_queue<P,vector<P>,greater<P> >pq;
int mz(int d,int id){
    int sum=0;
    for(int i=1;i<=d;i++)
sum+=max(p[id].b+i*p[id].c,1);
return sum;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
        p[i].id=i;
    }
    for(int i=1;i<n;i++){
        int ip1,ip2;
        scanf("%d%d",&ip1,&ip2);
        v[ip1].push_back(ip2);
    }
    pq.push(p[1]);
    vis[1]=1;
    int x=1;
    while(pq.size()){
        P f=pq.top();
        pq.pop();
        h.push_back(make_pair(f.id,x));
        for(int i=0;i<v[f.id].size();i++){
            if(vis[v[f.id][i]])continue;
            else pq.push(p[v[f.id][i]]);
        }
        x++;
    }
    priority_queue<pair<int ,int> >pq2;
    for(int i=0;i<h.size();i++){
        pq2.push(make_pair(mz(h[i].second,h[i].first),h[i].first));
        p[h[i].first].x=h[i].second;
    }
    while(pq2.top().first+(pq2.top().first+max(p[pq2.top().second].b+x*p[pq2.top().second].c,1))<p[pq2.top().second].a)pq2.top()=make_pair(pq2.top().first+max(p[pq2.top().second].b+x*p[pq2.top().second].c,1),pq2.top.second),x++;
    printf("%d",x);
    return 0;
}
