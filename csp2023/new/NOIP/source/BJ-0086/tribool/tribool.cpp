#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
const int MAXN=1e5+5;
vector<int>v[MAXN<<1];
int fa[MAXN<<1];
int vis[MAXN<<1];
char type[MAXN<<1];
int n,m;
void init()
{
    for(int i=1;i<=2*n;i++)
    {
        fa[i]=i;
        vis[i]=0;
        type[i]='X';
        v[i].clear();
    }
}
int findfa(int x)
{
    if(fa[x]!=x) fa[x]=findfa(fa[x]);
    return fa[x];
}
void mergefa(int x,int y)
{
    int tmp1=findfa(x),tmp2=findfa(y);
    cout<<tmp1<<' '<<tmp2<<endl;
    fa[tmp1]=tmp2;
}
int rev(int x)
{
    if(x>n) return x-n;
    return x+n;
}
bool check(int x)
{
    //cout<<x+n<<endl;
    if(type[x]=='U'||type[x+n]=='U') return false;
    for(auto node:v[x+n])
    {
        //cout<<node<<' ';
        if(node==x) return false;
        if(type[node]=='U') return false;
    }
    //cout<<endl<<x<<endl;
    for(auto node:v[x])
    {
        //cout<<node<<' ';
        if(node==n+x) return false;
        if(type[node]=='U') return false;
    }
    return true;
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    scanf("%d %d",&c,&t);
    while(t--)
    {
        scanf("%d%d\n",&n,&m);
        init();
        for(int i=1;i<=m;i++)
        {
            char op;
            scanf("%c ",&op);
            if(op=='T'||op=='F'||op=='U')
            {
                int x;
                scanf("%d\n",&x);
                type[fa[x]]=op;
            }
            else if(op=='+')
            {
                int x,y;
                scanf("%d%d\n",&x,&y);
                fa[x]=fa[y];
                //type[fa[x]]=type[fa[y]];
                //mergefa(x,y);
            }
            else if(op=='-')
            {
                int x,y;
                scanf("%d%d\n",&x,&y);
                int ny=rev(fa[y]);
                fa[x]=fa[ny];
                /*
                if(type[fa[y]]!='X')
                {
                    char tmp='U';
                    if(type[fa[y]]=='T') tmp='F';
                    else if(type[fa[y]]=='T') tmp='F';
                    type[x]=type[fa[x]]=tmp;
                }
                else type[fa[x]]='X';
                */
                //type[x]=tmp;
                //int tmp=rev(findfa(y));
                //mergefa(x,tmp);
            }
            /*
            for(int i=1;i<=2*n;i++)
            {
                cout<<i<<": "<<fa[i]<<' '<<type[i]<<endl;
            }
            cout<<endl;
            */

        }
        for(int i=1;i<=2*n;i++)
        {
            if(fa[i]<=n) v[fa[i]].push_back(i);
            else
            {
                if(fa[i]!=rev(i)) fa[i]=rev(fa[rev(fa[i])]);
                //cout<<rev(i)<<' '<<fa[rev(i)]<<endl;
                v[fa[i]].push_back(i);
            }
            if(i<=n) vis[fa[i]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(type[i]!='X')
            {
                for(auto node:v[i]) type[node]=type[i];
                char tmp='U';
                if(type[i]=='T') tmp='F';
                else if(type[i]=='F') tmp='T';
                for(auto node:v[n+i]) type[node]=tmp;
            }
        }
        /*
        for(int i=1;i<=2*n;i++)
        {
            cout<<i<<": "<<fa[i]<<' '<<type[i]<<endl;
        }
        */
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(!check(i))
            {
                //cout<<i<<endl;
                cnt+=vis[i]+vis[n+i];
            }
            //cout<<endl;
        }
        printf("%d\n",cnt);
        //cout<<endl;
    }
    return 0;
}