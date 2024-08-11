#include<iostream>
#define MAXN 100010
using namespace std;
char a[MAXN];
int c,t;
void init(int x)
{
    for(int i=1;i<=x;i++)
    {
        a[i]='F';
    }
}
struct step1{
    char opt;
    int x;
}stp1[MAXN];
struct step2{
    char opt;
    int x;
    int y;
}stp2[MAXN];
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    if(c==1||c==2)
    {
        while(t--)
        {
            int ans=0;
            int n,m;
            cin>>n>>m;
            for(int i=1;i<=m;i++)
            {
                char opt;
                cin>>opt;
                if(opt=='T'||opt=='F'||opt=='U')
                {
                    int x;
                    cin>>x;
                    stp1[i].opt=opt;
                    stp1[i].x=x;
                }
                if(opt=='+'||opt=='-')
                {
                    int x,y;
                    cin>>x>>y;
                    stp2[i].opt=opt;
                    stp2[i].x=x;
                    stp2[i].y=y;
                }
            }
        }
    }
    if(c==3||c==4)
    {
        while(t--)
        {
            int n,m;
            cin>>n>>m;
            init(n);
            int ans=0;
            for(int i=1;i<=m;i++)
            {
                int k;
                char opt;
                cin>>opt>>k;
                a[k]=opt;
            }
            for(int i=1;i<=n;i++)
            {
                if(a[i]=='U') ans++;
            }
            cout<<ans<<endl;
        }
    }
    if(c==7||c==8)
    return 0;
}
