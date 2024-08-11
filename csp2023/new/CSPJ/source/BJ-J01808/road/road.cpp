#include<bits/stdc++.h>
using namespace std;
int n,p,a[100009],v[100009],sum,ans,l,z,j;
bool y;
int main()
{

    cin>>n>>p;
    for(int i=1;i<=n-1;i++) cin<<a[i];
    for(int i=1;i<=n;i++) cin<<v[i];
    for(int i=1;i<=n;i=i)
    {
        for(j=i+1;j<=n-1;j++)
        {
           if(v[i]>v[j])
           {
               for(int k=i;k<=j-1;k++)
               {
                   sum+=a[k];
               }
               ans+=v[i]*((sum-1)/p+1);
               l+=((sum-1)/p+1);
               l-=sum;
               y=true;
               continue;
           }
           if(y==true) continue;
        }
        i=j;
        sum=0;
    }
    cout<<ans;
    return 0;
}
