#include<bits/stdc++.h>
#define debug printf("debug\n")
using namespace std;
typedef long long i64;
int c,t,n,m,x,ans;
char ch;
bool chose[100005];
void solve1()
{
    for(int i=1;i<=m;++i)
        {
            cin>>ch>>x;
            //scanf("%c%d",&ch,&x);
            if(ch=='U')chose[x]=true;
            else chose[x]=false;
        }
        for(int i=1;i<=n;++i)if(chose[i])
        {
            chose[i]=false;
            ++ans;
        }

}
int a,b;
void solve2()
{
    for(int i=1;i<=m;++i)
    {
        cin>>ch;
        if(ch=='U')
        {
            cin>>x;
            chose[x]=true;
        }
        else{
            cin>>a>>b;
            chose[a]=chose[b];
        }
    }
    for(int i=1;i<=n;++i)if(chose[i])
        {
            chose[i]=false;
            ++ans;
        }

}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--)
    {
        ans=0;
        scanf("%d%d",&n,&m);
        if(c==3||c==4)solve1();
        if(c==5||c==6)solve2();
        if(c==7||c==8)ans=0;
        printf("%d\n",ans);
    }
    return 0;
}
