#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m;
int ans;
char a[100003];
bool check[100003];
struct make
{
    char type;
    int pre,nex;
}way[100003];
void DFS(int x)
{
    if(x==n+1)
    {
        char prea[100003];
        for(int i=1;i<=n;i++)prea[i]=a[i];
        for(int i=1;i<=m;i++)
        {
            if(way[i].type=='-')
            {
                if(prea[way[i].nex]=='F')prea[way[i].pre]='T';
                else if(prea[way[i].nex]=='T')prea[way[i].pre]='F';
                else prea[way[i].pre]='U';
            }
            else if(way[i].type=='+')
            {
                if(prea[way[i].nex]=='F')prea[way[i].pre]='F';
                else if(prea[way[i].nex]=='T')prea[way[i].pre]='T';
                else prea[way[i].pre]='U';
            }
        }
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            if(prea[i]!=a[i])break;
            if(prea[i]=='U')sum++;
            if(i==n)ans=min(ans,sum);
        }
        return ;
    }
    else if(!check[x])
    {
        a[x]='T';
        DFS(x+1);
        a[x]='F';
        DFS(x+1);
        a[x]='U';
        DFS(x+1);
    }
    else DFS(x+1);
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    if(c<=2)
    {
        for(int p=1;p<=t;p++)
        {
            cin>>n>>m;
            ans=100003;
            for(int i=1;i<=n;i++)
            {
                a[i]='a';
                check[i]=false;
            }
            for(int i=1;i<=m;i++)
            {
                char x;
                int y,z;
                cin>>x;
                way[i].type=x;
                if(x=='-'||x=='+')
                {
                    cin>>y>>z;
                    way[i].pre=y;
                    way[i].nex=z;
                }
                else
                {
                    cin>>y;
                    way[i].pre=y;
                    a[y]=x;
                    check[y]=true;
                }
            }
            DFS(1);
            cout<<ans<<endl;
        }
    }
    else if(c>2&&c<=4)
    {
        for(int p=1;p<=t;p++)
        {
            cin>>n>>m;
            ans=0;
            for(int i=1;i<=n;i++)a[i]='a';
            for(int i=1;i<=m;i++)
            {
                char x,y;
                cin>>x>>y;
                a[y]=x;
                /*if(a[y]=='a'||a[y]=='F'||a[y]=='T')
                {
                    if(x=='U')ans++;
                    a[y]=x;
                }
                else if(a[y]=='U')
                {
                    if(x=='T'||x=='F')ans--;
                    a[y]=x;
                }*/
            }
            for(int i=1;i<=n;i++)if(a[i]=='U')ans++;
            cout<<ans<<endl;
        }
    }
    else if(c>4&&c<=6)
    {
        for(int p=1;p<=t;p++)
        {
            cin>>n>>m;
            ans=0;
            for(int i=1;i<=n;i++)a[i]='a';
            for(int i=1;i<=m;i++)
            {
                char x;
                int y,z;
                cin>>x;
                if(x=='+')
                {
                    cin>>y>>z;
                    a[y]=a[z];
                }
                else if(x=='U')
                {
                    cin>>y;
                    a[y]='U';
                }
            }
            for(int i=1;i<=n;i++)if(a[i]=='U')ans++;
            cout<<ans<<endl;
        }
    }
    else
    {
        for(int p=1;p<=t;p++)
        {
            cout<<n<<endl;
        }
    }
    return 0;
}
