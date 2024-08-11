#include<bits/stdc++.h>
using namespace std;
double p[100000],l[100000];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=0;i<n-1;++i)
    {
        scanf("%lf",&l[i]);
        l[i]/=d;
    }
    for(int i=0;i<n;++i)
    {
        scanf("%lf",&p[i]);
    }
    double o=0.0,t=0;
    int i=0;
    while(i<n-1)
    {
        int temp,j;
        for(j=i+1;j<=n;++j)
        {
            if(o<p[i]*ceil(l[j-1]))
            {
                int tmp=ceil(l[j-1]-o);
                o+=tmp;
                t+=p[i]*tmp;
            }
            o-=l[i];
            if(p[j]<p[i]){
                break;
            }
        }
        i=j;
    }
    cout<<t;
}
