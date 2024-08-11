#include<bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 2e5 + 8;

int a[N],b[N],c[N],t[N];
vector<int> E[N];
list<int> Q;
bitset<N> inQ;

bool cmp(int i, int j){
return a[i]>a[j];}


signed main(){
freopen("tree.in","rb",stdin);
freopen("tree.out","wb",stdout);

int n;
cin>>n;
for(int i=1;i<=n;++i){
cin>>a[i]>>b[i]>>c[i];
}
for(int i=1,u,v;i<n;++i){
cin>>u>>v;
E[u].push_back(v);
E[v].push_back(u);
}
for(int i=1;i<=n;++i){
sort(E[i].begin(),E[i].end(),cmp);
}
Q.push_back(1);
inQ[1]=1;
t[1]=0;
int cnt =1;

while(!Q.empty()){
int c=Q.front();
Q.pop_front();
t[c]=++cnt;
for(int j:E[c]){
if(inQ[j]) continue;
Q.push_back(j);
inQ[j]=1;
}
}
int ans=0;
for(int i=1;i<=n;++i){
ans+=t[i]+a[i];
}
cout << ans;
}