#include <bits/stdc++.h>
using namespace std;
long long n,m,k;
vector<long long> v[10005];
queue<long long> q;
bool  f=1;
bool vis[10005];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    long long x,y,z;
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&x,&y,&z);
        v[x].push_back(y);
        if(z)
            f=0;
    }
    if(f&&k==1){
            if(n==1)
    {

        printf("%d",0);
        return 0;
    }

    q.push(1);
    vis[1]=1;
    long long c=1;
    while(!q.empty()){
        int hx=q.front(); q.pop();
        for(int i=0;i<v[hx].size();i++){
            if(vis[v[hx][i]]==0){
                q.push(v[hx][i]);
                if(v[hx][i]==n)
                {

                    printf("%lld",c);
                    return 0;
                }
                vis[v[hx][i]]=1;
            }

        }
        c++;
    }
    printf("-1");
    }else
        printf("-1");
    return 0;
}

