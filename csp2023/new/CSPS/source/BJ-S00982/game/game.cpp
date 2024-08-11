#include<iostream>
#include<cstdio>
using namespace std;

const int maxn=805;
int n,ans;
char s[maxn];

bool chk(int x,int y)
{
  //  cout<<"\n\n\n\n"<<x<<' '<<y<<endl;
    int stk[maxn],tp=0;
    for(int i=x;i<=y;i++)
    {
        stk[++tp]=s[i];
        while(tp>0&&stk[tp]==stk[tp-1]) tp-=2;
  //      cout<<tp<<' '<<stk[tp]<<endl;
    }
    if(tp==0) return true;
    return false;
}


int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    cin>>(s+1);
    for(int k=1;k<=n;k++)
        for(int i=1,j=k;j<=n;i++,j++)
    {
        if(chk(i,j)) ans++;
    }
    printf("%d",ans);
    return 0;
}
