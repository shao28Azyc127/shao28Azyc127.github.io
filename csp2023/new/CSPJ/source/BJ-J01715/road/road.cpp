#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen(road.in,"r",stdin);
    freopen(road.out,"w",stdout);
    int n,d;
    scanf("%d %d",&n,&d);
    int v[n+4],a[n+5],stop=1,over=0,dis,k,p=0,drive;
    for(int i=1;i<n;i++)
    {
     scanf("%d",&v[i]);
    }
    for(int j=1;j<=n;j++)
    {
     scanf("%d",&a[j]);
    }
    while(stop<n)
    {
     dis=-over;
     k=0;
     while(a[stop]<a[stop+k]&&stop+k<n)
     {
      dis+=v[stop+k];
      k++;
     }
     k--;
     drive=ceil(dis*1.0/d);
     over=drive*d-dis;
     p+=drive*a[stop];
     stop+=k+1;
    }
    printf("%d",p);
    return 0;
}
