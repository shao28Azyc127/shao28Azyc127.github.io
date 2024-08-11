#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b;
}ks;
struct f{
    vector<int> v;
    vector<int> t;
}a[10005];
queue<node> q;
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int ax,bx,cx;
    scanf("%d%d%d",&ax,&bx,&cx);
    for(int i=1;i<=bx;i++){
        int af,bf,cf;
        scanf("%d%d%d",&af,&bf,&cf);
        a[af].v.push_back(bf);
        a[af].t.push_back(cf);
    }
    q.push(node{1,cx});
    while(1){
        if(q.empty())break;
        ks=q.front();
        q.pop();
        if(ks.a==ax){
            if(ks.b%cx==0){
                printf("%d",ks.b);
                return 0;
            }else{
                continue;
            }
        }
        for(int i=0;i<a[ks.a].v.size();i++){
            if(ks.b>=a[ks.a].t[i]){
                q.push(node{a[ks.a].v[i],ks.b+1});
            }
        }
    }
    printf("-1");
}
