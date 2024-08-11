#include<bits/stdc++.h>
using namespace std;
long long arr[100005];
long long fa[100005];
long long s[100005];
vector<long long> edge[100005];
long long dfs(int x){
    memset(s,0,sizeof s);
    long long ans=0;
    long long cnt=0;
    bool flag=0;
    for(auto v:edge[x]){
        if(v==fa[x])continue;
        fa[v]=x;
        flag=1;
        int temp=dfs(v);
        s[++cnt]=temp;
    }
    if(flag==0){
        return arr[x];
    }
    sort(s+1,s+cnt+1);
    for(long long i=cnt,j=1;i>=1;i--,j++){
        ans=max(ans,s[i]+j);
    }
    ans=max(ans,arr[x]);
    return ans;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        long long temp1=1;
        long long temp=max(b,temp1);
        if(a%temp==0){
            arr[i]=a/temp;
        }
        else{
            arr[i]=a/temp+1;
        }
    }
    for(long long i=1;i<n;i++){
        long long u,v;
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    cout<<dfs(1);
    return 0;
}
