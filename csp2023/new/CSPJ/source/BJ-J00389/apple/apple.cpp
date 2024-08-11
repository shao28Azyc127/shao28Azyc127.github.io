include<iostream>
#include<stdio.h>
using namespace std;
int n,day0,day1=1;
int a[1000001];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    a[1]=1;
    a[2]=2;
    a[3]=3;
    a[4]=3;
    for(int i=1;i<=n;i++)
    {
        int p=(i+2)/3;
        a[i]=a[i-p]+1;
    }
    day0=a[n];
    for(int i=1;i<=n;i++)
    {
        a[i]=0;
    }
    for(int i=1;i<=day0;i++)
    {
        int counting=1;
        for(int j=1;j<=n;j++)
        {
            if(a[j])continue;
            if(counting==1)a[j]=1;
            counting++;
            if(counting>3)counting=1;
        }
        if(a[n])
        {
            day1=i;break;
        }
    }
    cout<<day0<<' '<<day1<<endl;
    return 0;
}
