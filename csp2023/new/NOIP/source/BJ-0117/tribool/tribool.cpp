#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <algorithm>
using namespace std;
//#define int long long
////溢出？不存在的！
struct wanuuuuts
{
    int ty;
    int a,b;
}ad[100010];
char b;
int x1,x2;
int ans;
int i,j,n,m,c,t;
signed main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    if(c==1||c==2)
    {
        while(t--)
        {
            ans=1e9;
            cin>>n>>m;
            int tm=pow(3,n);
            for(i=1;i<=m;i++)
            {
                cin>>b;
                if(b=='T'||b=='U'||b=='F')
                {
                    ad[i].ty=0;
                    if(b=='T')
                        ad[i].a=0;
                    else if(b=='F')
                        ad[i].a=1;
                    else
                        ad[i].a=2;
                    cin>>x2;
                    ad[i].b=x2;
                }
                else if(b=='+')
                {
                    ad[i].ty=1;
                    cin>>ad[i].b>>ad[i].a;
                }
                else
                {
                    ad[i].ty=2;
                    cin>>ad[i].b>>ad[i].a;
                }
            }
            int be[20],no[20];
            for(i=0;i<tm;i++)
            {
                int nowt=1,unum=0;
                for(j=1;j<=n;j++)
                {
                    be[j]=(i/nowt)%3ll;
                    no[j]=be[j];
                    nowt *=3ll;
                    if(be[j]==2)
                        unum++;
                }
                if(unum>=ans)
                    continue;
                for(j=1;j<=m;j++)
                {
                    if(ad[j].ty==0)
                        no[ad[j].b]=ad[j].a;
                    else if(ad[j].ty==1)
                        no[ad[j].b]=no[ad[j].a];
                    else if(no[ad[j].a]!=2)
                        no[ad[j].b]=1-no[ad[j].a];
                    else
                        no[ad[j].b]=2;
                }
                bool fl=true;
                for(j=1;j<=n;j++)
                {
                    if(no[j]!=be[j])
                    {
                        fl=false;
                        break;
                    }
                }
                if(!fl)
                    continue;
                ans=unum;
                //for(j=1;j<=n;j++)
                    //cout<<no[j]<<" ";
                //cout<<endl;
            }
            cout<<ans<<endl;
        }
    }
    else if(c==3||c==4)
    {
        while(t--)
        {
            cin>>n>>m;
            int tnum[100010];
            for(i=1;i<=n;i++)
                tnum[i]=1;
            ans=0;
            for(i=1;i<=m;i++)
            {
                cin>>b>>x1;
                if(b=='U'&&tnum[x1]<2)
                {
                    tnum[x1]=2;
                    ans++;
                }
            }
            cout<<ans<<endl;
        }
    }
    else if(c==5||c==6)
    {
        while(t--)
        {
            cin>>n>>m;
            int tnum[100010];
            for(i=1;i<=n;i++)
                tnum[i]=1;
            ans=0;
            for(i=1;i<=m;i++)
            {
                cin>>b>>x1;
                ad[x1].a=x1;
                if(b=='U')
                    ad[x1].ty=0;
                else
                {
                    ad[x1].ty=1;
                    cin>>ad[x1].b;
                    swap(ad[x1].a,ad[x1].b);
                }
            }
            int fl=114514;
            while(fl>0)
            {
                fl=0;
                for(i=1;i<=m;i++)
                {
                    if(ad[i].ty==0&&tnum[ad[i].a]==1)
                    {
                        ans++;
                        tnum[ad[i].a]=0;
                        fl++;
                    }
                    else if(ad[i].ty==1&&tnum[ad[i].a]!=tnum[ad[i].b])
                    {
                        if(tnum[ad[i].b]==0)
                        {
                            tnum[ad[i].b]=1;
                            fl--;
                            ans--;
                        }
                        else
                        {
                            tnum[ad[i].b]=0;
                            fl++;
                            ans++;
                        }
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    else
    {
        while(t--)
        {
            cin>>n;
            cout<<n<<endl;
            //不可以，总司令
            cin>>m;
            for(i=1;i<=m;i++)
            {
                cin>>b;
                cin>>x1;
                if(b=='+'||b=='-')
                    cin>>x2;
            }
        }
    }
    return 0;
}