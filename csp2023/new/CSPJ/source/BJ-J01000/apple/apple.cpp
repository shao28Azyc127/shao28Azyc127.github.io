#include<iostream>
#include<cstdio>
using namespace std;
int n,flag=2,day;
int a[1000005],b[1000005];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        a[i]=i;
    }
    int t=n;
    while(t>0)
    {
        flag=2;
        for(int j=1;j<=n;j++)
        {
            if(a[j]!=0&&flag==2)
            {
                a[j]=0;
                b[j]=day+1;
                flag=0;
                t--;
            }
            else if(a[j]!=0)
            {
                flag++;
            }
        }
        day++;
    }
    cout<<day<<" "<<b[n];
    return 0;
}

