#include<bits/stdc++.h>
using namespace std;
int n,sum;
char a[2000010];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>a;
    for(int i=0;i<=n-1;i++)
    {
        int x[2000010],r=1;
        for(int k=i;k<=n;k++)
        {
            if(a[k]!=x[r-1])
            {
                x[r]=a[k];
                r++;
            }
            else
            {
                r--;
            }
            if(r==1)
            {
                sum++;
            }
        }

    }
    cout<<sum;
    return 0;
}
