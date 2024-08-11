#include <bits/stdc++.h>
using namespace std;
int n,lastnum=1;
long long a[10001],b[10001],c[10001];
bool edge[10005][10005];
bool plant[10005];
long long tree[10005];
long long ty[10005];
bool isG[10005];
bool isF[10005];
int dij()
{
    plant[1]=true;
    isF[1]=true;
    long long tt=1;
    for(int i=1; i<=n; i++)
    {
        tree[i]+=max(b[i]+c[i],tt);
        ty[i]=a[i]-tree[i];
    }
    int d=1;
    while(true)
    {
        d++;
        int conc=0;
        long long maxn=0x7fffffff;
        bool isBreak=false;
        for(int i=1; i<=n; i++)
        {
            tree[i]+=max(b[i]+d*c[i],tt);
            if(isF[i]==true){
                ty[i]+=a[i]-tree[i];
            }
            else{
                ty[i]=a[i]-tree[i];
            }
            if(isF[i]==false||ty[i]>0)
            {
                isBreak=true;
            }
        }
        if(isBreak==false)
        {
            break;
        }
        for(int i=1; i<=n; i++)
        {
            if(edge[lastnum][i])
            {
                isG[i]=true;
            }
        }
        for(int i=1; i<=n; i++)
        {
            if(ty[i]<maxn&&isF[i]==false&&isG[i]==true)
            {
                maxn=ty[i];
                conc=i;
                isF[i]=true;
            }
        }
        lastnum=conc;
    }
    d--;
    return d;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    memset(tree,0,sizeof(tree));
    for(int i=1; i<=n; i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        edge[u][v]=true;
        edge[v][u]=true;
    }
    cout<<dij();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
