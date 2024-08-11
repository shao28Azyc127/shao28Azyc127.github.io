#include<bits/stdc++.h>
#include<iostream>
#include<list>
#include<vector>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<iomanip>
#include<deque>
#include<algorithm>
using namespace std;
const int N=1e5+10;
typedef pair<long long,int> PII;
int n,cnt;
long long a[N];
int b[N],c[N],e[N],ma=0;
vector<int> to[N];
priority_queue<PII> innow;
bool use[N];
int main(){
    std::ios_base::sync_with_stdio(false);
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        to[u].push_back(v);
        to[v].push_back(u);
    }
    innow.push({a[1],1});
    for(int i=1;i<=n;i++){
        int t=innow.top().second;
        use[t]=true;
        e[t]=i;
        while(a[t]>0){
            a[t]-=max(b[t]+e[i]*c[t],1);
            e[i]++;
        }
        ma=max(ma,e[t]);
        for(auto j:to[t]){
            if(!use[j]){
                innow.push({a[j],j});
                use[j]=true;
            }
        }
    }
    cout<<ma;
    return 0;
}
