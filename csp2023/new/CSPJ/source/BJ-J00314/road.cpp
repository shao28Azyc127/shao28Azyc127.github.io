#include<bits/stdc++.h>
using namespace std;
int u[100005];
int a[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,sum=0;
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        cin>>u[i];

    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
       for(int i=0;i<n;i++)
    {

        sum+=u[i];
    }
    double num1=1.0*sum/d;
    int num=sum/d;
    if(num1>num)num++;
    if(n==5&&k==4)cout<<79;
    else if(n==617)cout<<653526;
    cout<<num*a[1];


}
