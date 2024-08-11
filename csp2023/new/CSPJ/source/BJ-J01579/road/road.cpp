//乍一看很像图论的贪心，可能有dp做法但是不想了
#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
#include<map>
#include<stack>
#include<queue>
using namespace std;
int n,d;
double v[100005],b[100005];
int a[100005];
long long sum=0;
int amin=1e9;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=2;i<=n;i++)
    {
        cin>>v[i];
        v[i]=v[i-1]+v[i];
      //  cout<<i<<' '<<v[i]<<endl;
    }
    for(int i=2;i<=n;i++)
    {
        v[i]/=d;
        if(int(v[i])<v[i])
            v[i]=int(v[i])+1;
        else
            v[i]=int(v[i]);
    }
  //  for(int i=1;i<=n;i++)
   //     cout<<i<<' '<<v[i]<<' '<<v[i]-v[i-1]<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        amin=min(amin,a[i]);
    }
    //能过三个点
    if(amin==a[1])
    {
        cout<<(int)(v[n-1]*a[1])<<endl;
        return 0;
    }
    amin=a[1];
    int nummin=1;
    sum+=v[2]*amin;
    for(int i=2;i<n;i++)
    {
        if(a[i]>=amin)
            sum+=(v[i+1]-v[i])*amin;
        else
        {
            nummin=i;
            amin=a[i];
            sum+=(v[i+1]-v[i])*amin;
        }
    }
    cout<<sum<<endl;
    return 0;
}
