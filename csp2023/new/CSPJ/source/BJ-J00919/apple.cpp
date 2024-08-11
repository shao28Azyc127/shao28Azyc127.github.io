#include <bits/stdc++.h>
using namespace std;
int n,a[1000020]={};
int main()
{
    int cnt=0,day=0;
    cin>>n;
    int m=n;
    while(m>0)
    {
        cnt++;
        int x,sum=(m-1)/3+1;
        m-=sum;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                x=i;
                break;
            }
        }
        for(int i=1;i<=sum;i++)
        {
            a[x]=1;
            if(x==n)
            {
                day=cnt;
            }
            x+=3;
        }
    }
    cout << cnt<<" "<<day;
    return 0;
}