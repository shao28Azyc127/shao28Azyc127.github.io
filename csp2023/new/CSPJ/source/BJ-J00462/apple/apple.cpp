#include<bits/stdc++.h>
using namespace std;
const int N=100000001;
int a[N];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,m,i,idmin=1000000001,ans=0,cnt=0,j=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        a[i]=i;
    }
    i=0;
    while(idmin<=n-1||a[n-1]!=-1)
    {
        while(i<n)
        {
            if(a[i]==-1)
            {
                if(idmin==n-1&&a[n-1]==-1)
                {
                    cout<<cnt<<" "<<ans;
                    return 0;
                }
                if(i>=n) break;
                i++;
                continue;
            }
            if(j%3==0)
            {
                a[i]=-1;
                if(i==n-1)
                {
                    ans=cnt+1;
                    idmin=n;
                    a[n-1]=-1;
                    break;
                }
            }
            if(a[i]!=-1)
            {
                idmin=min(idmin,a[i]);
            }
            i++;
            j++;
        }
        i=0;
        j=0;
        cnt++;
        bool f=false;
        for(int k=1;k<=n;k++)
        {
            if(a[k]!=-1)
            {
                f=true;
            }
        }
        if(f==false)
        {
            break;
        }
    }
    cout<<cnt<<" "<<ans;
    return 0;
}
