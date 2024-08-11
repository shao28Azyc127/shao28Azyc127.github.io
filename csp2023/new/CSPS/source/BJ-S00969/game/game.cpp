#include <bits/stdc++.h>
using namespace std;
int n,sum;
string a;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>a;
    int l=a.size();
    while(l>=2)
    {
        //cout<<l;
        for(int i=1;i<l;i++)
        {
            if(a[i]==a[i+1])
            {
                sum++;
                for(int j=i+2;j<=l;j++)
                {
                    a[j]=a[j-2];
                }
            }
            l-=2;
            i-=2;
        }
        if(l==2)
        {
            break;
        }
    }
    cout<<sum;
    return 0;
}