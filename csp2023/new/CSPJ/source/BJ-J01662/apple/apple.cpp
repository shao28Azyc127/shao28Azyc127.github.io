#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int i,n,a[1000010],n1,g,k,k1=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        a[i]=i;
    }
    while(a[1]!=0)
    {
        g++;
        for(i=1;i<=n;i=i+3)
        {
            if(a[i]=n)n1=g;
            a[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            a[i]=a[i+1];
            a[i+1]=0;
            if(a[i]==0)
            {
                while(a[i]==0)
                {
                    k1++;
                    a[i]=a[i+k1];
                    if(i+k1==n)break;
                }
                a[i+k1]=0;
                i=i+k1;
                k1=1;
            }
        }
    }
    cout<<n1<<' '<<g;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
