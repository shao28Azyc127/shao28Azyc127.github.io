#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen(apple,"r",stdin);
    int n;
    scanf("%d",&n);
    int a[n+5],end,take=0,k,day=0;
    freopen(apple,"w",stdout);
    for(int i=1;i<=n;i++)
    {
     a[i]=1;
    }
    while(take<n)
    {k=0;
     day++;
     for(int j=1;j<=n;j++)
     {if(a[j]==1)
      {
       k++;
      }
      if((k-1)%3==0)
      {if(j==n)
       {
        end=day;
       }
       a[j]=0;
       take++;
      }
     }
    }
    printf("%d %d",day,end);
    return 0;
}