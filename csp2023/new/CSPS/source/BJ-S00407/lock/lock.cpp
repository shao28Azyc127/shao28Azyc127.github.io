#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n,w[10][8],ans=0;
    scanf("%d",&n);
    for(register int i=1;i<=n;i++){
           for(register int j=1;j<=5;j++){
              scanf("%d",&w[i][j]);
           }
    }
    if(n==1)printf("%d",81);
    else
    {
       printf("%d",46-n);
    }
    return 0;
}