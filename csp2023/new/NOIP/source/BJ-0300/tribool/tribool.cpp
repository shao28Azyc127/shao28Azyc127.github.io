#include<iostream>
using namespace std;
#define M 100005
#define INF 1000000000
#define Min(a,b) ((a)<(b)?(a):(b))

struct sss{
    char op;
    int x,y;
}st[M];

int unk[M];

int bl[M],c,t,n,m,ans;
int df[M];
const int fei[]={1,0,2};

int ctobool(char x)
{
    if(x=='T')return 1;
    if(x=='F')return 0;
    return 2;
}

void zhixing()
{
    for(int i=1;i<=m;i++)
    {
        if(st[i].op=='+')
            bl[st[i].x]=bl[st[i].y];
        else if(st[i].op=='-')
            bl[st[i].x]=fei[bl[st[i].y]];
        else bl[st[i].x]=ctobool(st[i].op);
    }
}

void dfs(int de,int unkn)
{
    if(de==n)
    {
        for(int i=1;i<=n;i++)bl[i]=df[i];
        zhixing();
        bool flag=1;
        for(int i=1;i<=n;i++)
            if(bl[i]!=df[i])
        {
            flag=0;break;
        }
        if(flag)
        {
            //debug
            //for(int k=1;k<=n;k++)cout<<bl[k];
            //cout<<endl<<"unkn"<<unkn<<endl;

            ans=Min(ans,unkn);
        }
    }
    else
    {
        for(int i=0;i<=2;i++)
        {
            df[de+1]=i;
            if(i==2)dfs(de+1,unkn+1);
            else dfs(de+1,unkn);
        }
    }
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>m;
        if(c==1||c==2){
            for(int i=1;i<=m;i++)
            {
                cin>>st[i].op;
                if(st[i].op=='+'||st[i].op=='-')cin>>st[i].x>>st[i].y;
                else cin>>st[i].x;
            }
            ans=INF;
            dfs(0,0);
            cout<<ans<<endl;
        }
        if(c==3||c==4)
        {
            ans=0;
            for(int i=1;i<=m;i++)
            {
                char opp;int xx;
                cin>>opp>>xx;
                unk[xx]=ctobool(opp);
            }
            for(int i=1;i<=n;i++)
                if(unk[i]==2)ans++;
            cout<<ans<<endl;
        }
        if(c==5||c==6)
        {
            ans=0;
            for(int i=1;i<=m;i++)
            {
                char op;
                int x,y;
                cin>>op>>x;
                if(op=='U')
                {
                    unk[x]=2;
                }
                else
                {
                    cin>>y;
                    if(unk[y]==2)unk[x]=2;
                    else unk[x]=0;
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(unk[i]==2)ans++;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
