#include <bits/stdc++.h>
#define maxn 100001
using namespace std;
struct o
{
    char c;
    int i,j;
}opt[maxn];
//T==1 F==2 U==3
int rel[maxn];
int p;
int c,t,n,m,tp[maxn],ans;
pair<int,bool> fa[maxn];
int inv(int v) {return (v==3?3:(v==1?2:1));}
int tran(char c)
{
    if(c=='T') return 1;
    else if(c=='F') return 2;
    else if(c=='U') return 3;
    else return -1;
}
void dfs(int now)
{
    if(!fa[fa[now].first].first)
    {
        if(fa[now].second) tp[now]=p=inv(tp[fa[now].first]);
        else tp[now]=p=tp[fa[now].first];

        //cout<<"here end";
        //cout<<now<<"is 0 0\n";
        fa[now]=make_pair(0,0);
        return;
    }
    if(rel[fa[now].first]!=-1)
    {
        //cout<<"here with"<<now<<' '<<fa[now].first<<' '<<fa[now].second<<' '<<tp[fa[now].first]<<'\n';
        //if(tp[fa[now].first]) p=tp[now]=tp[fa[now].first];
        //else
        //{
        if(rel[fa[now].first]!=rel[now]^fa[now].second) p=tp[now]=3;
        //}
        //cout<<now<<"is 0 0\n";
        fa[now]=make_pair(0,0);
        return;
    }
    //vis[fa[now].first]=true;
    rel[fa[now].first]=rel[now]^fa[now].second;
    dfs(fa[now].first);
    if(p)
    {
        if(fa[now].second) p=inv(p);
    }
    tp[now]=p;
    //cout<<now<<"is 0 0\n";
    fa[now]=make_pair(0,0);
 }
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        //ans=0x3f3f3f3f;
        ans=0;
        memset(opt,0,sizeof(opt));
        memset(rel,0,sizeof(rel));
        memset(fa,0,sizeof(fa));
        memset(tp,0,sizeof(tp));
        cin>>n>>m;
        for(int i=1;i<=n;i++) rel[i]=-1;
        for(int i=1;i<=m;i++)
        {
            cin>>opt[i].c>>opt[i].i;
            if(tran(opt[i].c)==-1)
            {
                cin>>opt[i].j;
                tp[opt[i].i]=0;
                if(opt[i].c=='+') fa[opt[i].i]=make_pair(opt[i].j,0);
                else if(opt[i].c=='-') fa[opt[i].i]=make_pair(opt[i].j,1);
            }
            else{
                fa[opt[i].i]=make_pair(0,0);
                tp[opt[i].i]=tran(opt[i].c);
            }
        }
        /*cout<<"data: \n";
        for(int i=1;i<=n;i++)
        {
            cout<<fa[i].first<<' '<<fa[i].second<<' '<<tp[i]<<'\n';
        }*/
        for(int i=1;i<=n;i++)
        {
            if(fa[i]!=make_pair(0,false))
            {
                //cout<<"enter when i="<<i<<'\n';
                //memset(vis,0,sizeof(vis));
                rel[i]=0;
                p=0;
                dfs(i);
            }

        }
        /*cout<<"tp: \n";
        for(int i=1;i<=n;i++) cout<<tp[i]<<' ';
        cout<<'\n';*/
        for(int i=1;i<=n;i++) if(tp[i]==3) ans++;
        cout<<ans<<'\n';
    }
    return 0;
}
/*
10 10
- 7 6
+ 4 1
+ 6 4
T 1
+ 2 9
- 9 10
U 10
+ 5 5
U 8
T 3

*/
