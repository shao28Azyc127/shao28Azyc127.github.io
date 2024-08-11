#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n,p=0,pj=0,py=0,l=0;
    int a[5][8];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>a[j][i];
        }
    }
    if(n==1)
    {
        cout<<81<<endl;
        return 0;
    }
    else
    {
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(a[j][i]==a[j][i-1])
                {
                    p++;
                    if(a[j-1][i]==a[j-1][i-1]&&a[j-1][i]-a[j-1][i-1]==a[j][i]-a[j][i-1])
                    {
                        l++;
                    }
                }
            }
            if(p==4)
            {
                pj++;
            }
            if(p==3&&l!=0)
            {
                py++;
            }
        }
    }
    int total=pj*9-pj+py*9-py;
    cout<<total<<endl;
    return 0;
}
