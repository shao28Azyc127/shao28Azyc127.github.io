#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
int n;
long long ans=0;
set<int> p[MAXN];
vector<int> q[MAXN];
char c[MAXN];
int dfs(int x,int id){
    if(x>n) return 0;
    if(q[x].size()==0)  return 0;
    int sum=q[x].size();
    for(int i=0;i<q[x].size();i++){
        if(c[id-1]==c[q[x][i]+1])   p[id-1].insert(q[x][i]+1);
        if(q[x][i]<n)   sum+=dfs(q[x][i]+1,id);
    }
    return sum;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)   cin>>c[i];
    for(int i=1;i<n;i++){
        if(c[i]==c[i+1]){
            //printf("%d ",i);
            int l=i,r=i+1;
            while(l>=1 && r<=n){
                if(c[l]==c[r]){
                   if(c[l]!=c[l+1] || l==r-1)
                        q[l].push_back(r);
                }
                else    break;
                l--,r++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        //printf("%d ",q[i].size());
        ans+=dfs(i,i);
    }
    for(int i=1;i<=n;i++){
        ans+=p[i].size();
    }
    printf("%lld",ans);
    return 0;
}
