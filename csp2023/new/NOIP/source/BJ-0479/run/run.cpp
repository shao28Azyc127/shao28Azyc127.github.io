#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int N=1e5+9;
int f[1005][1005];
bool vis[N];
struct node{
    int a,v,w;
}s[N];
bool cmp(node x, node y)
{
    return x.a-x.v<y.a-y.v;
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int o,T;
    cin>>o>>T;
    while(T--)
    {
        int n,m,k,d;
        cin>>n>>m>>k>>d;
        for(int i=1; i<=m; i++)
            cin>>s[i].a>>s[i].v>>s[i].w;
        sort(s+1,s+m+1,cmp);
//        for(int i=1; i<=m; i++)
//            cout<<s[i].a<<" ";
        int ans=0,l=0;
        for(int i=1; i<=m; i++)
        {
            if(s[i].v<=k)
            {
                int tmp=0;
                for(int j=s[i].a; j>=s[i].a-s[i].v+1; j--)
                    vis[j]=true,tmp=j-s[i].v+1;
                ans+=s[i].w;
                l=tmp;
            }
        }
        for(int i=1; i<=n; i++)
            ans-=vis[i];
        cout<<ans<<endl;
    }
    return 0;
}
