#include<bits/stdc++.h>
using namespace std;

int c,n,m,q;
int N[2],M[2];
int x,y;
int n1,m1;

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    scanf("%d%d",&N[1],&M[1]);
    printf("%d",(N[1]!=M[1])?1:0);
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&x,&y);
        for(int i=1;i<=x;i++)scanf("%d%d",&n1,&n1);
        for(int i=1;i<=y;i++)scanf("%d%d",&m1,&m1);
        printf("%d",(n1!=m1)?1:0);
    }
    return 0;
}
//for 5 points,i tried my best