#include <iostream>
#include <stdlib.h>
#define inf 0x3f3f3f3f

using namespace std;

int n;
int cnt;
int t;
int ans;
int a[inf];

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    while(t==n)
    {
        for(int i=0;i<n;i=i+2)
        {
            if(a[i]==0)
            {
                continue;
            }
            else
            {
                if(i==n)
                {
                    cout<<cnt;
                }
                t++;
                a[i]=0;
            }
        }
        cnt++;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=0)
            {
                if(i-2<0)
                {
                    a[0]=a[i];
                    continue;
                }
                a[i-2]=a[i];
            }
        }
    }
    cout<<' '<<ans;
    return 0;
}
