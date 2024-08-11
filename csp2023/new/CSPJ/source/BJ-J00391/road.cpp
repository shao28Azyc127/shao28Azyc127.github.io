#include<bits/stdc++.h>
using namespace std;
    int dis[100001];
    struct N
    {
        int p,id;
    };
    N p[100001];
    int ans[100001];
    long long  sum[100001];
    int y[100001];
    int n,minp=0,pminp=1,d;
    queue<int> st;
    bool cmp1(N a,N b)
    {
        return a.p<b.p;
    }

    bool cmp2(N a,N b)
    {
        return a.id<b.id;
    }
    void ty(int m)
    {
        if(m==n)
        {
            return ;
        }
        int r=p[m].p;
        for(int i=m+1;i<=n;i++)
        {
            if(p[i].p<r)
            {
                //cout<<i<<" ";
                st.push(i);
                ty(i);
                break;
            }
        }
    }
    void dfs(int m,int pr,int dis)
    {
        if(m==n)
        {
            cout<<pr;
            return ;
        }
        int k=st.front();
        st.pop();
        int pr2;
        if((sum[k]-dis)/d*d!=sum[k]-dis)
        {
            pr2=(sum[k]-dis)/d+1;
        }else{
            pr2=(sum[k]-dis)/d;
        }
        //cout<<k<<" "<<pr2*p[m].p<<endl;
        dfs(k,pr+pr2*p[m].p,dis+pr2*d);
    }
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(ans,0x3f,sizeof(ans));
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)
    {
        cin>>dis[i];
        sum[i+1]=sum[i]+dis[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].p;
        p[i].id=i;
    }
    st.push(1);
    ty(1);
    st.push(n);
    dfs(st.front(),0,0);
// a different dfs.
    return 0;
}
