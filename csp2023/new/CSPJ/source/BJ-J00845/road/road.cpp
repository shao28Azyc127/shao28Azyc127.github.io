#include<bits/stdc++.h>
using namespace std;
int v[100005],a[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,sum=0;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)
    {
        cin>>v[i];
    }
    for(int j=1;j<=n;j++)
    {
        cin>>a[j];
    }
    int p=0;
    for(int i=1;i<=n-1;i++)
    {

        for(int j=i+1;j<=n;j++)
        {

            p=p+v[j-1];
            if(a[j]<a[i])
            {
              if(p%d==0)
              {
                  int q=p/d;

                  sum=sum+q*a[i];
                  p=0;
                  //cout<<sum<<endl;
              }
              else
              {
                  int q=p/d;
                  //cout<<q<<endl;
                  q++;

                sum=sum+q*a[i];
                p=p-q*d;
              // cout<<sum<<endl;
              }
              i=j-1;
              break;
            }
            if(a[j]>=a[i] and j==n)
            {
              if(p%d==0)
              {
                  int q=p/d;

                  sum=sum+q*a[i];
                  p=0;
                  //cout<<sum<<endl;
              }
              else
              {
                  int q=p/d;
                  //cout<<q<<endl;
                  q++;

                sum=sum+q*a[i];
                p=p-q*d;
              // cout<<sum<<endl;
              }
              i=j-1;
              break;
            }
        }
    }
    cout<<sum;
    return 0;
}
