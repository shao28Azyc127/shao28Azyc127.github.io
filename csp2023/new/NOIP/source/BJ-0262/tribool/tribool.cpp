#include<bits/stdc++.h>
using namespace std;

int v[114514][2];//v[i][0]表示值，v[i][1]表示对应变量（0为常量T）。T=1,F=-1,U=0,运算：*-1

void input(int n,int m)
{
    for(int i=0;i<=n;i++)v[i][0]=1,v[i][1]=i;
    while(m--)
    {
        char op;
        cin>>op;
        int i,j;
        cin>>i;
        switch(op)
        {
            case '+':
                cin>>j;
                if(j==i)break;
                v[i][0]=v[j][0],v[i][1]=v[j][1];
                break;
            case '-':
                cin>>j;
                if(j==i)break;
                v[i][0]=-1*v[j][0],v[i][1]=v[j][1];
                break;
            case 'T':
                v[i][0]=1,v[i][1]=0;
                break;
            case 'F':
                v[i][0]=-1,v[i][1]=0;
                break;
            case 'U':
                v[i][0]=0,v[i][1]=0;
                break;
            default:
                cout<<"你干嘛～～嗨嗨～～诶呦\n";
        }
    }
}

int value[114514];

void work12()
{
    int n,m;
    cin>>n>>m;
    input(n,m);
    value[0]=1;
    int ans=n+114514;
    for(int tk=0;tk<=59049;tk++)
    //for(int tk=20;tk<=20;tk++)
    {
        int k=tk,cnt=0;
        for(int i=1;i<=n;i++)value[i]=k%3-1,k/=3,cnt+=(value[i]==0);

        bool flag=1;
        for(int i=1;i<=n;i++)
            if(value[i]!=value[v[i][1]]*v[i][0])
            {
                //cout<<i<<' '<<value[i]<<' '<<v[i][0]<<' '<<v[i][1]<<' '<<value[v[i][1]]*v[i][0]<<'\n';
                flag=0;
                break;
            }
        //cout<<flag
        if(flag&&cnt<ans)ans=cnt;
    }
    cout<<ans<<'\n';
}

void work34()
{
    int n,m;
    cin>>n>>m;
    input(n,m);
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=(v[i][0]==0);
    cout<<ans<<'\n';
}

vector<int> child[114514];
int childcnt[114514];
bool book[114514];
int fa[114514];

void dfs(int f,int father)
{
    if(fa[f]==father)return;
        cout<<f<<'\n';

    fa[f]=fa[father];
    for(auto v:child[f])
        if(v!=f)
            dfs(v,father);
}

int dfs2(int start,int f,int step)
{
    //cout<<f<<'\n';
    if(book[f])
    {
        book[f]=0;
        return f;
    }
    if(fa[f]==f)return f;
    book[f]=1;
    fa[f]=dfs2(start,fa[f],step+1);
    book[f]=0;
    return fa[f];
}

void work56()
{
    int n,m;
    cin>>n>>m;
    input(n,m);
    for(int i=1;i<=n;i++)child[v[i][1]].push_back(i);
    for(int i=1;i<=n;i++)fa[i]=v[i][1];
    for(int i=1;i<=n;i++)dfs2(i,i,0);
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=(fa[i]==0);
    cout<<ans<<'\n';
}

void work(int id)
{
    switch(id)
    {
        case 1:case 2:work12();break;
        case 3:case 4:work34();break;
        case 5:case 6:work56();break;
        default:work12();
    }
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int id,t;
    cin>>id>>t;
    while(t--)work(id);    
}